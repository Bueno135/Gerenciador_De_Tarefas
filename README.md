# Gerenciador de Tarefas em C

Este é um simples gerenciador de tarefas desenvolvido em C, projetado para ajudar a organizar suas atividades diárias. Ele permite adicionar, listar, buscar e ordenar tarefas, além de persistir os dados em um arquivo.



## Funcionalidades

- **Adicionar Tarefas**: Permite incluir novas tarefas com título, descrição, data, prioridade (de 1 a 5) e status (pendente/concluída).
- **Listar Tarefas**: Exibe todas as tarefas cadastradas, com opções de ordenação por prioridade ou por data. Dentro da mesma data, as tarefas são ordenadas por prioridade.
- **Buscar Tarefas**: Possibilita a busca de tarefas por título ou por status.
- **Persistência de Dados**: As tarefas são salvas em um arquivo binário (`tarefas.dat`) ao sair do programa e carregadas automaticamente ao iniciar, garantindo que seus dados não sejam perdidos.



## Como Compilar e Executar

Para compilar e executar este gerenciador de tarefas, você precisará de um compilador C (como o GCC).

1.  **Clone o repositório** (se aplicável):

    ```bash
    git clone <(https://github.com/Bueno135/Gerenciador_De_Tarefas)>
    cd <gerenciador_tarefas>
    ```

2.  **Compile os arquivos fonte**:

    ```bash
    gcc main.C tarefas.c -o gerenciador_tarefas
    ```

3.  **Execute o programa**:

    ```bash
    ./gerenciador_tarefas
    ```



## Estrutura do Projeto

O projeto é organizado em três arquivos principais:

-   `main.C`: Contém a função `main` que gerencia o menu de interação com o usuário e chama as funções de manipulação de tarefas.
-   `tarefas.h`: Arquivo de cabeçalho que define a estrutura `Tarefa` e declara as funções de manipulação de tarefas (adicionar, listar, salvar, carregar, ordenar e buscar).
-   `tarefas.c`: Contém a implementação das funções declaradas em `tarefas.h`, incluindo a lógica para adicionar, listar, ordenar por prioridade e data, buscar, salvar e carregar tarefas.
