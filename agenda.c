#include <stdio.h>
#include <string.h>
#include "agenda.h"

// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Contatos ------------------------------------- |
Value criar(Contato contatos[], int *pos){
    if( *pos >= TOTAL)
        return MAX_CONTATO;
    
    char num[T_TELEFONE];

    printf("| > Nome do Contato: ");
    fgets(contatos[*pos].nome, T_NOME, stdin);
    
    printf("| > Sobrenome do Contato: ");
    fgets(contatos[*pos].sobrenome, T_SOBRENOME, stdin);

    printf("| > Telefone do Contato (Ex: 01234567890): ");
    fgets(contatos[*pos].telefone, T_TELEFONE, stdin);

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
// -------------------------------------------------------------------------- |