#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sCELULA{
	int info;
	struct sCELULA* next;
}CELULA;

void init(CELULA **lista){
	*lista = NULL;
}

CELULA* getnode(){
	return (CELULA*) malloc (sizeof(CELULA));
}

void freenode(CELULA* q){
	free(q);
}

int empty(CELULA *lista){
	if(lista == NULL){
		return 1;
	}
	return 0;
}

CELULA* insere_fim(CELULA** lista, int x){
	CELULA* q;
	CELULA* aux;
	
	q = getnode();
	
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		
		if(empty(*lista)){
			*lista = q;
		}else{
			aux = *lista;		
			while(aux->next != NULL){
				aux = aux->next;
			}	
			aux->next = q;
		}
	}else{
		printf("\n Nao criou o noh \n");
	}
}

CELULA* insere_inicio(CELULA** lista, int x){
	CELULA *q;
	
	q = getnode();
	
	if(q != NULL){
		q->info = x;
		q->next = *lista;
		*lista = q;
		
	}else{
		printf("\n Nao criou o noh \n");
	}
}

CELULA* remove_inicio(CELULA** lista){
	CELULA* q;
	
	q = *lista;
	
	if(!empty(*lista)){
		*lista = q->next;
		freenode(q);
	}else{
		printf("\n A lista estava vazia \n");
	}
}

CELULA* pesquisa(CELULA* lista, int x){
	CELULA *q;
	CELULA* aux;
	
	q->info = x;
	lista = aux;
	if(!empty(lista)){
		while(q != NULL){
			if(q->info == x){
				return q;
			}
			q = q->next;
		}
	}
	return NULL;
}

CELULA* remove_valor(CELULA** lista, int x){
	CELULA* q;
	CELULA* aux;
	
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

void exibe_lista(CELULA *lista){
	CELULA* aux;
	
	aux = lista;
	while(aux != NULL){
		printf("%d \t", aux->info);
		aux = aux->next;
	}
	printf("\n");
}

int main (){
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
			printf("Digite um inteiro: ");
			scanf("%d", &l);
			insere_inicio(&ptrlista, l);	
		}else if(k == 2){
			printf("Digite um inteiro: ");
			scanf("%d", &l);
			insere_fim(&ptrlista, l);
		}else if(k == 3){
			remove_inicio(&ptrlista);
		}else if(k == 4){
			printf("Digite um inteiro para remover: ");
			scanf("%d", &l);
			remove_valor(&ptrlista, l);
		}else if(k == 5){
			exibe_lista(ptrlista);
		}
				
	}while(k != 0);

	
	return 0;
	
}













