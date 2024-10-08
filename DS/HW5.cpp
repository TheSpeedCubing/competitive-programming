// HW5.cpp : 定義主控台應用程式的進入點。
//

#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm { 
public:                          
	int coef;
	int expo;
};                                                                          /////
                                                                         
class ArrayPolynomial {                                        /////
public:                                                                  /////
	PolynomialTerm terms[MAX_TERMS]; /////

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo) /////
	{

		// add your code here
		for(int i = 0; i < MAX_TERMS; i++ ) {
			if(terms[i].expo == expo) {
				terms[i] = {coef,expo};
				if(coef == 0) {
					while(i < MAX_TERMS-1) {
						terms[i] = terms[i+1];
						i++;
					}
				}
				return;
			}
			if(terms[i].expo < expo) {
				//insert
				if(coef == 0) {
					return;
				}
				for(int j = MAX_TERMS-1;j>i;j--) {
					terms[j] = terms[j-1];
				}
				terms[i] = {coef,expo};
				return;
			}
		}
		return;
	}

	void addArrayBasedPoly(ArrayPolynomial &a, ArrayPolynomial &b) /////
	{

		// add your code here

		ArrayPolynomial* r = new ArrayPolynomial;
		for(int i = 0;i<MAX_TERMS;i++) {
			r->terms[i].coef = 0;
			r->terms[i].expo = 0;
		}
		int i = 0,j=0,k=0;
		while(a.terms[i].coef && b.terms[j].coef) {
			if(a.terms[i].expo > b.terms[j].expo) {
				r->terms[k++] = a.terms[i++];
			} else if(a.terms[i].expo < b.terms[j].expo) {
				r->terms[k++] = b.terms[j++];
			} else {
				r->terms[k].expo = a.terms[i].expo;	
				r->terms[k++].coef = a.terms[i++].coef + b.terms[j++].coef;
			}
		}
	
		while(a.terms[i].coef) {
			r->terms[k++] = a.terms[i++];
		}
	
		while(b.terms[j].coef) {
			r->terms[k++] = b.terms[j++];
		}
	
		//clear zero coef
		int i2 = 0;
		for(int i = 0;i<MAX_TERMS;i++) {
			if(r->terms[i].coef != 0) {
				terms[i2++] = r->terms[i];
			}
		}
		return;
	}	

	void reverseArrayBasedPoly() /////
	{

		// add your code here
		int count = 0;
		for(int i = 0;i<MAX_TERMS;i++) {
			if(terms[i].coef != 0) {
				count++;
			}
		}
		for(int i = 0;i<count/2;i++) {
			swap(terms[i],terms[count-i-1]);
		}
		return;
	}

	void printArrayBasedPoly() /////
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			std::cout << terms[0].coef;
		else
			std::cout << terms[0].coef << "X^" << terms[0].expo;

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

	int compute(int x) 
	{                          
		// add your code here
		int result = 0;
		for(int i = 0;i<MAX_TERMS;i++) {
			int t = terms[i].coef;
			for(int j = 0;j<terms[i].expo;j++) {
				t *= x;
			}
			result += t;
		}

		return result;
	}                           
};                                                                
	
class LinkedPolynomialTerm {                       
public:                                                          
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr; /////
};                                                                  /////

class LinkPolynomial {                                /////
public:                                                          /////
	LinkedPolynomialTerm *polynomialTermPtr = nullptr; /////

	void clear() /////
	{
		LinkedPolynomialTerm *tmpPtr;                       

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}
    
	//custom methods	
	void addHelper(LinkedPolynomialTerm *&polyPtr, int coef, int expo,bool add) {
		if (polyPtr == NULL || polyPtr->expo < expo) {
			LinkedPolynomialTerm *tmpPtr = new LinkedPolynomialTerm;
			tmpPtr->coef = coef;
			tmpPtr->expo = expo;
			tmpPtr->nextTermPtr = polyPtr;
			polyPtr = tmpPtr;
		} else if(polyPtr->expo == expo) { //update value
			polyPtr->coef = (add ? polyPtr->coef : 0)+ coef;
		} else { //iterate to next
			addHelper(polyPtr->nextTermPtr,coef,expo,add);
		}
	}

