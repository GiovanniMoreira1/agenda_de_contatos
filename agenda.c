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
    contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = '\0';

    printf("| > Sobrenome do Contato: ");
    fgets(contatos[*pos].sobrenome, T_SOBRENOME, stdin);
    contatos[*pos].sobrenome[strcspn(contatos[*pos].sobrenome, "\n")] = '\0';

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
    contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = '\0';

    *pos = *pos + 1;


    printf("| > Contato Salvo com Sucesso!!");
    return OK;
}
Value deletar(Contato contatos[], int *pos){
    char tel_deletar[T_TELEFONE];
    printf("| > Número de telefone do contato a ser deletado: ");
    fgets(tel_deletar, T_TELEFONE, stdin);

    tel_deletar[strcspn(tel_deletar, "\n")] = '\0';
    printf("%s", tel_deletar);

     for (int i = 0; i < *pos; i++) {
        int comparacao = strcmp(tel_deletar, contatos[i].telefone);
        if (comparacao == 0) {
            for(int j = i; j < *pos - 1; j++){
                strcpy(contatos[j].nome, contatos[j+1].nome);
                strcpy(contatos[j].sobrenome, contatos[j+1].sobrenome);
                strcpy(contatos[j].telefone,  contatos[j+1].telefone);
                strcpy(contatos[j].email,  contatos[j+1].email);
            }
            printf("\nContato deletado com sucesso!\n");
            (*pos)--;
            return OK;
    }
        else {
                printf("\nEste número de telefone não está em seus contatos.\n");
            }
    }

}

Value listar(Contato contatos[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATO;
    }
    for (int i = 0; i < *pos; i++) {
        printf("=================================\n");
        printf("| > Nome: %s %s \n", contatos[i].nome, contatos[i].sobrenome);
        
        printf("| > Telefone: %s\n", contatos[i].telefone);
        
        printf("| > Email: %s \n", contatos[i].email);

        printf("=================================\n");
    }
    return OK;
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