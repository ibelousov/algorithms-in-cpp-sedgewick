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

node * copy(node *head)
{
    node * start = new node(head->item, nullptr);
    node * current = start;
    head = head->next;

    while(head) {
        current->next = new node(head->item, nullptr);
        current = current->next;
        head = head->next;
    }

    return start;
}

void print(node *n)
{
    while(n)
    {
        std::cout << n->item << ' ';
        n = n->next;
        
    }
}

int main(int argc, char **argv)
{
    node *n5 = new node(5, nullptr);
    node *n4 = new node(4, n5);
    node *n3 = new node(3, n4);
    node *n2 = new node(2, n3);
    node *n1 = new node(1, n2);

    node *copied = copy(n1);

    print(copied);

    return 0;
}