#include "consola.h"

t_log* logger;

int main(int argc, char ** argv){
    logger = log_create("./cfg/consola.log", "CONSOLA", true, LOG_LEVEL_INFO);
    if(argc < 3){
        log_error(logger, "Insuficientes parametros");
        return 1;
    }
    t_consola_config* config;
    t_list* instrucciones;
    config = inicializar_config(argv[2]);
    instrucciones = leer_archivo_pseudocodigo(argv[1]);
    //int socket_cliente = inicializar_cliente(config->ip_kernel, config->puerto_kernel);
    //handshakeCliente(socket_cliente, P_CONSOLA);
    //esperar_fin(socket_cliente);

    return 0;
}

t_consola_config* inicializar_config(char* path){
    t_config* raw;
    raw = config_create(path);

    t_consola_config* config = malloc(sizeof(t_consola_config));

    config->ip_kernel = buscarEnConfig(raw, "IP_KERNEL");
    config->puerto_kernel = buscarEnConfig(raw, "PUERTO_KERNEL");

    return config;
}

t_list* leer_archivo_pseudocodigo(char *path){
    FILE *archivo_de_instrucciones = fopen(path, "r");
    if(archivo_de_instrucciones == NULL){
        log_error(logger, "No se pudo abrir el archivo de insrucciones");
        return NULL;
    }
    char* linea = NULL;
    size_t len = 0;
    ssize_t read;
    t_list *instrucciones = list_create();
    while((read = getline(&linea, &len, archivo_de_instrucciones)) != -1){
        if(string_contains(linea, "F_READ") || string_contains(linea, "F_WRITE")){
            list_add(instrucciones, string_n_split(linea,4," "));
        }
        else if(string_contains(linea, "SET") || string_contains(linea, "MOV_IN") ||
                string_contains(linea, "MOV_OUT") || string_contains(linea, "F_TRUNCATE") ||
                string_contains(linea, "F_SEEK") || string_contains(linea, "CREATE_SEGMENT")){
                    list_add(instrucciones, string_n_split(linea,3," "));
                }
        else if(string_contains(linea, "I/O") || string_contains(linea, "WAIT") ||
                string_contains(linea, "SIGNAL") || string_contains(linea, "F_OPEN") ||
                string_contains(linea, "F_CLOSE") || string_contains(linea, "DELETE_SEGMENT")){
                    list_add(instrucciones, string_n_split(linea,2," "));
                }
        else if(string_contains(linea, "EXIT") || string_contains(linea, "YIELD")){
            list_add(instrucciones, linea);
        }
        else
            log_error(logger, "Instruccion invalida: %s", linea);
    }
    fclose(archivo_de_instrucciones);
    if(linea)
        free(linea);
    return instrucciones;
}




void esperar_fin(int socket_cliente){ //TODO: Definir esta funcion, es un placeholder que se cierra en 5 seg
    int code = -1;
    recv(socket_cliente, &code, sizeof(int), MSG_WAITALL);
    printf("Finalizando con '%d'", code);
}
