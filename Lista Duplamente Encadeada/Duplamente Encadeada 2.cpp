#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCELULA{
	int info;
	struct sCELULA* esq;
	struct sCELULA* dir;
}CELULA;

void init(CELULA** lista){
	*lista = NULL;
}

CELULA* getnode(){
	return (CELULA*) malloc(sizeof(CELULA));
}

void freenode(CELULA* q){
	free(q);
}

int empty(CELULA* lista){
	if(lista == NULL){
		return 1;
	}
	return 0;
}

void exibe_lista(CELULA* lista){
	CELULA* aux;
	
	aux = lista;
	while(aux != NULL){
		printf("%d  ", aux->info);
		aux = aux->dir;
	}
	printf("\n");
}

CELULA* pesquisa(CELULA* lista, int x){
	CELULA* q;
	
	if(!empty(lista)){
		q = lista;
		while(q != NULL){
			if(q->info == x){
				return q;
			}
			q = q->dir;
		}
	}
	return NULL;
}

void insere_inicio(CELULA** lista, int x){
	CELULA* q;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->esq = NULL;
		q->dir = *lista;
		
		if(!empty(*lista)){
			(*lista)->esq = q;
		}
		*lista = q;
	}else{
		printf("Erro: falha na alocacao da memoria");
	}
}

void insere_fim(CELULA** lista, int x){
	CELULA* q;
	CELULA* aux;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->esq = NULL;
		q->dir = NULL;
		if(empty(*lista)){
			*lista = q;
		}else{
			aux = *lista;
			while(aux->dir != NULL){
				aux = aux->dir;
			}
			aux->dir = q;
			q->esq = aux;
		}
	}else{
		printf("Erro: falha na alocacao da memoria");
	}
}

void remove_inicio(CELULA** lista){
	CELULA* q;
	
	q = *lista;
	
	if(!empty(*lista)){
	 	*lista = q->dir;
	 	if((*lista) != NULL){
	 		(*lista)->esq = NULL;
		 }
		 freenode(q);
	}else{
		printf("Erro: lista vazia");
	}
}

void remove_valor(CELULA** lista, int x){
	CELULA* q;
	
	if((q = pesquisa(*lista, x))!= NULL){
		if(*lista == q){
			remove_inicio(lista);
		}else{
			(q->esq)->dir = q->dir;
			if(q->dir != NULL){
				(q->dir)->esq = q->esq;
			}
			freenode(q);
		}
	}
}

int main(){
	CELULA *ptrlista;
	
	init(&ptrlista);
	
	insere_inicio(&ptrlista, 5);
	insere_fim(&ptrlista, 8);
	exibe_lista(ptrlista);
	remove_inicio(&ptrlista);
	exibe_lista(ptrlista);
	insere_inicio(&ptrlista, 7);
	exibe_lista(ptrlista);
	remove_valor(&ptrlista, 8);
	exibe_lista(ptrlista);
}
