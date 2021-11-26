#include <iostream>
using namespace std;

#define INTEGER_CHOICE 1
#define FLOAT_CHOICE 2
#define CHAR_CHOICE 3
#define EXIT_CHOICE 4

template <typename T>
struct node
{
    T data;
    node<T> * next;  
};

template <class T>
class SinglyLinearLinkedList
{
    private:
        int size;
        node<T> * first;

    public:
        SinglyLinearLinkedList();
        void insertFirst(T);
        void insertLast(T);
        void insertAtPos(T, int);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int);
        void display();
        int count();
};

template <class T>
SinglyLinearLinkedList<T>::SinglyLinearLinkedList()
{
    size = 0;
    first = NULL;
}

template <class T>
void SinglyLinearLinkedList<T>::insertFirst(T data)
{
    node<T> * newn = new node<T>;

    newn -> data = data;
    newn -> next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    
    size++;
}

template <class T>
void SinglyLinearLinkedList<T>::insertLast(T data)
{
    node<T> * newn = new node<T>;

    newn -> data = data;
    newn -> next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        node<T> * current = first;

        while (current -> next != NULL)
        {
            current = current -> next;
        }
        
        current -> next = newn;
    }
    
    size++;
}

template <class T>
void SinglyLinearLinkedList<T>::insertAtPos(T data, int iPos)
{
    if (iPos < 1 || iPos > (size + 1))
    {
        cout<<"Could not insert node at desired position."<<endl;
        return ;
    }
    
    if (iPos == 1)
    {
        insertFirst(data);
    }
    else if (iPos == (size + 1))
    {
        insertLast(data);
    }
    else
    {
        node<T> * newn = new node<T>;

        newn -> data = data;
        newn -> next = NULL;

        int iCnt = 1;
        node<T> * current = first;

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            current = current -> next;
        }
        
        newn -> next = current -> next;
        current -> next = newn;

        size++;
    }
    
}

template <class T>
void SinglyLinearLinkedList<T>::deleteFirst()
{
    if (first == NULL)
    {
        cout<<"Could not delete node."<<endl;
        return ;
    }

    if (first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node<T> * temp = first;
        first = first -> next;
        delete temp;
    }
    
    size--;
}

template <class T>
void SinglyLinearLinkedList<T>::deleteLast()
{
    if (first == NULL)
    {
        cout<<"Could not delete node."<<endl;
        return ;
    }
    
    if (first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        node<T> * temp = first;

        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        
        delete temp -> next;
        temp -> next = NULL;
    }

    size--;
}

template <class T>
void SinglyLinearLinkedList<T>::deleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > size)
    {
        cout<<"Could not delete node at desired position."<<endl;
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
        node<T> * temp = first;
        node<T> * target = NULL;
        int iCnt = 1;

        while (iCnt < (iPos - 1))
        {
            iCnt++;
            temp = temp -> next;
        }
        
        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        size--;
    }
    
}

template <class T>
void SinglyLinearLinkedList<T>::display()
{
    node<T> * current = first;

    while (current != NULL)
    {
        cout<<"["<<current -> data<<"] -> ";
        current = current -> next;
    }
    
    cout<<"[NULL]"<<endl;
}

template <class T>
int SinglyLinearLinkedList<T>::count()
{
    return size;
}

