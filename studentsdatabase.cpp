#include<iostream>
#include<string>
using namespace std;

class game
{
	private:int x,y,u[50],a[10],b[10],u1[20],in[20],i,j,k,onc[20],onb[20],ncnb[20],n;
            static int count1,count2;
                                                        //u[]=universal array & u1[]=union array.
	public:
	    void get1()
	    {
            cout<<" Enter total number of students in SE i.e,'M'."<<endl;
            cin>>n;

            //int u[n];
            cout<<" Enter roll number of students in SE "<<endl;
             for(j=0;j<n;j++)
            {
                cin>>u[j];
            }//Roll numbers are alloted to students of universal set.

            cout<<" Roll no. of students in SE are {";
            for(i=0;i<n;i++)
            {
            cout<<u[i]<<",";
            }
            cout<<" }."<<endl;

	    }

	    void get()
        {
            cout<<" \nEnter number of students playing cricket "<<endl;
            cin>>x;
            cout<<" Enter roll number of students playing cricket: "<<endl;
            for(i=0;i<x;i++)
           {
                cin>>a[i];
           }
            cout<<" \nEnter number of students playing badminton ";
            cin>>y;
            cout<<" Enter roll number of students playing badminton: "<<endl;
             for(i=0;i<y;i++)
            {
                cin>>b[i];
            }
        }

        void display()
        {
            cout<<" \nRoll no. of students playing cricket are {";
            for(i=0;i<x;i++)
            {
            cout<<a[i]<<",";
            }
            cout<<" }."<<endl;


            cout<<" \nRoll of students playing badminton are {";
            for(i=0;i<y;i++)
            {
            cout<<b[i]<<",";
            }
            cout<<" }."<<endl;
        }

        void unionf()
        {
            j=0;

            for(i=0;i<x;i++)//adding a[x] to union array.
            {
                u1[j]=a[i];
                j++;
            }

            int flag=0;

           for(k=0;k<y;k++)
            {
                for(i=0;i<x;i++)//comparing each  element of with a.
                {
                      if(b[k]==a[i])
                      {
                            flag=1;

                      }

                }
                if(flag==0)             //if it is not common in a&b then add it in union set.
                {
                    u1[j]=b[k];
                    j++;

                }
                flag=0;
            }

              cout<<" \nThe union is {";
              for(i=0;i<j;i++)
              {cout<<u1[i]<<",";}
              cout<<"}.";
              count1=j;        //MOST IMPORTANT this count is used in neither cricket nor badminton.
        }
        void intersect()
        {k=0;
            for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                    if(a[i] == b[j])
                        {
                            in[k] = b[j];   //elements common in both sets are stored in intersection array.
                            k++;
                        }
                }
            }

            cout<<"\nIntersection is:\t{";
            for(i=0;i<k;i++)
                cout<<in[i]<<",";
                cout<<"}";
                count2=k;//MOST IMPORTANT.
        }

        void onlyc()
        {
            k=0;
            int flag=1;
            for(i=0;i<x;i++)
            {   for(j=0;j<count2;j++)
               {
                        if(a[i]==in[j])
                        {
                            flag=0;     //element of cricket which is not present in intersection is stored in only cricket.
                        }
               }

                if(flag==1)
                {
                    onc[k]=a[i];
                    k++;

                }flag=1;
            }
                cout<<" \nStudents who play only cricket are {";
                for(j=0;j<k;j++)
                {
                    cout<<onc[j]<<",";
                }cout<<"}.";
        }

	void onlyb()
	{
            k=0;
            int flag=1;
            for(i=0;i<y;i++)
            {   for(j=0;j<count2;j++)
               {

                        if(b[i]==in[j])
                        {
                            flag=0;      //element of badminton which is not present in intersection is stored in only badminton.

                        }

               }

                if(flag==1)
                {
                    onb[k]=b[i];
                    k++;
                }flag=1;
            }

                cout<<" \nStudents who play only badminton are {";
                for(j=0;j<k;j++)
                {
                    cout<<onb[j]<<",";
                }cout<<"}.";

        }

        int neithercb()
        {       k=0;
            int flag=0;
            for(i=0;i<n;i++)//universal.
            {
                flag=0;
                for(j=0;j<count1;j++)//union.
               {
                        if(u[i]==u1[j])
                        {
                            flag=1;
                        }
               }

                if(flag==0)
                {
                    ncnb[k]=u[i];
                    k++;
                }flag=0;
            }
                cout<<" \nStudents who neither play cricket nor badminton are {";
                for(j=0;j<k;j++)
                {
                    cout<<ncnb[j]<<",";
                }cout<<"}.";

        }

};int game::count1;
  int game::count2;

int main()
{
    int j,n,i;
    game a;

    a.get1();
    a.get();
    a.display();
    a.unionf();
    a.intersect();
    a.onlyc();
    a.onlyb();
    a.neithercb();
}
