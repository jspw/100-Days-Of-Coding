#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head;

void printNode()
{
    struct Node *temp = head;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    cout << endl;
}

int main()
{
    head = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->link = (struct Node *)malloc(sizeof(struct Node));

    head->link->data = 3;

    head->link->link = (struct Node *)malloc(sizeof(struct Node));

    head->link->link->data = 5;
    head->link->link->link = NULL;

    printNode();
}