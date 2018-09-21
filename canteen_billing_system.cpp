/*
	NAME OF STUDENTS : MAYURESH RAJESH DINDORKAR(SECOC315)
		         
	BRANCH           : COMPUTER ENGG.
	DIVISION	 : C.
	SUBJECT          : DSA MINIPROJET
	DSA CONCEPT USED : SINGLY LINKED LIST
	TITLE OF PROJECT : SURYA CANTEEN SYSTEM
*/

#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>

using namespace std;

//structure for menu linked list
struct node{
	char name[10];
	char keyword;
	float price;
	node* next;

};

//stucture for billing linked list
struct node1{
	char keyword1;
	int qty1;
	float price1;
	node1 *next1;

};

class CanteenBilling
{
	private :
	float total;



    public:
      CanteenBilling()
      {
          header=NULL;
          header1=NULL;
      }
    	//cn and header for menu
    	node *cn;
    	node *header;
    	//cn and header for bill;

    	node1 *header1;


    	void getMenu();
    	void displayMenu();
    	void placeOrder();
    	void generateBill();



};

void CanteenBilling::getMenu(){
	//taking menu from canteen owner  very first time
	//single linked list - insert at end
    node *nn;
    node1 *cn1;
    		nn = new node;
		    nn->next = NULL;
		    cout << "\nEnter The Name of Food Item :\t";
		    cin >> nn->name;
		    cout << "\nEnter The KeyWord of Food Item :\t";
		    cin >> nn->keyword;
		    cout << "\nEnter The Price of Food Item :\t";
		    cin >> nn->price;

		    if (header == NULL) {
		        header = nn;
		    }
		    else{

		    	cn = header;
			    while (cn->next != NULL) {
			        cn = cn->next;
			    }
			    cn->next = nn;

		    }

}

void CanteenBilling::displayMenu(){
node1 *cn1;
	//main menu filled by canteen owner to see for client
	cn = header;
	cout<<"*****************MENU*****************"<<endl;
	cout<<"NAME OF ITEM "<<"\t\t"<<"PRICE"<<endl;
    while (cn) {
        cout << cn->name<<"\t\t\t";
        cout<<cn->price;
        cout << "\n";
        cn = cn->next;

    }
}

void CanteenBilling::placeOrder(){

node1 *nn1;
node1 *cn1;
    int do2,qty;
    float temp;
	char ch1;
	//do loop for one persons multiple orders
	do{

		cout<<"\nEnter the KeyWord of FoodItem which You want to Order : ";
		cin>>ch1;
		//searching for that keyword in menu l-list
		cn=header;
                char c1;
                c1=cn->keyword;
		while(c1 != ch1){
			cn=cn->next;
                        c1=cn->keyword;

		}//got the menu node
		cout<<"\nEnter the Quantity of Item : ";
		cin>>qty;
		//price after considering qty of specific food item;
		temp=qty*(cn->price);

		//inserting info(order = particular person) in linked list of bill
                    nn1 = new node1;
		    nn1->next1 = NULL;
		    //transfering name of item from menu l-list to bill l-list

                    nn1->keyword1=ch1;
     		    nn1->qty1=qty;
		    nn1->price1=temp;

		    if (header1 == NULL) {
		        header1 = nn1;
		    }
                    else
                    {
                        cn1 = header1;
			    while (cn1->next1 != NULL) {
			        cn1 = cn1->next1;
			    }
			    cn1->next1 = nn1;
                    }



		//ends here inserting all info of one order = person;

		    cout<<"\nEnter 1 to order another food item Else 0 : ";
		    cin>>do2;
	}while(do2);


}


void CanteenBilling::generateBill(){
	int gtotal=0;
        node1 *cn1;

	cout<<"\n****************Bill Receipt******************"<<endl;
	cout<<"NAME\t\t"<<"QUANTITY\t\t"<<"PRICE"<<endl;
	cn1=header1;

        node*ccn;
	while (cn1!=NULL) {

            ccn=header;
            while(ccn)
            {

                if(ccn->keyword != cn1->keyword1)
                {
                    ccn=ccn->next;
                }
                else
                    break;


            }
            cout<<ccn->name<<"\t\t";

        cout<<cn1->qty1<<"\t\t\t";
        cout<<cn1->price1;
        //doing total of each food item in bill side by side;
        gtotal=gtotal+cn1->price1;
        cout << "\n";
        cn1 = cn1->next1;

    }

    cout<<"\t\tTOTAL : "<<gtotal;
    cout<<"\nTHANK YOU...........VISIT AGAIN";
    //preparing for customer
    header1=NULL;
}


int main(){


	CanteenBilling c1;
	int sw;

        cout<<"\n******SURYA SNACKS******\n";
	cout<<"\nKeyWords are :"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"s  - Samosa"<<endl;
	cout<<"v -  VadaPav"<<endl;
	cout<<"t  - Tea "<<endl;
	cout<<"p  - Pohe"<<endl;
	cout<<"u  - Upma"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl;
	int c;
        do{
        	c1.getMenu();

		cout<<"\nPress 1 to enter another Food item in Menu Else 0 : ";
		cin>>c;
	}while(c);


	int do1,do3;
	do{
            do
            {
		cout<<"\nEnter (1). To Dispaly Menu";
		cout<<"\nEnter (2). To Placed Order";
		cin>>sw;
     		switch(sw){

			case 1:
					c1.displayMenu();
					break;

			case 2:
					c1.placeOrder();
					break;
		}cout<<"Enter 1 to continue single person's order else 0 :";
                cin>>do3;

            }while(do3);
		//calling the bill function for "a person";
		c1.generateBill();
		cout<<"\nEnter 1 To Take Next Person Order Else 0 : ";
		cin>>do1;

	}while(do1);
	return 0;
}
