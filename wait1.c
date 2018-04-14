// Exemplo de uso de fork e wait
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	pid_t pid;
	printf("Processo pai. PID do avô = %d\n", getpid());

	if((pid = fork()) != 0){
		printf("Processo pai. PID do filho = %d\n", pid);
		wait(NULL);
		printf("Meu filho morreu...:-(\n");
	}

	else{
		sleep(2); // Filho demora um pouco para executar
		printf("Processo filho. PID = %d\n", getpid());
	}
	return 0;
}
