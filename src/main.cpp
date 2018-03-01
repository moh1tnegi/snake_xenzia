#include "snake.h"

void print_box() {
	for(int y=0; y<ROWS; y++) {
		for(int x=0; x<COLUMNS; x++) {
			std::cout << box[y][x];
		}
		std::cout << '\n';
	}
}

int main() {
	set_borders();
	int x_move 	 =	 COL_START;
	int y_move	 =	 ROW_START;
	char direction	 =	 DIR_START;  // A:up, B:dwn, C:left, D:right
	char prev_dir	 =	 DIR_START;
	int pid		 =	 fork();
	
	while(1) {
		if(pid) {  // parent process
			usleep(SLEEP);
			FILE *ff;
			ff = fopen("user_input.txt", "r");
			direction = getc(ff);
			fclose(ff);
			system("clear");
			print_box();
			if(eaten) {
				set_bait();
				eaten = 0;
			}
			int get = move_snake(x_move, y_move, direction);

			if(get==1) {
				std::cout << "Total Score: " << Q.size()-SNAKE_LENGTH;
				std::cout << "\nChl bhai nikal ab!\n";
				FILE *fff;
				fff = fopen("user_input.txt", "w");
				putc(DIR_START, fff);  // left direction at the end
				fclose(fff);
				system("kill 0");  // kill the child (oh, is that infanticide or somethin'? lol)
				break;
			}
			else if(!get) {  // move pointer back and forth
				if(direction=='C') 	{	x_move++;	}
				else if(direction=='D') {	x_move--;	}
				else if(direction=='A') {	y_move--; 	}
				else if(direction=='B') {	y_move++;	}
			}
			else {}
		}
		else { // child process
			usleep(SLEEP);
			direction = getch();
			direction = getch();
			direction = getch();
		}
		
		FILE *f;
		f = fopen("user_input.txt", "wr");
		if(prev_dir=='C' and direction=='D') 		direction='C';  // checks for opposite direction
		else if(prev_dir=='D' and direction=='C') 	direction='D';
		else if(prev_dir=='B' and direction=='A') 	direction='B';
		else if(prev_dir=='A' and direction=='B') 	direction='A';
		prev_dir = direction;  // for next operation, snake won't move opposite
		putc(direction, f);
		fclose(f);
	}
	return 0;
}
