#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} NODE, * PNODE;

class SinglyLL
{
    private: 
        int size;
        PNODE first;

    public:
        SinglyLL()
        {
            size = 0;
            first = NULL;
        }

        void insertFirst(int iNo)
        {
            cout<<"Inserting a new node.."<<endl;

            PNODE newn = new NODE;

            newn -> data = iNo;
            newn -> next = NULL;

            if (first != NULL)
            {
                newn -> next = first;
            }
            
            first = newn;

            size++;

            cout<<"Success - New node inserted"<<endl;
        }

        void insertLast(int iNo)
        {
            cout<<"Inserting a new node.."<<endl;

            PNODE newn = new NODE;
            PNODE current = first;

            newn -> data = iNo;
            newn -> next = NULL;

            if (first == NULL)
            {
                first = newn;
            }
            else
            {
                while (current -> next != NULL)
                {
                    current = current -> next;
                }
                
                current -> next = newn;
            }
            
            size++;

            cout<<"Success - New node inserted"<<endl;
        }

        void insertAtPos(int iNo, int iPos)
        {
            if ((iPos < 1) || (iPos > (size + 1)))
            {
                cout<<"Could not add a node to the given position."<<endl;
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
                cout<<"Inserting a new node.."<<endl;

                PNODE newn = new NODE;

                newn -> data = iNo;
                newn -> next = NULL;

                int iCnt = 1;
                PNODE current = first;

                while (iCnt < (iPos - 1))
                {
                    iCnt++;
                    current = current -> next;
                }
                
                newn -> next = current -> next;
                current -> next = newn;

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
                PNODE current = first;
                PNODE temp = NULL;
                int iCnt = 1;

                while (iCnt < (iPos - 1))
                {
                    iCnt++;
                    current = current -> next;
                }
                
                temp = current -> next;
                current -> next = temp -> next;
                delete temp;

                size--;
                cout<<"Success - Node deleted"<<endl;
            }
        }

        void display()
        {
            PNODE current = first;

            while (current != NULL)
            {
                cout<<"["<<current -> data <<"] -> ";
                current = current -> next;
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
    SinglyLL obj;
    int iRet = 0;

    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);

    obj.insertLast(101);
    obj.insertLast(105);

    obj.insertAtPos(103, 4);
    obj.insertAtPos(99, 2);

    obj.display();
    
    obj.deleteFirst();
    obj.deleteLast();

    obj.display();

    obj.deleteAtPos(4);
    obj.display();
    obj.deleteAtPos(2);
    obj.display();

    iRet = obj.count();
    cout<<"Total nodes in the Linked List: "<<iRet<<endl;

    return 0;
}
