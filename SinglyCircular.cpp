#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node  * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
    public:
       PNODE First;
       PNODE Last;
       int iCount;

       SinglyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
};

SinglyCL :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = NULL;
}

void SinglyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Last = newn;
        Last -> next = First;
        iCount++;
    }
    else
    {
        newn -> next = First;
        First = newn;
        Last -> next = First;
        iCount++;
    }
}

void SinglyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;

    newn -> data = no;
    newn -> next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Last = newn;
        Last -> next = First;
        iCount++;
    }
    else
    {
        Last -> next = newn; 
        Last = newn;
        Last -> next = First;
        iCount++;
    }
}

void SinglyCL :: InsertAtPos(int no, int ipos)
{
    if((ipos < 1) || (ipos > iCount +1 ))
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

        PNODE temp = First;

        for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    } 
}

void SinglyCL :: DeleteFirst()
{
    PNODE temp = First;

    if((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
        iCount--;
    }
    else
    {
        First = temp -> next;
        delete temp;
        Last -> next = First;
        iCount--;
    }
}

void SinglyCL :: DeleteLast()
{
    PNODE temp = First;

    if((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
        iCount--;
    }
    else
    {
        while(temp -> next != Last)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        Last = temp;
        Last -> next = First;
    }
}

void SinglyCL :: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > iCount))
    {
        cout<<"Invalid Position \n";
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

        for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        PNODE temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;
        iCount--;
    }
}

void SinglyCL::Display()
{
    PNODE temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

int main()
{
    SinglyCL obj;

    int iRet = 0;
    
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"Number of elements are : "<<obj.iCount<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();
    cout<<"Number of elements are : "<<obj.iCount<<"\n";

    obj.InsertAtPos(105,5);
    obj.Display();
    cout<<"Number of elements are : "<<obj.iCount<<"\n";

    obj.DeleteAtPos(5);
    obj.Display();
    
    cout<<"Number of elements are : "<<obj.iCount<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();
    obj.Display();
    cout<<"Number of elements are : "<<obj.iCount<<"\n";

    return 0;
}