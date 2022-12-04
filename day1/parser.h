#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _parser
{
    int size;
    int* data;
};

typedef struct _parser parser;

parser parse_data(const char* filepath);