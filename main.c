#include <stdio.h>

int main(){

    int pos;
    int opcao;
    do{
        printf("\n|------------------------------|\n");
        printf("|- - - Agenda de Contatos - - -|\n");
        printf("| 1 - Criar Contato            |\n");
        printf("| 2 - Deletar Contato          |\n");
        printf("| 3 - Listar Contatos          |\n");
        printf("| 4 - Salvar Contatos          |\n");
        printf("| 5 - Carregar Contatos        |\n");
        printf("| 0 - Sair                     |\n");
        printf("|------------------------------|\n");
        printf("| > Escolha uma opcao: ");
        scanf("%d", &opcao);

        opcao--;
        if(opcao > 4)
            printf("| > Opcao inválida...\n");
        else if(opcao >= 0){
            // Tratamento de Chamado de Funções
        }
        else
            printf("| > Sair...\n");

    } while(opcao >= 0);

}