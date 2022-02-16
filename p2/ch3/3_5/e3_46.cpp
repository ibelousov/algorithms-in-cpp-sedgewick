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

void deleteList(node **head_ref)
{
    node *current = *head_ref;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }

    *head_ref = NULL;
}

int main(int argc, char **argv)
{
    node *n5 = new node(5, nullptr);
    node *n4 = new node(4, n5);
    node *n3 = new node(3, n4);
    node *n2 = new node(2, n3);
    node *n1 = new node(1, n2);

    std::cout << n1->item << ' ' << n2->item << ' ' << n3->item << ' ' << n4->item << ' ' << n5->item << std::endl;

    deleteList(&n1);

    std::cout << n1;
    
    std::cout << n1 << ' ' << n2->item << ' ' << n3 << ' ' << n4 << ' ' << n5 << std::endl;

    return 0;
}