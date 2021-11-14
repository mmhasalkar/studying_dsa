#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
} NODE, * PNODE;

class DoublyLL
{
    private:
        int size;
        PNODE first;

    public:
        DoublyLL()
        {
            size = 0;
            first = NULL;
        }

        void insertFirst(int iNo)
        {
            cout<<"Inserting a new node.."<<endl;

            PNODE newn = new NODE;

            newn -> next = NULL;
            newn -> prev = NULL;
            newn -> data = iNo;

            if (first != NULL)
            {
                newn -> next = first;
                first -> prev = newn;
            }
            
            first = newn;
            size++;

            cout<<"Success - New node inserted."<<endl;
        }

        void insertLast(int iNo)
        {
            cout<<"Inserting a new node.."<<endl;
            PNODE newn = new NODE;

            newn -> data = iNo;
            newn -> next = NULL;
            newn -> prev = NULL;

            if (first == NULL)
            {
                first = newn;
            }
            else
            {
                PNODE current = first;

                while (current -> next != NULL)
                {
                    current = current -> next;
                }
                
                current -> next = newn;
                newn -> prev = current;
            }

            size++;
            cout<<"Success - New node inserted."<<endl;
        }

        void insertAtPos(int iNo, int iPos)
        {
            if (iPos < 1 || iPos > (size + 1))
            {
                cout<<"Could not insert node at given position."<<endl;
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
                cout<<"Inserting new node.."<<endl;
                PNODE newn = new NODE;

                newn -> data = iNo;
                newn -> next = NULL;
                newn -> prev = NULL;

                PNODE current = first;
                int iCnt = 1;

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
                cout<<"Success - New node inserted"<<endl;
            }
            
        }

        void deleteFirst()
        {
            if (first == NULL)
            {
                cout<<"Could not delete the node."<<endl;
                return ;
            }

            cout<<"Deleting node.."<<endl;

            PNODE temp = first;
            first = first -> next;
            delete temp;
            if (first != NULL)
            {
                first -> prev = NULL;
            }

            size--;
            cout<<"Success - Node deleted"<<endl;
        }

        void deleteLast()
        {
            if (first == NULL)
            {
                cout<<"Could not delete the node."<<endl;
                return ;
            }

            cout<<"Deleting node.."<<endl;

            if (first -> next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                PNODE current = first;

                while (current -> next -> next != NULL)
                {
                    current = current -> next;
                }
                delete current -> next;
                current -> next = NULL;
            }

            size--;
            cout<<"Success - Node deleted"<<endl;
        }

        void deleteAtPos(int iPos)
        {
            if (iPos < 1 || iPos > size)
            {
                cout<<"Could not delete node at given position."<<endl;
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
                cout<<"Deleting node.."<<endl;

                int iCnt = 1;
                PNODE current = first;

                while (iCnt < (iPos - 1))
                {
                    iCnt++;
                    current = current -> next;
                }
                
                current -> next = current -> next -> next;
                delete current -> next -> prev;
                current -> next -> prev = current;

                size--;
                cout<<"Success - Node deleted"<<endl;
            }
        }

        void display()
        {
            PNODE current = first;

            while (current != NULL)
            {
                cout<<"["<<current -> data<<"] <==> ";
                current = current -> next;
            }
            
            cout<<"[NULL]"<<endl;
        }

        void displayReverse()
        {
            PNODE current = first;

            while (current != NULL && current -> next != NULL)
            {
                current = current -> next;
            }
            
            while (current != NULL)
            {
                cout<<"["<<current -> data<<"] <==> ";
                current = current -> prev;
            }
            
            cout<<"[NULL]"<<endl;
        }

        int count()
        {
            return size;
        }
};

int main(int argc, char const *argv[])
{
    DoublyLL obj;
    int iRet = 0;

    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);

    obj.insertLast(101);
    obj.insertLast(105);

    obj.insertAtPos(103, 4);
    obj.insertAtPos(99, 2);

    obj.display();
    obj.displayReverse();
    
    obj.deleteFirst();
    obj.deleteLast();

    obj.display();
    obj.displayReverse();

    obj.deleteAtPos(4);
    obj.display();
    obj.displayReverse();
    obj.deleteAtPos(2);
    obj.display();
    obj.displayReverse();

    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl;

    return 0;
}
