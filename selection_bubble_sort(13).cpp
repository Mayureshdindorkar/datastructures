#include<iostream>
using namespace std;

class sort
{
public:	int n,i,j,min;

	void selection()
	{
	cout<<"\n****************Doing selection/Sequential Sort***************"<<endl;

	cout<<"\nEnter number of students in class :";
	cin>>n;
	float arr[n];

	cout<<"\nEnter SGPA of students :";
	for(i=0;i<n;i++)
	cin>>arr[i];

	cout<<"\nEntered SGPA of students are  :";
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";

	for(i=0;i<n-1;i++)
	{	min=i;
		for(j=i+1;j<n;j++)
		{	if(arr[j]<arr[min])
			min=j;
		}
		float temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
	cout<<"\nDisplaying SGPA of students sorted by selection/Sequential sort are :";
	for(i=0;i<n;i++)
	cout<<arr[i]<<"\t";
	cout<<"\n";

	cout<<"\nDisplaying top five scores :";
	for(i=n-1;i>=n-5;i--)
	cout<<arr[i]<<"\t";
	cout<<"\n";

	}

	void bubble()
	{

	cout<<"\n****************Doing Bubble Sort***************"<<endl;
	cout<<"\nEnter number of students in class :";
	cin>>n;
	float b[n];

	cout<<"\nEnter SGPA of students:";
	for(i=0;i<n;i++)
	cin>>b[i];

	cout<<"\nEntered SGPA of students are   :";
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
	cout<<"\nDisplaying SGPA if students sorted by Bubble sort are :";
	for(i=0;i<n;i++)
	cout<<b[i]<<"\t";
	cout<<"\n";

    cout<<"\nDisplaying top five scores :";
	for(i=n-1;i>=n-5;i--)
	cout<<b[i]<<"\t";
	cout<<"\n";

	}

};
int main()
{
	sort s1;
	int ch;
	char z;
	do{
	cout<<"\n******SORTING*****";
	cout<<"\nEnter \n1.To do selection/sequential sort \n2.To do bubble sort :";
	cin>>ch;
	switch(ch)
	{	case 1:s1.selection();
		break;

		case 2:s1.bubble();
		break;

		default:cout<<"\nSORRY";
		break;


	}cout<<"\nEnter Y to continue else N :";
	 cin>>z;
	}while(z=='y'||z=='Y');
}

