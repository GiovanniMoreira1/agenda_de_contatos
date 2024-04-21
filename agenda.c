#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "agenda.h"

// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Contatos ------------------------------------- |
Value criar(Contato contatos[], int *pos){
    if( *pos >= TOTAL)
        return MAX_CONTATO;
    
    printf("Posição: %d", *pos);

    printf("| > Nome do Contato: ");
    fgets(contatos[*pos].nome, T_NOME, stdin);
    
    printf("| > Sobrenome do Contato: ");
    fgets(contatos[*pos].sobrenome, T_SOBRENOME, stdin);

    char num[T_TELEFONE];
    int numCorrect;
    do{
        numCorrect = 1;
        printf("| > Telefone do Contato (Ex: 01234567890): ");
        fgets(num, T_TELEFONE, stdin);

        num[strcspn(num, "\n")] = '\0'; // Remove o \n do final do número informado;
        if(strlen(num) > 12 || strlen(num) < 10){ // Verifica se o tamanho do número é válido
            numCorrect = 0;
        }
        if(numCorrect){
            for (int i = 0; num[i] != '\0'; i++) { // Verifica se não há nenhum char não numérico no número informado;
                if (!isdigit(num[i]) && num[i] != '\0') {
                    numCorrect = 0;
                    break;
                }
            }
        }

        else{
            printf("| > Telefone Inválido, tente novamente...\n");
            num[0] = '\0';
        }
    }while(!numCorrect);
    strcpy(contatos[*pos].telefone, num);
    //printf("| > Número: %s\n", contatos[*pos].telefone);

    printf("| > Email do Contato: ");
    fgets(contatos[*pos].email, T_EMAIL, stdin);

    *pos = *pos + 1;
    printf("Posição: %d", *pos);
    printf("| > Contato Salvo com Sucesso!!");
    return OK;
}
Value deletar(Contato contatos[], int *pos){
    printf("Deletar Contato...");
}
Value listar(Contato contatos[], int *pos){
    printf("Listar Contato...");
}    
// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Arquivo -------------------------------------- |
Value salvar(Contato contatos[], int *pos){
    printf("Salvar Arquivo de Contatos...");
}
Value carregar(Contato contatos[], int *pos){
    printf("Carregar Arquivo de Contatos...");
} 
// -------------------------------------------------------------------------- |
// > Funções Complementares ------------------------------------------------- |
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -------------------------------------------------------------------------- |