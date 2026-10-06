/* Adaptador TCP para el cliente FTP académico. */
int connectsock(const char *host, const char *service, const char *transport);
int connectTCP(const char *host, const char *service) {
    return connectsock(host, service, "tcp");
}
