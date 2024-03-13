//
// Created by admin on 10.03.2024.
//

#include "functions.h"
#include "List.h"
#include "Stack.h"
#include "iostream"

int CharToInt(char character) {
	int number = (int) character - 48;
	return number;
}

bool operatorOccurrence(Stack &stack, char op) {
	std::cout << op << ' ';
	if (stack.getSize() > 0) stack.print();
	int sum, a, b, c;
	switch (op) {
		case '+': {
			a = stack.takeFirst();
			b = stack.takeFirst();
			sum = a + b;
			stack.add(sum);
			break;
		}
		case '-' : {
			a = stack.takeFirst();
			b = stack.takeFirst();
			sum = b - a;
			stack.add(sum);
			break;
		}
		case '*' : {
			a = stack.takeFirst();
			b = stack.takeFirst();
			sum = a * b;
			stack.add(sum);
			break;
		}
		case '/' : {
			a = stack.takeFirst();
			b = stack.takeFirst();
			if (a == 0) return false;

			sum = b / a;
			stack.add(sum);
			break;
		}
		case 'N': {
			a = stack.takeFirst();
			a *= (-1);
			stack.add(a);
			break;
		}
		case 'I':
			break;
	}
	return true;

}


void calculate(List &input, int NOperations) {
	Stack stack;
	int newNumber, inStack;
	bool ThereWasASpace = false, MaxMinDetected = false, zeroCheck = false;
	while (true) {
		if (zeroCheck){
			std::cout << "ERROR";
			break;
		}
		if (input.getFirst() == 'F'){
			input.nextElement();
			continue;
		}
		if (input.getFirst() == '.') {
			stack.print();
			return;
		}
		if (input.getFirst() == ' ') {
			ThereWasASpace = true;
			input.nextElement();
			continue;
		} else if (input.getFirst() >= 48 and input.getFirst() <= 58) {
			newNumber = CharToInt(input.getFirst());
			if (stack.getSize() == 0){
				stack.add(newNumber);
			}else if (!ThereWasASpace){
				inStack = stack.takeFirst();
				inStack *= 10;
				inStack += newNumber;
				stack.add(inStack);
			} else{
				stack.add(newNumber);
				ThereWasASpace = false;
			}
			input.nextElement();
			continue;
		} else {
			zeroCheck = !(operatorOccurrence(stack, input.getFirst()));
			input.nextElement();
		}
	}

}