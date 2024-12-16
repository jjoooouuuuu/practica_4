#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
        if (argc < 3) {
                perror("Error, no has introduit dos arxius\n");
                exit(EXIT_FAILURE);
        }

        int fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1) {
        	perror("Error en obrir el primer arxiu");
        	exit(EXIT_FAILURE);
    	}

    	int fd2 = open(argv[2], O_RDONLY);
    	if (fd2 == -1) {
        	perror("Error en obrir el segon arxiu");
        	close(fd1);
        	exit(EXIT_FAILURE);
    	}

    	char buf1, buf2;
    	ssize_t bytes_read1, bytes_read2;
    	size_t byte_pos = 1;
    	size_t line_num = 1;

    	while (1) {
        	bytes_read1 = read(fd1, &buf1, 1);
        	bytes_read2 = read(fd2, &buf2, 1);

	        if (bytes_read1 == 0 && bytes_read2 == 0) {
            		close(fd1);
            		close(fd2);
            		return 0;
        	}

        	if (bytes_read1 == -1 || bytes_read2 == -1) {
            		perror("Error en llegir");
            		close(fd1);
            		close(fd2);
            		exit(EXIT_FAILURE);
        	}

		if (bytes_read1 != bytes_read2 || buf1 != buf2) {
            		printf("Diferència trobada al byte %zu, línia %zu\n", byte_pos, line_num);
            		close(fd1);
            		close(fd2);
            		exit(EXIT_SUCCESS);
        	}

        	if (buf1 == '\n') {
            		line_num++;
        	}

        	byte_pos++;
    	}

    	close(fd1);
    	close(fd2);
    	return 0;
}
