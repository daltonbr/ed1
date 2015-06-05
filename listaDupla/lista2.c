#include <stdio.h>

struct registro 
{
struct registro *ant;
int id;
struct registro *prox;	
};

typedef struct registro cell;  //renomeando o tipo

void initializeList (cell *p)
{
	p->id = 1;
}

void printList (cell *ini)
{
	cell *p;
	p = ini;
	if (!p) // p == NULL
	{
		printf("\nLista Vazia!\n");
		return;
	}
	do
	{
		printf("\nid: %d\n", p->id);
		p = p->prox;
	} while (p); // p != NULL
}

void addElement(int conteudo, cell *p)
{
	cell *new;
	new = (cell *)malloc(sizeof(cell));
	new->id = conteudo;
	new->prox = p->prox;
	new->ant = p;
	p->prox = new;
}

int main ()
{

int count = 0;
cell *first, *pointer;
first = (cell *)malloc ( sizeof (cell) ); //cast

first->ant = NULL;
first->prox = NULL;
pointer = first;

initializeList (first);

printf("\n 1 - ");
printList (first);

addElement(2, pointer);

printf("\n 2 - ");
printList(first);

for (count = 0; count < 10; count++)  // cria varios elementos para a lista
{
	pointer = pointer->prox;
	addElement(count, pointer);
}

printf("\n 3 - ");
printList(first);

return 0;	
}