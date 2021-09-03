#include<stdio.h>


void draw_board(int grid[3][3]);
char get_char(int input);

int main() {

	// 0 stands for default, 1 stands for O, 2 stands for X
	int grid[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = 0;
		}
	}
	while(1) {
		draw_board(grid);
		getchar();
//		get_input(grid);
//		make_a_move(grid);
	}
	return 0;
}

char **get_input(char *input) {
    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
            perror("malloc failed");
            exit(1);
    }
    char *separator = " ";
    char *parsed;
    int index = 0;

    parsed = strtok(input, separator);
    while (parsed != NULL) {
        command[index] = parsed;
        index++;

        parsed = strtok(NULL, separator);
    }

    command[index] = NULL;
    return command;
}

char* read_line(void) {
        int bufsize = 2;
        int pos = 0;
        char* buffer = malloc(sizeof(char) * bufsize);
        int c;

        if (!buffer) {
                printf("error!");
                exit(EXIT_FAILURE);
        }

        while (1) {
                c = getchar();

                if (c == EOF || c == '\n') {
                        buffer[pos] = '\0';
                        return buffer;
                } else {
                        buffer[pos] = c;
                }
                pos++;

                // if buffer is overflowing, reallocate
                if (pos >= bufsize) {
                        bufsize += SHELL_BUFF_SIZE;
                        buffer = realloc(buffer, bufsize);
                        if (!buffer) {
                                fprintf(stderr, "cshell: allocation error\n");
                                exit(EXIT_FAILURE);
                        }
                }
        }
}


void draw_board(int grid[3][3]) {
	for (int i = 0; i < 3; i++) {
		char charay[3];
	       for (int j = 0; j < 3; j++) {
			charay[j] = get_char(grid[i][j]);
	       }		 		
		printf("| %c | %c | %c |\n", charay[0], charay[1], charay[2]);
	}
}

char get_char(int input) {
	switch(input) {
		case 0:
			return '_';
			break;
		case 1:
			return 'O';
			break;
		case 2:
			return 'X';
			break;
	}
}
