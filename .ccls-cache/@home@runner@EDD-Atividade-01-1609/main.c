#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 10


typedef struct Aluno {
    char nome[20];
    int matricula;
    float nota;
} Aluno;


typedef struct ListaAlunos {
    Aluno alunos[MAXSIZE];
    int numElem;
} ListaAlunos;


void preencheAluno(Aluno* ptrAluno, 
                   int matricula,
                   float nota,
                   char* nome){
    (*ptrAluno).matricula = matricula;
    (*ptrAluno).nota = nota;
    strcpy((*ptrAluno).nome, nome);
}

void inicializaLista(ListaAlunos* listaAlunos){
    listaAlunos->numElem = 0;
}

void exibeLista(ListaAlunos* listaAlunos){
    int index;
    printf("Exibindo lista...\n");
    for(index = 0; index < listaAlunos->numElem;index++){
        printf("Aluno %d\n", index);
        printf("Nome: %s\n", listaAlunos->alunos[index].nome);
        printf("Matricula: %d\n", listaAlunos->alunos[index].matricula);
        printf("Nota: %.1f\n", listaAlunos->alunos[index].nota);
    }
}

bool insereAlunoNaLista(ListaAlunos* listaAlunos, Aluno aluno, int posicao) {
    if (listaAlunos->numElem >= MAXSIZE || posicao < 0 || posicao > MAXSIZE) {
        printf("Insercao em posicao invalida!!!\n");
        return false;
    }

    for (int index = 0; index < listaAlunos->numElem; index++) {
        if (listaAlunos->alunos[index].matricula == aluno.matricula) {
            printf("Matricula duplicada!!!\n");
            return false;
        }
    }

    if (posicao > listaAlunos->numElem) {
        posicao = listaAlunos->numElem;
    }

    for (int index = listaAlunos->numElem; index > posicao; index--) {
        listaAlunos->alunos[index] = listaAlunos->alunos[index - 1];
    }

    listaAlunos->alunos[posicao] = aluno;
    listaAlunos->numElem++;
    return true;
}

bool excluiElementoDaLista(ListaAlunos* listaAlunos, int posicao) {
    if (posicao >= 0 && posicao < listaAlunos->numElem) {
        for (int index = posicao; index < listaAlunos->numElem - 1; index++) {
            listaAlunos->alunos[index] = listaAlunos->alunos[index + 1];
        }
        listaAlunos->numElem--;

        memset(&listaAlunos->alunos[listaAlunos->numElem], 0, sizeof(Aluno));
        return true;
    }
    printf("Exclusao em posicao invalida!!!\n");
    return false;
}

int buscaAlunoPorNome(ListaAlunos* listaAlunos, char* nome) {
    for (int index = 0; index < listaAlunos->numElem; index++) {
        if (strcmp(listaAlunos->alunos[index].nome, nome) == 0) {
            return index; 
        }
    }
    return -1; 
}

int buscaAlunoPorMatricula(ListaAlunos* listaAlunos, int matricula) {
    for (int index = 0; index < listaAlunos->numElem; index++) {
        if (listaAlunos->alunos[index].matricula == matricula) {
            return index; 
        }
    }
    return -1; 
}

Aluno* retornaAluno(ListaAlunos* listaAlunos, int posicao) {
    if (posicao >= 0 && posicao < listaAlunos->numElem) {
        return &listaAlunos->alunos[posicao];
    }
    return NULL; 
}

int main(){

    ListaAlunos listaAlunos;
    inicializaLista(&listaAlunos);

    Aluno aluno0, aluno1, aluno2;
    preencheAluno(&aluno0, 15424242, 9.5, "Joao");
    preencheAluno(&aluno1, 10101011, 10, "Ana");
    preencheAluno(&aluno2, 22222222, 7, "Bia");

    insereAlunoNaLista(&listaAlunos, aluno0, 0);
    insereAlunoNaLista(&listaAlunos, aluno1, 0);
    insereAlunoNaLista(&listaAlunos, aluno2, 1);
    
    exibeLista(&listaAlunos);
    printf("Excluindo elemento.............\n");
    excluiElementoDaLista(&listaAlunos, 1);
    exibeLista(&listaAlunos);
    printf("nao foi apagado %s\n", listaAlunos.alunos[2].nome);
    return 0;
}