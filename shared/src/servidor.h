#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include <commons/config.h>
#include <commons/collections/list.h>
#include "shared.h"
#include <stdbool.h>
//server
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>
#include <ctype.h>




//  TO DO: Hacer control sobre el socket, sino loggear error y terminar proceso.
int inicializar_servidor(char* puerto, char* ip);
void handshake_servidor(int socket, idProtocolo id_conectado);
void cerrar_servidor(int servidor);


#endif
