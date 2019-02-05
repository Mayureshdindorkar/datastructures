#include<iostream>
using namespace std;
#define SIZE 10

struct node
{
    node *l,*r;
    char data;
};

int top1=-1,top2=-1;
node *arr1[SIZE],*arr2[SIZE];


        void push1(node *x)
        {   if(top1>=SIZE-1)
            cout<<"\nStack1 full";
            else
            {
                top1++;
                arr1[top1]=x;
            }
        }
        node* pop1()
        {   node *x;
            if(top1==-1)
                cout<<"\nStack1 empty";
            else
            {
                x=arr1[top1--];
                return x;
            }
        }
        void push2(node *x)
        {   if(top2>=SIZE-1)
            cout<<"\nStack2 full";
            top2++;
            arr2[top2]=x;
        }
        node* pop2()
        {   node *x;
            if(top2==-1)
            cout<<"\nStack2 empty";
            else
            x=arr2[top2--];
            return x;
        }

class stack
{
   public:node* s[50];
          int top;

        stack()
        {
           top=-1;
        }
        void push(node *temp)
        {
            s[++top]=temp;
        }
        node* pop()
        {
            return s[top--];
        }
        int isstackempty()
        {
            if(top==-1)
            return 1;
            else
            return 0;
        }

};
int getpriority(char s)
{
   int a;
   switch(s)
   {
        case '+' : a=1;break;
        case '-' : a=1;break;
        case '*' : a=2;break;
        case '/' : a=2;break;

    }
    return a;
}

class tree
{
        public: char exp[100];
                int i;
                stack operator1,operand;    //creating objects
                node *temp,*nn;

        void getexp()
        {
                cout<<"\nEnter the infix expression :";
                cin>>exp;

                for(i=0;exp[i]!='\0';i++)
                {
                        nn=new node;
                        nn->data=exp[i];
                        nn->l=nn->r=NULL;

                        if(nn->data=='+' || nn->data=='-' ||nn->data=='*' ||nn->data=='/')
                        {
                                if(operator1.isstackempty())
                                {
                                        operator1.push(nn);

                                }
                                else if(getpriority(operator1.s[operator1.top]->data)<=getpriority(nn->data))
                                {
                                       temp=operator1.pop();
                                       operator1.push(nn);
                                       temp->r=operand.pop();
                                       temp->l=operand.pop();
                                       operand.push(temp);

                                }
                                else
                                {
                                        operator1.push(nn);
                                }

                        }
                        else
                        {
                                operand.push(nn);
                        }

                   }
                   while(!operator1.isstackempty())
                   {
                                temp=operator1.pop();
                                temp->r=operand.pop();
                                temp->l=operand.pop();
                                operand.push(temp);
                   }

        }

        void nonrec_postorder_display()
        {
            temp=operand.s[operand.top];
            push1(temp);
            while(top1!=-1)
            {
                temp=pop1();
                push2(temp);

                if(temp->l!=NULL)
                push1(temp->l);

                if(temp->r!=NULL)
                push1(temp->r);

            }
            while(top2!=-1)
            {
                temp=pop2();
                cout<<" "<<temp->data;
            }

        }

};
int main()
{
        int ch;
        char z;
        tree t1;

        do
        {       cout<<"\n*****EXPRESSION TREE*****\n";
                cout<<"\n1.To enter the infix expression";
                cout<<"\n2.To display its postfix(postorder) conversion :";
                cin>>ch;

                switch(ch)
                {
                        case 1:t1.getexp();
                        break;

                        case 2:t1.nonrec_postorder_display();
                        break;

                        default:cout<<"\nInvalid.";

                }

         cout<<"\nWant to continue? (Y/N):";
         cin>>z;
        }while(z=='Y'||z=='y');

}
