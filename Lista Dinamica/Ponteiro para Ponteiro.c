#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sCELULA{
	char info;
	struct sCELULA *next;
}CELULA;

void init (CELULA **lista){			
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

CELULA* insere_fim (CELULA **lista, char x){		
	CELULA *q;
	CELULA *aux;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		
		if(empty(*lista)){
			*lista = q;
		}else{
			aux = *lista;
			while (aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
		}
	}else{
		printf("\n ERRO de alocacao do noh. \n");
		exit(1);
	}
}

CELULA* insere_inicio (CELULA **lista, char x){	
	CELULA *q;
	
	q = getnode();
	if(q != NULL){
		q->info = x;
		q->next = *lista;
		*lista = q;
	}else{
		printf("ERRO de alocacao do noh. \n");
		exit(1);
	}
}

CELULA* remove_inicio(CELULA **lista){		
	
	CELULA *q;
	
	q = *lista;
	if(!empty(*lista)){
		*lista = q->next;
		freenode(q);
	}else{
		printf("\nERRO lista vazia.\n");
		exit(1);
	}
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

void exibe_lista (CELULA *lista){			
	CELULA *aux;
	
	aux = lista;
	while(aux != NULL){
		printf("%c \t", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

int main(){
	CELULA *ptrlista;
	
	init(&ptrlista);									//inicia lista
	
 	insere_inicio(&ptrlista, 'a');						//insere no inicio
 	insere_fim(&ptrlista, 'b');							//insere no fim
 	insere_fim(&ptrlista, 'c');							//insere no fim
 	printf("Lista Completa:\n");
 	exibe_lista(ptrlista);								//exibe a lista
 	
 	remove_valor(&ptrlista, 'b');						//remove valor 'b'	
 	printf("Lista com valor 'b' removido:\n");
	exibe_lista(ptrlista);
	
 	remove_inicio(&ptrlista);
 	printf("Lista com inicio removido:\n");
	exibe_lista(ptrlista);
	
 	return 0;
}
