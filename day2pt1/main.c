#include <stdio.h>
#include "parser.h"

int main(void)
{
		int score = parse_data("./input.txt");
		printf("Your score is: %d\n", score);
		return 0;
}
