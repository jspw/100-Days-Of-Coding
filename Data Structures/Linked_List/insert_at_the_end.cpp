#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void printNode()
{
    struct Node *temp = head;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    cout << endl;
};

void insertIntoEndOfNode(int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = value;

    temp->next = NULL;

    if (head == NULL)
        head = temp;

    else
    {
        struct Node *t = head;

        while (t->next)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

int main()
{

    head = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        insertIntoEndOfNode(a);
    }

    insertIntoEndOfNode(1);
    insertIntoEndOfNode(2);
    insertIntoEndOfNode(3);
    insertIntoEndOfNode(4);
    insertIntoEndOfNode(5);

    printNode();

    return 0;
}