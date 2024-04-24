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


    printf("\033[32m| > Contato Salvo com Sucesso!!\n");
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
            printf("\033[32m| > Contato deletado com sucesso!!\n");
            (*pos)--;
            return OK;
    }
        else {
                printf("| > Este número de telefone não está em seus contatos.\n");
            }
    }

}

Value listar(Contato contatos[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATO;
    }
    for (int i = 0; i < *pos; i++) {
        printf("|===============================\n");
        printf("| > Nome: %s %s \n", contatos[i].nome, contatos[i].sobrenome);
        
        printf("| > Telefone: %s\n", contatos[i].telefone);
        
        printf("| > Email: %s \n", contatos[i].email);

        printf("|===============================\n");
    }
    return OK;
}

// -------------------------------------------------------------------------- |
// > Funções de Manipulação de Arquivo -------------------------------------- |
Value salvar(Contato contatos[], int *pos){
   FILE *arq = fopen("contatos.bin", "wb");
    if(arq == NULL)
        return ABRIR;
    
    int qtd = fwrite(contatos, TOTAL, sizeof(Contato), arq);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), arq);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(arq))
        return FECHAR;

    printf("\033[32m| > Arquivo Salvo!!\n");
    return OK;
}

Value carregar(Contato contatos[], int *pos){
    FILE *f = fopen("contatos.bin", "rb");
    if(f == NULL)
    return ABRIR;

    int qtd = fread(contatos, TOTAL, sizeof(Contato), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
       return LER;

    if(fclose(f))
        return FECHAR;

    printf("\033[32m| > Contatos carregados!!\n");
    return OK;

}

// -------------------------------------------------------------------------- |
// > Funções Complementares ------------------------------------------------- |
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void tratarRes(Value err){
    if (err == MAX_CONTATO) {
        printf("\033[31m| ERRO - Máximo de contatos atingido.\n");
    } else if (err == CRIAR) {
        printf("\033[31m| ERRO - Não foi possível criar o arquivo.\n");
    } else if (err == SEM_CONTATO) {
        printf("\033[31m| ERRO - Não existem contatos salvos.\n");
    } else if (err == ABRIR) {
        printf("\033[31m| ERRO - Não foi possível abrir o arquivo.\n");
    } else if (err == FECHAR) {
        printf("\033[31m| ERRO - Não foi possível fechar o arquivo.\n");
    } else if (err == ESCREVER) {
        printf("\033[31m| ERRO - Não foi possível escrever em seu arquivo.\n");
    } else if (err == LER) {
        printf("\033[31m| ERRO - Não foi possível ler o seu arquivo.\n");
    } else if (err == OK) {
        // Fazer nada em caso de sucesso 
    } 
    else{
        printf("\033[31m| ERRO - Erro de Sistema Desconhecido.\n");
    }
    
}

// -------------------------------------------------------------------------- |