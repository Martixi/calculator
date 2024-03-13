//
// Created by admin on 09.03.2024.
//


#ifndef CALCULATOR_STACK_H
#define CALCULATOR_STACK_H
#include "List.h"
#include "iostream"


class Stack {
	IntList stack;
	int size;

public:
	Stack(){
		size = 0;
	}
	void add(int value){
		stack.append(value);
		size++;
	}
	int getSize(){
		return size;
	}

	int takeLast(){
		if (size != 0) {
			int number = stack.getLast();
			stack.removeLast();
			size--;
			return number;
		} else{
			return 0;
		}
	}
	void print(){
		stack.print();
		std::cout << std::endl;
	}
};


#endif //CALCULATOR_STACK_H
