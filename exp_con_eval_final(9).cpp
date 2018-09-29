#include <iostream>
using namespace std;
int top=-1; //this top is used for both char as well as int stack.
int j=0; //counter for output array.

class post
{
    private: char exp[30]; //accepting expression
             char stack[20]; //for storing operators during exp conversion
             char out[30]; //storing postfix expression
             int stackint[20]; //for storing integers during exp evaluation

    public:
    void getinfix()
    {
        cout<<"Enter the infix expression :";
        cin>>exp;
    }
    void push(char ch) //pushing into the character stack
    {
        stack[++top]=ch;
    }
    char pop() //pushing into the character stack
    {
        return stack[top--];
    }
    int getpriority(char ch) //returns priority of each char of input infix exp.
    {
        if(ch=='+'||ch=='-')
            return 1;
        if(ch=='*'||ch=='/')
            return 2;
        else
            return 0; //priority for brackets
    }
    void conversion()
    {   int i=0;
        char temp;
        while(exp[i]!='\0')
        {
            if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            {
                push(exp[i]);
            }
            else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
            {
                if(exp[i]==')')
                {
                    while(stack[top]!='(')
                    {
                        out[j++]=pop();
                    }
                }
                if(exp[i]==']')
                {
                    while(stack[top]!='[')
                    {
                        out[j++]=pop();
                    }

                }
                if(exp[i]=='}')
                {
                    while(stack[top]!='{')
                    {
                        out[j++]=pop();
                    }
                }
                temp=pop();
            }
            else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
            {
                if(getpriority(stack[top])>=getpriority(exp[i]))
                {
                    out[j++]=pop();
                    push(exp[i]);
                }
                else  //means the element is a character like a,b,c,d which is considered as ASCII or it is an integer;
                {
                    push(exp[i]);
                }
            }
            else
            {
                out[j++]=exp[i];
            }
            i++;
        }
        if(top!=-1)  //checking is the array completely empty
        {
            while(top!=-1)
            {
                out[j++]=pop();
            }
        }
        out[j]='\0';

        cout<<"\nPostfix Expression is : ";
        for(i=0;out[i]!='\0';i++)
        cout<<out[i];
        cout<<endl;
    }
    void push_int(int item) //this function is for integer stack i.e. for exp evaluation
    {
        stackint[++top]=item;
    }
    int pop_int()  //this function is for integer stack i.e. for exp evaluation
    {
        return stackint[top--];
    }

    void evaluation()
    {   //same top will be used here because it becomes -1 after executing conversion function
        int i=0,op1=0,op2=0;

        while(out[i]!='\0') //taking one by one values from output array
        {
            if(out[i]=='+')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1+op2);
            }
            else if(out[i]=='-')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1-op2);
            }
            else if(out[i]=='*')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1*op2);
            }
            else if(out[i]=='/')
            {
                op2=pop_int();
                op1=pop_int();
                push_int(op1/op2);
            }
            else
            {
                push_int((int)out[i]-48); //important
                                          //storing the integer from (postfix)output array to
            }
        i++;
        }
        cout<<"\nEvaluated result is :"<<pop_int(); //printing the result
    }
};
int main()
{
    post p1;
    int choice;
    char z;
    do
    {
    cout<<"\n******EXPRESSION CONVERSION AND EVALUATION******\n";
    cout<<"Enter \n1.To Convert infix expression to postfix \n2.To evaluate that (postfix) expression :";
    cin>>choice;

    switch(choice)
    {
        case 1: p1.getinfix();
                p1.conversion();
        break;

        case 2: p1.evaluation();
        break;

        default:cout<<"\nSorry wrong input";
        break;
    }cout<<"\nEnter y to continue else n :";
     cin>>z;

    }while(z=='y'||z=='Y');
    return 0;

}

