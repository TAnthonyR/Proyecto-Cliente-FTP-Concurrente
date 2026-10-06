#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int errexit(const char *format, ...) {
    va_list arguments;
    va_start(arguments, format);
    vfprintf(stderr, format, arguments);
    va_end(arguments);
    exit(EXIT_FAILURE);
}
