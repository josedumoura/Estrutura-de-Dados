#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCELULA{
	int info;
	struct sCELULA *next;
}CELULA;

CELULA* init (CELULA *lista){
	lista = NULL;
	return lista;
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

CELULA* insere_fim (CELULA *lista, int x){
	CELULA *q;
	CELULA *aux;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		
		if(empty(lista)){
			lista = q;
		}else{
			aux = lista;
			while (aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
		return lista;
	}else{
		printf("\n ERRO de alocacao do noh. \n");
		return NULL;
	}
}

CELULA* insere_inicio (CELULA *lista, int x){
	CELULA *q;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->next = lista;
		lista = q;
		return lista;
	}else{
		printf("ERRO de alocacao do noh. \n");
		return NULL;
	}
}

CELULA* remove_inicio(CELULA *lista){
	
	CELULA *q;
	
	q = lista;
	if(!empty(lista)){
		lista = q->next;
		freenode(q);
		return lista;
	}else{
		printf("\nERRO lista vazia.\n");
		return NULL;
	}
}

CELULA* pesquisa(CELULA *lista, int x){
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

CELULA* remove_valor (CELULA *lista, int x){
	CELULA *q;
	CELULA *aux;
	
	if((q = pesquisa(lista, x)) != NULL){
		aux = lista;
		if(aux == q){
			remove_inicio(lista);
		}else{
			while(aux->next != q){
				aux = aux->next;
			}
			aux->next = q->next;
			freenode(q);
		}
		return lista;
	}
	return NULL;
}

void exibe_lista (CELULA *lista){
	CELULA *aux;
	
	aux = lista;
	while(aux != NULL){
		printf("%d \t", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

int main(){
	CELULA *ptrlista;
	
 	ptrlista = init(ptrlista);
 	ptrlista = insere_inicio(ptrlista, 7);
 	ptrlista = insere_fim(ptrlista, 3);
 	ptrlista = insere_fim(ptrlista, 9);
 	printf("Lista Completa:\n");
 	exibe_lista(ptrlista);
 	
 	ptrlista = remove_valor(ptrlista, 3);
	printf("Lista com valor 3 removido:\n");
	exibe_lista(ptrlista);
	
 	ptrlista = remove_inicio(ptrlista);
 	printf("Lista com inicio removido:\n");
	exibe_lista(ptrlista);
	
 	return 0;
} 
