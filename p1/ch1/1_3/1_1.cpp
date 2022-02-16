#include <iostream>
#include <time.h>

#define COUNT 10


int main(int argc, char ** argv)
{
    int n[10];
    int p,q,t;
    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
        n[i] = i;

    for (int i = 0; i < COUNT; i++)
        std::cout << n[i] << ' ';
    
    std::cout << std::endl;

    for (int i = 0; i < COUNT; i++)
    {
        p = rand() % COUNT;
        q = rand() % COUNT;

        if (p == q)
            p = (p + 5) % COUNT;

        std::cout << "p: " << p << ", q: " << q << std::endl;

        t = n[p];

        if (t == n[q])
            continue;

        for(int j = 0; j < COUNT; j++)
            if(t == n[j])
                n[j] = n[q];

        for (int i = 0; i < COUNT; i++)
            std::cout << n[i] << ' ';
        
        std::cout << std::endl;
    }
}