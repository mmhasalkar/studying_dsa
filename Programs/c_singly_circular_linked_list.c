#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} NODE, * PNODE, ** PPNODE;

void InsertFirst(PPNODE, PPNODE, int);
void InsertLast(PPNODE, PPNODE, int);
void InsertAtPos(PPNODE, PPNODE, int, int);

void DeleteFirst(PPNODE, PPNODE);
void DeleteLast(PPNODE, PPNODE);
void DeleteAtPos(PPNODE, PPNODE, int);

void Display(PNODE, PNODE);
int Count(PNODE, PNODE);

int main(int argc, char const *argv[])
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    printf("Inserting 51, 21, 11 at first.. \n");
    InsertFirst(&first, &last, 51);
    InsertFirst(&first, &last, 21);
    InsertFirst(&first, &last, 11);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 101, 103 at last.. \n");
    InsertLast(&first, &last, 101);
    InsertLast(&first, &last, 103);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 99 at 4th position..\n");
    InsertAtPos(&first, &last, 99, 4);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 102 at 6th position..\n");
    InsertAtPos(&first, &last, 102, 6);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting first node..\n");
    DeleteFirst(&first, &last);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting last node..\n");
    DeleteLast(&first, &last);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting 2nd node..\n");
    DeleteAtPos(&first, &last, 2);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting 3rd node..\n");
    DeleteAtPos(&first, &last, 3);

    Display(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    return 0;
}

void InsertFirst(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if (*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn -> next = (*head);
        *head = newn;
    }

    (*tail) -> next = *head;   
}

void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;

    if (*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        (*tail) -> next = newn;
        *tail = newn;
    }
    
    (*tail) -> next = *head;
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    PNODE newn = NULL;
    PNODE current = *head;
    int iCnt = 1;
    int iSize = Count(*head, *tail);

    if (iPos < 1 || iPos > (iSize + 1))
    {
        printf("Could not insert at the given position. \n");
        return ;
    }

    if (iPos == 1)
    {
        InsertFirst(head, tail, iNo);
    }
    else if (iPos == (iSize + 1))
    {
        InsertLast(head, tail, iNo);
    }
    else
    {
        newn = (PNODE) malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;
        
        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        newn -> next = current -> next;
        current -> next = newn;
    }
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
    if (*head == NULL && *tail == NULL)
    {
        printf("Could not delete the first node. Linked List is empty. \n");
        return;
    }
    else if (*head == *tail)
    {
        free(*head);

        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head) -> next;
        free((*tail) -> next);
        (*tail) -> next = *head;
    }
}

void DeleteLast(PPNODE head, PPNODE tail)
{
    PNODE current = *head;
    
    if (*head == NULL && *tail == NULL)
    {
        printf("Could not delete the last node. Linked List is empty. \n");
        return ;
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        while (current -> next != *tail)
        {
            current = current -> next;
        }
        
        free(*tail);
        *tail = current;
        (*tail) -> next = *head;
    }
}

void DeleteAtPos(PPNODE head, PPNODE tail, int iPos)
{
    int iSize = Count(*head, *tail);
    PNODE current = *head;
    PNODE target = NULL;
    int iCnt = 1;

    if (iPos < 1 || iPos > iSize)
    {
        printf("Could not delete element at the given position.\n");
        return ;
    }
    
    if (iPos == 1)
    {
        DeleteFirst(head, tail);
    }
    else if (iPos == iSize)
    {
        DeleteLast(head, tail);
    }
    else
    {
        while (iCnt < (iPos - 1))
        {
            current = current -> next;
            iCnt++;
        }
        
        target = current -> next;
        current -> next = current -> next -> next;
        free(target);
    }
    
}

void Display(PNODE head, PNODE tail)
{
    if (head != NULL && tail != NULL)
    {
        do
        {
            printf("[%d] -> ", head -> data);
            head = head -> next;
        } while (head != tail -> next);
    }    
    
    printf("\n");
}

int Count(PNODE head, PNODE tail)
{
    int iCnt = 0;

    if (head != NULL && tail != NULL)
    {
        do
        {
            iCnt++;
            head = head -> next;
        } while (head != tail -> next);
    }
    
    return iCnt;
}