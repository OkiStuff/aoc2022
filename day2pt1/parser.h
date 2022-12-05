#include <stdio.h>
#include <stdlib.h>

enum PLAYS
{
		PLAY_ROCK = 0,
		PLAY_PAPER,
		PLAY_SCISSORS
};

enum PLAY_CHARACTERS
{
		ENEMY_ROCK = 0x41,
		ENEMY_PAPER = 0x42,
		ENEMY_SCISSORS = 0x43,
		PLAYER_ROCK = 0x58,
		PLAYER_PAPER = 0x59,
		PLAYER_SCISSORS = 0x5A
};

int parse_data(const char* filepath);