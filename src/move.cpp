inline void swap_em_qu(int x, int y) {
	SWAP(box[Q.front().first][Q.front().second], box[y][x]);
	Q.pop();
	Q.push(std::make_pair(y, x));
}

int move_snake(int x, int y, int dir) {
	if(baits.first==y and baits.second==x) {
		box[y][x] = SNAKE_BODY;
		Q.push(std::make_pair(y, x));
		eaten = 1;
		return 0;
	}
	switch(dir) {
		case 'C':
			if(x==COLUMNS-2 or box[y][x+1]==SNAKE_BODY) return 1; // snake's been hit
			swap_em_qu(x, y);
			return 0;

		case 'A':
			if(y==1 or box[y-1][x]==SNAKE_BODY) return 1;
			swap_em_qu(x, y);
			return 0;	

		case 'D':
			if(x==1 or box[y][x-1]==SNAKE_BODY) return 1;
			swap_em_qu(x, y);
			return 0;

		case 'B':
			if(y+2==ROWS or box[y+1][x]==SNAKE_BODY) return 1;
			swap_em_qu(x, y);
			return 0;

		default:
			// crap user input >_>
			return 2;
	}
}