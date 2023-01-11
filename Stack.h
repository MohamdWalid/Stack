#pragma once
#include <iostream>

using namespace std;
template <class T>

class Stack
{

private:

	int length;
	int capacity;
	T topElement;
	T *array;

public:

	Stack()
	{
		length = 0;
		capacity = 1;
		this->array = new T[1];
	}

	~Stack()
	{
		delete[] this->array;
	}

	void push(T element)
	{
		if (length == capacity)	// Checking if we have more space to add elements
		{
			T *temp = new T[capacity * 2];		//Doubling the capacity of temp array to add more elements

			for (int i = 0; i < capacity; i++)
			{
				temp[i] = this->array[i];		//Copy the elements to onther array with new capacity
			}

			delete[] this->array;		// Deleting the pervious array after copying the elements
			capacity *= 2;		//Doubling stack array capacity to contain the elements
			this->array = temp;		// Assignment the stack array with the elements

			this->array[length] = element;		 // push the element in the end of stack array
			length++;
			topElement = this->array[length-1];
		}

		else
		{
			this->array[length] = element;
			length++;
			topElement = this->array[length - 1];
		}
	}

	T peek(int indx)
	{
		if (indx < 0 || indx > length)
		{
			cout << "This index is out of range \n";
		}

		else
		{	// To get the index from the top we will use this formula (index = top-position+1)
			
			T element;

			element = this->array[ (length-1) - indx + 1];
			
			return element;

		}
	}

	bool isEmpty()
	{
		if (length == 0)
		{
			return 1;
		}

		else
		{
			return 0;
		}
	}

	void pop()
	{
		if (length == 0)
		{
			cout << "The stack is empty\n";
		}

		else
		{
			this->array[length] = NULL;
			length--;
			topElement = this->array[length - 1];
		}
	}

	T top()
	{
		return this->topElement;
	}

	void display()
	{
		for (int i = length -1 ; i > -1 ; i--)
		{
			cout << this->array[i] << " ";
		}
	}

	int size()
	{
		return this->length;
	}

};

