void set_bait() {
	int row_lim = ROWS-2;
	int col_lim = COLUMNS-2;

	srand(time(0));

	int rb = (rand()%row_lim)+1;
	int cb = (rand()%col_lim)+1;

	baits = std::make_pair(rb, cb);
	box[rb][cb] = FOOD;
}