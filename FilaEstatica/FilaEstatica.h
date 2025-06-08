#define MAX 100

//Definindo meu tipo de dado a ser manipulado na fila
typedef struct Aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

//Definindo a minha fila
typedef struct Fila
{
    int inicio, fim, tamanho;
    Aluno dados[MAX];
}Fila;

//Funcao para criar fila
Fila *criaFila();

//Funcao para liberar memoria da fila
void liberaFila(Fila *f);

//Funcao para verificar tamanho da fila
int tamanhoFila(Fila *f);

//Funcao para verificar se a fila esta vazia
int filaVazia(Fila *f);

//Funcao para verificar se a fila esta cheia
int filaCheia(Fila *f);

//Funcao para imprimir fila
void imprimeFila(Fila *f);

//Funcao para adicionar aluno
int addAluno(Fila *f, Aluno a);

//Funcao para remover aluno
Aluno removeAluno(Fila *f);