// Exemplo de uso de fork e wait
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int i;
	if(fork())
		if(fork()){
			for(i = 0; i < 2; i++)
				wait(NULL); //Espera a morte de dois filhos
			printf("Processo A\n");
	}
		else
			printf("Processo C\n");
	else // Processo B
		if(fork())
			if(fork())
				if(fork()){
					for(i = 0; i < 3;i++)
						wait(NUKK); // Espera a morte de três filhos
					printf("Processo B\n");
				}
				else
					printf("Processo F\n");
			else
				printf("Processo E\n");
		else
			printf("Processo D\n");

	return 0;
}
