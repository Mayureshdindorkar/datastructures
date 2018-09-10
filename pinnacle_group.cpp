#include<iostream>
#include<string>
using namespace std;

class node
{   public:
	int prn;
	string name;
	node *next;

};

class list
{   private:node *nn;
	public: node *header;
            int n;
            static int count;

	list()
	{
		header=NULL;
	}

	void insertstart()
	{   count++;
		nn=new node;
		node *cn;

		cout<<" Enter the name of president : ";
		cin>>nn->name;


		cout<<" Enter the prn number :";
		cin>>nn->prn;

		if(header==NULL)
		{
			header=nn;
			nn->next=NULL;
		}

		else
		{
			nn->next=header;
			header=nn;

		}

	}

	void insertend()
	{   count++;
		node *cn;

		nn=new node;

		cout<<" Enter the name of member ";
		cin>>nn->name;

		cout<<" Enter the prn number "<<endl;
		cin>>nn->prn;

		if(header==NULL)
				{
					header=nn;
					nn->next=NULL;
				}

        cn=header;
		while(cn->next!=NULL)
		{
			cn=cn->next;

		}cn->next=nn;
		nn->next=NULL;

    }

	void insertany()
	{   count++;
	    nn=new node;
		node *temp4;


		cout<<" Enter position at which you want to insert new member "<<endl;
                cin>>n;

		if(n==1)
		{
			insertstart();
		}

		else{   temp4=header;

                cout<<" Enter the name of member ";
                cin>>nn->name;

                cout<<" Enter the prn number "<<endl;
                cin>>nn->prn;

				for(int i=1;i<n-1;i++)
					{
						temp4=temp4->next;
					}nn->next=temp4->next;
					temp4->next=nn;

		     }

	}

    void delstart()
    {
        header=header->next;
         count--;
    }

 void delend()
    {
        node *cn,*temp;
        temp=header;
        cn=header->next;

        while(cn->next!=NULL)
        {
            cn=cn->next;
            temp=temp->next;
        }
        temp->next=NULL;

         count--;
    }

 void delany()
    {   int m;
        node *cn;
        cn=header;
        cout<<" Enter position number of element you want to delete "<<endl;
        cin>>m;
        if(m==1)
        {
            delstart();
        }

     else {   for(int i=1;i<m-1;i++)
            {
                cn=cn->next;

            }cn->next=cn->next->next;

          }
          count--;
    }


	int retcount()
	{
		cout<<" Total number of members in the pinnacle group are :"<<count<<endl;

	}
	void rev(node* sn)  //RECURSIVE FUNCTION CALL.
	{
		if(sn->next!=NULL)
		{
			rev(sn->next);

		}

		cout<<"\nName is :"<<sn->name<<endl;
		cout<<"\nRoll number is :"<<sn->prn<<endl;
	}


    void put()
    {
         node *cn;


		cout<<"\n PRESIDENT NAME:"<<header->name;
		cout<<"\n PRESIDENT PRN:"<<header->prn;

        cout<<"\n**************************";

		cn=header->next;
		while(cn->next!=NULL)
		{

				cout<<"\n\n MEMBER NAME:"<<cn->name;
				cout<<"\n MEMBER PRN:"<<cn->prn;
				cn=cn->next;

		}

		cout<<"\n****************************";

		cout<<"\n SECRETARY NAME :"<<cn->name;
		cout<<"\n SECRETARY PRN :"<<cn->prn;

    }

	void join(node *sn)		//parameter receives header of l2
	{
        node *fn;
		fn=header;		//header of first

		while(fn->next!=NULL)
		{
			fn=fn->next;
		}
        fn->next=sn;
        put();

	}

};int list::count;


int main()
{
	list l1,l2;


	int ch,h,m;
	char z;
	cout<<"\nSINGLY LINKED LIST";
	cout<<"****DEPARTMENT OF COMPUTER ENGINEERING****"<<endl;
	cout<<"---------PINNACLE GROUP---------";
	do
{

	cout<<" \nEnter \n1.Insert president at start. \n2.Insert secretary at end. \n3.Insert new member at any position. \n4.Cancel membership of the presedent at start. \n5.Cancel membership of the secretary at end. \n6.Cancel membership of a member at any particular position. \n7.To display total number of members in group PINNACLE. \n8.Reversing the list \n9.Display list \n10.To join two lists."<<endl;
	cin>>ch;


	switch(ch)
	{
            case 1:l1.insertstart();
            break;

            case 2:l1.insertend();
            break;

            case 3:l1.insertany();
            break;

            case 4:l1.delstart();
            break;

            case 5:l1.delend();
            break;

            case 6:l1.delany();
            break;

            case 7:l1.retcount();
            break;

            case 8:l1.rev(l1.header);
            break;


            case 9:l1.put();
                break;

            case 10:	cout<<"\n  Insert first list \n";

			l1.insertstart();
		   	h=1;
				while(h==1)
				{
					l1.insertend();
					cout<<"\n 1. to add another member else 0\n";
					cin>>h;
				}

				cout<<"\n  Insert second list \n";

		    		l2.insertstart();
				m=1;
				while(m==1)
				{
					l2.insertend();
					cout<<"\n 1. to add another member else 0\n";
					cin>>m;
				}

		    		l1.join(l2.header);
                    break;


            default :cout<<"\n !!!!SORRY!!!! \n";
            break;


	}cout<<" \nEnter y for another operation else n "<<endl;
	cin>>z;

}while(z=='y' || z=='Y');

}
