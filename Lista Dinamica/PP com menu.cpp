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
		printf("%c ", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

int main(){
	CELULA *ptrlista;
	int k=0;
	int l;
	
	init(&ptrlista);
	
	do{																				//MENU
		printf("Digite 1 para inserir no inicio\n");
		
		printf("Digite 2 para inserir no final\n");
		
		printf("Digite 3 para remover o inicio\n");
		
		printf("Digite 4 para remover um valor\n");
		
		printf("Digite 5 para exibir a lista\n");
	
		printf("Digite 0 para finalizar\n");
		scanf("%d", &k);
		
		if(k == 1){
			printf("Digite um inteiro");
			fflush(stdin);
			scanf("%c", &l);
			insere_inicio(&ptrlista, l);	
		}else if(k == 2){
			printf("Digite um inteiro");
			fflush(stdin);
			scanf("%c", &l);
			insere_fim(&ptrlista, l);
		}else if(k == 3){
			remove_inicio(&ptrlista);
		}else if(k == 4){
			printf("Digite um inteiro para remover");
			fflush(stdin);
			scanf("%c", &l);
			remove_valor(&ptrlista, l);
		}else if(k == 5){
			exibe_lista(ptrlista);
		}
				
	}while(k != 0);
	
	
 	return 0;
}
