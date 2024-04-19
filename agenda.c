#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "agenda.h"

// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Contatos ------------------------------------- |
Value criar(Contato contatos[], int *pos){
    if( *pos >= TOTAL)
        return MAX_CONTATO;
    

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

        if(numCorrect){ // Se passou nas validações anteriores faz a formatação do número
            formatNumber(num);
        }
        else{
            printf("| > Telefone Inválido, tente novamente...\n");
            num[0] = '\0';
        }
    }while(!numCorrect);

    strcpy(contatos[*pos].telefone, num);
    // printf("\n| > %s", contatos[*pos].telefone);


    printf("| > Email do Contato: ");
    fgets(contatos[*pos].email, T_EMAIL, stdin);

    *pos == *pos + 1;

    printf("| > Contato Salvo com Sucesso!!");
    return OK;
}
Value deletar(Contato tarefas[], int *pos){
    printf("Deletar Contato...");
}
Value listar(Contato tarefas[], int *pos){
    printf("Listar Contato...");
}    
// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Arquivo -------------------------------------- |
Value salvar(Contato tarefas[], int *pos){
    printf("Salvar Arquivo de Contatos...");
}
Value carregar(Contato tarefas[], int *pos){
    printf("Carregar Arquivo de Contatos...");
} 
// -------------------------------------------------------------------------- |
// > Funções Complementares ------------------------------------------------- |
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void formatNumber(char telefone[]) {

    // Verifica o tamanho do número de telefone
    int tamanho = strlen(telefone);
    if (tamanho == 10) {
        // Formata como telefone: 11 1234-1234
        sprintf(telefone, "%c%c %c%c%c%c-%c%c%c%c",
            telefone[0], telefone[1],
            telefone[2], telefone[3], telefone[4], telefone[5],
            telefone[6], telefone[7], telefone[8], telefone[9]);
    } else if (tamanho == 11) {
        // Formata como celular: 11 91234-1234
        sprintf(telefone, "%c%c %c%c%c%c%c-%c%c%c%c",
            telefone[0], telefone[1],
            telefone[2], telefone[3], telefone[4], telefone[5], telefone[6],
            telefone[7], telefone[8], telefone[9], telefone[10]);
    }
}

// -------------------------------------------------------------------------- |