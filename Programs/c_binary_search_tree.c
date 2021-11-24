#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
} NODE, * PNODE, ** PPNODE;

void Insert(PPNODE, int);
bool Search(PNODE, int);
void DisplayInorder(PNODE);
void DisplayPreorder(PNODE);
void DisplayPostorder(PNODE);
int CountNodes(PNODE);
int CountLeafNodes(PNODE);
int CountParentNodes(PNODE);

int main(int argc, char const *argv[])
{
    PNODE first = NULL;
    int iVal = 0, iRet = 0;
    bool bRet = false;

    Insert(&first, 51);
    Insert(&first, 11);
    Insert(&first, 101);

    printf("Enter a number to search in the Tree: ");
    scanf("%d", &iVal);

    bRet = Search(first, iVal);
    if (bRet)
    {
        printf("The given number is present in the Tree. \n");
    }
    else
    {
        printf("The given number is absent in the Tree. \n");
    }
    
    iRet = CountNodes(first);
    printf("Total nodes in the Tree: %d\n", iRet);

    iRet = CountParentNodes(first);
    printf("Total parent nodes in the Tree: %d\n", iRet);

    iRet = CountLeafNodes(first);
    printf("Total leaf nodes in the Tree: %d\n", iRet);

    printf("\nInorder Tree: \n");
    DisplayInorder(first);

    printf("\nPreorder Tree: \n");
    DisplayPreorder(first);

    printf("\nPostorder Tree: \n");
    DisplayPostorder(first);

    printf("\n");
    return 0;
}

void Insert(PPNODE head, int iNo)
{
    PNODE newn = (PNODE) malloc(sizeof(NODE));
    PNODE current = *head;

    newn -> data = iNo;
    newn -> lchild = NULL;
    newn -> rchild = NULL;
    
    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        while (1)
        {
            if (iNo == current -> data)
            {
                printf("Duplicate node. \n");
                free(newn);
                break;
            }
            else if (iNo > current -> data)
            {
                if (current -> rchild == NULL)
                {
                    current -> rchild = newn;
                    break;
                }
                
                current = current -> rchild;
            }
            else if (iNo < current -> data)
            {
                if (current -> lchild == NULL)
                {
                    current -> lchild = newn;
                    break;
                }
                
                current = current -> lchild;
            }
        }
    }
}

bool Search(PNODE head, int iNo)
{
    if (head == NULL)
    {
        return false;
    }
    else
    {
        while (head != NULL)
        {
            if (head -> data == iNo)
            {
                break;
            }
            else if (iNo > head -> data)
            {
                head = head -> rchild;
            }
            else if (iNo < head -> data)
            {
                head = head -> lchild;
            }
        }
        
        if (head == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int CountNodes(PNODE head)
{
    static int iCnt = 0;

    if (head != NULL)
    {
        iCnt++;
        CountNodes(head -> lchild);
        CountNodes(head -> rchild);
    }
    
    return iCnt;
}

int CountParentNodes(PNODE head)
{
    static int iCnt = 0;

    if (head != NULL)
    {
        if (head -> lchild != NULL || head -> rchild != NULL)
        {
            iCnt++;
        }
        
        CountParentNodes(head -> lchild);
        CountParentNodes(head -> rchild);
    }
    
    return iCnt;
}

int CountLeafNodes(PNODE head)
{
    static int iCnt = 0;

    if (head != NULL)
    {
        if ((head -> lchild) == NULL && (head -> rchild) == NULL)
        {
            iCnt++;
        }
        
        CountLeafNodes(head -> lchild);
        CountLeafNodes(head -> rchild);
    }

    return iCnt;
}

void DisplayInorder(PNODE head)             // LDR
{
    if (head != NULL)
    {
        DisplayInorder(head -> lchild);     // L
        printf("%d \t", head -> data);      // D
        DisplayInorder(head -> rchild);     // R
    }
}

void DisplayPreorder(PNODE head)            // DLR
{
    if (head != NULL)
    {
        printf("%d \t", head -> data);      // D
        DisplayPreorder(head -> lchild);    // L
        DisplayPreorder(head -> rchild);    // R
    }
}

void DisplayPostorder(PNODE head)           // LRD
{
    if (head != NULL)
    {
        DisplayPostorder(head -> lchild);   // L
        DisplayPostorder(head -> rchild);   // R
        printf("%d \t", head -> data);      // D
    }
}