int main(int argc, char const *argv[])
{
    int iTChoice = 1, iOChoice = 1, iRet = 0, iPos = 0;
    int iInput = 0;
    float fInput = 0.0;
    char cInput = '\0';
    SinglyLinearLinkedList<int> iObj;
    SinglyLinearLinkedList<float> fObj;
    SinglyLinearLinkedList<char> cObj;

    while (iTChoice)
    {
        cout<<"*********************************************************************"<<endl;
        cout<<"Select one of the types below to test Generic Linked List app."<<endl;
        cout<<"*********************************************************************"<<endl;
        cout<<"1. Integer"<<endl;
        cout<<"2. Float"<<endl;
        cout<<"3. Char"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>iTChoice;

        if (iTChoice == EXIT_CHOICE)
        {
            cout<<"---------------------------------------------------------------------"<<endl;
            cout<<"Thank you for using Mukunda's Simple Generic Linked List app."<<endl;
            iTChoice = 0;
        }
        else if (iTChoice >= 1 || iTChoice <= 3)
        {
            iOChoice = 1;
            while (iOChoice)
            {
                cout<<"====================================================================="<<endl;
                cout<<"Select your choice from below options:"<<endl;
                cout<<"---------------------------------------------------------------------"<<endl;
                cout<<"1. Insert First."<<endl;
                cout<<"2. Insert Last"<<endl;
                cout<<"3. Insert At Position"<<endl;
                cout<<"4. Delete First"<<endl;
                cout<<"5. Delete Last"<<endl;
                cout<<"6. Delete At Position"<<endl;
                cout<<"7. Display"<<endl;
                cout<<"8. Count Nodes"<<endl;
                cout<<"9. Change Type Choice"<<endl;
                cout<<"0. Exit"<<endl;
                cout<<"---------------------------------------------------------------------"<<endl;
                cout<<"Enter your choice: ";
                cin>>iOChoice;
                cout<<"---------------------------------------------------------------------"<<endl;

                switch (iOChoice)
                {
                    // Enter at first
                    case 1:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            cout<<"Enter a integer number: ";
                            cin>>iInput;
                            iObj.insertFirst(iInput);
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            cout<<"Enter a float number: ";
                            cin>>fInput;
                            fObj.insertFirst(fInput);
                        }
                        else
                        {
                            cout<<"Enter a character: ";
                            cin>>cInput;
                            cObj.insertFirst(cInput);
                        }
                        
                        break;

                    // Enter at last
                    case 2:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            cout<<"Enter a integer number: ";
                            cin>>iInput;
                            iObj.insertLast(iInput);
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            cout<<"Enter a float number: ";
                            cin>>fInput;
                            fObj.insertLast(fInput);
                        }
                        else
                        {
                            cout<<"Enter a character: ";
                            cin>>cInput;
                            cObj.insertLast(cInput);
                        }
                        
                        break;

                    // Enter at position
                    case 3:
                        cout<<"Enter position you want to insert to: ";
                        cin>>iPos;

                        if (iTChoice == INTEGER_CHOICE)
                        {
                            cout<<"Enter a integer number: ";
                            cin>>iInput;
                            iObj.insertAtPos(iInput, iPos);
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            cout<<"Enter a float number: ";
                            cin>>fInput;
                            fObj.insertAtPos(fInput, iPos);
                        }
                        else
                        {
                            cout<<"Enter a character: ";
                            cin>>cInput;
                            cObj.insertAtPos(cInput, iPos);
                        }
                        
                        break;

                    // Delete first
                    case 4:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            iObj.deleteFirst();
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            fObj.deleteFirst();
                        }
                        else
                        {
                            cObj.deleteFirst();
                        }
                        
                        break;

                    // Delete last
                    case 5:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            iObj.deleteLast();
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            fObj.deleteLast();
                        }
                        else
                        {
                            cObj.deleteLast();
                        }
                        
                        break;

                    // Delete at position
                    case 6:
                        cout<<"Enter position you want to delete: ";
                        cin>>iPos;

                        if (iTChoice == INTEGER_CHOICE)
                        {
                            iObj.deleteAtPos(iPos);
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            fObj.deleteAtPos(iPos);
                        }
                        else
                        {
                            cObj.deleteAtPos(iPos);
                        }
                        
                        break;

                    // Display linked list
                    case 7:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            iObj.display();
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            fObj.display();
                        }
                        else
                        {
                            cObj.display();
                        }
                        
                        break;

                    // Count nodes
                    case 8:
                        if (iTChoice == INTEGER_CHOICE)
                        {
                            iRet = iObj.count();
                        }
                        else if (iTChoice == FLOAT_CHOICE)
                        {
                            iRet = fObj.count();
                        }
                        else
                        {
                            iRet = cObj.count();
                        }
                        
                        cout<<"Total nodes in the Linked List: "<<iRet<<endl;
                        break;

                    // Change the type choice
                    case 9:
                        iOChoice = 0;
                        break;

                    // Exit application
                    case 0:
                        iOChoice = 0;
                        iTChoice = 0;
                        cout<<"Thank you for using Mukunda's Simple Generic Linked List app."<<endl;
                        break;
                    
                    default:
                        cout<<"Please select a valid choice."<<endl;
                        break;
                }

                cout<<"====================================================================="<<endl;
            }
        }
        else
        {
            cout<<"---------------------------------------------------------------------"<<endl;
            cout<<"Please enter a valid choice of the type."<<endl;
        }
        cout<<"*********************************************************************"<<endl;
    }    

    return 0;
}
