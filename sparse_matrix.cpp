#include<iostream>
using namespace std;

class matrix
{
    private:

    public:int r,c,i,j,l,m,k,sp[30][30],tri[30][30],tran[30][30],terms,col,d,e,rterms[20],rpos[20],ftran[30][30],trip3[30][30];


    void getsp()
    {       cout<<" \nFOR SPARSE MATRIX\n";

            cout<<" \nEnter number of rows of sparse matrix \n";
            cin>>r;

            cout<<" \nEnter number of columns of sparse matrix \n";
            cin>>c;

            for(i=0;i<r;i++)
            {	for(j=0;j<c;j++)
                {	cout<<"\nEnter the element of "<<i<<" row & "<<j<<"th column of sparse matrix :"<<endl;
                    cin>>sp[i][j];
                }
            }

    }

    void dissp()
    {
            cout<<" \n DISPLAYING SPARSE MATRIX\n\n"<<endl;
            for(i=0;i<r;i++)
            {	for(j=0;j<c;j++)
                {
                        cout<<sp[i][j]<<"\t";
                }cout<<"\n";
            }

    }

    void triplet()
    {   cout<<" \nMAKING IT TRIPLET FORM MATRIX \n\n";

        tri[0][0]=r;
        tri[0][1]=c;
        k=1;

        for(l=0;l<r;l++)		//important
        {	for(m=0;m<c;m++)
            {
                if(sp[l][m]!=0)
                {	tri[k][0]=l;
                    tri[k][1]=m;
                    tri[k][2]=sp[l][m];
                    k++;
                }

            }
            tri[0][2]=(k-1);
        }
        terms=(k-1);        //terms=Number of nonzero terms.
    }

    void distrip()
    {
        cout<<" \nDISPLAYING TRIPLET FORM OF SPARSE MATRIX \n\n";

        for(l=0;l<=terms;l++)
        {	for(m=0;m<3;m++)    //columns for triplet matrix must be 3 always.
            {
                cout<<tri[l][m]<<"\t";

            }cout<<"\n";
        }

    }

    void sltran()
    {
            cout<<" DOING SIMPLE/SLOW TRANSPOSE OF THAT TRIPLET MATRIX \n";

            tran[0][0]=tri[0][1];
            tran[0][1]=tri[0][0];
            tran[0][2]=tri[0][2];

            e=1;
            for(col=0;col<c;col++)
                {	for(d=1;d<=terms;d++)
                    {	if(tri[d][1]==col)
                        {	tran[e][0]=tri[d][1];
                            tran[e][1]=tri[d][0];
                            tran[e][2]=tri[d][2];
                            e=e+1;
                        }

                    }
                        if(e>terms)
                        break;

                }
                cout<<" DISPLAYING THE SIMPLE/SLOW TRANPOSE MATRIX \n";

                for(i=0;i<=terms;i++)
                    {	for(j=0;j<3;j++)
                        {
                            cout<<tran[i][j]<<"\t";

                        }cout<<"\n";
                    }

        }

        void fatran()
        {
                    cout<<" DOING FAST TRANSPOSE OF TRIPLET FORM ";

                    ftran[0][0]=tri[0][1];
                    ftran[0][1]=tri[0][0];
                    ftran[0][2]=tri[0][2];


                    for(i=0;i<c;i++) //fill rterms from 0th position.
                    {	rterms[i]=0;
                    }rpos[0]=1;

                    for(i=1;i<=terms;i++) //fill rpos from 1st position.
                    {
                        rterms[tri[i][1]]++;

                    }

                for(i=1;i<c;i++)
                {	rpos[i]=rterms[i-1]+rpos[i-1];

                }


                for(i=1;i<=terms;i++)
                {	int j=rpos[tri[i][1]];
                    rpos[tri[i][1]]++;
                    ftran[j][0]=tri[i][1];
                    ftran[j][1]=tri[i][0];
                    ftran[j][2]=tri[i][2];

                }


             cout<<" DISPLAYING THE FAST TRANSPOSE ";

                    for(i=0;i<=terms;i++)
                    {	for(j=0;j<3;j++)
                        {
                            cout<<ftran[i][j]<<"\t";


                        }cout<<"\n";
                    }


        }

