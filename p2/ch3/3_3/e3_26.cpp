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

node * getBefore(node * item)
{
    node * beforeItem = item->next;

    while (beforeItem->next != item)
        beforeItem = beforeItem->next;

    return beforeItem;
}

int move(node *from, node *after)
{
    int count = 0;

    node * beforeFrom = getBefore(from);
    node * afterFrom = from->next;
    node * beforeAfter = getBefore(after);
    node * afterAfter = after->next;

    beforeFrom->next = afterFrom;
    after->next = from;
    from->next = afterAfter;

    return count;
}

void print(node * n)
{
    node * was = nullptr;

    while(true) {
        if(!was)
            was = n;
        else if(was == n)
            return;

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
    n5->next = n1;

    move(n1, n3);

    print(n2);

    return 0;
}