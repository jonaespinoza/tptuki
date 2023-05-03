#include "memoria.h"

t_log* logger;

int main(int argc, char ** argv){
    t_memoria_config* config;
    config = inicializar_config(argv[1]);
    logger = log_create("./cfg/memoria.log", "MEMORIA", true, LOG_LEVEL_INFO);
    
    return 0;
}

t_memoria_config* inicializar_config(char* path){
    t_config* raw;
    raw = config_create(path);

    t_memoria_config* config = malloc(sizeof(t_memoria_config));

    config->puerto_escucha = buscarEnConfig(raw, "PUERTO_ESCUCHA");
    config->tam_memoria = textoAuint32(buscarEnConfig(raw, "TAM_MEMORIA"));
    config->tam_segmento_0 = textoAuint32(buscarEnConfig(raw, "TAM_SEGMENTO_0"));
    config->cant_segmentos = textoAuint32(buscarEnConfig(raw, "CANT_SEGMENTOS"));
    config->retardo_memoria = textoAuint32(buscarEnConfig(raw, "RETARDO_MEMORIA"));
    config->retardo_compactacion = textoAuint32(buscarEnConfig(raw, "RETARDO_COMPACTACION"));
    config->algoritmo_asignacion = buscarEnConfig(raw, "ALGORITMO_ASIGNACION");

    return config;
}