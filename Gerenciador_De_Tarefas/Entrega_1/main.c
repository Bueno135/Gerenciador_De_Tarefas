#include "activ.h"


main(){
    
    Tarefa tarefas[MAX_TAREFAS];
    int totalTarefas = 0;
    int opcao;

    do {
        printf("\n1 - Adicionar tarefa\n2 - Listar tarefas\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        //Menu para escolher qual opção você deseja
        switch (opcao) {
            case 1:
                adicionarTarefa(tarefas, &totalTarefas);
                break;
            case 2:
                listarTarefas(tarefas, totalTarefas);
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