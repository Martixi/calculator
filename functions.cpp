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
	if ((int)element >= 48 and (int)element <= 58){
		return true;
	} else return false;
}

//returns the priority of an operator
int operatorPriority(char element){
	switch (element) {
		case '+':
		case '-':
			return 1; //low priority
		case '*':
		case '/':
			return 2; //high priority
		case 'I':
		case 'N':
		case 'M':
		case 'm':
			return 3; //top priority

	}
	return 0;
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


void calculate(List &input) {
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
				ThereWasASpace = false;
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

void outputHandler(char tmp, CHStack &stack, List &output){
	output.append(' ');
	if (tmp == 'm'){
		output.append('M');
		output.append('I');
		output.append('N');
	} else if (tmp == 'M') {
		output.append('M');
		output.append('A');
		output.append('X');
	} else if (tmp == 'I'){
		output.append('F');
	} else{
		output.append(tmp);
	}
}

bool areLogicalOperators(char a, char b){
	if (a == 'N' or a == 'I' or a == 'M') {
		if (b == 'I' or b == 'N' or a == 'M') return true;
		else return false;
	}
	else return false;
}

void handleStackOutput(CHStack &stack, List &output, char element){
	Stack ElInBrackets;
	int number;
	//skip unnecessary info
	if (element == 'F') return;
	char tmp = stack.takeLast();
	if (element == ','){
		number = ElInBrackets.takeLast();
		number++;
		ElInBrackets.add(number);
		while (true){
			if (stack.getSize() == 0) break;
			if (tmp == '('){
				stack.add(tmp);
				return;
			}
			outputHandler(tmp,stack, output);
			tmp = stack.takeLast();
		}
		stack.add(tmp);
		return;
	}
	else if (element == '('){
		ElInBrackets.add(1);
		stack.add(tmp);
		stack.add(element);
		return;
	}
//	else if (element == 'M'){
//		stack.add(tmp);
//		tmp = input.getFirst();
//		if (tmp == 'A') stack.add('M');
//		else stack.add('m');
//		input.removeFirst();
//		input.removeFirst();
//
//		return;
//	}
//	else if (tmp == 'M'){
//		if (element == 'A') stack.add('M');
//		else stack.add('m');
//		input.removeFirst();
//		return;
//	}
	else if (tmp == '(' and element != ')'){
		stack.add(tmp);
		stack.add(element);
		return;
	}
	else if (element == ')'){
		while (tmp != '('){
			outputHandler(tmp,stack, output);
			tmp = stack.takeLast();
		}
		tmp = stack.takeLast();
		number = ElInBrackets.takeLast();
		if (tmp == 'm' or tmp == 'M'){
			stack.add(tmp);
			stack.add((char)(number + 48));
		} else stack.add(tmp);
		return;
	}
	else if ((operatorPriority(tmp) >= operatorPriority(element)) and
	!areLogicalOperators(tmp, element)) {
		outputHandler(tmp, stack, output);
			while (true){
				if (stack.getSize() == 0) break;
				tmp = stack.takeLast();
				if (tmp == '('){
					stack.add(tmp);
					break;
				}
				if (operatorPriority(tmp) >= operatorPriority(element)){
					outputHandler(tmp, stack, output);
				} else{
					stack.add(tmp);
					break;
				}
			}
			stack.add(element);
	} else {
		stack.add(tmp);
		stack.add(element);
	}
}


bool conversionToNotation(char element, List &convertedInput, CHStack &stack){
		if (element == '.'){
			while (stack.getSize() > 1){
				outputHandler(stack.takeLast(), stack, convertedInput);
			}
			convertedInput.append(element);
			return true;
		//number appearance: adds the number to list
		} else if (isNumber(element)){
			convertedInput.append(element);
		//space appearance: adds space to list
		} else if (element == ' ') convertedInput.append(element);
		//enter in input: skip it
		else if (element == '\n') {
			return false;
		//operator occurrence
		} else{
			if (stack.getSize() == 0)stack.add(element);
			else handleStackOutput(stack, convertedInput, element);
		}
		//there was no dot: we are not finished with input
	return false;
}