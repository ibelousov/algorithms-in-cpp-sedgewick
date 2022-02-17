#include <iostream>
#include <string.h>
#include <time.h>

#define START 33
#define CHARS 127

int main(int argc, char ** argv)
{
    int symbols[CHARS];

    for (int i = 0; i < CHARS; i++)
        symbols[i] = 0;

    for(int i = strlen(argv[1])-1; i >= 0; i--)
        symbols[argv[1][i]]++;

    for(int i = START; i < CHARS; i++)
        std::cout << '"' << char(i) << "\": " << symbols[i] << (i % 16 ? " | " : "\n");
    
    std::cout << std::endl;

    return 0;
}