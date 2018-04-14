// Quantos Processos Serão Criados?
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	fork();
	fork();
	fork();
	
	printf("PID = %d\n", getpid());
	return 1;
}
