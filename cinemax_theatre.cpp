//============================================================================
// Name        : theatre.cpp
// Author      : MAYURESH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

struct node
{
	node *prev;
	char status;
	node *next;

};

class list
{
	public:node *header;
           node *nn;
           node *cn;

    void insertend()
	{
        header = NULL;

    for (int j = 0; j < 7; j++)
        {
            nn = new node;
            nn->status = 'A';
            nn->next = NULL;
            nn->prev = NULL;

            if (header == NULL)
            {
            header = nn;
            nn->next = header;
            nn->prev = header;
            }
            else
            {
                cn = header;
                while (cn->next != header)
                {
                    cn = cn->next;
                }
                cn->next = nn;
                nn->prev = cn;
                nn->next = header;
                header->prev = nn;
            }
        }

    }

        void display()
		{
            cn=header;
            do
			{   cout<<cn->status<<"\t";

			    cn=cn->next;
			}while(cn!=header);
        }

         void book(int c)
		{
		    node *sn;
		    sn=header;
		    for(int t=1;t<c;t++)
            {
                sn=sn->next;
            }
            sn->status='B';

		}
		void cancel(int c)
		{   node *sn;
            sn=header;
            for(int t=1;t<c;t++)
            {
                cn=cn->next;
            }cn->status='A';

		}
};

int main()
{
	int ch,i,r,c;
	char z;
	list l[10]; //For 10 rows.

	do
	{
	cout<<"\n**********CINEMAX THEATRE***********\n";
	cout<<"\n**********DOUBLY CIRCULAR LINK LIST***********\n";

	cout<<" \nEnter \n1.(Must use initially)Display list of available seats. \n2.To Book ticket. \n3.To cancel Booking."<<endl;
	cin>>ch;

	switch(ch)
	{
            case 1:for(int k=0;k<10;k++)
                    {
                        l[k].insertend();
                    }
                    for(i=0;i<10;i++)
                    {
                        l[i].display();
                        cout<<"\n";
                    }

            break;

            case 2:cout<<"\nEnter the seat no. you want to book(row & seat)\n";
            cin>>r>>c;
            l[r-1].book(c);
                    for(i=0;i<10;i++)
                    {
                        l[i].display();
                        cout<<"\n";
                    }

            break;

            case 3:cout<<"\nEnter the seat no. at which you want to cancel booking(row & seat)\n";
            cin>>r>>c;
            l[r-1].cancel(c);
                    for(i=0;i<10;i++)
                    {
                        l[i].display();
                        cout<<"\n";
                    }

            break;


            default :cout<<" !!!!SORRY!!!! ";
			break;


	}cout<<" \nEnter y for another operation else n "<<endl;
	cin>>z;

	}while(z=='y' || z=='Y');

}
