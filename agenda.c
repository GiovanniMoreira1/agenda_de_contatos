#include <stdio.h>
#include <string.h>
#include "agenda.h"

// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Contatos ------------------------------------- |
Value criar(Contato tarefas[], int *pos){
    printf("Criar Contato...");
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