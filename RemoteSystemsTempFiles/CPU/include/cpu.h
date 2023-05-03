#ifndef CPU_H
#define CPU_H
#include <stdio.h>
#include <commons/log.h>
#include <commons/config.h>
#include "shared/include/cliente.h"
#include "shared/include/servidor.h"
#include "shared/include/shared.h"

typedef struct t_cpu_config{
    char* ip_memoria;
    char* puerto_memoria;
    char* puerto_escucha;
    uint32_t tam_max_segmento;
}t_cpu_config;

t_cpu_config* inicializar_config(char*);

#endif