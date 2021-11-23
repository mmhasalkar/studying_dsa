#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} NODE, * PNODE, ** PPNODE;

void InsertFirst(PPNODE, PPNODE, int);
void InsertLast(PPNODE, PPNODE, int);
void InsertAtPos(PPNODE, PPNODE, int, int);

void DeleteFirst(PPNODE, PPNODE);
void DeleteLast(PPNODE, PPNODE);
void DeleteAtPos(PPNODE, PPNODE, int);

void Display(PNODE, PNODE);
void DisplayReverse(PNODE, PNODE);
int Count(PNODE, PNODE);

int main(int argc, char const *argv[])
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    printf("Inserting 51, 21 & 11 at first..\n");
    InsertFirst(&first, &last, 51);
    InsertFirst(&first, &last, 21);
    InsertFirst(&first, &last, 11);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 101 at last..\n");
    InsertLast(&first, &last, 101);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 103 at last..\n");
    InsertLast(&first, &last, 103);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 99 at 4th position..\n");
    InsertAtPos(&first, &last, 99, 4);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Inserting 102 at 6th position..\n");
    InsertAtPos(&first, &last, 102, 6);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting first node..\n");
    DeleteFirst(&first, &last);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting last node..\n");
    DeleteLast(&first, &last);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting node at 3rd position..\n");
    DeleteAtPos(&first, &last, 3);

    Display(first, last);
    DisplayReverse(first, last);
    iRet = Count(first, last);
    printf("Total nodes in the linked list: %d\n\n", iRet);

    printf("Deleting node at 2nd position..\n");
    DeleteAtPos(&first, &last, 2);

    Display(first, last);
    DisplayReverse(first, last);
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
    newn -> prev = NULL;


    if (*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn -> next = *head;
        (*head) -> prev = newn;
        *head = newn;
    }

    (*head) -> prev = *tail;
    (*tail) -> next = *head;
}

void InsertLast(PPNODE head, PPNODE tail, int iNo)
{
    PNODE newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (*head == NULL && *tail == NULL)
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn -> prev = *tail;
        (*tail) -> next = newn;
        *tail = newn;
    }

    (*head) -> prev = *tail;
    (*tail) -> next = *head;    
}

void InsertAtPos(PPNODE head, PPNODE tail, int iNo, int iPos)
{
    int iSize = Count(*head, *tail);
    int iCnt = 1;
    PNODE newn = NULL, current = *head;

    if (iPos < 1 || iPos > (iSize + 1))
    {
        printf("Unable to add node at given position. \n");
        return;
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
        newn -> prev = NULL;

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        newn -> next = current -> next;
        current -> next -> prev = newn;

        newn -> prev = current;
        current -> next = newn;
    }    
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
    if (*head == NULL && *tail == NULL)
    {
        printf("Could not delete first node of the Linked List. \n");
        return ;
    }

    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head) -> next;
        free((*head) -> prev);

        (*head) -> prev = *tail;
        (*tail) -> next = *head;
    }   
}

void DeleteLast(PPNODE head, PPNODE tail)
{
    if (*head == NULL && *tail == NULL)
    {
        printf("Could not delete last node of Linked List. \n");
        return ;
    }
    
    if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = (*tail) -> prev;
        free((*tail) -> next);

        (*head) -> prev = *tail;
        (*tail) -> next = *head;
    }
}

void DeleteAtPos(PPNODE head, PPNODE tail, int iPos)
{
    int iSize = Count(*head, *tail);
    int iCnt = 1;
    PNODE current = *head;

    if (iPos < 1 || iPos > iSize)
    {
        printf("Could not delete node at given position. \n");
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
            iCnt++;
            current = current -> next;
        }
        
        current -> next = current -> next -> next;
        free(current -> next -> prev);
        current -> next -> prev = current;
    }    
}

void Display(PNODE head, PNODE tail)
{
    if (head != NULL && tail != NULL)
    {
        do
        {
            printf("[%d] <==> ", head -> data);
            head = head -> next;
        } while (head != tail -> next);
    }
    
    printf("\n");
}

void DisplayReverse(PNODE head, PNODE tail)
{
    if (head != NULL && tail != NULL)
    {
        do
        {
            printf("[%d] <==> ", tail -> data);
            tail = tail -> prev;
        } while (tail != head -> prev);
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