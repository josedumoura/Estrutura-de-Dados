#include <stdio.h>

int fibonacci(int x){
	if(x == 0 || x == 1){
		return x;
	}else{
		return fibonacci(x-2) + fibonacci(x-1);
	}
}

int main(){
	int a;
	
	printf("Digite um valor: ");
	scanf("%d", &a);

	printf("%d ",fibonacci(a));
	
}
