#include <stdio.h>

#define MAX 100  //constante de tamanho maximo da lista

typedef struct 
{
	char nome[30];
    int idade;
}CLIENTE;

typedef struct 
{
	CLIENTE vetor[MAX];
	int nElem;
}LISTA;

void criarLista (LISTA * lista)
{
	lista->nElem = 0;
}

void inserirFinal(LISTA * lista, CLIENTE cl)
{
	lista->vetor[lista->nElem] = cl;
	lista->nElem++;
}

void inserirPosicao(LISTA * lista, int pos, CLIENTE cl)
{
	int i;
	if (pos >= lista->nElem)
	{
		inserirFinal(lista, cl);
	}
	else
	{
		for (i = lista->nElem; i > pos; i--)
		{
			lista->vetor[i] = lista->vetor[i - 1];
		}
		lista->vetor[pos] = cl; //insercao
		lista->nElem++;
	}
}

void inserirInicio (LISTA * lista, CLIENTE cl)
{
	inserirPosicao(lista, 0, cl);
}

CLIENTE * acessarAPartirInicio(LISTA * lista, int pos) //entra com ponteiro e sai com ponteiro
{
	if (pos < lista->nElem )
	{
		return &lista->vetor[pos];
	}
	else
	{
		return NULL; //nao encontrou
	}	
}

CLIENTE * acessarAPartirFim(LISTA * lista, int pos)
{
	if (pos < lista->nElem )
	{
		return &lista->vetor[lista->nElem-pos-1];
	}
	else
	{
		return NULL; //nao encontrou
	}	
}

void listarInicioAoFIm(LISTA *lista)
{
	int i;
	CLIENTE cl;
	for (i = 0; i < lista->nElem; i++)
	{
		cl = lista->vetor[i];
		printf("nome: %s\n", cl.nome);
		printf("idade: %d\n\n", cl.idade);
	}
}

int menu()
{
    int saida = 0;
    
    //draw menu
    
    return saida;
}


int main ()
{
	int opcao = 0; 	
	int pos;
 	printf("Lista de dados\n");
  
  	LISTA lista;
  	CLIENTE cl;
	CLIENTE *cp;

	do
	{
		printf ("1 - Criar Lista\n");
		printf ("2 - Inserir Inicio\n");
		printf ("3 - Inserir Final\n");
		printf ("4 - Inserir em Posicao\n");
		printf ("5 - Acessar a partir Inicio\n");
		printf ("6 - Acessar a partir Fim\n");
		printf ("7 - LIsta do Inicio ao Fim\n");
		printf ("8 - LIsta do Fim ao Inicio\n");
		printf ("99 - Sair\n");

		printf("opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			{
				criarLista(&lista);
			}
			case 2:
			{
				printf("nome: ");
				scanf("%s", cl.nome);
				printf("\nidade: ");
				scanf("%d", &cl.idade);
				inserirInicio(&lista, cl);
				break;
			}
			case 3:
			{
				printf("nome: ");
				scanf("%s", cl.nome);
				printf("\nidade: ");
				scanf("%d", &cl.idade);
				inserirFinal(&lista, cl);
				break;
			}
			case 4:
			{
				printf("nome: ");
				scanf("%s", cl.nome);
				printf("\nidade: ");
				scanf("%d", &cl.idade);
				printf("\nposicao: ");
				scanf("%d", &pos);
				inserirPosicao(&lista, pos, cl);
				break;
			}
			case 5:  //acessar
			{
				printf("\nposicao: ");
				scanf("%d", &pos);
				cp = acessarAPartirInicio(&lista, pos);
				if (cp != NULL)
				{
					printf("nome: %s\n", cp->nome);
					printf("\nidade: %d\n", cp->idade);
					printf("\nposicao: ");
					inserirPosicao(&lista, pos, cl);
				}
				else
					printf("\nPosicao nao existe!\n");
				break;
			}
			case 6:  //acessar do fim
			{
				printf("\nposicao: ");
				scanf("%d", &pos);
				cp = acessarAPartirFinal(&lista, pos);
				if (cp != NULL)
				{
					 printf("nome: %s\n", cp->nome);
					 printf("\nidade: %d\n", cp->idade);
					 printf("\nposicao: ");
					 inserirPosicao(&lista, pos, cl);
				 }
				else
				{
					printf("\nPosicao nao existe!\n");
					break;
				}			
			case 99:
			{
				printf("Saindo!");
				break;
			}
			default:
			{
				printf("default!");
				break;
			}
		}

	} while (opcao != 99);

 	return 0;
}