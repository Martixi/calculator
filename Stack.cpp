//
// Created by admin on 09.03.2024.
//

#include "Stack.h"

//
// int stack
//

Stack::Stack() {
	size = 0;
}

void Stack::add(int value) {
	stack.pushFront(value);
	size++;
}

int Stack::getSize() const {
	return size;
}

int Stack::takeFirst() {
	if (size != 0) {
		int number = stack.getFirst();
		stack.removeFirst();
		size--;
		return number;
	} else{
		return 0;
	}
}

void Stack::print() {
	stack.print();
	std::cout << '\n';
}

//
// Char stack
//

CHStack::CHStack() {
	size = 0;
}

void CHStack::add(char value) {
	stack.pushFront(value);
	size++;
}

int CHStack::getSize() const{
	return size;
}

char CHStack::takeLast() {
	if (size != 0) {
		char element = stack.getFirst();
		stack.removeFirst();
		size--;
		return element;
	} else{
		return 0;
	}
}