#ifndef SNAKE_H
#define SNAKE_H

#ifdef WIN32
#include <cstdio>
#include <cstdlib>
printf("The version is not available for windows!\n");
exit(0);
#endif

#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <utility>
#include <unistd.h>
#include <sys/types.h>

#define ROWS 			35 
#define COLUMNS 		75
#define ROW_START 		18
#define COL_START		9
#define DIR_START		'C'
#define UD_BOARD 		'='
#define LR_BOARD 		'#'
#define SNAKE_HEAD		'o' ///////// useless
#define SNAKE_BODY		'o'
#define FOOD			'*'
#define SNAKE_LENGTH 		4
#define SLEEP			140000
#define SWAP(x, y)	 	x+=y;y=x-y;x-=y

std::queue<std::pair<int, int> > Q;
std::pair<int, int> baits;

char box[ROWS][COLUMNS];
int eaten = 1;

#include "box_borders.cpp"
#include "instant_getc.cpp"
#include "move.cpp"
#include "bait.cpp"

#endif
