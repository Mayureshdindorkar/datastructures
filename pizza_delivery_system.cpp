#include<iostream>
using namespace std;
#define SIZE 3


	struct queue
	{
		int front;
		int rear;
		int que[SIZE];

	}q;

class pizza
{

	public:pizza()
	{
		q.front=q.rear=-1;
	}

	int qfull()
		{
			if(q.front==(q.rear+1)%SIZE)
			return 1;

			else
			{return  0;
			}
		}

	int qempty()
	{
		if(q.front==-1)
		return 1;

		else
		{return 0;}

	}

	int push(int item)
	{
	    if(qfull()==1)
        {
            cout<<"\nOrder list is full delete some orders!";
        }
	    else
        {
            if(q.front==-1)
            {
                q.front=q.rear=0;
            }
            else
            {
                q.rear=(q.rear+1)%SIZE;
            }
			q.que[q.rear]=item;

        }
    }

	void pop()
	{
        if(qempty()==1)
        {
            cout<<"\nOrder list is empty.";
        }
        else
        {   cout<<"\nYour order is ready :"<<q.que[q.front];

            if(q.front==q.rear)  //Only one element in list.
            q.front=q.rear=-1;
            else
            q.front=(q.front+1)%SIZE;

        }

	}
	void display()
	{
		int i=q.front;
			while(i!=q.rear)
			{
				cout<<q.que[i]<<"\t";
				i=(i+1)%SIZE;
			}cout<<q.que[i];
	}

};
int main()
{	int ch,orno;
	pizza p1;
	char z;

	do
	{
	cout<<"\n*****PIZZA STORE*****\n";

	cout<<"\nEnter \n1.To place an order. \n2.To get ready order. \n3.To display all remaining orders list :";
	cin>>ch;

	switch(ch)
	{
		case 1: cout<<"\nEnter your order number :";
                cin>>orno;
                p1.push(orno);
		break;

		case 2: p1.pop();
		break;

		case 3: p1.display();

		break;

		default: cout<<"\nSORRY";
		break;

	}cout<<"\nEnter y to continue else n :";
	 cin>>z;

	}while(z=='Y'||z=='y');
}
