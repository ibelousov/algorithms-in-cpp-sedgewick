#include <iostream>
#include <time.h>

struct node {
    int item;
    node * next;
    node(int x, node * t)
    {
        item = x;
        next = t;
    }
};

typedef node *link;

int count(node * link)
{
    int count = 1;
    node * start = link;

    while (link && start != link->next){
        link = link->next;
        ++count;
    }
    
    return count;
}

int main(int argc, char ** argv)
{
    node * t = new node(1, nullptr);
    t->next = t;
    srand(time(NULL));
    int randomNumber = 0;
    node * n = t;
    
    for(int i = 0; i < randomNumber; i++)
        n = (n->next = new node(i, t));

    std::cout << count(n);

    return 0;
}