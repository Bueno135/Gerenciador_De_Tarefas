#ifndef ACTIV_H_INCLUDED
#define ACTIV_H_INCLUDED

#include <stdlib.h>

typedef struct
{
	int id;
    char titulo[100];
    char descricao[200];
    char data[11]; //(formato "DD/MM/AAAA")
    int prioridade; //(1 a 5) 
    int status; // (0 = pendente, 1 = concluída)


} Tarefa;


#endif // ACTIV_H_INCLUDED
