#include <iostream>
#include <time.h>

struct node
{
    int item;
    node *next;
    node(int x, node *t)
    {
        item = x;
        next = t;
    }
};

typedef node *link;

int count(node *start, node *end)
{
    int count = 0;

    while (start && start != end && start->next != end)
    {
        start = start->next;
        ++count;
    }

    return count;
}

int main(int argc, char **argv)
{
    node *n5 = new node(1, nullptr);
    node *n4 = new node(1, n5);
    node *n3 = new node(1, n4);
    node *n2 = new node(1, n3);
    node *n1 = new node(1, n2);
    n5->next = n1;

    std::cout << count(n2,n1);

    return 0;
}