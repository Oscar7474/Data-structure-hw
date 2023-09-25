#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};

class ArrayPolynomial {
public:
	PolynomialTerm terms[MAX_TERMS];

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo)//revise 
	{
		// modify the following code and add your code here
		int i = 0, j = 0;
		if (coef == 0) {
			return;
		}
		for (i = 0; i < MAX_TERMS && terms[i].coef != 0; i++) {
			if (terms[i].expo > expo) {
				for (j = i + 1; terms[j].coef != 0; j++);
						while (j != i) {
							terms[j] = terms[j - 1];
							j--;
						}
						terms[i].expo = expo;
						terms[i].coef = coef;
						return;
				
				
			}

		}
		terms[i].expo = expo;
		terms[i].coef = coef;
		return;
	}

	void printArrayBasedPoly()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				cout << " + " << terms[i].coef;
			else
				cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	void showArrayBasedPolyMaxTerm()
	{
		PolynomialTerm term = findArrayBasedPolyMaxTerm(0);

		if (term.coef == 0)
			return;

		if (term.expo == 0)
			cout << term.coef;
		else
			cout << term.coef << "X^" << term.expo;
	}

	PolynomialTerm findArrayBasedPolyMaxTerm(int i)
	{
		PolynomialTerm term;
		term.expo = 0;
		term.coef = 0;
		if (i == MAX_TERMS) {
			return term;
		}
		term = findArrayBasedPolyMaxTerm(i + 1);

		if (terms[i].expo > term.expo) {
			return terms[i];
		}
		else if (terms[i].expo < term.expo) {
			return term;
		}
		else {
			if (terms[i].coef > term.coef) {
				return terms[i];
			}
			else {
				return term;
			}
		}
		 

	}

	void ArrayBasedRotateTerms() {
		int last = 0;
		PolynomialTerm term;

		for (int i = 0; i < MAX_TERMS&&terms[i].coef != 0; i++) {
			last = i - 1;
		}
		term.expo=terms[0].expo;
		term.coef=terms[0].coef;

		for (int i = 0; i < last; i++) {
			terms[i].expo = terms[i + 1].expo;
			terms[i].coef = terms[i + 1].coef;
		}
		terms[last].expo = term.expo;
		terms[last].coef = term.coef;
	}

	void copy(ArrayPolynomial& poly)
	{
		for (int i = 0; i < MAX_TERMS && poly.terms[i].coef != 0; i++) {
			terms[i].coef = poly.terms[i].coef;
			terms[i].expo = poly.terms[i].expo;
		}
	}

	void compactCopy(ArrayPolynomial& poly)
	{
		copy(poly);

		for (int i = 0; i < MAX_TERMS&& terms[i].coef != 0; i++) {
			for (int j=i+1; j < MAX_TERMS && terms[j].coef != 0; j++) {
				if (terms[i].expo = terms[j].expo) {
					terms[i].coef += terms[j].coef;
					for (int k = j; k < MAX_TERMS && terms[k].coef != 0; k++) {
						terms[k].coef = terms[k + 1].coef;
						terms[k].expo = terms[k + 1].expo;
					}
				}
			}
			if (terms[i].coef == 0) {
				for (int k = i; k < MAX_TERMS && terms[k].coef != 0; k++) {
					terms[k].coef = terms[k + 1].coef;
					terms[k].expo = terms[k + 1].expo;
				}
			}
		}
	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm* nextTermPtr;
};

class LinkedPolynomial {
public:
	LinkedPolynomialTerm* polynomialTermPtr = nullptr;

	void clear()
	{
		LinkedPolynomialTerm* tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		LinkedPolynomialTerm* tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;

		return;
	}

	void printLinkBasedPoly()
	{
		LinkedPolynomialTerm* termPtr = polynomialTermPtr;

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

	void showLinkBasedPolyMaxTerm()
	{
		LinkedPolynomialTerm* termPtr = findLinkBasedPolyMaxTerm(polynomialTermPtr);

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;
	}

	LinkedPolynomialTerm* findLinkBasedPolyMaxTerm(LinkedPolynomialTerm* currPtr)
	{
		LinkedPolynomialTerm* cur = nullptr;

		if (currPtr == nullptr) {
			return currPtr;
		}
		cur = findLinkBasedPolyMaxTerm(currPtr->nextTermPtr);
		if (cur == nullptr) {
			return currPtr;
		}
		else if (cur->expo > currPtr->expo) {
			return cur;
		}
		else if (cur->expo < currPtr->expo) {
			return currPtr;
		}
		else {
			if (cur->coef > currPtr->coef) {
				return cur;
			}
			else {
				return currPtr;
			}
		
		}
	}

	void LinkBasedRotateTerms() {

		if (polynomialTermPtr == nullptr || polynomialTermPtr->nextTermPtr == nullptr) {
			return;//1 2 3 
		}
		LinkedPolynomialTerm* cur = polynomialTermPtr;//1

		polynomialTermPtr = polynomialTermPtr->nextTermPtr;

		LinkedPolynomialTerm* tmp = polynomialTermPtr;//2

		while (cur->nextTermPtr) {//3			cur tmp  2 3 1               
			cur = cur->nextTermPtr;//123  231  // 1->2<  2 -> 1
		}

			cur->nextTermPtr = tmp;
			tmp->nextTermPtr = nullptr;
	}
	
	void copy(LinkedPolynomial& poly)
	{
		if (poly.polynomialTermPtr == nullptr) {
			return;
		}
		LinkedPolynomialTerm* orign = poly.polynomialTermPtr;
		LinkedPolynomialTerm* tmp = new LinkedPolynomialTerm();
		LinkedPolynomialTerm* cur;
		tmp->coef = orign->coef;
		tmp->expo = orign->expo;
		orign = orign->nextTermPtr;
		polynomialTermPtr = tmp;
		cur = tmp;
		while (orign) {
			LinkedPolynomialTerm* tmp = new LinkedPolynomialTerm();
			tmp->coef = orign->coef;
			tmp->expo = orign->expo;
			cur->nextTermPtr = tmp;
			cur = tmp;
			orign = orign->nextTermPtr;
		}
		cur->nextTermPtr = nullptr;
	}

	void compactCopy(LinkedPolynomial& poly)
	{
		copy(poly);
		LinkedPolynomialTerm* cur = polynomialTermPtr;
		LinkedPolynomialTerm* tmp;
		LinkedPolynomialTerm* prev = nullptr;
		LinkedPolynomialTerm* rellprev = nullptr;

		while (cur) {

			tmp = cur->nextTermPtr;
			prev = cur;
			while (tmp) {

				if (tmp->expo == cur->expo) {

					cur->coef = cur->coef + tmp->coef;

					if (prev) {
						prev->nextTermPtr = tmp->nextTermPtr;
						delete tmp;
						tmp = prev->nextTermPtr;
					}
					else {
						polynomialTermPtr = tmp->nextTermPtr;
						delete tmp;
						tmp = polynomialTermPtr;
					}
				}
				else {
					prev = tmp;
					tmp = tmp->nextTermPtr;
				}
			}
			if (cur->coef == 0) {
				if (rellprev) {
					rellprev->nextTermPtr = cur->nextTermPtr;
					delete cur;
					cur = rellprev->nextTermPtr;
				}
				else {
					polynomialTermPtr = cur->nextTermPtr;
					delete cur;
					cur = polynomialTermPtr;
				}
			}
			else {
				rellprev = cur;
				cur = cur->nextTermPtr;
			}
		}
	}
};
