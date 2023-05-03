#include "cpu.h"

t_log* logger;

int main(int argc, char ** argv){
    t_cpu_config* config;
    config = config_create(argv[1]);
    logger = log_create("CPU/cfg/cpu.log", "CPU", true, LOG_LEVEL_INFO);

    int socket_cliente = inicializar_cliente(config->ip_kernel, config->puerto_kernel);
    handshakeCliente(socket_cliente, P_CONSOLA);

    return 0;
}

t_cpu_config* inicializar_config(char* path){
    t_config* raw;
    raw = config_create(path);

    t_cpu_config* config = malloc(sizeof(t_cpu_config));

    config->ip_memoria = buscarEnConfig(raw, "IP_KERNEL");
    config->puerto_escucha = buscarEnConfig(raw, "PUERTO_ESCUCHA");
    config->puerto_memoria = buscarEnConfig(raw, "PUERTO_MEMORIA");
    config->tam_max_segmento = buscarEnConfig(raw, "TAM_MAX_SEGMENTO");

    return config;
}

void atender_kernel(int socket){
    idProtocolo code = P_KERNEL;
    printf("Hilo '%s' ejecutando", __func__);
    send(socket, &code, sizeof(int), 0);
    recv(socket, &code, sizeof(int), MSG_WAITALL); //Placeholder: Acá iría la lógica de interactuar con el kernel
    close(socket);
}