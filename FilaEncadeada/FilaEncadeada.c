#include<stdio.h>
#include<stdlib.h>
#include"FilaEncadeada.h"

//Funcao para criar Fila vazia
Fila *criaListaVazia()
{
    Fila *fila = (Fila *) malloc(sizeof(Fila*));

    if(fila)
    {
        fila->head = NULL;
        fila->tail = NULL;
        fila->quantidade = 0;
    }

    return fila;
}

//Funcao para liberar fila
void liberaFila(Fila *fila)
{
    if(fila != NULL)
    {
        while(fila->head != NULL)
        {
            No *remover = fila->head;
            fila->head = remover->proximo;
            free(remover);
        }
        free(fila);
    }
}

//Retorna tamanho da fila
int tamanhoFila(Fila *fila)
{
    if(fila == NULL)
    {
        return 0;
    }
    else
    {
        return fila->quantidade;
    }
}

//Imprimir fila
void imprimeFila(Fila *fila)
{
    if(fila == NULL)
    {
        printf("Fila Vazia\n");
    }
    else
    {
        No *aux = fila->head;

        while(aux != NULL)
        {
            printf("-----------------------------------\n");
            printf("Aluno: %s - Matricula: %d\n", aux->aluno.nome, aux->aluno.matricula);
            aux = aux->proximo;
        }
    }

}

//Inserir um elemento na fila
int addAluno(Fila *fila, Aluno aluno)
{
    No *novoNo = (No *) malloc (sizeof(No));

    if(novoNo != NULL)
    {
        novoNo->aluno = aluno;
        novoNo->proximo = NULL;

        //Se a fila for vazia
        if(fila->head == NULL)
        {
            fila->head = novoNo;
            fila->tail = novoNo;
            fila->quantidade++;
            return 1; //Sucesso na adicao
        }
        //Se a fila nao estiver vazia
        else
        {
            fila->tail->proximo = novoNo;
            fila->tail = novoNo;
            fila->quantidade++;
            return 1; //Sucesso na adicao
        }
    }
}

//Remover um elemento da fila
int removeElemento(Fila *fila)
{
    if(fila == NULL)
    {
        return -1; //Fila vazia
    }
    else
    {
        No *remover = fila->head;
        fila->head = fila->head->proximo;

        //Se a cabeca receber nulo, significa que a fila ficou vazia
        if(fila->head == NULL)
        {
            fila->tail = NULL;
            fila->quantidade = 0;
            return -1; //Fila vazia
        } 
        else
        {
            fila->quantidade--;
        }

        free(remover);
    }
}

int main()
{
    Fila *filaAlunos;
    Aluno x = {1234, "Hyago", 10, 6, 8};
    Aluno y = {1, "Isadora", 10, 6, 8};
    Aluno z = {34, "Isis", 10, 6, 8};
    Aluno s = {4, "Fabiana", 10, 6, 8};
    Aluno t = {5, "Roberto", 8, 9 , 7};

    filaAlunos = criaListaVazia();

    addAluno(filaAlunos, x);
    addAluno(filaAlunos, y);
    addAluno(filaAlunos, z);
    addAluno(filaAlunos, s);

    imprimeFila(filaAlunos);
    printf("\n\n");
    addAluno(filaAlunos, t);
    removeElemento(filaAlunos);
    imprimeFila(filaAlunos);
    printf("\n\n");
    removeElemento(filaAlunos);
    imprimeFila(filaAlunos);
    return 0;
}