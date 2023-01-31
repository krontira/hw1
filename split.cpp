/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
//bool failcheck(Node*& a);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
	if(in == nullptr){ //if list containing everything is empty then so is the other two.
		evens = nullptr;
		odds = nullptr;
		in = nullptr;
		return; //returns since the linked list has no value and no operations can be carried out on it	
	}

	
	

	if((in->value)%2 == 0){//checks if the in value is even
		evens = in; //sets even to the value of in
		in = in->next; //in rec
		split(in, odds, evens->next); //recursive run with new values
			
	}

	else if((in->value)%2 != 0){ //checks if value is odd
		odds = in; // sets odd value to in
		in = in->next;
		split(in, odds->next, evens); //recursive run with new values
	}


	

}

/* If you needed a helper function, write it here */
/*bool failcheck(Node*& in){
	if(in == nullptr){ //if list containing everything is empty then so is the other two.
		
		return false; //returns since the linked list has no value and no operations can be carried out on it	
	}
	

}*/
