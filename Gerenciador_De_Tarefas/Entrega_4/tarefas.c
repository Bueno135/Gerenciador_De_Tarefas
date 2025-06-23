#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tarefas.h"

void adicionarTarefa(Tarefa *vetor, int *total) {
    if (*total >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido.\n");
        return;
    }

    vetor[*total].id = *total + 1;

    printf("Digite o título da tarefa: ");
    getchar(); // limpar buffer
    fgets(vetor[*total].titulo, 100, stdin);
    vetor[*total].titulo[strcspn(vetor[*total].titulo, "\n")] = '\0';

    printf("Digite a descrição da tarefa: ");
    getchar(); // limpar buffer
    fgets(vetor[*total].descricao, TAM_DESC, stdin);
    vetor[*total].descricao[strcspn(vetor[*total].descricao, "\n")] = '\0'; // remover '\n'
    //Adicionar tarefa e sua descrição

    do {
    printf("Digite a prioridade da tarefa (1-5): ");
    scanf("%d", &vetor[*total].prioridade);
    } while (vetor[*total].prioridade < 1 || vetor[*total].prioridade > 5);
    //Coloca um limite de 5 para a prioridade e continua a repetir a pergunta até o numero ser menor ou igual a 5

    do {
    printf("Digite a data da tarefa (DD/MM/AAAA): ");
    scanf("%s", vetor[*total].data);
    if (!validarData(vetor[*total].data)) {
        printf("Data inválida. Tente novamente.\n");
    }
    } while (!validarData(vetor[*total].data));
    //Validação de data para saber se está seguindo a devida formatação

    do {
    printf("Digite o status da tarefa (0 = pendente, 1 = concluída): ");
    scanf("%d", &vetor[*total].status);
    } while (vetor[*total].status != 0 && vetor[*total].status != 1);
    //Limita o status para pendente e concluida

    (*total)++;
    printf("Tarefa adicionada!\n");
    salvarEmArquivo(vetor, *total);
}

void listarTarefas(Tarefa *vetor, int total) {
    int i;
    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    int tipo_ordenacao;
    printf("\nComo deseja ordenar as tarefas?\n");
    printf("1 - Por prioridade\n");
    printf("2 - Por data (e prioridade dentro da data)\n");
    printf("3 - Sem ordenação\n");
    printf("Escolha: ");
    scanf("%d", &tipo_ordenacao);

    switch (tipo_ordenacao) {
        case 1:
            ordenarPrioridade(vetor, total);
            break;
        case 2:
            ordenarData(vetor, total); // já organiza por data
            ordenarPrioridadeDentroDaMesmaData(vetor, total); // função para ordenar a prioridade da data escolhida
            break;
        case 3:
            break;
        default:
            printf("Opção inválida. Mostrando sem ordenação.\n");
    }

    printf("\nLista de tarefas:\n");

    for (i = 0; i < total; i++) {
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

void ordenarPrioridadeDentroDaMesmaData(Tarefa *vetor, int total) {
    int i, j;
    for (i = 0; i < total - 1; i++) {
        for (j = i + 1; j < total; j++) {
            if (strcmp(vetor[i].data, vetor[j].data) == 0 && vetor[i].prioridade > vetor[j].prioridade) {
                Tarefa temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    printf("Tarefas com mesma data ordenadas por prioridade!\n");
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

void apagarTarefa(Tarefa *vetor, int *total) {
    int i;
    if (*total == 0) {
        printf("Nenhuma tarefa para apagar.\n");
        return;
    }

    int id;
    printf("Digite o número da tarefa que deseja apagar (1 a %d): ", *total);
    scanf("%d", &id);

    if (id < 1 || id > *total) {
        printf("ID inválido.\n");
        return;
    }

    // Apaga a tarefa movendo as próximas para trás
    for (i = id - 1; i < *total - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    (*total)--;
    printf("Tarefa apagada com sucesso!\n");

    salvarEmArquivo(vetor, *total); // salvar após apagar
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

void salvarEmArquivo(Tarefa* vetor, int total) {
    FILE *arquivo = fopen("tarefas.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, arquivo); // salva total de tarefas
    fwrite(vetor, sizeof(Tarefa), total, arquivo); // salva vetor
    fclose(arquivo);
    printf("Tarefas salvas com sucesso!\n");
}

void carregarDeArquivo(Tarefa* vetor, int* total) {
    FILE *arquivo = fopen("tarefas.dat", "rb");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    fread(total, sizeof(int), 1, arquivo); // lê o total de tarefas
    fread(vetor, sizeof(Tarefa), *total, arquivo); // lê o vetor
    fclose(arquivo);
    printf("Tarefas carregadas com sucesso!\n");
}   

bool validarData(const char *data) {
    int dia, mes, ano;

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3)
        return false;

    if (dia < 1 || dia > 31) return false;
    if (mes < 1 || mes > 12) return false;
    if (ano < 1900 || ano > 2100) return false;

    // Validação extra para meses com menos de 31 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return false;

    // Fevereiro e ano bissexto
    if (mes == 2) {
        bool bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if (dia > (bissexto ? 29 : 28))
            return false;
    }

    return true;
}