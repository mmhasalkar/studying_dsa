#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} NODE, * PNODE;

class SinglyCLL
{
    private:
        PNODE first;
        PNODE last;
        int size;

    public:
        SinglyCLL();
        void insertFirst(int);
        void insertLast(int);
        void insertAtPos(int, int);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int);
        void display();
        int count();
};

SinglyCLL::SinglyCLL()
{
    first = NULL;
    last = NULL;
    size = 0;
}

void SinglyCLL::insertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    
    last -> next = first;
    size++;
}

void SinglyCLL::insertLast(int iNo)
{
    PNODE newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        last = newn;
    }
    
    last -> next = first;
    size++;
}

void SinglyCLL::insertAtPos(int iNo, int iPos)
{
    if (iPos < 1 || iPos > (size + 1))
    {
        cout<<"Could not enter node at given position."<<endl;
        return;
    }

    if (iPos == 1)
    {
        insertFirst(iNo);
    }
    else if (iPos == (size + 1))
    {
        insertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        int iCnt = 1;
        PNODE current = first;

        newn -> data = iNo;
        newn -> next = NULL;

        while (iCnt < (iPos - 1))
        {
            current = current -> next;
            iCnt++;
        }
        
        newn -> next = current -> next;
        current -> next = newn;
        
        size++;
    }
}

void SinglyCLL::deleteFirst()
{
    if (first == NULL && last == NULL)
    {
        cout<<"Could not delete node."<<endl;
        return;
    }
    
    
    if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;
        last -> next = first;
    }

    size--;
}

void SinglyCLL::deleteLast()
{
    if (first == NULL && last == NULL)
    {
        cout<<"Could not delete node."<<endl;
        return;
    }

    if (first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE current = first;

        while (current -> next != last)
        {/* code */
            current = current -> next;
        }
        
        delete last;
        last = current;
        last -> next = first;
    }
    
    size--;
}

void SinglyCLL::deleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > size)
    {
        cout<<"Could not delete node."<<endl;
        return ;
    }

    if (iPos == 1)
    {
        deleteFirst();
    }
    else if (iPos == size)
    {
        deleteLast();
    }
    else
    {
        PNODE current = first, target = NULL;
        int iCnt = 1;

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        target = current -> next;
        current -> next = target -> next;
        delete target;
        
        size--;
    }    
}

void SinglyCLL::display()
{
    PNODE current = first;

    if (first != NULL && last != NULL)
    {
        do
        {
            cout<<"["<<current -> data<<"] -> ";
            current = current -> next;
        } while (current != last -> next);
    }
    
    cout<<endl;
}

int SinglyCLL::count()
{
    return size;
}

int main(int argc, char const *argv[])
{
    SinglyCLL obj;
    int iRet = 0;

    cout<<"Inserting 51, 21 & 11 at start.."<<endl;
    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 101 & 103 at start.."<<endl;
    obj.insertLast(101);
    obj.insertLast(103);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 99 at 4th position.."<<endl;
    obj.insertAtPos(99, 4);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 102 at 6th position.."<<endl;
    obj.insertAtPos(102, 6);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting first node.."<<endl;
    obj.deleteFirst();

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting last node.."<<endl;
    obj.deleteLast();

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting node at 3rd position.."<<endl;
    obj.deleteAtPos(3);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting node at 2nd position.."<<endl;
    obj.deleteAtPos(2);

    obj.display();
    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl<<endl;

    return 0;
}