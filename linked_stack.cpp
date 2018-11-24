#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
public: node *top;
        node *nn;
    list()
    {
        top=NULL;
    }
    void push(int item)
    {
        nn=new node;
        nn->data=item;
        nn->next=NULL;
        if(top==NULL)
        {
            top=nn;
        }
        else
        {
            nn->next=top;
            top=nn;
        }
    }
    int pop()
    {
        if(top==NULL)
        {
            cout<<"\nStack is empty.";
        }
        else
        {
            int z=top->data;
            top=top->next;
            return z;
        }
    }
    void display()
    {
        if(top==NULL)
        {
            cout<<"\nStack is empty.";
        }
        else
        {
            node *cn;
            cn=top;
            do
            {
                cout<<cn->data<<" ";
                cn=cn->next;
            }while(cn!=NULL);
        }
    }
};
int main()
{   list l1;
    int ch,item;
    char z;
    do
    {
    cout<<"\n*****STACK BY SLL******\n";
    cout<<"\nEnter";
    cout<<"\n1.Push";
    cout<<"\n2.Pop";
    cout<<"\n3.Display :";
    cin>>ch;

    switch(ch)
    {
        case 1: cout<<"\nEnter the data :";
                cin>>item;
                l1.push(item);
        break;

        case 2: cout<<"\nPoped value :"<<l1.pop();
        break;

        case 3: l1.display();
        break;

        default:cout<<"\nINVALID.";
    }
    cout<<"\n(Y/N) :";
    cin>>z;
    }while(z=='y'||z=='Y');
}
