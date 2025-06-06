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

    printf("Digite o título da tarefa: ");
    getchar(); // limpar buffer
    fgets(vetor[*total].titulo, 100, stdin);
    vetor[*total].titulo[strcspn(vetor[*total].titulo, "\n")] = '\0';

    printf("Digite a data da tarefa (DD/MM/AAAA): ");
    scanf("%s", vetor[*total].data);

    printf("Digite o status da tarefa (ex: 0 ou 1): ");
    scanf("%d", &vetor[*total].status);

    (*total)++;
    //ordenar por prioridade:
    ordenarPrioridade(vetor, *total);
    //ordenar por data:
    ordenarData(vetor, *total);
    printf("Tarefa adicionada e ordenada com sucesso!\n");
}

void listarTarefas(Tarefa *vetor, int total) {
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Tarefa %d: %s (Prioridade: %d)\n", i + 1, vetor[i].descricao, vetor[i].prioridade);
        //Loop para puxar cada tarefa e sua prioridade
    }
}


//algoritmo de ordenação usado: insertionsort
void ordenarPrioridade(Tarefa *vetor, int total){
    Tarefa temp;
    int i, j;

    for (i = 1; i < total; i++) {
        temp = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j].prioridade > temp.prioridade) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = temp;
    }

    printf("Tarefas ordenadas por prioridade!\n");
}

//função auxiliar
int converterDataParaInteiro(const char *data) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;  // AAAAMMDD
}

void ordenarData(Tarefa *vetor, int total) {
    Tarefa temp;
    int i, j;

    for (i = 1; i < total; i++) {
        temp = vetor[i];
        int dataTemp = converterDataParaInteiro(temp.data);
        j = i - 1;

        while (j >= 0 && converterDataParaInteiro(vetor[j].data) > dataTemp) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = temp;
    }

    printf("Tarefas ordenadas por data!\n");
}

int buscar(Tarefa *vetor, int total, const char *valor_pesquisado, int tipo_busca){
    int i;
    int encontrados = 0;

    switch (tipo_busca){
        case 1: // busca por palavras no título
            for (i = 0; i < total; i++) {
                if (strstr(vetor[i].titulo, valor_pesquisado) != NULL) {
                    printf("Tarefa encontrada: %s (Prioridade: %d)\n", vetor[i].titulo, vetor[i].prioridade);
                    encontrados++;
                }
            }
            break;

        case 2: // busca por status (permitindo parcial como "1" ou "0")
            for (i = 0; i < total; i++) {
                char statusStr[10];
                sprintf(statusStr, "%d", vetor[i].status);
                if (strstr(statusStr, valor_pesquisado) != NULL) {
                    printf("Tarefa encontrada: %s (Status: %d)\n", vetor[i].titulo, vetor[i].status);
                    encontrados++;
                }
            }
            break;

        default:
            printf("Tipo de busca inválido.\n");
            return 0;
    }

    if (encontrados == 0) {
        printf("Nenhuma tarefa correspondente encontrada.\n");
    }

    return encontrados;
}