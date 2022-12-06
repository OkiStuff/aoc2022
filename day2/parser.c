#include "parser.h"

int parse_data(const char* filepath)
{
	int cursor = 0;
	FILE* file;
		
	fopen_s(&file, filepath, "r");

	if (!file)
	{
		printf("Could not read file '%s'\n", filepath);
		exit(-1);
	}
	
	fseek(file, 0, SEEK_END);
	const int filesize = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	char buffer[filesize + 1];
	
	fread(buffer, 1, filesize, file);
	buffer[filesize] = 0;
	fclose(file);
	
	int total_score = 0;
	int plays[2];
	
	for (cursor = 0; cursor < filesize; cursor++)
	{
		if (buffer[cursor] == 0) break;
		else if (buffer[cursor] == '\n')
		{
			switch(plays[0])
			{
			case PLAY_ROCK:
				if (plays[1] == PLAY_LOSE) total_score += 3; // Play scissors for lost match
				else if (plays[1] == PLAY_DRAW) total_score += 4; // Play rock for drawn match
				else if (plays[1] == PLAY_WIN) total_score += 8; // Play paper for won match
				break;
			case PLAY_PAPER:
				if (plays[1] == PLAY_LOSE) total_score += 1; // Play rock for lost match
				else if (plays[1] == PLAY_DRAW) total_score += 5; // Play paper for drawn match
				else if (plays[1] == PLAY_WIN) total_score += 9; // Play scissors for won match
				break;
			case PLAY_SCISSORS:
				if (plays[1] == PLAY_LOSE) total_score += 2; // Play paper for lost match
				else if (plays[1] == PLAY_DRAW) total_score += 6; // Play scissors for drawn match 
				else if (plays[1] == PLAY_WIN) total_score += 7; // Play rock for won match
				break;
			default:
				printf("Unknown error!\n");
				exit(-1);
				break;
			}
						
			continue;
		};
		
		switch(buffer[cursor])
		{
		case ENEMY_ROCK:
			plays[0] = PLAY_ROCK;
			break;
		case ENEMY_PAPER:
			plays[0] = PLAY_PAPER;
			break;
		case ENEMY_SCISSORS:
			plays[0] = PLAY_SCISSORS;
			break;
		case PLAYER_LOSE:
			plays[1] = PLAY_LOSE;
			break;
		case PLAYER_DRAW:
			plays[1] = PLAY_DRAW;
			break;
		case PLAYER_WIN:
			plays[1] = PLAY_WIN;
			break;
		default:
			break;
		}
	}
	
	return total_score;
}
