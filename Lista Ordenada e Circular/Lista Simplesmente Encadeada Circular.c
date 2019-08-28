#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCELULA{
	int info;
	struct sCELULA *next;
}CELULA;

void init(CELULA **lista){			
	*lista = NULL;
}

CELULA* getnode(){						
	return (CELULA*) malloc (sizeof(CELULA));
}

void freenode (CELULA *q){				
	free(q);
}

int empty (CELULA *lista){				
	if (lista == NULL){
		return 1;
	}
	return 0;
}

void insere_fim(CELULA **lista, int x){
	CELULA *q;
	
	q= getnode();
	if(q != NULL){
		q->info = x;
		if(empty(*lista)){
			q->next = q;
		}else{														//insere no fim da lista
			q->next = (*lista)->next;
			(*lista)->next = q;
		}
		*lista = q;
	}else{															//Fim do if(q != NULL)
		printf("\nErro na alocação do noh. \n");
	}
}

void listar(CELULA *lista){
	CELULA *aux;
	
	if(!empty(lista)){
		aux = lista->next;
		do{
			printf("%d\t", aux->info);
			aux = aux->next;
		}while(aux != lista->next);
	}else{
		printf("\nNao ha elemento na lista");
	}
	printf("\n");
}


CELULA* pesquisa(CELULA *lista, char x){		
	CELULA* q;
	
	if(!empty(lista)){
		q = lista;
		while(q != NULL){
			if(q->info == x){
				return q;
			}
			q = q->next;
		}
	}
	return NULL;
}

void remove_inicio(CELULA **lista){
	CELULA *aux;
	
	if(!empty(*lista)){												//há itens na lista
		if((*lista) == (*lista)->next){
			freenode(*lista);
			*lista = NULL;
		}else{
			aux = (*lista)->next;
			(*lista)->next = aux->next;
			freenode(aux);
		}
	}else{
		printf("\nErro: lista vazia\n");
	}
}

CELULA* remove_valor (CELULA **lista, char x){		
	CELULA *q;
	CELULA *aux;
	
	if((q = pesquisa(*lista, x)) != NULL){
		aux = *lista;
		if(aux == q){
			remove_inicio(lista);
		}else{
			while(aux->next != q){
				aux = aux->next;
			}
			aux->next = q->next;
			freenode(q);
		}
	
	}
	
}

int main(){
	CELULA *ptrlista;
	
	init(&ptrlista);
	
	insere_fim(&ptrlista, 9);
	insere_fim(&ptrlista, 1);
	insere_fim(&ptrlista, 3);
	
	printf("Lista completa\n");
	listar(ptrlista);
	
	remove_valor(&ptrlista, 9);
	
	printf("Lista com '9' removido\n");
	listar(ptrlista);
	
	remove_inicio(&ptrlista);
	
	printf("Lista com '1' removido\n");
	listar(ptrlista);
	
	return 0;
}



