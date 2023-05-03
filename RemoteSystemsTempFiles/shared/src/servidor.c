#include "servidor.h"

int inicializar_servidor(char* puerto, char* ip){
    struct addrinfo *servinfo;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(ip, puerto, &hints, &servinfo); //crea el socket del server

    int socket_servidor = socket(servinfo->ai_family,
                                servinfo->ai_socktype,
                                servinfo->ai_protocol);

    bind(socket_servidor, servinfo->ai_addr, servinfo->ai_addrlen);

    listen(socket_servidor, SOMAXCONN);

    freeaddrinfo(servinfo);
    
    return socket_servidor;
}

void handshake_servidor(int socket, idProtocolo id_conectado){
    uint32_t handshake;
    uint32_t resultOk = 0;
    uint32_t resultError = -1;

    recv(socket, &handshake, sizeof(uint32_t), MSG_WAITALL);

    if(handshake == id_conectado){
        send(socket, &resultOk, sizeof(uint32_t), 0);
        printf("\nHandshake OK. Fue: %d\n", resultOk);  //Borrar, solo para corroborar
    }
    else{
        send(socket, &resultError, sizeof(uint32_t), 0);
        printf("\nHandshake incorrecto. Fue: %d\n", resultError); //Borrar, solo para corroborar
    }
}

void cerrar_servidor(int servidor){
    close(servidor);
}
