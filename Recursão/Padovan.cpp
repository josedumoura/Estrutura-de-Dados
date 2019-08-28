#include <stdio.h>

int padovan(int x){
	if(x == 0 || x == 1 || x == 2){
		return 1;
	}else{
		return padovan(x-2) + padovan(x-3);
	}
}

int main(){
	int a;
	
	printf("Digite um valor: ");
	scanf("%d", &a);

	printf("%d ",padovan(a));
	
}
