#include "filesystem.h"

t_log* logger;

int main(int argc, char ** argv){
    t_filesystem_config* config;
    config = inicializar_config(argv[1]);
    logger = log_create("./cfg/filesystem.log", "FILESYSTEM", true, LOG_LEVEL_INFO);

    int socket_servidor = inicializar_servidor(config->puerto_escucha,config->ip_memoria);
    handshakeServidor(socket_servidor, P_FILESYSTEM);//chequear  _P
    crear_hilo_conexion(atender_kernel, socket_servidor);//?

    int socket_cliente =inicializar_cliente(config->ip_memoria,config->puerto_memoria);
    handshake_cliente(socket_cliente,P_FILESYSTEM);//chequear  _P
    return 0;
}

t_filesystem_config* inicializar_config(char* path){
    t_config* raw;
    raw = config_create(path);

    t_filesystem_config* config = malloc(sizeof(t_filesystem_config));

    config->ip_memoria = buscarEnConfig(raw, "IP_MEMORIA");
    config->puerto_memoria = buscarEnConfig(raw, "PUERTO_MEMORIA");
    config->path_bitmap = buscarEnConfig(raw, "PATH_BITMAP");
    config->path_bloques = buscarEnConfig(raw, "PATH_BLOQUES");
    config->path_FCB = buscarEnConfig(raw, "PATH_FCB");
    config->path_superbloque = buscarEnConfig(raw, "PATH_SUPERBLOQUE");
    config->puerto_escucha = buscarEnConfig(raw, "PUERTO_ESCUCHA");
    config->retardo_acceso_bloque = buscarEnConfig(raw, "RETARDO_ACCESO_BLOQUE");

    return config;
}


void atender_kernel(int socket){
    idProtocolo code = P_CONSOLA;


    send(socket, &code, sizeof(int), 0);
    recv(socket, &code, sizeof(int), MSG_WAITALL); //Placeholder: Acá iría la lógica de interactuar con el kernel
    close(socket);
}
