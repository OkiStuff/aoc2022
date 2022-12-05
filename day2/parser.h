#include <stdio.h>
#include <stdlib.h>

enum PLAYS
{
		PLAY_ROCK = 0,
		PLAY_PAPER,
		PLAY_SCISSORS,
		PLAY_LOSE,
		PLAY_DRAW,
		PLAY_WIN
};

enum PLAY_CHARACTERS
{
		ENEMY_ROCK = 'A',
		ENEMY_PAPER = 'B',
		ENEMY_SCISSORS = 'C',
		PLAYER_LOSE = 'X',
		PLAYER_DRAW = 'Y',
		PLAYER_WIN = 'Z'
};

int parse_data(const char* filepath);