	void removeZero(LinkedPolynomialTerm** n) {
		if (*n == NULL) 
			return;

		if ((*n)->coef == 0) {
			LinkedPolynomialTerm* temp = *n;
			*n = (*n)->nextTermPtr;
			delete temp;
			removeZero(n);
		} else {
			removeZero(&(*n)->nextTermPtr);
		}
	}

	void inputLinkTerms(int coef, int expo) /////
	{
		LinkedPolynomialTerm *tmpPtr;                                                 

		tmpPtr = new LinkedPolynomialTerm;                                        
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;


		// add your code here 
		addHelper(polynomialTermPtr,coef,expo,false);
		removeZero(&polynomialTermPtr);

		return;
	}

	void addLinkBasedPoly(LinkPolynomial &aPol, LinkPolynomial &bPol) /////
	{
                         /////


		// add your code here
		while(aPol.polynomialTermPtr != nullptr) {
			addHelper(polynomialTermPtr,aPol.polynomialTermPtr->coef,aPol.polynomialTermPtr->expo,true);
			aPol.polynomialTermPtr = aPol.polynomialTermPtr->nextTermPtr;
		}
		while(bPol.polynomialTermPtr != nullptr) {
			addHelper(polynomialTermPtr,bPol.polynomialTermPtr->coef,bPol.polynomialTermPtr->expo,true);
			bPol.polynomialTermPtr = bPol.polynomialTermPtr->nextTermPtr;
		}

		removeZero(&polynomialTermPtr);
		return;
	}

	void reverseLinkBasedPoly() /////
	{
		/////


		// add your code here    
		
		//empty
		if(polynomialTermPtr == nullptr) {
			return;
		}
		LinkedPolynomialTerm *prev = nullptr;
		LinkedPolynomialTerm *curr = polynomialTermPtr;
		LinkedPolynomialTerm *next = curr->nextTermPtr;

		while (next != nullptr) {
			//point to the last one
			curr->nextTermPtr = prev;
			//step forward
			prev = curr;
			curr = next;
			next = next->nextTermPtr;
		}
		//assign last one
		curr->nextTermPtr = prev;
		//replace
		polynomialTermPtr = curr;
		return;
	}

	void printLinkBasedPoly()                                                            /////
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr; /////

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

	int compute(int x) 	
	{



		// add your code here
		int result = 0;
		LinkedPolynomialTerm* cur = polynomialTermPtr;
		while(cur != NULL) {
			int t = cur->coef;
			for(int i = 0;i<cur->expo;i++) {
				t*= x;
			}
			result += t;
			cur = cur->nextTermPtr;
		}

		return result;
	}
}; 

int main()
{
	ArrayPolynomial a, b, d;                                                              /////
	LinkPolynomial aPol, bPol, dPol;                                             /////

	int coef, expo, x;

          // aPtr = bPtr = dPtr = nullptr; /////

	while (1) {
		a.clear(); b.clear(); d.clear();                                    /////
                      // aPtr->clear(aPtr); bPtr->clear(bPtr); dPtr->clear(dPtr); /////


		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			a.inputTerms(coef, expo);             /////
			aPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\na = ";
		a.printArrayBasedPoly();     /////
		cout << "\na = ";
		aPol.printLinkBasedPoly(); /////
		cout << "\n";

		for (int i = 0; i < MAX_TERMS; i++) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if (expo == 0 && coef == 0)
				break;

			b.inputTerms(coef, expo);             /////
			bPol.inputLinkTerms(coef, expo); /////
		}

		cout << "\n\nb = ";
		b.printArrayBasedPoly();      /////

		cout << "\nb = ";
		bPol.printLinkBasedPoly(); /////

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		d.addArrayBasedPoly(a, b); /////
		cout << "\na + b = ";
		d.printArrayBasedPoly();     /////

		dPol.addLinkBasedPoly(aPol, bPol); /////
		cout << "\na + b = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		d.reverseArrayBasedPoly(); /////
		cout << "\nreversed d = ";
		d.printArrayBasedPoly();     /////
		
		dPol.reverseLinkBasedPoly(); /////
		cout << "\nreversed d = ";
		dPol.printLinkBasedPoly();               /////

		cout << "\n";

		cout << "\ninput X: ";
		cin >> x;

		cout << "\nd = ";
		cout << d.compute(x);      //////

		cout << "\nd = ";
		cout << dPol.compute(x); //////

		cout << "\n";

		aPol.clear(); bPol.clear(); dPol.clear(); /////
	}

	return 0;
}
