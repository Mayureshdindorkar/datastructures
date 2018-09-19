#include<iostream>
#define SIZE 20
using namespace std;

int partition(float a[SIZE],int,int);
void swap(float a[SIZE],int,int);
void quick(float a[SIZE],int,int);

int main()
{   int n,i;
	cout<<"\n****************Doing Quick Sort***************"<<endl;

	cout<<"\nEnter number of students in class :";
	cin>>n;
	float a[SIZE];

	cout<<"\nEnter SGPA of students :";
	for(i=0;i<n;i++)
	cin>>a[i];

	cout<<"\nEntered SGPA of students are  :";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";

    quick(a,0,n-1);

    cout<<"\nSGPA of students after Quick sorting are :";
	for(i=0;i<n;i++)
	cout<<a[i]<<"\t";

	cout<<"\nDisplaying top five scores :";
	for(i=n-1;i>=n-5;i--)
	cout<<a[i]<<"\t";
	cout<<"\n";

}

int partition(float a[SIZE],int low,int high)
{
        int pivot=a[low];
        int i=low+1;
        int j=high;

        while(i<=j)
        {
            while(a[i]<a[low])
                i++;

            while(a[j]>a[low])
                j--;

            if(i<j)
            swap(a,i,j);
        }
            swap(a,low,j);

            return j;
}
void swap(float a[SIZE],int i,int j)
{
    float temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void quick(float a[SIZE],int low,int high)
{   int m;
    if(low<high)
    {
        m=partition(a,low,high);

        quick(a,low,m-1);
        quick(a,m+1,high);
    }
}
