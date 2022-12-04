#include "parser.h"
//#define BREAKPOINT(num) printf("breakpoint but not real breakpoint number %d\n", num);

parser parse_data(const char* filepath)
{
    int cursor = 0;
    int line = 0;
    int increment_last_line = 0;
  
    FILE* file;
    fopen_s(&file, filepath, "r");
    
    if (!file)
    {
        printf("Could nott read file '%s'\n", filepath);
        exit(-1);
    }
  
    fseek(file, 0, SEEK_END);
    const int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char buffer[filesize + 1];
    
    fread(buffer, 1, filesize, file);
    buffer[filesize] = 0;  
    fclose(file);
    
    parser parser_data = {0};
    parser_data.size = 1;
    parser_data.data = calloc(parser_data.size, sizeof(int));
    
    if (parser_data.data == NULL)
    {
        printf("Failed to allocate memory (line 32)\n");
        exit(-1);
    }
    
    char* numdata = calloc(6, sizeof(char));
    if (numdata == NULL)
    {
        printf("Failed to allocate memory (line 42)\n");
        free(parser_data.data);
        exit(-1);
    }
    
    numdata[5] = 0;
    
    int numdata_index = 0;
  
    for (cursor = 0; cursor < filesize; cursor++)
    {
        //printf("%c", buffer[cursor]);
    
        if (buffer[cursor] == 0) break;
        else if (buffer[cursor] == '\n' || buffer[cursor] == '\r')
        {
            line++;
            numdata_index = 0;
            
            if (++increment_last_line >= 2)
            {
                parser_data.size++;
                int* temp = realloc(parser_data.data, sizeof(int) * parser_data.size);
                                    
                if (temp == NULL)
                {
                    printf("Failed to allocate memory (line 52)\n");
                    
                    free(numdata);
                    free(parser_data.data);
                    exit(-1);
                }
                
                parser_data.data = temp;
                parser_data.data[parser_data.size - 1] = 0;
                continue;
            }
            parser_data.data[parser_data.size - 1] += atoi(numdata);
            numdata[4] = 0;
            
            perror("Message");
            printf("numdata has been cleared: %s\nParser Data %d is equal to %d\n", numdata, parser_data.size - 1, parser_data.data[parser_data.size - 1]);
      
            continue;
        }
    
        else increment_last_line = 0;
        numdata[numdata_index] = buffer[cursor];
        
        printf("Set numdata[%d] to %c\n", numdata_index, numdata[numdata_index]);
        printf("numdata is now: %s\n", numdata);
        
        numdata_index++;
    }

    free(numdata);  
    return parser_data;
}