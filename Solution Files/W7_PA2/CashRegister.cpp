#include "CashRegister.h"

//Default constructor
CashRegister::CashRegister()
{
	//Set the initial values to 0
	unitPrice = 0;			//Cost of unit with profit margin added
	purchaseSubtotal= 0;	//Unit price of item ordered by user * quantity ordered by user
	salesTax = 0;			//Amount of sales tax charged on the order
	purchaseTotal = 0;		//Order subtotal for each iteration that the user orders items
}

//Mutator functions
void CashRegister::calcUnitPrice(double c)
{
	const double PROFIT_RATE = 0.3;

	unitPrice = (c * PROFIT_RATE) + c;
}

void CashRegister::calcPurchaseSubtotal(int q)
{
	purchaseSubtotal = unitPrice * q;
}

void CashRegister::calcSalesTax()
{
	const double TAX_RATE = 0.06;

	salesTax = purchaseSubtotal * TAX_RATE;
}

void CashRegister::calcPurchaseTotal()
{
	purchaseTotal = purchaseSubtotal + salesTax;
}

//Accessor functions
double CashRegister::getUnitPrice() const
{
	return unitPrice;
}

double CashRegister::getPurchaseSubtotal() const
{
	return purchaseSubtotal;
}

double CashRegister::getSalesTax() const
{
	return salesTax;
}

double CashRegister::getPurchaseTotal() const
{
	return purchaseTotal;
}

//Deconstructor
CashRegister::~CashRegister()
{
}
