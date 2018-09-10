//============================================================================
// Name        : priority_queue.cpp
// Author      : MAYURESH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 5

struct queue
{
	int front;
	int rear;
	int arr[SIZE];

}Q;

class priority
{
private:
public:int i;

    int Qempty()
    {
        if((Q.front==-1) ||(Q.front>Q.rear))
            return 1;

        else
            return 0;
    }

    int Qfull()
    {
        if(Q.rear>=SIZE-1)
           { return 1;
           }
        else
		{return 0;
		}
    }

	void insert_ascend(int x)
	{
		if(Q.front==-1)  //Qempty()
           Q.front=0;

		i=Q.rear;
		while(i>=0 && x<Q.arr[i]) //Ascending priority Queue
		{
			Q.arr[i+1]=Q.arr[i];
			i--;

		}Q.arr[i+1]=x;
		 Q.rear++;
	}

	void insert_decend(int x)
		{
			if(Q.front==-1)
               Q.front=0;

			i=Q.rear;
			while(i>=0 && x>Q.arr[i]) //Ascending priority Queue
			{
				Q.arr[i+1]=Q.arr[i];
				i--;

			}Q.arr[i+1]=x;
			 Q.rear++;
		}

	void deletef()  //Common for both
		{
                if(Qempty()==1)
                {
                    cout<<"\nQueue is empty.";
                }
                else
                {
                 cout<<"\nDeleted Element is : "<<Q.arr[Q.front];
                 Q.front++;

                }
		}
        void displayall()       //Common for both
        {
            for(i=Q.front;i<=Q.rear;i++)
                cout<<Q.arr[i]<<"\t";

        }
};

int main()
{
		Q.front=Q.rear=-1;
	    priority p1;
	    int item,ch,h;
	    char z;

	    cout<<"\Enter \n1.For Ascending Priority Queue \n2.Descending Priority Queue :";
	    cin>>h;

	    if(h==1)
	    {
	    cout<<"\n*****ASCENDING PRIORITY QUEUE*****\n";

	    do
	    {
	        cout<<"\nEnter \n1.To add element in Queue \n2.To delete element from Queue \n3.To display whole queue :";
	        cin>>ch;

	        switch(ch)
	        {
	            case 1:	cout<<"\nEnter the number you want to insert :";
	            		cin>>item;
						p1.insert_ascend(item);
	            break;

	            case 2: p1.deletef();
	            break;

	            case 3: p1.displayall();
	            break;

	            default:cout<<"\nSORRY";
	            break;

	        }cout<<"\nEnter Y to cintinue else N :";
	         cin>>z;
	    }while(z=='Y'||z=='y');

	    }

	    if(h==2)
	    {
	    	cout<<"\n*****DESCENDING PRIORITY QUEUE*****\n";

	    		    do
	    		    {
	    		        cout<<"\nEnter \n1.To add element in Queue \n2.To delete element from Queue \n3.To display whole queue :";
	    		        cin>>ch;

	    		        switch(ch)
	    		        {
	    		            case 1:	cout<<"\nEnter the number you want to insert :";
	    		            		cin>>item;
	    							p1.insert_decend(item);
	    		            break;

	    		            case 2: p1.deletef();
	    		            break;

	    		            case 3: p1.displayall();
	    		            break;

	    		            default:cout<<"\nSORRY";
	    		            break;

	    		        }cout<<"\nEnter Y to cintinue else N :";
	    		         cin>>z;
	    		    }while(z=='Y'||z=='y');

	    }
}

