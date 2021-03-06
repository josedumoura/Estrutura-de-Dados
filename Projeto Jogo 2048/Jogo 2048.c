#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sPrioridade {													//struct com informa��es da fila com prioridade
    char cpf[11];
    char nome[100];
    struct sPrioridade *proxP;
}Pri;

typedef struct sFilap {														//Fila com prioridade
    Pri* fim;
    Pri* inicio;
}Filap;

typedef struct sNormal {    													//Struct com informa��es da fila normal
    char cpfn[11];
    char nomen[100];
    struct sNormal *proxN;
}Normal;

typedef struct sFilan {														//Fila normal
    Normal* fimN;
    Normal* inicioN;
}FilaN;

typedef struct sComp {
    char nomec[100];													//Fila de todas as pessoas que foram e estao na fila
    struct sComp *next;
}Comp;

typedef struct sCompleta {
    Comp* inicioc;
    Comp* fimc;
}Completa;

void iniciaComp(Completa* C) {
    C->fimc = NULL;
    C->inicioc = NULL;
}

int vaziaComp(Completa* CP) {
    if (CP->inicioc == NULL) {
        return 1;
    }
    return 0;
}

Comp* getnode3() {						
    return (Comp*)malloc(sizeof(Comp));
}

void freenode3(Comp *q) {
    free(q);
}

Comp* PessoasAtendidasRec(Completa* CP) {
    Comp* aux = getnode3();												//Mostra a lista de pessoas que foram atendidas e que est�o na lista de forma recursiva
    if (aux == NULL) {
        printf("\t\t\tErro na listagem!!\n");
        return 0;
    }
    if ((CP->inicioc) == NULL) {
        return 0;
    } else {
        printf("->\t\t %s \n", (CP->inicioc)->nomec);
        aux = (CP->inicioc)->next;
        freenode3(CP->inicioc);
        CP->inicioc = aux;
        return PessoasAtendidasRec(CP);
    }
}

Pri* getnode() {
    return (Pri*) malloc(sizeof(Pri));
}

Normal* getnode1() {
    return (Normal*) malloc(sizeof(Normal));
}

void freenode(Pri *q) {
    free(q);
}

void freenode1(Normal *q) {
    free(q);
}

void iniciaPri(Filap *FP) {													//Inicia fila com prioridade
    FP->fim = NULL;
    FP->inicio = NULL;
}

void iniciaNor(FilaN* FN) {													//Inicia fila normal
    FN->fimN = NULL;
    FN->inicioN = NULL;
}

int vaziaPri(Filap* FP) {      												//Verifica se a fila comprioridade esta vazia
    if (FP->inicio == NULL) {
        return 1;
    }
    return 0;
}

int vaziaNor(FilaN* FN) {													//Verifica se a fila normal esta vazia
    if (FN->inicioN == NULL) {
        return 1;
    }
    return 0;
}

int verificaCPF(char cpf2[11]) {
	int i;
    for (i =0; i<11; i++) { 
	    if (cpf2[i] < 48 || cpf2[i] > 57) {
            return 1;
        }
    }
    return 0;
}

