#include<iostream>
using namespace std;
#define SIZE 20

class searching
{
	public: float b[SIZE],key;
		int i,n,low,high,mid;

	void bubble()
	{

	cout<<"\n****************Doing Bubble Sort***************"<<endl;
	cout<<"\nEnter total number of students in attending the program :";
	cin>>n;
	int i,j;
	cout<<"\nEnter roll number of students attending the program:";
	for(i=0;i<n;i++)
	cin>>b[i];

	cout<<"\nDisplaying entered roll numbers of students attending the program:\n";
	for(i=0;i<n;i++)
	cout<<b[i]<<"\t";


	for(i=1;i<n;i++)
	{
		for(j=0;j<(n-1);j++)
		{	float temp1=0;
			if(b[j]>b[j+1])
			{	temp1=b[j];
				b[j]=b[j+1];
				b[j+1]=temp1;
			}
		}
	}
	cout<<"\nDisplaying entered roll numbers of students attending the program in sorted order by Bubble sort:\n";
	for(i=0;i<n;i++)
	cout<<b[i]<<"\t";
	cout<<"\n";

	}
	void binary()       //FOR BINARY SEARCH WE NEED AECENDING ORDER SORTED INPUT hence used bubble sort
	{	bubble();
		int flag=0;
		low=0;
		high=n-1;
		cout<<"\nEnter roll number of student you want to check attendance :";
		cin>>key;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(key==b[mid])
			{	flag=1;
				cout<<"\nStudent was present to the program."<<b[mid]<<endl;
				break;
			}
			else
			{
				if(key<b[mid])
				high=mid-1;
				else
				low=mid+1;
			}
		}
		if(flag==0)
		{
		cout<<"\nStudent was absent to program.";
		}
	}

	void fibonacci()
	{

	int f,i,temp,key,j,a,b,flag=0;
	cout<<"\nEnter the size of array :";
	cin>>f;
	int fib[SIZE],ar[SIZE];	//fib will store fibonacci series & ar will store user given values
	fib[0]=0;
	fib[1]=1;
	for(i=2;i<f;i++) //it is index of that array.
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<"\nDisplaying the fibonacci series :";
	for(i=0;i<f;i++)
	{
		cout<<fib[i]<<" ";
	}cout<<"\n";

	cout<<"\nEnter the roll numbers of students attending the program :";
	for(i=1;i<=f;i++)   //IMPORTANT FOR FIBONACCI SEARCH i=1 to f
	{
		cin>>ar[i];
	}

	//Doing bubble sort because searching needs sorted array

	for(i=1;i<f;i++)	//no. of passes
	{
	    for(j=1;j<=f-1;j++) //no. of comparisions
	    {
	    	if(ar[j]>ar[j+1])
		{
			temp=ar[j];
			ar[j]=ar[j+1];
			ar[j+1]=temp;
		}
	    }
	}
	cout<<"\nRoll numbers by bubble sort are :";
	for(i=1;i<=f;i++)
	{
		cout<<ar[i]<<" ";
	}cout<<"\n";

	b=fib[f-1];
	a=fib[f-2];

	cout<<"\nEnter roll number of student you want to check attendance :";
	cin>>key;
	while(a>=0 && b>=1)
	{
		if(key<ar[f])
		{
		f=f-a;
		temp=b-a;
		b=a;
		a=temp;
		}
		else if(key>ar[f])
		{
		f=f+a;
		b=b-a;
		a=a-b;
		}
		else if(key==ar[f])
		{
		    flag=1;
            break;
		}
    }

    if(flag==1)
    {
        cout<<"\nStudent was present :"<<ar[f]<<"\n";
    }
    if(flag==0)
    {
        cout<<"\nStudent was absent :"<<key<<"\n";
    }

	}

};

int main()
{	int ch;
	searching s1;
	char z;
	do
	{
	cout<<"\n*****SEARCHING*****\n";

	cout<<"\nEnter  \n1.For binary search \n2.For fibonacci search :";
	cin>>ch;
	switch(ch)
	{

		case 1:s1.binary();
		break;

		case 2:s1.fibonacci();
		break;

		default:cout<<"\nSorry";
		break;
	}cout<<"\nWant to continue?(Y/N)";
	 cin>>z;

	}while(z=='y'|z=='Y');
}
