#include<iostream>
using namespace std;

struct node
{
    int data;
    node *l,*r; //contains address of predecessor or successor or child
    int lth,rth; //contains 1 if node have left or right child
};

class TBT
{
public:node *dummy,*nn,*temp,*root,*parent;
    TBT()
    {
        dummy=new node;
        dummy->data=999;
        dummy->l=dummy->r=NULL;
        dummy->lth=dummy->rth=0;

        root=NULL;
    }
    void create_inorder()
    {
        nn=new node;
        cout<<"\nEnter the data to be inserted in the node :";
        cin>>nn->data;
        nn->r=nn->l=NULL;
        nn->lth=nn->rth=0;

        if(root==NULL)
        {
            root=nn;
            dummy->l=root;
            root->l=root->r=dummy;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                parent=temp;
                if(nn->data<temp->data)
                {
                    if(temp->lth==1)
                        temp=temp->l;
                    else
                        temp=NULL;
                }
                else if(nn->data>temp->data)
                {
                    if(temp->rth==1)
                        temp=temp->r;
                    else
                        temp=NULL;
                }
            }

            if(nn->data<parent->data)
            {
                nn->l=parent->l;
                nn->r=parent;
                parent->l=nn;
                parent->lth=1;
            }
            else
            {
                nn->r=parent->r;
                nn->l=parent;
                parent->r=nn;
                parent->rth=1;
            }
        }
    }
    void display_inorder()
    {
        temp=root;

        while(1)
        {
            while(temp->lth==1)
            {
                temp=temp->l;
            }
            cout<<" "<<temp->data;
            while(temp->rth==0)
            {
                if(temp->r==dummy)
                    return;
                else
                {
                    temp=temp->r;
                    cout<<" "<<temp->data;
                }
            }
            temp=temp->r;
        }

    }
};
int main()
{
    TBT t1;
    int ch,key;
    char z;

    do
    {
        cout<<"\n********THREADED BINARY(SEARCH) TREE***********\n";
        cout<<"\nEnter your choice :";
        cout<<"\n1.To insert a node in the TBT";
        cout<<"\n2.To display TBT by inorder (without recursion) :";
        cin>>ch;

        switch(ch)
        {
        case 1: t1.create_inorder();
        break;

        case 2: t1.display_inorder();
        break;

        default:cout<<"\n Invalid.";
        }
        cout<<"\nWant to continue? (Y/N) :";
        cin>>z;
    }while(z=='y' || z=='Y');

}
