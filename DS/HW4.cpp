// HW4.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

typedef struct{
	int coef;
	int expo;
} polynomialTerm;

typedef struct linkedTerm {
	int coef;
	int expo;
	linkedTerm *nextTermPtr;
} linkedPolynomialTerm;

void clear(polynomialTerm t[]) 
{
	for ( int i = 0; i < MAX_TERMS; i++ ) {
		t[i].coef = 0;
		t[i].expo = 0;
	}

	return;
}

void clear(linkedPolynomialTerm *&polynomialTermPtr) 
{
	linkedPolynomialTerm *tmpPtr;

	while ( polynomialTermPtr != nullptr ) {
		tmpPtr = polynomialTermPtr;
		polynomialTermPtr = polynomialTermPtr->nextTermPtr;
		delete tmpPtr;
	}
}

void inputTerms(polynomialTerm terms[], int coef, int expo)
{

	// add your code here
    for(int i = 0; i < MAX_TERMS; i++ ) {
		if(t[i].expo == expo) {
			t[i] = {coef,expo};
			if(coef == 0) {
			    while(i < MAX_TERMS-1) {
			        t[i] = t[i+1];
			        i++;
			    }
			}
			return;
		}
	    if(t[i].expo < expo) {
	        //insert
	        if(coef == 0) {
	            return;
	        }
			for(int j = MAX_TERMS-1;j>i;j--) {
				t[j] = t[j-1];
			}
			t[i] = {coef,expo};
			return;
	    }
	}
}

void inputLinkTerms(linkedPolynomialTerm *&polyPtr, int coef, int expo)
{
	linkedPolynomialTerm *tmpPtr;

	tmpPtr = new linkedPolynomialTerm;
	tmpPtr->coef = coef;
	tmpPtr->expo = expo;
	
	// add your code here

    //insert node
    if (polyPtr == NULL || polyPtr->expo < expo) {
        tmpPtr->nextTermPtr = polyPtr;
        polyPtr = tmpPtr;
    } else if(polyPtr->expo == expo) { //update value
        polyPtr->coef = coef;
    } else { //iterate to next
        inputLinkTerms(polyPtr->nextTermPtr,coef,expo);
        free(tmpPtr);
    }
}


void addArrayBasedPoly(polynomialTerm a[], polynomialTerm b[], polynomialTerm d[])
{
	// add your code here
	polynomialTerm r[MAX_TERMS];
	clear(r);
	int i = 0,j=0,k=0;
	while(a[i].coef && b[j].coef) {
		if(a[i].expo > b[j].expo) {
			r[k++] = a[i++];
		} else if(a[i].expo < b[j].expo) {
			r[k++] = b[j++];
		} else {
			r[k].expo = a[i].expo;	
		    r[k++].coef = a[i++].coef + b[j++].coef;
		}
	}
	
	while(a[i].coef) {
		r[k++] = a[i++];
	}
	
	while(b[j].coef) {
		r[k++] = b[j++];
	}
	
	//clear zero coef
	int i2 = 0;
	for(int i = 0;i<MAX_TERMS;i++) {
	    if(r[i].coef != 0) {
	        d[i2++] = r[i];
	    }
	}
}


void helper(linkedPolynomialTerm *&polyPtr, int coef, int expo) {
    //insert node
    if (polyPtr == NULL || polyPtr->expo < expo) {
	    linkedPolynomialTerm *tmpPtr = new linkedPolynomialTerm;
	    tmpPtr->coef = coef;
	    tmpPtr->expo = expo;
        tmpPtr->nextTermPtr = polyPtr;
        polyPtr = tmpPtr;
    } else if(polyPtr->expo == expo) { //update value
        polyPtr->coef += coef;
    } else { //iterate to next
        helper(polyPtr->nextTermPtr,coef,expo);
    }
}

linkedPolynomialTerm *addLinkBasedPoly(linkedPolynomialTerm *aPtr, linkedPolynomialTerm *bPtr)
{
	linkedPolynomialTerm *dPtr;
	// add your code here
	dPtr = nullptr;
	while(aPtr != nullptr) {
	    helper(dPtr,aPtr->coef,aPtr->expo);
	    aPtr = aPtr->nextTermPtr;
	}
	while(bPtr != nullptr) {
	    helper(dPtr,bPtr->coef,bPtr->expo);
	    bPtr = bPtr->nextTermPtr;
	}

	return dPtr;
}

void printArrayBasedPoly(polynomialTerm terms[])
{
	if ( terms[0].coef == 0 ) 
		return;

	if ( terms[0].expo == 0 )
		cout << terms[0].coef;
	else
		cout << terms[0].coef << "X^" << terms[0].expo;

	for ( int i = 1; i < MAX_TERMS; i++ ) {
		if ( terms[i].coef == 0 ) 
			return;

		if ( terms[i].expo == 0 )
			cout << " + " << terms[i].coef;
		else
			cout << " + "<< terms[i].coef  << "X^" << terms[i].expo;
	}
}

void printLinkBasedPoly(linkedPolynomialTerm *polyPtr)
{
	linkedPolynomialTerm *termPtr =  polyPtr;

	if ( termPtr  == nullptr )
			return;

	if ( termPtr->expo == 0 )
		cout << termPtr->coef;
	else
		cout << termPtr->coef << "X^" << termPtr->expo;

	termPtr  = termPtr->nextTermPtr;
	
	while ( termPtr  != nullptr ) {
		if ( termPtr->coef == 0 ) 
			return;

		if ( termPtr->expo == 0 )
			cout << " + " << termPtr->coef;
		else
			cout << " + "<< termPtr->coef  << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;
	}
}

int main()
{
	polynomialTerm a[MAX_TERMS], b[MAX_TERMS], d[MAX_TERMS];
	linkedPolynomialTerm *aPtr, *bPtr, *dPtr;

	int coef, expo;

	aPtr = bPtr = dPtr = nullptr;

	while (1) {
		clear( a ); clear( b ); clear( d );
		clear( aPtr ); clear( bPtr ); clear( dPtr );

		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput a's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerms( a, coef, expo );
			inputLinkTerms( aPtr, coef, expo );
		}

		cout << "\n\na = ";
		printArrayBasedPoly( a );
		cout << "\na = ";
		printLinkBasedPoly( aPtr );
		cout << "\n";
		
		for ( int i = 0; i < MAX_TERMS; i++ ) {
			cout << "\ninput b's coefficient and exponent: ";
			cin >> coef >> expo;

			if ( expo == 0 && coef == 0 )
				break;

			inputTerms( b, coef, expo );
			inputLinkTerms( bPtr, coef, expo );
		}

		cout << "\n\nb = ";
		printArrayBasedPoly( b );

		cout << "\nb = ";
		printLinkBasedPoly( bPtr );

		cout << "\n";

		// d =a + b, where a, b, and d are polynomials

		addArrayBasedPoly( a, b, d );
		cout << "\na + b = ";
		printArrayBasedPoly( d );
		
		dPtr = addLinkBasedPoly( aPtr, bPtr );
		cout << "\na + b = ";
		printLinkBasedPoly( dPtr );

		cout << "\n";
	}
	return 0;
}
 
