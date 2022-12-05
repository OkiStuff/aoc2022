#include <stdio.h>
#include "parser.h"

int main(void)
{
    parser parser_data = parse_data("./input.txt");
    int highest = 0;
    int second = 0;
    int third = 0;
        
    for (int i = 0; i < parser_data.size; i++)
    {
        if (parser_data.data[i] >= highest) highest = parser_data.data[i];
        else if (parser_data.data[i] >= second) second = parser_data.data[i];
        else if (parser_data.data[i] >= third) third = parser_data.data[i];
    }
    
    for (int i = 0; i < parser_data.size; i++)
    {
        if (parser_data.data[i] >= highest) highest = parser_data.data[i];
        else if (parser_data.data[i] >= second) second = parser_data.data[i];
        else if (parser_data.data[i] >= third) third = parser_data.data[i];
    }
    
    printf("Highest: %d\nSecond: %d\nThird: %d\nSum: %d\n", highest, second, third, highest + second + third);
    
    free(parser_data.data);
    return 0;
}