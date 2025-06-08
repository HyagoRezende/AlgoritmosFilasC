#include<stdio.h>
#include<stdlib.h>
#include"FilaEstatica.h"

//Funcao para criar fila
Fila *criaFila()
{
    Fila *novaFila = (Fila *) malloc(sizeof(Fila));

    if(novaFila)
    {
        novaFila->tamanho = 0;
        novaFila->inicio = 0;
        novaFila->fim = 0;
    }
    return novaFila;
}

//Funcao para liberar memoria da fila
void liberaFila(Fila *f)
{
    free(f);
    printf("Memoria liberada\n");
}

//Funcao para verificar tamanho da fila
int tamanhoFila(Fila *f)
{
    return f->tamanho;
}

//Funcao para verificar se a fila esta vazia
int filaVazia(Fila *f)
{
    if(f->tamanho == 0)
    {
        return 1; //Fila vazia
    }
    else
    {
        return 0; //Fila nao esta vazia
    }
}

//Funcao para verificar se a fila esta cheia
int filaCheia(Fila *f)
{
    if(f->tamanho == MAX)
    {
        return 1; //Fila cheia
    }
    else
    {
        return 0; //Fila nao esta cheia
    }
}

//Funcao para imprimir fila
void imprimeFila(Fila *f)
{
    if(f->tamanho == 0)
    {
        printf("Fila vazia\n");
    }
    else
    {
        for(int i = f->inicio; i < f->fim; i++)
        {
            printf("------------------------------------------\n");
            printf("Aluno: %s - Matricula: %d - Media = %.2f\n", f->dados[i].nome, f->dados[i].matricula, ((f->dados[i].n1+f->dados[i].n2+f->dados[i].n3)/3));
        }
    }
}

//Funcao para adicionar aluno
int addAluno(Fila *f, Aluno a)
{
    if(f->tamanho == MAX)
    {
        return 0; //Fila cheia
    }
    else
    {
        f->dados[f->fim] = a;
        f->fim = (f->fim + 1) % MAX; //aspecto circular
        f->tamanho++;
        return 1; //aluno adicionado
    }
}

//Funcao para remover aluno
Aluno removeAluno(Fila *f)
{
    if(f->tamanho == 0)
    {
        Aluno vazio = {0, "", 0, 0, 0};
        return vazio;
    }
    else
    {
        Aluno aluno = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX; //aspecto circular
        f->tamanho--;
        return aluno;
    }
}

int main()
{
    Fila *filaAlunos;
    Aluno x = {1234, "Hyago", 8, 7, 9};
    filaAlunos = criaFila();
    addAluno(filaAlunos, x);

    Aluno y = {1256, "Isadora", 5, 4, 7};
    addAluno(filaAlunos, y);
    Aluno z = {12, "Isis", 10, 7, 9};
    addAluno(filaAlunos, z);
    Aluno s = {56, "Fabiana", 9, 7, 9};
    addAluno(filaAlunos, s);
    Aluno k = {1, "Hyasmin", 5, 7, 9};
    addAluno(filaAlunos, k);

    imprimeFila(filaAlunos);
    printf("\n\n");

    removeAluno(filaAlunos);
    imprimeFila(filaAlunos);
}