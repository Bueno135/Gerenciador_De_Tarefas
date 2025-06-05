// tarefas.h
#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_TAREFAS 100
#define TAM_DESC 100

typedef struct {
    int id;
    char titulo[100];   
    char descricao[TAM_DESC];
    char data[11];
    int status;
    int prioridade;
} Tarefa;

void adicionarTarefa(Tarefa *vetor, int *total);
void listarTarefas(Tarefa *vetor, int total);

//Código para separar as funções da maine chama-las

#endif
