//
// Created by admin on 09.03.2024.
//


#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H
#include "List.h"
#include "iostream"

//stack containing int type

class Stack {
private:

	IntList stack;
	int size;

public:

	Stack();

	void add(int value);

	int getSize() const;

	int takeFirst();

	void print();
};

//stack containing char type

class CHStack{
private:
	List stack;
	int size;

public:
	CHStack();

	void add(char value);

	int getSize() const;

	char takeLast();

};


#endif //CALCULATOR_STACK_H
