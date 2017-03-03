
// Created by Nathan Lindenbaum on 3/2/17.
//
//
#include <stdio.h>
#include <stdlib.h>
#include "handle_arguments.h"
#include "connect4.h"

int main(int argc, char** argv) {

	int boardHeight = 7;
	int boardWidth = 6;
	int connect = 4;
	int * gameBoard;

	struct arguments args;

	setup(argc, argv, &args);
	
	boardHeight = args.height;
	boardWidth = args.width;
	connect = args.connect;

	genBoard(&gameBoard, boardHeight, boardWidth);

	return 0;
	
}
