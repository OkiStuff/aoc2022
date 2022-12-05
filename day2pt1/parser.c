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
								if (plays[1] == PLAY_ROCK) total_score += 4; // Draw
								else if (plays[1] == PLAY_PAPER) total_score += 8; // Player Win
								else if (plays[1] == PLAY_SCISSORS) total_score += 3; // Enemy Win
								break;
						case PLAY_PAPER:
								if (plays[1] == PLAY_ROCK) total_score += 1; // Enemy Win
								else if (plays[1] == PLAY_PAPER) total_score += 5; // Draw
								else if (plays[1] == PLAY_SCISSORS) total_score += 9; // Player Win
								break;
						case PLAY_SCISSORS:
								if (plays[1] == PLAY_ROCK) total_score += 7; // Player Win
								else if (plays[1] == PLAY_PAPER) total_score += 2; // Enemy Win
								else if (plays[1] == PLAY_SCISSORS) total_score += 6; // Draw
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
				case PLAYER_ROCK:
						plays[1] = PLAY_ROCK;
						break;
				case PLAYER_PAPER:
						plays[1] = PLAY_PAPER;
						break;
				case PLAYER_SCISSORS:
						plays[1] = PLAY_SCISSORS;
						break;
				default:
						break;
				}
		}
	
		return total_score;
}
