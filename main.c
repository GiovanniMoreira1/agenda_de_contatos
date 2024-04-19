#include <stdio.h>
#include "agenda.h"

int main(){
    func funcoes[] = {criar, deletar, listar, salvar, carregar}; // Lista de Funções

    Contato contatos[TOTAL];

    int pos = 0;
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
        clearBuffer();

        opcao--;
        if(opcao <= 4 && opcao >= 0 ){
            Value res = funcoes[opcao](contatos, &pos); // Chama a Função Respectiva a opção escolhida
        }
        else if(opcao == -1){
            printf("| > Sair...\n");
        }
        else{
            printf("| > Opcao inválida, Tente Novamente...\n");
        }
            
    } while(opcao != -1);

}