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

bool isNumber(char element){
	if ((int)element > 48 and (int)element < 58){
		return true;
	} else return false;
}

bool operatorOccurrence(Stack &stack, char op) {
	if (op == '\n') return true;
	if (op == 'I'){
		std::cout << op << 'F' << ' ';
	}else std::cout << op << ' ';

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
			a = stack.takeFirst();
			b = stack.takeFirst();
			c = stack.takeFirst();
			if (c > 0) stack.add(b);
			else stack.add(a);
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


void conversionToNotation(List &input, List &convertedInput){
	CHStack operatorContainer;
	char element;
	while (true){
		element = input.getFirst();
		if (isNumber(element)){

		}
	}
	;
}