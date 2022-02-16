#include <iostream>
#include <time.h>

#define COUNT 10

int main(int argc, char ** argv)
{
    int n[COUNT];
    int p,q,t,j,k;
    srand(time(NULL));

    for(int i = 0; i < COUNT; i++)
        n[i] = i;

    for(int i = 0; i < COUNT; i++)
    {
        p = rand() % COUNT;
        q = rand() % COUNT;

        if(p == q)
            p = (p + 5) % COUNT;
        // 0 1 2 3 4
        // j = 1  1 != n[1]
        // k = 2  2 != n[2]
        // n[1] = 2
        // j = 1  1 != n[1](2) j = n[1]
        //        2 != n[1](2)
        // q = 2  2 != n[2](2)
        for(j = p; j != n[j]; j = n[j]);
        for(k = q; k != n[k]; k = n[k]);
        if(j == k)
            continue;
        n[j] = k;

        std::cout << " " << p << " " << q << std::endl;
    }

    return 0;
}