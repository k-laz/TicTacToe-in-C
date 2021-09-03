#include<stdio.h>
#include<stdlib.h>


void draw_board(void);
char *read_line(void);
int display_menu(void);
void get_user_move(void);
void get_computer_move(int player);

// 0 stands for default, 1 stands for O, 2 stands for X
int board[3][3];

int main() {
        int player = display_menu();
	while(1) {
                check_for_win(player);
                get_user_move();
                get_computer_move(player);
                draw_board();
	}
	return 0;
}

void check_for_win(int player) {
        int row, col;
        int count = 0;
       
}

int display_menu() {
    printf("Welcome to Tic Tac Toe, please choose a side: 0 for O, 1 for X\n");
    while (1) {
        char* user_input = read_line();
        if (user_input[0] == '0' || user_input[0] == '1') {
                int result = user_input[0] - '0';
                return result;
        }
        printf("Invalid input, please try again\n");
    }
}

char *read_line(void)
{
  int bufsize = 2;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

    if (!buffer) {
            printf("allocation error\n");
            exit(EXIT_FAILURE);
    }

  while (1) {
    c = getchar();

    // If we hit EOF, replace it with a null character and return.
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    // If we have exceeded the buffer, reallocate.
    if (position >= bufsize) {
      bufsize = bufsize*2;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        printf("reallocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


void draw_board(void) {
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