void entrarNaFila(int escolha, Filap* FP, FilaN* FN, Completa* CP) {						//Entra na fila
    char nome2[20];
    char cpf2[11];
   
    Comp* ajuda = getnode3();
    
    if (escolha == 1) {														//escolhe 1 para a fila prioritaria, e 2 para entrar na fila normal
        Pri* aux;
        aux = getnode();
		
        if (aux != NULL) {
            printf("\n------------------------------------\n");
            int i;
            
            do{														
                printf("\n -Digite seu cpf: \n");
                fflush(stdin);
                gets(cpf2);
            }while(verificaCPF(cpf2));
				
            strcpy((aux->cpf), cpf2);
			printf("\n -Digite seu nome completo: \n");
            fflush(stdin);
            gets(nome2);
        	
				
            strcpy((aux->nome), nome2);	                 //copia o nome pra struct
			strcpy((ajuda->nomec), nome2);                    
			ajuda->next = NULL;									
			if(vaziaComp(CP)){
				CP->fimc = ajuda;
				CP->inicioc = ajuda;
			}else{
				(CP->fimc)->next = ajuda;
				CP->fimc = ajuda;
			}
            aux->proxP = NULL;
            if (vaziaPri(FP)) {												//Aloca na fila 
                FP->fim = aux;
                FP->inicio = aux;
            } else {															//aloca na fila
                (FP->fim)->proxP = aux;
                FP->fim = aux;
            }
            printf("\n Entrada na fila realizada com sucesso! \n");
            printf("\n--------------------------------------------------\n");
        } else {
            printf("\n\tErro ao entrar na fila!\n");						//Erro na cria��o do no
        }
    } else {																	//Entrar na fila normal
        Normal* aux2;
        aux2 = getnode1();
        if (aux2 != NULL) {
            printf("\n------------------------------------\n");
            
            do{
            printf("\n -Digite seu cpf: \n");
            fflush(stdin);
            gets(cpf2);
        	}while(verificaCPF(cpf2));
        	
            strcpy((aux2->cpfn), cpf2);
            printf("\n -Digite seu nome completo: \n");
            fflush(stdin);
            gets(nome2);
            strcpy((ajuda->nomec), nome2);                    
			ajuda->next = NULL;									
			if(vaziaComp(CP)){
				CP->fimc = ajuda;
				CP->inicioc = ajuda;
			}else{
				(CP->fimc)->next = ajuda;
				CP->fimc = ajuda;
			}
            strcpy(aux2->nomen, nome2);
            aux2->proxN = NULL;
            if (vaziaNor(FN)) {
                FN->fimN = aux2;
                FN->inicioN = aux2;
            } else {
                (FN->fimN)->proxN = aux2;
                FN->fimN = aux2;
            }
            printf("\nEntrada na fila realizada com sucesso!\n");
            printf("\n-----------------------------------------------\n");
        } else {
            printf("\n\tErro ao entrar na fila!\n");
        }
    }
}

void ChamaOProxDaFila(Filap* FP, FilaN* FN) {     							//Chama o proximo da fila
    if (vaziaPri(FP)) {					 									//Se a fila comprioridade estuver vazia ele vai pra fila normal
        if (vaziaNor(FN)) {
            printf("\n Nao ha mais pessoas na fila!\n");					//Exibe essa mensagem caso nao tenha mais pessoas na fila
            printf("\n------------------------------------\n");
        } else {																//Caso tenha pessoa na fila normal ele chama e da free
            Normal* q1;
            printf("Nome:\t %s \n", (FN->inicioN)->nomen);
            printf("Cpf:\t %s \n", (FN->inicioN)->cpfn);
            q1 = (FN->inicioN)->proxN;
            freenode1(FN->inicioN);
            FN->inicioN = q1;
            if (FN->inicioN == NULL) {
                FN->fimN == NULL;
            }
            printf("\n------------------------------------\n");
        }	
    } else {																	//Se tiver alguem na fila priorit�ria, essa pessoa � prioridade, a fila normal s� � executada caso a fila prioritaria esteja vazia 
        Pri* q;
        printf("Nome:\t %s \n", (FP->inicio)->nome);
        printf("Cpf:\t %s \n", (FP->inicio)->cpf);
        q = (FP->inicio)->proxP;
        freenode(FP->inicio);
        FP->inicio = q;
        if (FP->inicio == NULL) {
            FP->fim == NULL;
        }
        printf("\n------------------------------------\n");
    }
}

void verPosicao(Filap* FP, FilaN* FN) {  									//Mostra todas as pessoas na fila e sua posi��o 
    int cont = 1;
    Pri* aux;
    aux = getnode();
    aux = (FP->inicio);
	
    if (aux != NULL) {
        while ((FP->inicio) != NULL) {
            printf("%d ->\t %s\n", cont, (FP->inicio)->nome);
            cont++;
            (FP->inicio) = (FP->inicio)->proxP;
        }
        (FP->inicio) = aux;           										 //Volta o ponteiro inicial pro inicio
    }
	
    Normal* aux2 = getnode1();
    if (aux2 != NULL) {
        aux2 = (FN->inicioN);
        while ((FN->inicioN) != NULL) {
            printf("%d ->\t %s\n", cont, (FN->inicioN)->nomen);
            cont++;
            (FN->inicioN) = (FN->inicioN)->proxN;
        }
        FN->inicioN = aux2;	
    }
    printf("\n------------------------------------\n");
}

