#include <stdio.h>
#include "tarefas.h"
#include <string.h>

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int opcao;
    int tipo_busca;
    char valor_pesquisado[100];

    carregarDeArquivo(tarefas, &totalTarefas);

    do {
        printf("\n================ MENU ================\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Listar tarefas\n");
        printf("3 - Buscar tarefa\n");
        printf("4 - Ordenar tarefas\n");
        printf("5 - Editar tarefa\n");
        printf("6 - Excluir tarefa\n");
        printf("7 - Relatorio de tarefas pendentes\n");
        printf("0 - Salvar e sair\n");
        printf("======================================\n");
        printf("\nTotal de tarefas cadastradas: %d\n", totalTarefas);
        printf("Escolha: ");

        scanf("%d", &opcao);
        while (getchar() != '\n');  // Limpa o buffer
        //Menu para escolher qual opção você deseja
        switch (opcao) {
            case 1: // adic tarefa
                adicionarTarefa(tarefas, &totalTarefas);
                break;
            case 2: //listar tarefa
                listarTarefas(tarefas, totalTarefas);
                break;
            case 3: //buscar tarefa
                printf("\n1 - Busca por titulo\n2 - Busca por status\n3 - Busca por id\nEscolha: ");
                scanf("%d", &tipo_busca);
                printf("\nItem buscado: \n");
                getchar(); // limpar o buffer
                fgets(valor_pesquisado, sizeof(valor_pesquisado), stdin);
                valor_pesquisado[strcspn(valor_pesquisado, "\n")] = '\0'; // remover \n
                buscar(tarefas, totalTarefas, valor_pesquisado, tipo_busca);
                break;
            case 4: //ordenar tarefa
                printf("1 - Ordenar por prioridade\n2 - Ordenar por data\nEscolha: ");
                int tipo_ordenar;
                scanf("%d", &tipo_ordenar);
                while (getchar() != '\n');  // Limpa o buffer
                if (tipo_ordenar == 1) ordenarPrioridade(tarefas, totalTarefas);
                else if (tipo_ordenar == 2) ordenarData(tarefas, totalTarefas);
                else printf("Opção inválida.\n");
                break;
            case 5: //editar tarefa
                listarTarefas(tarefas, totalTarefas);
                editarTarefa(tarefas, totalTarefas);
                break;
            case 6: //excluir tarefa
                apagarTarefa(tarefas, &totalTarefas);
                break;
            case 7: //relatorio de tarefas pendentes
                relatorioTarefas(tarefas, totalTarefas);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    salvarEmArquivo(tarefas, totalTarefas);

    return 0;
}
