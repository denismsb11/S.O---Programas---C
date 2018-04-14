#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	if(fork() == 0){
	 execve(argv[1], &argv[1],envp);
	 fprintf(stderr, "Nao conseguiu executar execve.\n");
	 return 2;
	}
	else{ // Processo pai
	 wait(NULL); 
	 printf("Filho terminou sua execusao/n");
	}
	return 0;
}
