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

node * escalateBiggest(node *head)
{
    node * outputHead = head;
    node * biggest = head;
    node * beforeBiggest = nullptr;

    while(head && head->next) {
        if(head->next->item > biggest->item) {
            beforeBiggest = head;
            biggest = head->next;
        }
        head = head->next;
    }

    if(beforeBiggest && biggest->next)
        beforeBiggest->next = biggest->next;

    outputHead =  biggest == outputHead ? outputHead->next : outputHead;
    
    if(biggest != head){
        biggest->next = nullptr;
        head->next = biggest;
    }

    return outputHead;
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
    node *n2 = new node(8, n3);
    node *n1 = new node(1, n2);

    n1 = escalateBiggest(n1);

    print(n1);

    return 0;
}