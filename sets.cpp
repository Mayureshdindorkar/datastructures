#include<iostream>

using namespace std;
int total;
static int j[31];

class stud
{	private:  static int max,min,ab;
              static float sum,avg,pre;
		      int x,y,i;
	public: int marks,roll;
            char name[10];

	void get()
	{	cout<<" Enter name of student "<<endl;
		cin>>name;
		cout<<" Enter the roll number "<<endl;
		cin>>roll;
		cout<<" Enter the marks of students & Enter -1 for absent students "<<endl;
		cin>>marks;

		if(marks<0)
		{
			ab++;
		}
		else{	j[marks]++;
			if(max<marks)
				{	max=marks;

				}
			if(min>marks)
				{	min=marks;

				}

		    }
	}

	void add()
	{
		if(marks>0&&marks<30)
		sum=sum+marks;

	}

	void average()
	{
		pre=total-ab;
		cout<<" sum is = "<<sum<<endl;
		avg=sum/pre;
		cout<<" \nAverage is = "<<avg<<endl;
		cout<<" \nHighest/Maximum marks = "<<max;
		cout<<" \nLowest/Minimum marks = "<<min;
		cout<<" \nNumber of students absent are :"<<ab<<endl;
		x=j[0];
		for(i=0;i<31;i++)
		{	if(x<j[i])
			{	x=j[i];
				y=i;
			}

		}
		cout<<"\nMarks scored by most students: \n";
		cout<<" "<<x<<" number of students scored "<<y<<"marks."<<endl;
	}

};

int stud::max;
int stud::min=30;
float stud::avg;
float stud::sum;
int stud::ab;
float stud::pre;

int main()
{	cout<<"Enter total number of students int the class :";
	cin>>total;

    int i;
	stud s[total];
	for(i=0;i<total;i++)
	{	s[i].get();
		s[i].add();
	}
	s[total-1].average();
}
