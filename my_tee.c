#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1){
		perror("Error obrint l'arxiu\n");
		exit(EXIT_FAILURE);
	}
}
