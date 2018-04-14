// Exemplo de hierarquia de processos
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	if(fork()){
		//printf("------------\n");
		if(fork())
			printf("Processo A\n");
		else
			printf("Processo C\n");
		printf("------------\n");
	}else{
		printf("Processo B\n");
	}
	return 0;
}
