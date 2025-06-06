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
void salvarEmArquivo(Tarefa*, int);
void carregarDeArquivo(Tarefa*, int*);
void ordenarPrioridade(Tarefa *vetor, int total);
void ordenarData(Tarefa *vetor, int total);
int buscar(Tarefa *vetor, int total, const char *valor_pesquisado, int tipo_busca);


//Cabeçalho para estruturar melhor o projeto e declararação das funções.
//Separa a lógica da main

#endif
