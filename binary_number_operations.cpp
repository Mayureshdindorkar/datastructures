#include<iostream>
using namespace std;

class node
{   public:
	node *next;
	int bit;
    node *prev;
};

class list
{
	private:node *header;
            node *nn;
            node *cn;

            int nb;

	public:list()
		{
			header=NULL;
		}

	void insertend()
	{
		cout<<"\nEnter number of bits in binary number: ";
		cin>>nb;
        cout<<"\nEnter bits from MSB to LSB.\n";

		for(int i=0;i<nb;i++)
		{
			nn=new node;
			cout<<"\nEnter the individual bit ";
			cin>>nn->bit;
			nn->prev=nn->next=NULL;

			if(header==NULL)
			{
				header=nn;
			}
			else
			{
				cn=header;
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}cn->next=nn;
				nn->prev=cn;        //for making doubly list.

			}
		}
		cout<<"\n Binary number is :\t";
	}

	void oncecomp()
	{
        cn=header;

		while(cn!=NULL)
		{
			if(cn->bit==0)
			{	cn->bit=1;
			}
			else
			{	cn->bit=0;
			}

			cn=cn->next;
		}
            cout<<"\n One's complement is :\n";
	}

	void towscomp()
	{
	    oncecomp();         //IMPORTANT STEP.
        display();

		cn=header;

		while(cn->next!=NULL)
		{
			cn=cn->next;
		}

        while(cn!=NULL)
        {
                if(cn->bit==0)
                   {    cn->bit=1;
                        break;  //important.
                   }
                else if(cn->bit==1)
                       {
                         cn->bit=0;
                       }
                cn=cn->prev;
        }
            cout<<"\nTwo's complement is :\n";
	}

	void display()
	{
		cn=header;

		while(cn!=NULL)
		{
			cout<<cn->bit<<" ";
			cn=cn->next;
		}

	}

    void add(list l3,list l4)
	{
	    node *cn1,*cn2;

        int carry=0,sum=0;

        cn1=l3.header;
        cn2=l4.header;

        while(cn1->next!=NULL)  //traverse to last node of l3
        {
            cn1=cn1->next;
        }
        while(cn2->next!=NULL)     //traverse to last node of l4
        {
            cn2=cn2->next;
        }

        while(cn1!=NULL && cn2!=NULL)
        {
            nn=new node;
            sum=(cn1->bit + cn2->bit +carry)%2;
            carry=(cn1->bit + cn2->bit +carry)/2;

            cn1=cn1->prev;
            cn2=cn2->prev;
            nn->bit=sum;

            //IMPORTANT insert at start.
		if(header==NULL)       //header of l5 object.
		{
         		header=nn;
                nn->prev=nn->next=NULL;
        }
		else
		{
			nn->prev=NULL;
			nn->next=header;
			header->prev=nn;
			header=nn;

		}
	}
	while(cn1!=NULL)
	{
            nn=new node;
            sum=(cn1->bit +carry)%2;
            carry=(cn1->bit +carry)/2;

            cn1=cn1->prev;

            nn->bit=sum;
        //insert at start.
		if(header==NULL)
		{
         		header=nn;
                nn->prev=nn->next=NULL;
        }
		else
		{
			nn->prev=NULL;
			nn->next=header;
			header->prev=nn;
			header=nn;

		}

	}
	while(cn2!=NULL)
	{
            nn=new node;
            sum=(cn2->bit +carry)%2;
            carry=(cn2->bit +carry)/2;


            cn2=cn2->prev;
            nn->bit=sum;
        //insert at start.
		if(header==NULL)
		{
         		header=nn;
                nn->prev=nn->next=NULL;
        }
		else
		{
			nn->prev=NULL;
			nn->next=header;
			header->prev=nn;
			header=nn;

		}

	}

	if(carry==1)
	{
		nn=new node;
		nn->bit=1;
        //insert at start.
		if(header==NULL)
		{
         		header=nn;
                nn->prev=nn->next=NULL;
        }
		else
		{
			nn->prev=NULL;
			nn->next=header;
			header->prev=nn;
			header=nn;

		}
	}

		cout<<"\n\nAdded binary number is : ";
	}

};

int main()
{
	list l1,l2,l3,l4,l5;
	int ch;
	char z;
  do
    {           	cout<<"\nBINARY ADDITION\n";
                cout<<"\nBy Doubly linked list";
	cout<<"\nEnter :\n1.Do once complement \n2.Do twos complement.\n3.Do addition of two binary numbers ";
	cin>>ch;

	switch(ch)
	{
		case 1: l1.insertend();
                l1.display();
                l1.oncecomp();
		        l1.display();
		break;

		case 2: l2.insertend();
                l2.display();
                l2.towscomp();
		        l2.display();
		break;

		case 3: l3.insertend();
                l3.display();
                l4.insertend();
                l4.display();
                l5.add(l3,l4);
                l5.display();

		break;

		default:cout<<"\nSorry.";
		break;

	}cout<<"\nWant to do another operation? (y/n)";
	 cin>>z;

     }while(z=='Y'||z=='y');
}
