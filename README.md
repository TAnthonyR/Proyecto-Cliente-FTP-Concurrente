# Proyecto — Cliente FTP concurrente en C

Proyecto académico de Computación Distribuida. Implementa un cliente FTP mediante sockets POSIX y utiliza procesos hijos con `fork()` para transferencias múltiples. Permite observar la diferencia entre comunicación de control, comunicación de datos y ejecución concurrente.

## Funcionalidades

| Comando | Función |
|---|---|
| `list [patrón]` | Listar archivos remotos |
| `cd directorio` | Cambiar de directorio remoto |
| `size archivo` | Consultar tamaño |
| `mkd directorio` | Crear directorio |
| `dele archivo` | Eliminar archivo remoto |
| `get archivo` / `put archivo` | Transferir un archivo en modo pasivo |
| `pput archivo` | Subir un archivo en modo activo |
| `mget a b` / `mput a b` | Transferir varios archivos con procesos hijos |
| `help` / `quit` | Ayuda y salida |

## Estructura

- `ReinosoA-clienteFTP.c`: comandos, autenticación y transferencias.
- `connectTCP.c`, `connectsock.c`: resolución y conexión TCP IPv4.
- `errexit.c`: manejo de errores fatales.
- `Makefile-ClienteFTP`: compilación y limpieza.

## Requisitos y compilación

Linux o un entorno POSIX compatible, GCC, Make y un servidor FTP de laboratorio. En Windows utiliza una distribución Linux mediante WSL; el código no utiliza Winsock.

```bash
git clone https://github.com/TAnthonyR/Proyecto-Cliente-FTP-Concurrente.git
cd Proyecto-Cliente-FTP-Concurrente
make -f Makefile-ClienteFTP
./clienteftp_RA 127.0.0.1 21
```

El ejecutable se llama **`clienteftp_RA`**, igual que en el Makefile. Introduce el usuario y contraseña del servidor de prueba cuando lo solicite.

## Ejemplo de uso

```text
ftp> list
ftp> get ejemplo.txt
ftp> put prueba.txt
ftp> mget archivo1.txt archivo2.txt
ftp> quit
```

Los archivos locales se leen/escriben en el directorio desde el que ejecutas el cliente. Para observar procesos hijos, utiliza `ps` o `htop` en otra terminal y archivos de prueba suficientemente grandes: las transferencias pequeñas pueden terminar demasiado rápido para observarlas.

## Configurar el laboratorio

El servidor debe admitir PASV y PORT, autenticación de un usuario de prueba y los permisos necesarios para leer o escribir. Los modos activos requieren que el servidor pueda conectar hacia el cliente; NAT o un firewall pueden impedirlo. Usa un servidor desechable en una red controlada. No se incluyen usuarios, contraseñas ni direcciones de servidores institucionales.

## Limitaciones

Implementación académica de FTP sin TLS: las credenciales y el contenido viajan sin cifrar. Úsala con archivos y cuentas de prueba en el laboratorio. No sustituye un cliente SFTP/FTPS ni pretende cubrir todas las variantes del protocolo. La concurrencia y las respuestas del servidor requieren pruebas de integración en tu entorno.

## Créditos

Proyecto de [Anthony Reinoso](https://github.com/TAnthonyR). Los tres archivos auxiliares se añadieron al preparar esta versión para que el repositorio no dependa de fuentes ausentes. Se conserva el cliente principal del trabajo académico.

## Evidencia visual

El informe original no contiene capturas. No se añade una captura de ejecución nueva porque esta revisión se realizó en Windows sin compilador POSIX ni WSL disponible. Los pasos anteriores permiten compilar y probar el cliente en Linux.