        matrix add(matrix p,matrix q)   //two objects are passed.
        {   int i=j=k=1;
             if(p.tri[0][0]==q.tri[0][0]&&p.tri[0][1]==q.tri[0][1])    //checking order
                {
                    //trip3 is the addition triplet matrix(addition result).
                        trip3[0][0]=p.tri[0][0];
                        trip3[0][1]=p.tri[0][1];


            while(i<=p.tri[0][2]&&j<=q.tri[0][2])
            if(p.tri[i][0]==q.tri[j][0])  //row check
            {
                if(p.tri[i][1]==q.tri[j][1])  //column check
                {
                    trip3[k][0]=p.tri[i][0];
                    trip3[k][1]=p.tri[i][1];
                    trip3[k][2]=p.tri[i][2]+q.tri[j][2];
                    i++,j++,k++;
                }
                else if(p.tri[i][1]<q.tri[j][1])
                        {
                                trip3[k][0]=p.tri[i][0];
                                trip3[k][1]=p.tri[i][1];
                                trip3[k][2]=p.tri[i][2];
                                i++,k++;
                        }

                        else
                        {

                                trip3[k][0]=q.tri[j][0];
                                trip3[k][1]=q.tri[j][1];
                                trip3[k][2]=q.tri[j][2];
                                j++,k++;
                        }

            }

            else if(p.tri[i][0]<q.tri[j][0])      //if first row is small
                    {
                                trip3[k][0]=p.tri[i][0];
                                trip3[k][1]=p.tri[i][1];
                                trip3[k][2]=p.tri[i][2];
                                i++,k++;
                    }

                    else                            //if second row is small
                    {
                                trip3[k][0]=q.tri[j][0];
                                trip3[k][1]=q.tri[j][1];
                                trip3[k][2]=q.tri[j][2];
                                j++,k++;
                    }

            while(i<=p.tri[0][2])
            {
                trip3[k][0]=p.tri[i][0];
                trip3[k][1]=p.tri[i][1];
                trip3[k][2]=p.tri[i][2];
                i++,k++;
            }

             while(j<=q.tri[0][2])
            {
                trip3[k][0]=q.tri[j][0];
                trip3[k][1]=q.tri[j][1];
                trip3[k][2]=q.tri[j][2];
                j++,k++;
            }

            trip3[0][2]=k-1;
        }
        else
        {
            cout<<"\nOrder is not same hence addition is not possible.";
        }

        }

        void disadd()
        {
                  cout<<" \nDISPLAYING TRIPLET FORM OF ADDITION MATRIX \n\n";

                    for(l=0;l<=(k-1);l++)
                        {	for(m=0;m<3;m++)
                                {
                                    cout<<trip3[l][m]<<"\t";


                                }cout<<"\n";

                        }

        }
};

int main()
{   matrix z1,z2,z3;
    int ch,g;

    do
    {
        cout<<" Enter 1.To enter sparse matrix & display its triplet form \n 2.To display slow transpose \n 3.To display fast transpose \n4.To add two sparse matrices. "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:z1.getsp();
                   z1.dissp();
                   z1.triplet();
                   z1.distrip();
                    break;

            case 2: z2.getsp();
                    z2.dissp();
                    z2.triplet();
                    z2.distrip();
                    z2.sltran();
                    break;

            case 3: z3.getsp();
                    z3.dissp();
                    z3.triplet();
                    z3.distrip();
                    z3.fatran();
                    break;

            case 4: cout<<" Enter first sparse matrix ";
                    z1.getsp();
                    z1.dissp();
                    z1.triplet();

                    cout<<" Enter second sparse matrix ";
                    z2.getsp();
                    z2.dissp();
                    z2.triplet();

                    z3.add(z1,z2);
                    z3.disadd();
        }cout<<" Enter 1 for another operation else press 0 "<<endl;
        cin>>g;
    }while(g==1);

}
