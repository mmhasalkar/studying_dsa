#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
} NODE, * PNODE;

class BST
{
    private:
        PNODE first;

    public:
        BST();
        PNODE getFirst();
        void insert(int);
        bool search(int);
        void dispInorder(PNODE);
        void dispPreorder(PNODE);
        void dispPostorder(PNODE);
        int countNodes(PNODE);
        int countLeafNodes(PNODE);
        int countParentNodes(PNODE);
};

BST::BST()
{
    first = NULL;
}

PNODE BST::getFirst()
{
    return first;
}

void BST::insert(int iNo)
{
    PNODE current = first;
    PNODE newn = new NODE;
    bool inserted = true;

    newn -> data = iNo;
    newn -> lchild = NULL;
    newn -> rchild = NULL;
    
    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (1)
        {
            if (iNo == current -> data)
            {
                cout<<"Duplicate node."<<endl;
                delete newn;
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

bool BST::search(int iNo)
{
    PNODE current = first;

    if (first == NULL)
    {
        return false;
    }
    else
    {
        while (current != NULL)
        {
            if (current -> data == iNo)
            {
                break;
            }
            else if (iNo > current -> data)
            {
                current = current -> rchild;
            }
            else if (iNo < current -> data)
            {
                current = current -> lchild;
            }
        }
    }
    
    if (current == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void BST::dispInorder(PNODE current)
{
    if (current != NULL)
    {
        dispInorder(current -> lchild);
        cout<<current -> data<<"\t";
        dispInorder(current -> rchild);
    }
}

void BST::dispPreorder(PNODE current)
{
if (current != NULL)
    {
        cout<<current -> data<<"\t";
        dispInorder(current -> lchild);
        dispInorder(current -> rchild);
    }
}

void BST::dispPostorder(PNODE current)
{
    if (current != NULL)
    {
        dispInorder(current -> lchild);
        dispInorder(current -> rchild);
        cout<<current -> data<<"\t";
    }
}

int BST::countNodes(PNODE current)
{
    static int iCnt = 0;

    if (current != NULL)
    {
        iCnt++;
        countNodes(current -> lchild);
        countNodes(current -> rchild);
    }
    
    return iCnt;
}

int BST::countLeafNodes(PNODE current)
{
    static int iCnt = 0;

    if (current != NULL)
    {
        if (current -> lchild == NULL && current -> rchild == NULL)
        {
            iCnt++;
        }
        countLeafNodes(current -> lchild);
        countLeafNodes(current -> rchild);
    }
    
    return iCnt;
}

int BST::countParentNodes(PNODE current)
{
    static int iCnt = 0;

    if (current != NULL)
    {
        if (current -> lchild != NULL || current -> rchild != NULL)
        {
            iCnt++;
        }
        countParentNodes(current -> lchild);
        countParentNodes(current -> rchild);
    }
    
    return iCnt;
}

int main(int argc, char const *argv[])
{
    BST obj;
    int iRet = 0, iVal = 0;
    bool bRet = false;

    obj.insert(51);
    obj.insert(21);
    obj.insert(101);
    obj.insert(21);

    cout<<"Enter a number to search in the Tree: ";
    cin>>iVal;

    bRet = obj.search(iVal);
    if (bRet)
    {
        cout<<"The number is present in the Tree."<<endl;
    }
    else
    {
        cout<<"The number is absent in the Tree."<<endl;
    }
    
    cout<<endl<<"Total nodes in the Tree: "<<obj.countNodes(obj.getFirst())<<endl;
    cout<<endl<<"Total leaf nodes in the Tree: "<<obj.countLeafNodes(obj.getFirst())<<endl;
    cout<<endl<<"Total parent nodes in the Tree: "<<obj.countParentNodes(obj.getFirst())<<endl;

    cout<<endl<<"Inorder Tree"<<endl;
    obj.dispInorder(obj.getFirst());

    cout<<endl<<"Preorder Tree"<<endl;
    obj.dispPreorder(obj.getFirst());

    cout<<endl<<"Postorder Tree"<<endl;
    obj.dispPostorder(obj.getFirst());

    cout<<endl;
    return 0;
}
