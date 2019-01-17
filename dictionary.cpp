#include<iostream>
#include<string>
using namespace std;

struct node
{
   string word,mean;
   node *l,*r;
};

class dictionary
{
    public:node *root,*temp,*nn,*parent,*temp_succ;

    dictionary()
    {
        root=NULL;
    }

    void create()
    {
        nn=new node;
        nn->l=nn->r=NULL;

        cout<<"\nEnter the word and its meaning that you want to store in BST :";
        cin>>nn->word>>nn->mean;

        if(root==NULL)
        {
            root=nn;
        }
        else
        {
            temp=root;

            while(temp!=NULL)
            {
                parent=temp;
                if(nn->word<temp->word)
                temp=temp->l;
                else
                temp=temp->r;
            }
            if(nn->word<parent->word)
            parent->l=nn;
            else
            parent->r=nn;
        }

    }
    void inorder_disp(node *temp)
    {
    	if(temp!=NULL)
    	{
    		inorder_disp(temp->l);
    		cout<<" "<<temp->word<<"--"<<temp->mean<<"\n";
    		inorder_disp(temp->r);
    	}
    }
    void preorder_disp(node *temp)
    {
    	if(temp!=NULL)
    	{
    		cout<<" "<<temp->word<<"--"<<temp->mean<<"\n";
    		preorder_disp(temp->l);
    		preorder_disp(temp->r);
    	}
    }
    void postorder_disp(node *temp)
    {
    	if(temp!=NULL)
    	{
    		postorder_disp(temp->l);
    		postorder_disp(temp->r);
    		cout<<" "<<temp->word<<"--"<<temp->mean<<"\n";
    	}
    }
    void search(string key)
    {
    	int flag=0;
    	temp=root;

    	while(temp!=NULL)
    	{
    		if(key==temp->word)
    		{	flag=1;
    			cout<<"\nKey found :"<<temp->word<<endl;
                break;
    		}
    		else if(key<temp->word)
    		{	parent=temp;
    			temp=temp->l;
    		}
    		else
    		{	parent=temp;
    			temp=temp->r;
    		}
    	}
    	if(flag==0)
    	{
    		cout<<"\nSORRY, Entered word is not found!"<<endl;
    	}

    }
    void update()
    {	cout<<"\nUpdation :\n";
        string key;
        cout<<"Enter the word whose meaning you want to update/modify in the dictionary :";
    	cin>>key;
    	search(key);

    	cout<<"\nEnter the new meaning of that word :";
    	cin>>temp->mean;
    }
    void deletef()
    {   string key;
        cout<<"\nEnter the word that you want to delete :";
        cin>>key;

        search(key);
        
        if(temp==NULL) //word is absent or there is no tree.
        {
                cout<<"\nDeletion aborted due to absence of word."<<endl; 
        }
        else if(temp==root)  //tree contains only root 
        {
               root=NULL;     
        }
        else
        {

                if(temp->l==NULL && temp->r==NULL)
                {
                        if(temp->word<parent->word)
                        parent->l=NULL;
                        else
                        parent->r=NULL;

                        cout<<"\nWord deleted."<<endl;
                }
                else if(temp->l!=NULL && temp->r==NULL)
                {
                        if(temp->word<parent->word)
                         parent->l=temp->l;
                        else
                        parent->r=temp->l;

                        cout<<"\nWord deleted."<<endl;
                }
                else if(temp->l==NULL && temp->r!=NULL)
                {
                        if(temp->word<parent->word)
                        parent->l=temp->r;
                        else
                        parent->r=temp->r;

                        cout<<"\nWord deleted."<<endl;
                }
                else if(temp->l!=NULL && temp->r!=NULL)
                {
                        temp_succ=temp->r;
                        parent=temp;

                        while(temp_succ->l!=NULL)
                        {
                                parent=temp_succ;
                                temp_succ=temp_succ->l;
                        }

                        temp->word=temp_succ->word; //IMPORTANT

                        if(parent->word==temp->word)
                        parent->r=NULL;
                        else if(parent->word!=temp->word)
                        parent->l=temp_succ->r;

                        cout<<"\nWord deleted."<<endl;
                }
                
         }       
    }
};

int main()
{
	int ch;
	string key;
	char z;
	dictionary d1;

	do
	{
		cout<<"\n*******DICTIONARY********\n";

		cout<<"\nEnter ";
		cout<<"\n1.To insert a node";
		cout<<"\n2.To display BST by inorder ";
		cout<<"\n3.To display BST by preorder ";
		cout<<"\n4.To display BST by postorder ";
		cout<<"\n5.To search a word ";
		cout<<"\n6.To update a word's meaning";
		cout<<"\n7.To delete a word :";
		cin>>ch;

		switch(ch)
		{
			case 1:d1.create();
			break;

			case 2:cout<<"\n WORD"<<"   MEANING\n";
			       d1.inorder_disp(d1.root);
			break;

			case 3: cout<<"\n WORD"<<"   MEANING\n";
				d1.preorder_disp(d1.root);
			break;

			case 4: cout<<"\n WORD"<<"   MEANING\n";
				d1.postorder_disp(d1.root);
			break;

			case 5: cout<<"\nEnter the word that you want to search in dictionary :";
                    cin>>key;
                    d1.search(key);
			break;

			case 6:d1.update();
			break;

			case 7:d1.deletef();
			break;

			default:cout<<"\nINVALID.";

		}
	cout<<"\nWant to continue? (Y/N) :";
	cin>>z;

	}while(z=='Y'||z=='y');
}
