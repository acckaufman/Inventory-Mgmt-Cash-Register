#include <iostream>
#include <iomanip>
#include "InventoryItem.h"
#include "CashRegister.h"
using namespace std;

double orderTotal;						//Global accumulator variable for the total of the whole order

int main()
{
	char again;							//Hold user input for repeat
	const int ARRAY_SIZE = 5;			//Hold the number of different products available for sale
	InventoryItem stock[ARRAY_SIZE];	//Array to hold the information about the items for sale

	//*****************************************************************************************************
	//Initialize the stock array with the product information
	//Set values manually, since the default constructor was used and no initial values were entered.

	//Item descriptions, entered manually
	char item1[] = { "Adjustable Wrench" };
	char item2[] = { "Screwdriver" };
	char item3[] = { "Pliers" };
	char item4[] = { "Ratchet" };
	char item5[] = { "Socket Wrench" };

	//Assign the descriptions to the InventoryItem attributes manually
	stock[0].setDescription(item1);	//Adjustable Wrench
	stock[1].setDescription(item2);	//Screwdriver
	stock[2].setDescription(item3);	//Pliers
	stock[3].setDescription(item4);	//Ratchet
	stock[4].setDescription(item5);	//Socket Wrench

	//Assign quantities on hand to each item
	stock[0].setUnits(10);	//Adjustable Wrench
	stock[1].setUnits(20);	//Screwdriver
	stock[2].setUnits(35);	//Pliers
	stock[3].setUnits(10);	//Ratchet
	stock[4].setUnits(7);	//Socket Wrench

	//Assign prices to each item
	stock[0].setCost(9.99);		//Adjustable Wrench
	stock[1].setCost(4.49);		//Screwdriver
	stock[2].setCost(8.79);		//Pliers
	stock[3].setCost(15.89);	//Ratchet
	stock[4].setCost(12.99);	//Socket Wrench

	//End initialization
	//*****************************************************************************************************

	//Repeat the following program as long as the user wants to keep buying stuff
	do {
		int selection;				//Variable to hold the user's selection
		int qty = 0;				//Variable to hold the quantity ordered by the user
		CashRegister purchase;		//Create a CashRegister object to handle this purchase

		//Display the menu for the user
		cout << setw(5) << left << "#" << setw(20) << left << "Item" << setw(15) << left << "Qty on Hand" << endl;
		cout << "----------------------------------------" << endl;
		for (int count = 0; count < ARRAY_SIZE; count++)
		{
			cout << setw(5) << left << (count + 1)
				<< setw(20) << left << stock[count].getDescription()
				<< setw(15) << left << stock[count].getUnits() << endl;
		}

		//Ask the user for the item being purchased
		cout << endl << "Which item # above is being purchased? ";
		cin >> selection;

		//Input validation: Only allow numbers from the list to be selected
		while (selection < 1 || selection > 5)
		{
			cout << "Error! You must make a valid menu selection.  Please try again." << endl;
			cout << "Which item # above is being purchased? ";
			cin >> selection;
		}

		//Ask the user for the quantity being purchased
		cout << "How many units? ";
		cin >> qty;

		//Input validation: Do not accept a negative number of units to be ordered
		while (qty < 1)
		{
			cout << "Error: You must enter a positive quantity.  Please try again." << endl;
			cout << "How many units? ";
			cin >> qty;
		}

		//Input validation: Make sure there are enough units on hand to fulfill the user's request
		while (qty > stock[selection - 1].getUnits())
		{
			cout << "Error: There are only " << stock[selection - 1].getUnits() << " units on hand for that item. Please try again." << endl;
			cout << "How many units? ";
			cin >> qty;
		}

		//Use the item number entered by the user to retrieve the cost of the corresponding item from the InventoryItem object
		double cost;	//Temporary holder for the cost of the item selected
		cost = stock[(selection - 1)].getCost();

		//For testing purposes only:
		//Display the item's raw cost
		//cout << left << setw(12) << "Item Cost: ";
		//cout << setw(1) << "$";
		//cout << setw(7) << right << fixed << showpoint << setprecision(2) << cost << endl;

		//Calculate the unit price of the item based on cost.
		purchase.calcUnitPrice(cost);

		//For testing purposes only:
		//Display the unit price
		//cout << left << setw(12) << "Unit Price ";
		//cout << setw(1) << "$";
		//cout << setw(7) << right << fixed << showpoint << setprecision(2) << purchase.getUnitPrice() << endl;

		//Calculate purchase subtotal (quantity times unit cost of item;
		purchase.calcPurchaseSubtotal(qty);

		//Display the purchase subtotal
		cout << endl << left << setw(12) << "Subtotal: ";
		cout << setw(1) << "$";
		cout << setw(7) << right << fixed << showpoint << setprecision(2) << purchase.getPurchaseSubtotal() << endl;

		//Calculate the sales tax on the order
		purchase.calcSalesTax();

		//Display the sales tax charged for the user
		cout << left << setw(12) << "Sales Tax: ";
		cout << setw(1) << "$";
		cout << setw(7) << right << fixed << showpoint << setprecision(2) << purchase.getSalesTax() << endl;

		//Calculate the purchase total
		purchase.calcPurchaseTotal();

		//Display the purchase total for the user
		cout << left << setw(12) << "Total: ";
		cout << setw(1) << "$";
		cout << setw(7) << right << fixed << showpoint << setprecision(2) << purchase.getPurchaseTotal() << endl;

		//Add the purchase subtotal to the external accumulator variable, to add up the grand total of the order
		orderTotal += purchase.getPurchaseTotal();

		//Modify the existing inventory's unit quantity
		int beginningUnits = stock[selection - 1].getUnits();	//Retrieve the starting number of units
		int endingUnits = beginningUnits - qty;					//Subtract the quantity ordered by the user to get the final number of units
		stock[selection - 1].setUnits(endingUnits);				//Store the new number of units on hand in the inventory item's unit quantity attribute

		//Ask the user if they want to run the program again
		cout << endl << "Do you want to purchase another item? (y/n): ";
		cin >> again;
		cout << endl;

	} while (again == 'y' || again == 'Y');		//As long as the user wants to keep buying stuff

	//Display the final purchase total for the user
	cout << "Final order total: $" << orderTotal << endl << endl;

	//Pause the system window open
	system("pause");
	return 0;
}