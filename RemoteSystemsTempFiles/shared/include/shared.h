#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include <stdbool.h>
//server
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>
#include <ctype.h>


typedef enum idProtocolo{
    P_CONSOLA,
    P_KERNEL,
    P_CPU,
    P_MEMORIA,
    P_FILESYSTEM
}idProtocolo;


int testShared();
void crear_hilo_conexion(void* funcion(void*), int socket);
char* buscarEnConfig(t_config*, char*);
uint32_t textoAuint32(char*);
double textoAdouble(char*);
t_list* listarTexto(char*);
void showList(t_list*);



#endif