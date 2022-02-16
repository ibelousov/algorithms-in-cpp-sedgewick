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

void deleteEven(node **head_ref)
{
    node *current = *head_ref;
    node *next = NULL;
    node *previous = *head_ref;
    int counter = 0;

    while (current != NULL)
    {
        next = current->next;
        if(counter % 2) {
            delete current;
            previous->next = next;
            previous = next;
        }
        counter++;
        current = next;
    }
}

void print(node *n)
{
    while (n)
    {
        std::cout << n->item << ' ';
        n = n->next;
    }

    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    node *n6 = new node(6, nullptr);
    node *n5 = new node(5, n6);
    node *n4 = new node(4, n5);
    node *n3 = new node(3, n4);
    node *n2 = new node(2, n3);
    node *n1 = new node(1, n2);

    print(n1);

    deleteEven(&n1);

    print(n1);

    return 0;
}