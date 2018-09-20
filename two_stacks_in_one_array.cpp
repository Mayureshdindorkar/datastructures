#include<iostream>
using namespace std;
#define SIZE 6

int top1=-1;
int top2=SIZE-1;
int arr[SIZE];


void push(int stno,int item)
{
	if(stno==1)
	{
		if(top1+1==top2)
		{cout<<"\nStack is full.";
		}
		else
		{
			top1++;
			arr[top1]=item;
		}
	}
	if(stno==2)
	{
		if(top2-1==top1)
		{cout<<"\nStack is full.";
		}
		else
		{
			top2--;
			arr[top2]=item;
		}
	}
}

int pop(int stno)
{
	if(stno==1)
	{
		if(top1==-1)
		{cout<<"\nStack is empty.";
		}
		else
		{
			int item;
			item=arr[top1];
			top1--;
			return(item);
		}
	}
	if(stno==2)
	{
		if(top2==SIZE)
		{cout<<"\nStack is empty.";
		}
		else
		{
			int item;
			item=arr[top2];
			top2++;
			return(item);
		}
	}
}
int main()
{	char z;	
	int ch,x,d;
	int stno,k;
	
	do
	{
	cout<<"\n******Two stacks in single array*****\n";
	cout<<"\nEnter \n 1.To push 2.To pop 3.To display stack :";
	cin>>ch;

	switch(ch)
	{
	
	case 1:cout<<"\nEnter 1 to push in stack 1 or 2 to push in array 2 :";
		   cin>>stno;
		   cout<<"\nEnter number you want to push :";
		   cin>>x;
		   push(stno,x);
	break;
	
	case 2:cout<<"\nEnter 1 to pop from stack 1 or 2 to pop from stack 2:";
		   cin>>stno;
		   k=pop(stno);
		   cout<<"\nPoped value is :"<<k;
	break;

	case 3:cout<<"Enter 1.To display stack1 else enter 2.To display stack2 :";
		   cin>>d;
		   if(d==1)
		   {
		   	for(int i=top1;i>=0;i--)
		   	cout<<arr[i]<<endl;
		   }
		   if(d==2)
		   {
		   	for(int i=top2;i<SIZE;i++)
		   	cout<<arr[i]<<endl;
		   }
	break;
	}cout<<"\nEnter Y to continue else N";
	 cin>>z;
	}while(z=='y'||z=='Y');	
}
