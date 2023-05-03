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

typedef struct data_segmento{
    uint32_t id;
    uint32_t dir_base;
    uint32_t size;
}data_segmento;

typedef struct t_registros_cpu{
    //4 Bytes
    char ax[4];
    char bx[4];
    char cx[4];
    char dx[4];
    //8 Bytes
    char eax[8];
    char ebx[8];
    char ecx[8];
    char edx[8];
    //16 Bytes
    char rax[8];
    char rbx[8];
    char rcx[8];
    char rdx[8];
}t_registros_cpu;

typedef struct t_pcb{
    uint32_t pid;
    t_list* instrucciones;
    uint32_t program_counter;
    t_registros_cpu registros;
    t_list* tabla_segmentos; //Lista de "data_segmento"
    uint32_t est_prox_rafaga;
    uint32_t llegada_ready;
    t_list* archivos_abiertos; //A definir como se va a implementar esta tabla
}t_pcb;

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
