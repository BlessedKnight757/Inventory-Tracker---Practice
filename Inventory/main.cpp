/*
Author: Brandon Kennedy

This is an old program that I got a decent grade on in class, 
but I never got it working correctly. I want to get this program running
the right way, so I can get better at coding. 

The program should run as follows:
1: Menu Prompt should ask the user what it would like to do. There are 
seven different choices: 
(1)Make a record of a new item
(2)Make an alphabetic ordered list of the items made
(3)Make an descending ordered list of the items made
(4)Display the total quantity of all items that were made
(5)Display the total value of all the items that were made
(6)Display a list of insured items only
(7)Ends the program

2: Invalid entries such as char or strings should display an error message
without causing the program to crash.

3: If a new item has not been made, menu prompts 2, 3, and 6 should display
a message that there was no items made.

4: Each menu option should have its own block of code seperate from main.

I am trying to avoid the use of global variables. I am trying to make the 
most efficient code I can with what I am trying to accomplish.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct items
{
	string name;
	int quantity;
	float price;
	char insured;
};

int main()
{
	int option1(int);//Prototypes for the menu prompt options
	int option2(int);
	int option3(int);
	int option4(int);
	int option5(int);
	int option6(int);
	int option7(int);
	
	int opt;//Menu Input Variable
    	int i_count = 0;//Tracks the items recorded
    	int control;//Loop Control Variable
    	int stop;//Loop Control Variable - While Loops
    	int t_quantity = 0;//Tracks total Quantity
	float sum = 0.0;//Tracks total value of each item
	items *item = new items[20];//Holds the items created

	while(opt != 7)
	{
		cout<<"Inventory Tracker\n"<<endl;
		cout<<"1. New Item(s)"<<endl;
		cout<<"2. Total Items (Alpha)"<<endl;
		cout<<"3. Total Items (Descending)"<<endl;
		cout<<"4. Total Quantity"<<endl;
		cout<<"5. Total Value"<<endl;
		cout<<"6. Insured Items"<<endl;
		cout<<"7. Quit"<<endl;
		cout<<"______________________________"<<endl;
		cin>>opt;

		if(opt < 1 || opt > 7)//Input Validation
		{
        		cout<<"Error:Invalid Entry!"<<endl;
        		cout<<"Please enter a valid option."<<endl;
        		cout<<"1. New Item(s)"<<endl;
			cout<<"2. Total Items (Alpha)"<<endl;
			cout<<"3. Total Items (Descending)"<<endl;
			cout<<"4. Total Quantity"<<endl;
			cout<<"5. Total Value"<<endl;
			cout<<"6. Insured Items"<<endl;
			cout<<"7. Quit"<<endl;
			cout<<"______________________________"<<endl;
			cin>>opt;
		}

		if(opt == 1)//Make New Item Record
		{
			cout<<"\nPlease enter item name: ";
			cin>>item[i_count].name;
			cout<<"\nPlease enter item quantity: ";
			cin>>item[i_count].quantity;
			t_quantity += item[i_count].quantity;
			cout<<"\nPlease enter item price: ";
			cin>>item[i_count].price;

			if(item[i_count].price > 10000)
			{
				while(stop == 0)//Valid Price check
				{
					cout<<"Price should not exceed $10,000. Please try again." << endl;
					cin>>item[i_count].price;
					if(item[i_count].price < 10001)
						stop = 1;
				}
			}

			cout<<"\nIs this item insured? Y/N: ";//Insured question
			cin>>item[i_count].insured;
			if((item[i_count].insured == 'Y' || item[i_count].insured == 'y') && (item[i_count].insured == 'N' || item[i_count].insured == 'n'))
			{
				while(stop == 1)//Checks for Y or N
				{
					cout << "Insured can not be empty. Please enter Y/N: ";
					cin >> item[i_count].insured;
					if((item[i_count].insured == 'Y' || item[i_count].insured == 'y') && (item[i_count].insured == 'N' || item[i_count].insured == 'n'))
						stop = 0;//ends loop
				}
			}
			i_count++;//New item has been made
		}
		else if(opt== 2)//Option 2 -couldn't figure out how to order this
		{
			string display = item[i_count].name;
			if(i_count == 0)
			{
				cout << "List is empty!"<<endl;//Checks for empty list
			}
			for(control = 0; control < i_count; control++)
			{
				if(item[control].name < display)
                			{
                    				cout<<"\nItem name: "<<display<<endl;
                    				cout<<"\nPrice: $"<<item[i_count].price<<endl;
                			}
                		else
					{
		    				cout<< "\nItem name: "<<item[control].name<< endl;
                    				cout<< "\nPrice: $"<<item[control].price << endl;
					}
			}
		}
		else if(opt==3)//Option 3 - couldn't figure this one out either
        	{
            		float h_price = item[i_count].price;
            		if(i_count == 0)
			{
				cout <<"List is empty!"<<endl;//Checks for empty list
			}

			for(control = 0; control < i_count; control++)
			{
				if(h_price > item[control].price)
                		{
                			cout << "\nItem name: "<<item[i_count].name<< endl;	//Displays item in list form
					cout << "\nPrice: $"<<h_price<<endl;
               			}
                		else
                		{
                    			cout<<"\n\nItem name: "<<item[control].name<<endl;//
                    			cout<<"\nPrice: $"<<item[control].price<<endl;
				}
        	}
			
		else if(opt==4)//Option 4
			cout<<"Total quantity of item is: "<<t_quantity<<endl;//Total items quantity
		
		else if(opt == 5)//Option 5
		{
			if(i_count == 0)
			{
				cout<<"List is empty!"<<endl;//Checks for an empty list
			}
			for(control = 0; control < i_count; control++)//Displays the total value of items
                	sum = sum + item[control].quantity * item[control].price;
			
			cout.setf(ios::fixed);
			cout<<setprecision(2)<<endl;
			cout<<"Total value of all asset is: $" <<sum<<'\n'<<endl;
		}
		else if(opt == 6)
		{
			if(i_count == 0)
			{
				cout<<"List is empty!"<<endl;
			}
			for(control = 0; control<i_count; control++);
			{
				if(item[control].insured == 'n' || item[control].insured == 'N')//Displays insured items
				cout<< "\n\nItem name: "<<item[control].name<<endl;
				cout<< "\nQuantity: "<<item[control].quantity<<endl;
				cout<< "\nPrice: $"<<item[control].price<<endl;
				cout<< "\nInsured: "<<item[control].insured<<endl;
			}
		}
		else
		return 0;
	}
}
