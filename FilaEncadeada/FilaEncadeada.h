
//Tad Aluno
typedef struct Aluno
{
    int matricula;
    char nome[20];
    float n1,n2,n3;
}Aluno;

//Tad no
typedef struct No
{
    Aluno aluno;
    struct No *proximo;
}No;

//Tad fila
typedef struct Fila
{
    No *head;
    No *tail;
    int quantidade;
}Fila;

//Funcao para criar Fila vazia
Fila *criaListaVazia();

//Funcao para liberar fila
void liberaFila(Fila *fila);

//Retorna tamanho da fila
int tamanhoFila(Fila *fila);

//Imprimir fila
void imprimeFila(Fila *fila);

//Inserir um elemento na fila
int addAluno(Fila *fila, Aluno aluno);

//Remover um elemento da fila
int removeElemento(Fila *fila);
