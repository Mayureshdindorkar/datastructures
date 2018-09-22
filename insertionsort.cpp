#include<iostream>
using namespace std;

int main()
{   int i,j,n;
    float temp;

    cout<<"\n****************Doing insertion Sort***************"<<endl;

	cout<<"\nEnter number of students in class :";
	cin>>n;
	float a[n];

	cout<<"\nEnter SGPA of students :";
	for(i=0;i<n;i++)
	cin>>a[i];

	cout<<"\nEntered SGPA of students are  :";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";

    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;

        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    cout<<"\nDisplaying elements of array sorted by selection/Sequential sort are :";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";
	cout<<"\n";

}
