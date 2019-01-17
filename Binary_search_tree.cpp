#include<iostream>
using namespace std;

struct node
{
   node *left;
   int data;
   node *right;
};

class BST
{
public:node *root,*nn,*temp,*parent; //IMPORTANT
    BST()
    {
        root=NULL;
    }
    void insert()
    {
        nn=new node;
        nn->left=nn->right=NULL;
        cout<<"\nEnter the data that you want to insert in BST :";
        cin>>nn->data;

        if(root==NULL)
        {
            root=nn;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {   parent=temp;
                if(nn->data<temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
            if(nn->data<parent->data)
                parent->left=nn;
            else
                parent->right=nn;
        }
    }
    void rec_inorder_display(node *temp)
    {
        if(temp!=NULL)
        {
            rec_inorder_display(temp->left);
            cout<<" "<<temp->data;
            rec_inorder_display(temp->right);
        }
    }
    void rec_preorder_display(node *temp)
    {
        if(temp!=NULL)
        {   cout<<" "<<temp->data;
            rec_preorder_display(temp->left);
            rec_preorder_display(temp->right);
        }
    }
    void rec_postorder_display(node *temp)
    {
        if(temp!=NULL)
        {
            rec_postorder_display(temp->left);
            rec_postorder_display(temp->right);
            cout<<" "<<temp->data;
        }
    }
    void search(int key)
    {
        int flag=0;

        temp=root;
        while(temp!=NULL)
        {
            if(key==temp->data)
            {
                cout<<"\nKey found in BST! "<<temp->data;
                flag=1;
                break;
            }
            else if(key<temp->data)
            {   parent=temp;
                temp=temp->left;
            }
            else
            {   parent=temp;
                temp=temp->right;
            }
        }
        if(flag==0)
        {
            cout<<"\nSorry! Key not found in BST.";
        }
    }
    void deletef()
    {   if(root==NULL)
        {
            cout<<"\nBST is empty.";
        }
        else
        {
            int key;
            cout<<"\nEnter the key you want to delete :";
            cin>>key;

            search(key);
            //Je node delete karayache ahe tyacha ani tyachya immediate parentcha address aaplyala temp ani parentmadhe resp. milel
            //search mule.
            //1.Node to be deleted have no child
            if(temp->left==NULL && temp->right==NULL)
            {
                if(temp->data<parent->data)
                    parent->left=NULL;
                else
                    parent->right=NULL;
                cout<<"\nValue deleted.";
            }//2.1.Node to be deleted have one left child
            else if(temp->left!=NULL && temp->right==NULL)
            {
                if(temp->data<parent->data)
                    parent->left=temp->left;
                else
                    parent->right=temp->left;
                    cout<<"\nValue deleted.";
            }//2.2.Node to be deleted have one right child
            else if(temp->left==NULL && temp->right!=NULL)
            {
                if(temp->data<parent->data)
                    parent->left=temp->right;
                else
                    parent->right=temp->right;
                cout<<"\nValue deleted.";
            }//3.Node to be deleted have two child
            else if(temp->left!=NULL && temp->right!=NULL)
            {
                node *temp_succ;

                parent=temp;
                temp_succ=temp->right;

                while(temp_succ->left!=NULL)
                {
                    parent=temp_succ;
                    temp_succ=temp_succ->left;
                }
                temp->data=temp_succ->data;

                if(temp->data==parent->data)
                    temp->right=NULL;
                else if(temp->data!=parent->data)
                    parent->left=temp_succ->right;

                cout<<"\nValue deleted.";
            }
        }


    }
};
int main()
{
    BST b1;
    int ch,key;
    char z;

    do
    {
        cout<<"\n********BINARY SEARCH TREE***********\n";
        cout<<"\nEnter your choice :";
        cout<<"\n1.To insert a node in the BST";
        cout<<"\n2.To display BST by recursive inorder";
        cout<<"\n3.To display BST by recursive preorder";
        cout<<"\n4.To display BST by recursive postorder";
        cout<<"\n5.To search an element";
        cout<<"\n6.To delete a value from BST :";
        cin>>ch;

        switch(ch)
        {
        case 1: b1.insert();
        break;

        case 2: b1.rec_inorder_display(b1.root);
        break;

        case 3: b1.rec_preorder_display(b1.root);
        break;

        case 4: b1.rec_postorder_display(b1.root);
        break;

        case 5: cout<<"\nEnter the key you want to search :";
                cin>>key;
                b1.search(key);
        break;

        case 6: b1.deletef();
        break;

        default:cout<<"\n Invalid.";
        }
        cout<<"\nWant to continue? (Y/N) :";
        cin>>z;
    }while(z=='y' || z=='Y');
}
