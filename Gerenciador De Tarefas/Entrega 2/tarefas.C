// tarefas.c
#include <stdio.h>
#include <string.h>
#include "tarefas.h"

void adicionarTarefa(Tarefa *vetor, int *total) {
    if (*total >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    printf("Digite a descrição da tarefa: ");
    getchar(); // limpar buffer
    fgets(vetor[*total].descricao, TAM_DESC, stdin);
    vetor[*total].descricao[strcspn(vetor[*total].descricao, "\n")] = '\0'; // remover '\n'
    //Adicionar tarefa e sua descrição
    printf("Digite a prioridade da tarefa (1-5): ");
    scanf("%d", &vetor[*total].prioridade);

    (*total)++;
    printf("Tarefa adicionada com sucesso!\n");
}

void listarTarefas(Tarefa *vetor, int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Título: %s\n", vetor[i].titulo);
        printf("Descrição: %s\n", vetor[i].descricao);
        printf("Prioridade: %d\n", vetor[i].prioridade);
        printf("Data: %s\n", vetor[i].data);
        printf("Status: %d\n", vetor[i].status);
        printf("---------------------------\n");
        //Loop para puxar cada tarefa e sua prioridade
    }
}
