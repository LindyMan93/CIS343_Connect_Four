#include <stdio.h>
#include <stdlib.h>
#include "connect4.h"

int genBoard(int **gameBoard, int boardHeight, int boardWidth){

	char **gameBoard = (char **)malloc(height * sizeof(char *));
	for( int i = 0; i < height; i++){
		gameBoard[i] = (char *)malloc(width * sizeof(char));
	}
	for( int i = 0; i < height; i++){
		for( int j = 0; j < width; j++){
			gameBoard[i][j] = '_';
		}
	}
	//printing board
	for( int i = 0; i < height; i++){
		for( int j = 0; j < width; j++){
			printf(gameBoard[i][j];
		}
	}
	
	return boardHeight * boardWidth;
}
