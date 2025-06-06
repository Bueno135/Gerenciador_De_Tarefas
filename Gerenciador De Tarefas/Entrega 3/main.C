// main.c
#include <stdio.h>
#include "tarefas.h"
#include <string.h>

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int opcao;
    int tipo_busca;
    char valor_pesquisado[100];

    do {
        printf("\n================ MENU ================\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Buscar tarefa\n");
        printf("0 - Sair\n");
        printf("======================================\n");
        printf("Escolha: ");

        scanf("%d", &opcao);
        //Menu para escolher qual opção você deseja
        switch (opcao) {
            case 1:
                adicionarTarefa(tarefas, &totalTarefas);
                break;
            case 2:
                listarTarefas(tarefas, totalTarefas);
                break;
            case 3:
                printf("\n1 - Busca por titulo\n2 - Busca por status\nEscolha: ");
                scanf("%d", &tipo_busca);
                printf("\nItem buscado: \n");
                getchar(); // limpar o buffer
                fgets(valor_pesquisado, sizeof(valor_pesquisado), stdin);
                valor_pesquisado[strcspn(valor_pesquisado, "\n")] = '\0'; // remover \n
                buscar(tarefas, totalTarefas, valor_pesquisado, tipo_busca);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);


    return 0;
}
