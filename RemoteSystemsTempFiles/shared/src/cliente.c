#include "cliente.h"

int inicializar_cliente(char *ip,char *puerto){

    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(ip, puerto, &hints, &servinfo); //agarra el puerto y la ip del server

    int socket_cliente = socket(servinfo->ai_family,
                                servinfo->ai_socktype,
                                servinfo->ai_protocol);

    if(connect(socket_cliente, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
        printf("Error al conectar\n");
    else
        printf("Conecto bien al puerto %s\n", puerto);
    freeaddrinfo(servinfo);
    
    return socket_cliente;
}

int handshake_cliente(int socket, idProtocolo id_a_conectar){
    uint32_t handshake = id_a_conectar;
    uint32_t result = -5;
    send(socket, &handshake, sizeof(uint32_t), 0);
    recv(socket, &result, sizeof(uint32_t), MSG_WAITALL);

    printf("\nHICE EL HANDSHAKE, FUE: %d\n", result);
    return result;
}