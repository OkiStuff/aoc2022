#include <stdio.h>
#include "parser.h"

int main(void)
{
    parser parser_data = parse_data("./input.txt");
    int highest = 0;
    
    for (int i = 0; i < parser_data.size; i++)
    {
        if (parser_data.data[i] > highest) highest = parser_data.data[i];
    }
    
    printf("Highest: %d\n", highest);
    
    free(parser_data.data);
    return 0;
}