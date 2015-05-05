#include <stdio.h>

#define MAX 100  //constante de tamanho maximo da lista

typedef struct 
{
	char nome[30]
    int idade;
}ALUNO;

typedef struct 
{
	ALUNO vetor[MAX];
	int nElem;
}LISTA;

void criarLista (LISTA * lista)
{
	lista->nElem = 0;
}

void inserirFinal (LISTA * lista, CLIENTE cl)
{
	lista->vetor[lista->nElem] = cl;
	lista->nElem ++;
}

int menu()
{
    int saida = 0;
    
    //draw menu
    
    return saida;
}


int main ()
{
 	printf("Lista de dados\n");
  
  LISTA lista;
  criarLista (&lista);

 	return 0;
}