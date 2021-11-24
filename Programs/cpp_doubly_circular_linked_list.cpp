#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} NODE, * PNODE;

class DoublyCLL
{
    private:
        int size;
        PNODE first;
        PNODE last;

    public:
        DoublyCLL();
        void insertFirst(int);
        void insertLast(int);
        void insertAtPos(int, int);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int);
        void display();
        void displayReverse();
        int count();
};

DoublyCLL::DoublyCLL()
{
    size = 0;
    first = NULL;
    last = NULL;
}

void DoublyCLL::insertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last -> next = first;
    first -> prev = last;

    size++;
}

void DoublyCLL::insertLast(int iNo)
{
    PNODE newn = new NODE;

    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> prev = last;
        last -> next = newn;
        last = newn;
    }

    last -> next = first;
    first -> prev = last;

    size++;    
}

void DoublyCLL::insertAtPos(int iNo, int iPos)
{
    if (iPos < 1 || iPos > (size + 1))
    {
        cout<<"Could not insert node."<<endl;
        return ;
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
        PNODE current = first;
        int iCnt = 1;

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

        size++;
    }    
}

void DoublyCLL::deleteFirst()
{
    if (first == NULL && last == NULL)
    {
        cout<<"Could not delete node."<<endl;
        return ;
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
        delete first -> prev;

        last -> next = first;
        first -> prev = last;
    }

    size--;
}

void DoublyCLL::deleteLast()
{
    if (first == NULL && last == NULL)
    {
        cout<<"Could not delete node.."<<endl;
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
        last = last -> prev;
        delete last -> next;

        last -> next = first;
        first -> prev = last;
    }
    
    size--;
}

void DoublyCLL::deleteAtPos(int iPos)
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
        PNODE current = first;
        int iCnt = 1;

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        current -> next = current -> next -> next;
        delete current -> next -> prev;
        current -> next -> prev = current;

        size--;
    }
    
}

void DoublyCLL::display()
{
    if (first != NULL && last != NULL)
    {
        PNODE current = first;

        do
        {
            cout<<"["<<current -> data<<"] <==> ";
            current = current -> next;
        } while (current != last -> next);
    }

    cout<<endl;    
}

void DoublyCLL::displayReverse()
{
    if (first != NULL && last != NULL)
    {
        PNODE current = last;
        
        do
        {
            cout<<"["<<current -> data<<"] <==> ";
            current = current -> prev;
        } while (current != first -> prev);
    }
    
    cout<<endl;
}

int DoublyCLL::count()
{
    return size;
}

int main(int argc, char const *argv[])
{
    DoublyCLL obj;
    int iRet = 0;

    cout<<"Inserting 51, 21 & 11 at first.."<<endl;
    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 101 & 103 at last.."<<endl;
    obj.insertLast(101);
    obj.insertLast(103);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 99 at 4th position.."<<endl;
    obj.insertAtPos(99, 4);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Inserting 102 at 6th position.."<<endl;
    obj.insertAtPos(102, 6);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting first node.."<<endl;
    obj.deleteFirst();

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting last node.."<<endl;
    obj.deleteLast();

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting 3rd node.."<<endl;
    obj.deleteAtPos(3);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    cout<<"Deleting 2nd node.."<<endl;
    obj.deleteAtPos(2);

    obj.display();
    obj.displayReverse();
    iRet = obj.count();
    cout<<"Total nodes in Linked List: "<<iRet<<endl<<endl;

    return 0;
}