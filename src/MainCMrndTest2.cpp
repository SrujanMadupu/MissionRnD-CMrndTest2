/*
***********************
Comment the Printfs  you used in the Problems before you submit,as Printf might lead to timeouts in large 
cases as I/O is costly operation than CPU operations.
***********************
Do Read All questions carefully ,before writing any Code .
Make sure you submit the Code you have written through tool ,
before the submit window Closes .
*****************
Note : Make sure your MSBuild Suceeds before you submit ,or else It will lead to 0 marks .
->If you are stuck on a question or a particular Test case
is failing , Do Solve the Next question .As long as you click on submit at correct time,
your submissions are safe .
**************
There are only Sample Test Cases provided .Your code will also be graded
using Test cases on our end ,So Do think about testcases in all possible ways .
Your score will totally be based on the number of TestCases your programs
have passed on our end ,so if your code just passes sample cases
and fails all testcases at our end ,you will get you 0 marks .
******************
You can fill in the Helper Functions and make use of it
if you want to test from MainMrndCTest2.cpp
******************
All the Best .
*/

#include <stdlib.h>
#include <stdio.h>
#include "FunctionHeadersMrndTest2.h"


struct oddevennode{
	int data;
	struct oddevennode * next;
	struct oddevennode * random;
};

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct oddevennode * createNode(int num) {
	struct oddevennode *newNode = (struct oddevennode *)malloc(sizeof(struct oddevennode));
	newNode->data = num;
	newNode->next = NULL;
	newNode->random = NULL;
	return newNode;
}

void addNode(struct oddevennode **head, int data){
	struct oddevennode * cur = createNode(data);
	if (*head == NULL){
		*head = cur;
	}
	else{
		struct oddevennode *temp = *head;
		cur->next = temp;
		*head = cur;
	}
}
//Helper Functions Start


//Helper Functions End

int main(){
	
	//Test Odd Even SLL
	int arr[] = { 50, 4, 3, 7, 10, 99, 17 };
	struct oddevennode *head = NULL;
	for (int i = 0; i < 7; i++){
		addNode(&head, arr[i]);
	}
	oddeven_sll(head);
	getchar();
	return 0;

	//Test CommonRoute

	//MangoCollector
	
	//Test Pillars
}



