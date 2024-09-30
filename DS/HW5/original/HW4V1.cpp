// HW4V1.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm { /////
public:                            /////
	int coef;
	int expo;
                                       /////

	void clear(PolynomialTerm terms[])      /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(PolynomialTerm terms[], int coef, int expo)      /////
	{

		// add your code here

		return;
	}

	void addArrayBasedPoly(PolynomialTerm a[], PolynomialTerm b[], PolynomialTerm terms[])     /////
	{

		// add your code here

		return;
	}

	void printArrayBasedPoly(PolynomialTerm terms[])      /////
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			std::cout << terms[0].coef;                                            /////
		else
			std::cout << terms[0].coef << "X^" << terms[0].expo; /////

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				std::cout << " + " << terms[i].coef;
			else
				std::cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}
};                                                                 /////

class LinkedPolynomialTerm {                   /////
public:                                                         /////
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr; /////
                                                                              /////

	void clear(LinkedPolynomialTerm *&polynomialTermPtr)      /////
	{
		LinkedPolynomialTerm *tmpPtr;                              /////

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputLinkTerms(LinkedPolynomialTerm *&polyPtr, int coef, int expo)    /////
	{
		LinkedPolynomialTerm *tmpPtr;                                                         /////

		tmpPtr = new LinkedPolynomialTerm;                                                /////
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;


		// add your code here 


		return;
	}

	LinkedPolynomialTerm *addLinkBasedPoly(LinkedPolynomialTerm *aPtr, LinkedPolynomialTerm *bPtr)        /////
	{
		LinkedPolynomialTerm *dPtr = nullptr;                         /////


		// add your code here


		return dPtr;
	}

	void printLinkBasedPoly(LinkedPolynomialTerm *polyPtr)        /////
	{
		LinkedPolynomialTerm *termPtr = polyPtr;                   /////

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;

		while (termPtr != nullptr) {
			if (termPtr->coef == 0)
				return;

			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}
}; /////

int _tmain(int argc, _TCHAR* argv[])
{
	PolynomialTerm a[MAX_TERMS], b[MAX_TERMS], d[MAX_TERMS];     /////
	LinkedPolynomialTerm *aPtr, *bPtr, *dPtr;                                                      /////

	int coef, expo;

	aPtr = bPtr = dPtr = nullptr;

	while (1) {
		a[0].clear(a); b[0].clear(b); d[0].clear(d);                               /////
		aPtr->clear(aPtr); bPtr->clear(bPtr); dPtr->clear(dPtr);          /////

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			a[0].inputTerms(a, coef, expo);                /////
			aPtr->inputLinkTerms(aPtr, coef, expo); /////
		}

		cout << "\n\na = ";
		a[0].printArrayBasedPoly(a);      /////
		cout << "\na = ";
		aPtr->printLinkBasedPoly(aPtr); /////
		cout << "\n";

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			b[0].inputTerms(b, coef, expo);              /////
			bPtr->inputLinkTerms(bPtr, coef, expo); /////
		}

		cout << "\n\nb = ";
		b[0].printArrayBasedPoly(b);      /////

		cout << "\nb = ";
		bPtr->printLinkBasedPoly(bPtr); /////

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		d[0].addArrayBasedPoly(a, b, d); /////
		cout << "\na + b = ";
		d[0].printArrayBasedPoly(d);      /////

		dPtr = dPtr->addLinkBasedPoly(aPtr, bPtr); /////
		cout << "\na + b = ";
		dPtr->printLinkBasedPoly(dPtr);                  /////

		cout << "\n";
	}

	return 0;
}
