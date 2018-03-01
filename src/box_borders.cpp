void set_borders() {

	std::memset(box, ' ', sizeof(box));  // clear the box

	/*set first and last COLUMNS*/
	for(int j=0; j<COLUMNS; j++) {
		box[0][j] = UD_BOARD;
		box[ROWS-1][j] = UD_BOARD;
	}

	/*set first and last row*/
	for(int i=1; i<ROWS-1; i++) {
		box[i][0] = LR_BOARD;
		box[i][COLUMNS-1] = LR_BOARD;
	}

	// box[ROW_START][COL_START] = SNAKE_HEAD;
	for(int i=COL_START-SNAKE_LENGTH; i<COL_START; i++) {
		box[ROW_START][i] = SNAKE_BODY;
		Q.push(std::make_pair(ROW_START, i));
	}
}