#include "shared.h"

int testShared(){
    printf("Funcionan las shared");
    return 0;
}

char* buscarEnConfig(t_config* config, char* index){
    char* valorObtenido;
    valorObtenido = config_get_string_value(config, index);
    return valorObtenido;
}

uint32_t textoAuint32(char* texto){
    int aux=0;
    uint32_t result;

    result = (uint32_t) sscanf(texto, "%d", &aux);

    return result;
}

double textoAdouble(char* texto){
    double result;

    result = (double) atof(texto);

    return result;
}

void showList(t_list* list){
    printf("\n[");
    for(int i=0; i<list_size(list); i++){
        printf("%s", list_get(list, i));
        if(list_size(list)-i-1)
            printf(",");
    }
    printf("]\n");
}

t_list* listarTexto(char* texto){
    char* rest = texto;
    t_list* lista = list_create();
    char* token = strtok_r(rest, "[, ]", &rest);

    while(token != NULL){
        list_add(lista, token);
        token = strtok_r(rest, "[, ]", &rest);
    }
    return lista;
}

void listaTextoANum(t_list* original){
    list_map(original, (void*)atoi);
}

void crear_hilo_conexion(void *funcion(void *), int socket)
{
    while (1)
    {
        pthread_t hilo;
        int socket_cliente = accept(socket, NULL, NULL);
        pthread_create(&hilo,
                       NULL,
                       funcion,
                       socket_cliente);
        pthread_detach(hilo);
    }
}