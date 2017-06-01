#pragma once
class CashRegister
{
private:
	double unitPrice;			//Cost of unit with profit margin added
	double purchaseSubtotal;	//Unit price of item ordered by user * quantity ordered by user
	double salesTax;			//Amount of sales tax charged on the order
	double purchaseTotal;		//Order subtotal for each iteration that the user orders items

public:
	//Default constructor
	CashRegister();

	//Mutator functions
	void calcUnitPrice(double c);
	void calcPurchaseSubtotal(int q);
	void calcSalesTax();				//Could be made private?
	void calcPurchaseTotal();			//Could be made private?

	//Accessor functions
	double getUnitPrice() const;
	double getPurchaseSubtotal() const;
	double getSalesTax() const;
	double getPurchaseTotal() const;

	//Deconstructor
	~CashRegister();
};

