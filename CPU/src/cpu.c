#include "cpu.h"

t_log* logger;
t_dictionary* dict_instrucciones;

int main(int argc, char ** argv){
    dict_instrucciones = inicializar_diccionario();
    t_cpu_config* config = inicializar_config;
    config = config_create(argv[1]);
    logger = log_create("././cfg/cpu.log", "CPU", true, LOG_LEVEL_INFO);

    t_pcb* pcb_actual = malloc(sizeof(t_pcb));

    ciclo_ejec(pcb_actual);

    //int socket_cliente = inicializar_cliente(config->ip_kernel, config->puerto_kernel);
    //handshakeCliente(socket_cliente, P_CONSOLA);

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

//Funciones execute de cada instrucción

int exe_SET(t_list* list){
    char* registro = list_get(list, 0);
    char* valor = list_get(list, 1);

    printf("\nEjecutando SET %s %s\n", registro, valor);
    return 0;
}

int exe_MOV_IN(t_list* list){
    char* registro = list_get(list, 0);
    char* dir_log = list_get(list, 1);
    return 0;
}

int exe_MOV_OUT(t_list* list){
    char* dir_log = list_get(list, 0);
    char* registro = list_get(list, 1);
    return 0;
}

int exe_IO(t_list* list){
    char* tiempo = list_get(list, 0);
    return 0;
}

int exe_F_OPEN(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    return 0;
}

int exe_F_CLOSE(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    return 0;
}

int exe_F_SEEK(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    char* posicion = list_get(list, 1);
    return 0;
}

int exe_F_READ(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    char* dir_log = list_get(list, 1);
    char* cant_bytes = list_get(list, 2);
    return 0;
}

int exe_F_WRITE(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    char* dir_log = list_get(list, 1);
    char* cant_bytes = list_get(list, 2);

    printf("\nEjecutando F_WRITE %s %s %s\n", nombre_archivo, dir_log, cant_bytes);
    return 0;
}

int exe_F_TRUNCATE(t_list* list){
    char* nombre_archivo = list_get(list, 0);
    char* size = list_get(list, 1);
    return 0;
}

int exe_WAIT(t_list* list){
    char* recurso = list_get(list, 0);
    return 0;
}

int exe_SIGNAL(t_list* list){
    char* recurso = list_get(list, 0);
    return 0;
}

int exe_CREATE_SEGMENT(t_list* list){
    char* id = list_get(list, 0);
    char* size = list_get(list, 1);
    return 0;
}

int exe_DELETE_SEGMENT(t_list* list){
    char* id = list_get(list, 0);
    return 0;
}

int exe_YIELD(t_list* list){
    return 0;
}

int exe_EXIT(t_list* list){
    return 0;
}

//Función para inicializar el t_dictionary creado como global con los valores de las 16 instrucciones existentes

t_dictionary* inicializar_diccionario(){
    t_dictionary* dict = dictionary_create();

    dictionary_put(dict, "SET", *exe_SET);
    dictionary_put(dict, "MOV_IN", *exe_MOV_IN);
    dictionary_put(dict, "MOV_OUT", *exe_MOV_OUT);
    dictionary_put(dict, "I/O", *exe_IO);
    dictionary_put(dict, "F_OPEN", *exe_F_OPEN);
    dictionary_put(dict, "F_CLOSE", *exe_F_CLOSE);
    dictionary_put(dict, "F_SEEK", *exe_F_SEEK);
    dictionary_put(dict, "F_READ", *exe_F_READ);
    dictionary_put(dict, "F_WRITE", *exe_F_WRITE);
    dictionary_put(dict, "F_TRUNCATE", *exe_F_TRUNCATE);
    dictionary_put(dict, "WAIT", *exe_WAIT);
    dictionary_put(dict, "SIGNAL", *exe_SIGNAL);
    dictionary_put(dict, "CRAETE_SEGMENT", *exe_CREATE_SEGMENT);
    dictionary_put(dict, "DELETE_SEGMENT", *exe_DELETE_SEGMENT);
    dictionary_put(dict, "YIELD", *exe_YIELD);
    dictionary_put(dict, "EXIT", *exe_EXIT);

    return dict;
}

void ejecutar(void* (func)(t_list*), t_list* params){
    (func)(params);
}

int ciclo_ejec(t_pcb* pcb){
    //fetch:
    //t_list* info_instr = list_get(pcb->instrucciones, pcb->program_counter);
    t_list* info_instr = list_create();
    list_add(info_instr, "F_WRITE");
    list_add(info_instr, "ARCHIVO");
    list_add(info_instr, "4");
    list_add(info_instr, "4");
    char* codigo_instr = list_remove(info_instr, 0);

    //decode:
    ejecutar(dictionary_get(dict_instrucciones, codigo_instr), info_instr);
}
