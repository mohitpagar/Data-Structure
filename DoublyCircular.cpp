#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyCL
{
    public:
       PNODE First;
       PNODE Last;
       int iCount;

       DoublyCL();

       void InsertFirst(int no);
       void InsertLast(int no);
       void InsertAtPosition(int no, int ipos);

       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPosition(int no);

       void Display();
};

DoublyCL :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = NULL;
}

void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        iCount++;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
    First -> prev = Last;
    Last -> next = newn;
}

void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
        iCount++;
    }
    else
    {
       Last -> next = newn;
       newn -> prev = Last;
       Last = newn;
       iCount++;
    }

    First -> prev = Last;
    Last -> newn = First;
}

void DoublyCL :: InsertAtPosition(int no, int ipos)
{
    if((ipos < 1) || (ipos > iCount + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
        iCount++;
    }
    else if(ipos == iCount + 1)
    {
        InsertLast(no);
        iCount++;
    }
    else
    {
        PNODE newn = new NODE;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        PNODE temp = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        newn -> prev = temp;
        temp -> next = newn;
        iCount++;
    }
}

void DoublyCL:: DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
        iCount--;
    }
    else if(ipos == iCount)
    {
        DeleteLast();
        iCount--;
    }
    else
    {
        PNODE temp1 = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        PNODE temp2 = temp1 -> next;

        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;
        delete temp2;
        iCount--;
    }
}

void DoublyCL :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if( First == Last )
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        First = First -> next;
        delete Last -> next;

        First -> prev = Last;
        Last -> next = First;
        iCount--;
    }
}

void DoublyCL :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if( First == Last )
    {
        delete First;
        First = NULL;
        Last = NULL;
        iCount--;
    }
    else
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

void DoublyCL :: Display()
{
    PNODE temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

int main()
{
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";

    obj.InsertAtPosition(105,5);
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";
 
    obj.DeleteAtPosition(5);
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";

    obj.DeleteFirst();
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";

    obj.DeleteLast();
    obj.Display();
    cout<<"Nodes in doubly linear list are :"<<obj.iCount<<"\n";

    return 0;
}
