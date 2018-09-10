#include<iostream>
using namespace std;
#define SIZE 10

struct stack
{
    char stackarr[SIZE];
    int top;

}s1;

class expression
{	
    public:int i;

    int stackfull()
    {
        if(s1.top>=SIZE-1)
       {return 1;}

       else {return 0;}
    }


    int stackempty()
    {
        if(s1.top==-1)
       {return 1;}

       else {return 0;}
    }

    void push(char x)
    {
        s1.top++;
        s1.stackarr[s1.top]=x;
    }

    void pop()
    {
        char z;
        z=s1.stackarr[s1.top];
        s1.top--;  
       
    }

    int check(char exp[],int length)
    {
    
    for(i=0;i<length;i++)
    	{
    		if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
    		{
    			push(exp[i]);
    		
    		}
    		else
    		{
    			if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
    			{
    				if(stackempty()==1)
    				{
    					cout<<"\nStack is empty equation is not balanced.";
    					return 0;
    				}
    			
    				else 
    				{	if(exp[i]=='}' && s1.stackarr[s1.top]=='{')
    					{
    						pop();
    					}
    					else if(exp[i]==']' && s1.stackarr[s1.top]=='[')
    						{
    							pop();
    						}
    						else if(exp[i]==')' && s1.stackarr[s1.top]=='(')
    							{
    								pop();
    							}
    							else
    							{
    								cout<<"\nExpression is not balanced.";
    								return 0;
    							}		
    					
    						
    				
    					
    			
    		        	}
    			
          		 }	
    		
    		
    	          }
    
   
    	}
    	if(stackempty()==1)
    	{
    		cout<<"\nParenthesis is balanced correctly.";
    	}
    }


};

int main()
{	
    expression e1;
    char exp[40];   
    int i,length;
 
    s1.top=-1;

                      cout<<"\n****BALANCED PARENTHESIS****\n";
       
       cout<<"\nEnter the expression :";
       cin>>exp;
       
       for(i=0;exp[i]!='\0';i++);
       length=i;
       if(length<10)
       {
       e1.check(exp,length);
       }
       else
       {
       	cout<<"\nExpression is too long for stack to handle.\n";
       }
       
        
    
}
