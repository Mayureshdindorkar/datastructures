#include<iostream>
using namespace std;

int main()
{
	cout<<"\n****************Doing Bubble Sort***************"<<endl;
    int i,j,n;
    float temp;


    cout<<"\nEnter number of students in class :";
	cin>>n;
	float b[n];

	cout<<"\nEnter SGPA of students:";
	for(i=0;i<n;i++)
	cin>>b[i];

	cout<<"\nEntered SGPA of students are   :";
	for(i=0;i<n;i++)
	cout<<b[i]<<"\t";

	for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(b[j]>b[j+1])
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    cout<<"\nBubble sorted array :";
	for(i=0;i<n;i++)
	cout<<b[i]<<"\t";
}
