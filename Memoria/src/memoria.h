#ifndef MEMORIA_H
#define MEMORIA_H
#include <stdio.h>
#include <commons/log.h>
#include <commons/config.h>
#include "../include/cliente.h"
#include "../include/servidor.h"
#include "../include/shared.h"

typedef struct t_memoria_config{
    char* puerto_escucha;
    uint32_t tam_memoria;
    uint32_t tam_segmento_0;
    uint32_t cant_segmentos;
    uint32_t retardo_memoria;
    uint32_t retardo_compactacion;
    char* algoritmo_asignacion;
}t_memoria_config;

t_memoria_config* inicializar_config(char*);

#endif
