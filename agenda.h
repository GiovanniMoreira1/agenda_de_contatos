#define TOTAL 255
#define T_NOME 300
#define T_SOBRENOME 100
#define T_TELEFONE 13
#define T_EMAIL 100

typedef struct {
    char nome[T_NOME];
    char sobrenome[T_SOBRENOME];
    char email[T_EMAIL];
    char telefone[T_TELEFONE];
} Contato;

typedef enum {OK, MAX_CONTATO, SEM_CONTATO, ABRIR, FECHAR, ESCREVER, LER, CRIAR} Value;

typedef Value (*func)(Contato[], int*);

Value criar(Contato contatos[], int *pos);     // Função de Criar novo Contato
Value deletar(Contato contatos[], int *pos);   // Função de Deletar um Contato
Value listar(Contato contatos[], int *pos);    // Função de Listar os Contatos
Value salvar(Contato contatos[], int *pos);    // Função de Salvar a lista de contatos no arquivo binário
Value carregar(Contato contatos[], int *pos);  // Função de Carregar a lista de contatos do arquivo binário


void clearBuffer(); // Função de Limpeza de Buffer
void tratarRes(Value err); // Tratamento de Erros das funções de tipo Value

// \033[0m -> Cor Padrão de texto
// \033[34m -> Cor azul  - Utilizado no menu
// \033[32m -> Cor Verde - Utilizado para mensagens de sucesso de funções
// \033[31m -> Cor Vermelha - Utilizado para mensagens de erro