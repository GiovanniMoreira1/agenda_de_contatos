#include <stdio.h>
#include "agenda.h"

int main(){
    func funcoes[] = {criar, deletar, atualizar, listar}; // Lista de Funções

    Contato pessoal[TOTAL];
    Contato business[TOTAL];
    int pos_p = 0;
    int pos_b = 0;

    Value load = carregar(pessoal, &pos_p, business, &pos_b); // Carrega o arquivo contatos.bin caso ele já exista
    tratarRes(load); // Tratamento do Erro recebido da função;

    int opcao;
    do{
        printf("\n\033[34m|==============================|\n");
        printf("|- - - Agenda de Contatos - - -|\n");
        printf("| 1 - Criar Contato            |\n");
        printf("| 2 - Deletar Contato          |\n");
        printf("| 3 - Atualizar Contato        |\n");
        printf("| 4 - Listar Contatos          |\n");
        printf("| 5 - Salvar Contatos          |\n");
        printf("| 6 - Carregar Contatos        |\n");
        printf("| 0 - Sair                     |\n");
        printf("|==============================|\n");
        printf("| > Escolha uma opcao: ");
        scanf("%d", &opcao);
        clearBuffer();


        opcao--;
        if(opcao <= 5 && opcao >= 0 ){ // Condição para quando o usuário utilizar uma função
            char opc;
            printf("| > Qual agenda será feita esta ação (p/b): ");
            scanf("%c", &opc);
            clearBuffer();
            if (opc == 'p') {
                Value erro = funcoes[opcao](pessoal, &pos_p); // Chama a Função Respectiva a opção escolhida
                tratarRes(erro); // Tratamento do Erro recebido da função;  
            }  
            else if (opc == 'b') {
                Value erro = funcoes[opcao](business, &pos_b); // Chama a Função Respectiva a opção escolhida
                tratarRes(erro); // Tratamento do Erro recebido da função;
            }
            else {
                printf("| > Opção inválida, tente novamente!");
            }
            printf("\033[34m| Pressione Enter para continuar |\n");
            printf("| ============================== |\n");
            clearBuffer();
        }
        else if(opcao == -1){ // Condição para o usuário sair
            
            printf("| > Deseja Salvar Alterações? (y/n). "); // Pergunta se o usuário deseja salvar o arquivo antes de encerrar
            char Opc;
            scanf("%c", &Opc);
            clearBuffer();

            if(Opc == 'y'){ // Caso Queira Salvar as Alterações
                Value res = salvar(pessoal, &pos_p, business, &pos_b); // Salva o Arquivo Binário Antes de Encerrar
                tratarRes(res); // Tratamento do valor recebido da função;
                if(res == OK){ // Salvar funcionou corretamente, encerrando normalmente
                    printf("\033[34m| > Encerrando...\n");
                }
                else{ // Função Salvar apresentou algum erro, pergunta ao usuário se deseja sair assim mesmo ou se deseja voltar para o menu
                    do{ 
                        printf("\033[34m| > Encerrar assim mesmo? o arquivo não foi salvo (y/n). ");
                        scanf("%c", &Opc);
                        clearBuffer();
                        if(Opc == 'n'){ // Cancela o encerramento, Retorna para o menu.
                            printf("| > Retornando para menu...\n");
                            opcao = 1;
                        }
                        else if(Opc == 'y'){ // Encerra o programa sem salvar mesmo.
                            printf("| > Encerrando...\n");
                        }
                        else{
                            printf("| > Opção Inválida, tente novamente...");
                        }
                    }while(Opc != 'n' && Opc != 'y' ); // Repete o processo se o usuário digitar uma opção inválida
                }
            }
            else if(Opc == 'n'){ // Apenas encerra o programa sem salvar alterações
                    printf("| > Encerrando...\n");
            }
            else{ // Retorna para o menu se o usuário digitar uma opção inválida
                printf("| > Opção inválida, Retornando para menu...\n");
                opcao = 1;
            }
        }
        else{ // Condição caso o usuário escolha uma opção inválida
            printf("| > Opcao inválida, Tente Novamente...\n");
        }
            
    } while(opcao != -1);
}