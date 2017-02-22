//this is a simple c program that demonstrates the memory management system in operating systems implemented in a linked list.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <malloc.h>

struct node
{
    char pName;
    int startPoint;
    int size;
    struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

struct node *merge()
{
    struct node *holder;
    holder = head;
    while (holder->next != NULL)
    {
        if (holder->pName == 'X' && holder->next->pName == 'X')
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp = holder->next;
            holder->size = holder->size + holder->next->size;
            holder->next = holder->next->next;
            free(temp);
        }
        else
        {
            holder = holder->next;
        }
    }
}

struct node *scan(char name, int size)
{
    struct node *temp = head;
    struct node *scan = NULL;
    int avail;
    bool found = false;

    while (temp != NULL)
    {
        avail = temp->size - size;
        if (temp->pName == name && avail >= 0)
        {
            found = true;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (found == true)
    {
        return temp;
    }
    else
    {
        return NULL;
    }
}

struct node *manip(char name, int act, int size)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (act == 1)
    {
        curr = scan('X', size);

        if (curr == NULL)
        {
            perror("not found!!!");
        }
        else
        {
            temp->pName = curr->pName;
            temp->startPoint = curr->startPoint + size;
            temp->size = curr->size - size;
            temp->next = curr->next;

            curr->pName = name;
            curr->size = size;
            curr->next = temp;
        }
    }

    if (act == 0)
    {
        while (curr->pName != name)
        {
            curr = curr->next;
        }
        if (size != curr->size)
        {
            perror("size error");
        }
        else
        {
            curr->pName = 'X';
        }
    }
    merge();
}

void print()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%c, %d, %d =>", temp->pName, temp->startPoint, temp->size);
        temp = temp->next;
    }
    printf("\n");
    return;
}

int main()
{
    char name;
    int size;
    int act;

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("enter in the memory size: ");
    scanf("%d", &temp->size);

    temp->pName = 'X';
    temp->startPoint = 0;

    head = temp;
    print();

    while (!scanf("quit"))
    {
        printf("\nenter next process infromation(Process name,(1 or 0),Memory size): ");
        scanf("%s%d%d", &name, &act, &size);
        curr = head;
        manip(name, act, size);
        print();
    }

    return 0;
}
