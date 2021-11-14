#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * prev;
    struct node * next;
} NODE, * PNODE, ** PPNODE;

void InsertFirst(PPNODE, int);
void InsertLast(PPNODE, int);
void InsertAtPos(PPNODE, int, int);

void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE, int);

void Display(PNODE);
int Count(PNODE);
void DisplayReverse(PNODE);

int main(int argc, char const *argv[])
{
    PNODE first = NULL;
    int choice = 1, iData = 0, iRet = 0, iPos = 0;

    while (choice)
    {
        printf("==========================================\n");
        printf("Enter your choice from below menu: \n");
        printf("------------------------------------------\n");
        printf("1. Insert at start. \n");
        printf("2. Insert at last. \n");
        printf("3. Insert at position. \n");
        printf("4. Delete first. \n");
        printf("5. Delete last. \n");
        printf("6. Delete at position. \n");
        printf("7. Display linked list. \n");
        printf("8. Display linked list in reverse. \n");
        printf("9. Count nodes in Linked List. \n");
        printf("0. Exit \n");
        printf("------------------------------------------\n");
        printf("> ");
        scanf("%d", &choice);
        printf("==========================================\n\n");

        switch (choice)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &iData);
                InsertFirst(&first, iData);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &iData);
                InsertLast(&first, iData);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &iData);
                printf("Enter position to insert: ");
                scanf("%d", &iPos);
                InsertAtPos(&first, iData, iPos);
                break;

            case 4:
                DeleteFirst(&first);
                break;

            case 5:
                DeleteLast(&first);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &iPos);
                DeleteAtPos(&first, iPos);
                break;

            case 7:
                Display(first);
                break;

            case 8:
                DisplayReverse(first);
                break;

            case 9:
                iRet = Count(first);
                printf("Total %d nodes in the Linked List. \n", iRet);
                break;

            case 0:
                printf("Thanks for using simple Linked List app. \n");
                break;
            
            default:
                printf("Please enter a valid choice. \n");
                break;
        }

        printf("\n==========================================\n");
    }
    
    return 0;
}

void InsertFirst(PPNODE head, int iNo)
{
    printf("Inserting a new node.. \n");
    
    PNODE newn = NULL;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (*head != NULL)
    {
        newn -> next = *head;
        (*head) -> prev = newn;
    }
    
    *head = newn;

    printf("Success - New node inserted. \n");
}

void InsertLast(PPNODE head, int iNo)
{
    printf("Inserting a new node.. \n");

    PNODE newn = NULL;
    PNODE current = *head;

    newn = (PNODE) malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        while (current -> next != NULL)
        {
            current = current -> next;
        }
        
        newn -> prev = current;
        current -> next = newn;
    }
    
    printf("Success - New node inserted. \n");
}

void InsertAtPos(PPNODE head, int iNo, int iPos)
{
    PNODE newn = NULL;
    PNODE current = *head;
    int iCnt = 1, iSize = Count(*head);

    if ((iSize < 1) || (iPos > (iSize + 1)))
    {
        printf("Could not insert node at %d. \n", iPos);
        return;
    }
    
    if (iPos == 1)
    {
        InsertFirst(head, iNo);
    }
    else if (iPos == (iSize + 1))
    {
        InsertLast(head, iNo);
    }
    else
    {
        printf("Inserting a new node.. \n");

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

        current -> next = newn;
        newn -> prev = current;

        printf("Success - New node inserted. \n");
    }
}

void DeleteFirst(PPNODE head)
{
    if (*head == NULL)
    {
        printf("Could not delete node. Linked List is empty. \n");
        return;
    }
    printf("Deleting node.. \n");

    *head = (*head) -> next;
    free((*head) -> prev);
    (*head) -> prev = NULL;
    
    printf("Success - Node deleted. \n");
}

void DeleteLast(PPNODE head)
{
    PNODE current = *head;
    
    if (*head == NULL)
    {
        printf("Could not delete node. Linked List is empty. \n");
        return;
    }

    printf("Deleting node.. \n");

    if ((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        while (current -> next -> next != NULL)
        {
            current = current -> next;
        }
        
        free(current -> next);
        current -> next = NULL;
    }

    printf("Success - Node deleted. \n");
}

void DeleteAtPos(PPNODE head, int iPos)
{
    PNODE current = *head;
    int iSize = Count(*head), iCnt = 1;

    if ((iSize < 1) || iPos > iSize)
    {
        printf("Could not delete node at %d. \n", iPos);
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst(head);
    }
    else if (iPos == iSize)
    {
        DeleteLast(head);
    }
    else
    {
        printf("Deleting node.. \n");

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        current -> next = current -> next -> next;
        free(current -> next -> prev);
        current -> next -> prev = current;

        printf("Success - Node deleted. \n");
    }   
}

void Display(PNODE head)
{
    while (head != NULL)
    {
        printf("[%d] <==> ", head -> data);
        
        head = head -> next;
    }

    printf("[NULL] \n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while (head != NULL)
    {
        iCnt++;
        head = head -> next;
    }
    
    return iCnt;
}

void DisplayReverse(PNODE head)
{
    while (head != NULL && head -> next != NULL)
    {
        head = head -> next;
    }
    
    while (head != NULL)
    {
        printf("[%d] <==> ", head -> data);
        head = head -> prev;
    }
    
    printf("[NULL] \n");
}