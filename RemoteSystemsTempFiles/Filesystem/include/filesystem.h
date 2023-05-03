#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <stdio.h>
#include <commons/log.h>
#include <commons/config.h>
#include "shared/include/cliente.h"
#include "shared/include/servidor.h"
#include "shared/include/shared.h"

typedef struct t_filesystem_config{
    char* ip_memoria;
    char* puerto_memoria;
    char* puerto_escucha;
    char* path_superbloque;
    char* path_bitmap;
    char* path_bloques;
    char* path_FCB;
    int32_t retardo_acceso_bloque;
}t_filesystem_config;


t_filesystem_config* inicializar_config(char*);
/*
logs obligatorios :
Crear Archivo: “Crear Archivo: <NOMBRE_ARCHIVO>”
Apertura de Archivo: “Abrir Archivo: <NOMBRE_ARCHIVO>”
Truncate de Archivo: “Truncar Archivo: <NOMBRE_ARCHIVO> - Tamaño: <TAMAÑO>”
Acceso a Bitmap: “Acceso a Bitmap - Bloque: <NUMERO BLOQUE> - Estado: <ESTADO>” Nota: El estado es 0 o 1 donde 0 es libre y 1 es ocupado.
Lectura de Archivo: “Leer Archivo: <NOMBRE_ARCHIVO> - Puntero: <PUNTERO ARCHIVO> - Memoria: <DIRECCION MEMORIA> - Tamaño: <TAMAÑO>”
Escritura de Archivo: “Escribir Archivo: <NOMBRE_ARCHIVO> - Puntero: <PUNTERO ARCHIVO> - Memoria: <DIRECCION MEMORIA> - Tamaño: <TAMAÑO>”
Acceso a Bloque: “Acceso Bloque - Archivo: <NOMBRE_ARCHIVO> - Bloque Archivo: <NUMERO BLOQUE ARCHIVO> - Bloque File System <NUMERO BLOQUE FS>”
*/
#endif