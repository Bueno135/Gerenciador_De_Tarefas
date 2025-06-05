// tarefas.h
#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_TAREFAS 100
#define TAM_DESC 100

typedef struct {
    char descricao[TAM_DESC];
    int prioridade;
} Tarefa;

void adicionarTarefa(Tarefa *vetor, int *total);
void listarTarefas(Tarefa *vetor, int total);

//Código para separar as funções da maine chama-las

#endif
