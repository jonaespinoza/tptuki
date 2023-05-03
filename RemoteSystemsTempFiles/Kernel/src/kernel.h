/*
 * kernel.h
 *
 *  Created on: 15 abr. 2023
 *      Author: utnso
 */

#ifndef SRC_KERNEL_H_
#define SRC_KERNEL_H_

#define IP 127.0.0.1

#include <stdio.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/config.h>
#include <commons/string.h>
#include <commons/collections/list.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <time.h>
#include <commons/collections/queue.h>

typedef struct pcb{
	int pid;
	t_list* instrucciones;
	int program_counter;
	//Estructura con valores de registro de CPU
	//Tabla de Segmentos ¿t_list? tabla_segmentos
	float estimado_rafaga;
	time_t timestamp_ready;
	t_list* tabla_archivos;
	char estado;

}pcb;

typedef enum {
	NEW,
	READY,
	EXECUTE,
	BLOCK,
	EXIT
}estado_proceso;

t_log* logger;
t_queue* cola;


void conexionMemoria(t_config* arg1);
void conexionFileSystem(t_config* arg1);
void conexionCPU(t_config* arg1);
void handlerConsola(int sockConsola);
pcb* crearPcb(int socket);
void planificacionFIFO(pcb* pcb);
void planificacionHRRN(pcb* pcb);

#endif /* SRC_KERNEL_H_ */