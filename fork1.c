#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	pid_t r_fork;
	printf("Processo pai. PID do avô = %d\n", getppid());
	printf("Processo pai. PID = %d\n", getpid());

	if((r_fork = fork()) != 0)
		printf("Processo pai. PID do filho = %d\n", r_fork);
	else{
	sleep(1);
	printf("Processo filho. PID = %d\n", getpid());
	}
	return 0;
}
