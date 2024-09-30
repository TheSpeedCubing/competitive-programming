// HW0.cpp : 定義主控台應用程式的進入點。
//

#include "stdio.h"
#include "stdlib.h"
#include "iostream"

using namespace std;

#define MAX 5

struct Node
{
	int item;
	Node* next;
};

typedef Node* nodePtr;

void display(Node* currentPtr) {
	while (currentPtr != nullptr) {
		cout << currentPtr->item << " ";
		currentPtr = currentPtr->next;
	}

}

Node* inputData(int num, nodePtr headPtr)
{
	nodePtr currentPtr = headPtr;
	nodePtr previousPtr = nullptr;

	nodePtr tmpPtr = new Node;
	tmpPtr->item = num;
	tmpPtr->next = nullptr;

	if (headPtr == nullptr)
		headPtr = tmpPtr;
	else {
		while (currentPtr != nullptr && currentPtr->item < num ) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->next;
		}
		if (currentPtr == nullptr) // 加入list成為最後一個節點
			previousPtr->next = tmpPtr;
		else {
			tmpPtr->next = currentPtr; 
			if (previousPtr == nullptr) // 加入list成為第一個節點
				headPtr = tmpPtr;
			else
				previousPtr->next = tmpPtr; // 加入list成為中間的節點
		}
	}
	display(headPtr);
	return headPtr;
}

void printArrayForward(int A[])
{


	// add your code here


}


void printArrayBackward(int A[], int i)
{


	// add your code here


}

void printListForward(nodePtr ptr)
{


	// add your code here


}

void printListBackward(nodePtr ptr)
{


	// add your code here


}

int main()
{
	int num;
	int A[MAX] = { 0 };
	nodePtr headPtr = nullptr;

	printf("Input %d numbers: ", MAX);

	for (int i = 0; i < MAX; i++) {
		cin >> num;
		A[i] = num;
		headPtr = inputData(num, headPtr);
	}

	printf("\nArray Forward Iteratively:  ");
	printArrayForward(A);
	printf("\nArray Backward Recursively: ");
	printArrayBackward(A, 0);

	printf("\nList Forward Iteratively:  ");
	printListForward(headPtr);
	printf("\nList Backward Recursively: ");
	printListBackward(headPtr);

	printf("\n");
//	system("PAUSE");
	return 0;
}
