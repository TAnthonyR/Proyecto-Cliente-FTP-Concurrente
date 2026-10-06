/* Resuelve host/puerto y abre una conexión TCP IPv4 (el cliente usa PORT). */
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int errexit(const char *format, ...);
int connectsock(const char *host, const char *service, const char *transport) {
    struct addrinfo hints = {0}, *addresses = NULL, *entry;
    int sock = -1, saved_errno = 0;
    if (strcmp(transport, "tcp") != 0)
        errexit("Solo se admite TCP\n");
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(host, service, &hints, &addresses);
    if (status != 0)
        errexit("No se pudo resolver %s:%s: %s\n", host, service, gai_strerror(status));
    for (entry = addresses; entry != NULL; entry = entry->ai_next) {
        sock = socket(entry->ai_family, entry->ai_socktype, entry->ai_protocol);
        if (sock == -1) { saved_errno = errno; continue; }
        if (connect(sock, entry->ai_addr, entry->ai_addrlen) == 0) break;
        saved_errno = errno;
        close(sock);
        sock = -1;
    }
    freeaddrinfo(addresses);
    if (sock == -1)
        errexit("No se pudo conectar a %s:%s: %s\n", host, service, strerror(saved_errno));
    return sock;
}
