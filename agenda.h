#define TOTAL 100
#define T_NOME 300
#define T_SOBRENOME 100
#define T_TELEFONE 100
#define T_EMAIL 100

typedef struct {
    int prioridade;
    char nome[T_NOME];
    char sobrenome[T_SOBRENOME];
    char email[T_EMAIL];
    char telefone[T_TELEFONE];
} Contato;

typedef enum {OK, MAX_CONTATO, SEM_CONTATO, ABRIR, FECHAR, ESCREVER, LER, CRIAR} ERRO;

typedef ERRO (*funcao)(Contato[], int*);