void quantidadeDePessoas(Filap* FP, FilaN* FN) { 							// Ve a quantidade de pessoas na fila
    int contador = 0;
    Pri* aux = getnode();
    if (aux != NULL) {
        aux = (FP->inicio);
        while ((FP->inicio) != NULL) {
            contador++;
            (FP->inicio) = (FP->inicio)->proxP;
        }
    }
	
    FP->inicio = aux;                  										//Volta o ponteiro inicial pro inicio
    Normal* aux2 = getnode1();
    if (aux2 != NULL) {
        aux2 = (FN->inicioN);
        while ((FN->inicioN) != NULL) {
            contador++;
            (FN->inicioN) = (FN->inicioN)->proxN;
        }		
    }
    FN->inicioN = aux2;	
    printf("\n\tQuantidade de pessoas na fila: %d \n", contador); 			// "Soma" a quantidade de pessoas nas duas filas
    printf("\n------------------------------------\n");
}

void telaDeEscolha() {														//Tela de escolhas
    printf("----------------------------------------------------------------------------------\n");
    printf("\t   Pressione o numero da alternativa desejada:\n");
    printf("\n");
    printf(" \t  1   ->Entrar na fila\n");
    printf(" \t  2   ->Ver posicao na fila\n");
    printf(" \t  3   ->Ver a quantidade de pessoas na fila\n");
    printf(" \t  4   ->Chamar o proximo da fila\n");
    printf(" \t  5   ->Listar todas as pessoas atendidas e as que estao na fila \n");
    printf(" \t  0   ->Sair do programa\n");
    printf("----------------------------------------------------------------------------------\n");	
}


int main() {
    Filap FP;
    FilaN FN;
    Completa CP;
    iniciaComp(&CP);
    iniciaPri(&FP);
    iniciaNor(&FN);
    int escolha = 1, alternativa = 3, rec=0;
	
    while (escolha != 0) {
        telaDeEscolha();
        scanf("%d", &escolha);												// pega a op��o selecionada
        if (escolha == 1) {      												//entrar na fila
            printf("\t--------------------------------------------------------\n");
            printf("\t Voce tem algum tipo de necessidade especial? \n");
            printf("\t 1 -> Sim \n");
            printf("\t 2 -> Nao \n");
            printf("\t--------------------------------------------------------\n");
            while (alternativa != 1 && alternativa != 2) {
                scanf("%d", &alternativa);
                printf("\n\t\tOpcao incorreta!\n");
            }
            system("cls");
            entrarNaFila(alternativa, &FP, &FN, &CP);
            alternativa = 3;
        } else if (escolha == 2) {												//ver posi��o na fila
            system("cls");
            verPosicao(&FP, &FN);
        } else if (escolha == 3) {												//ver quantidade de pessoas na fila
            system("cls");
            quantidadeDePessoas(&FP, &FN);
        } else if (escolha == 4) { 											//chamar o proximo da fila
            system("cls");
            ChamaOProxDaFila(&FP, &FN);
        }else if (escolha == 5) {
        	printf("-> A listagem ira mostrar todas as pessoas atendidas e as que estao na fila, apos sair dela\n");
        	printf("   todas as informacoes serao excluidas e a lista(apenas a lista de informacoes) comecara do zero!!\n");
        	printf("   (A lista(Fila) de pessoas da fila continuara com seu andamento normal, ela nao sera afetada!)\n");
        	printf("        ->Aperte 1 para aceitar:     ");
        	scanf("%d", &rec);
        	system("cls");
        	if (rec == 1) {
        		PessoasAtendidasRec(&CP);
			}
		} else if (escolha == 0) {												//encerrar
            break;
        } else {
            system("cls");
            printf("\n\t Escolha incorreta!!\n");
        }
		
    }
    return 0;
}

