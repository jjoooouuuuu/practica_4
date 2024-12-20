#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	if (argc < 2) {
        	perror("Error, no has introduit l'arxiu\n");
        	exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
	if (fd == -1){
		perror("Error obrint l'arxiu\n");
		exit(EXIT_FAILURE);
	}
	char buffer;
	ssize_t bytes_read, bytes_written;
	while ((bytes_read = read (0, &buffer, 1)) > 0){
		if (write(0, &buffer, 1) == -1 || (write(fd, &buffer, 1) == -1)){
			perror("Error en escriure\n");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
}
