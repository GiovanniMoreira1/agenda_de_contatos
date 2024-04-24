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
            Value erro = funcoes[opcao](contatos, &pos); // Chama a Função Respectiva a opção escolhida
        
                    if (erro == MAX_CONTATO) {
                printf("ERRO - Máximo de contatos atingido.\n");
            } else if (erro == CRIAR) {
                printf("ERRO - Não foi possível criar o arquivo.\n");
            } else if (erro == SEM_CONTATO) {
                printf("ERRO - Não existem contatos salvos.\n");
            } else if (erro == ABRIR) {
                printf("ERRO - Não foi possível abrir o arquivo.\n");
            } else if (erro == FECHAR) {
                printf("ERRO - Não foi possível fechar o arquivo.\n");
            } else if (erro == ESCREVER) {
                printf("ERRO - Não foi possível escrever em seu arquivo.\n");
            } else if (erro == LER) {
                printf("ERRO - Não foi possível ler o seu arquivo.\n");
            } 
        }


        else if(opcao == -1){
            funcoes[3](contatos, &pos); // Salva o Arquivo Binário Antes de Encerrar
            printf("| > Sair...\n");
        }
        else{
            printf("| > Opcao inválida, Tente Novamente...\n");
        }
            
    } while(opcao != -1);

}