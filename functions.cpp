//
// Created by admin on 10.03.2024.
//

#include "functions.h"
#include "List.h"
#include "Stack.h"
#include "iostream"

//convert Char to int type
int CharToInt(char character) {
	int number = (int) character - 48;
	return number;
}

//convert int to char type
char IntToChar(int number){
	char character = (char)(48 + number);
	return character;
}

//check if the element is number
bool isNumber(char element){
	if ((int)element >= 48 and (int)element <= 58){
		return true;
	} else return false;
}

//returns priority of operator given
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

//handle min max operator occurrence
void minMax(Stack &stack, List &list){
	list.removeFirst();
	char number;
	//min function
	if (list.getFirst() == 'I'){
		list.removeFirst();
		list.removeFirst();
		number = list.getFirst();
		std::cout << 'M' << 'I' << 'N' << number << ' ';
		if (stack.getSize() > 0) stack.print();
		int smaller = stack.takeFirst(), other;
		for (int i = 1; i < CharToInt(number); ++i) {
			other = stack.takeFirst();
			if (smaller < other);
			else smaller = other;
		}
		stack.add(smaller);
	}
	//max function
	else{
		list.removeFirst();
		list.removeFirst();
		number = list.getFirst();
		std::cout << 'M' << 'A' << 'X' << number << ' ';
		if (stack.getSize() > 0) stack.print();
		int bigger = stack.takeFirst(), other;
		for (int i = 1; i < CharToInt(number); ++i) {
			other = stack.takeFirst();
			if (bigger > other);
			else bigger = other;
		}
		stack.add(bigger);
	}
}

//perform calculations with operator given
//return false if division by 0
bool operatorOccurrence(Stack &stack, List &input, char op) {
	if (op == '\n') return true;
	if (op == 'M'){
		minMax(stack, input);
		return true;
	}
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

//main function for reversed notation calculator
void calculate(List &input) {
	Stack stack;
	int newNumber, inStack;
	bool ThereWasASpace = false, zeroCheck = false;
	while (true) {
		if (zeroCheck){
			std::cout << "ERROR";
			break;
		}
		else if (input.getFirst() == 'F'){
			input.nextElement();
			continue;
		}
		//end of operations
		else if (input.getFirst() == '.') {
			stack.print();
			return;
		}
		else if (input.getFirst() == ' ') {
			ThereWasASpace = true;
			input.nextElement();
			continue;
		}
		//number in char type hidden, convert it to int if needed
		else if (input.getFirst() >= 48 and input.getFirst() <= 58) {
			newNumber = CharToInt(input.getFirst());
			if (stack.getSize() == 0){
				stack.add(newNumber);
				ThereWasASpace = false;
			}
			else if (!ThereWasASpace){
				inStack = stack.takeFirst();
				inStack *= 10;
				inStack += newNumber;
				stack.add(inStack);
			}
			else{
				stack.add(newNumber);
				ThereWasASpace = false;
			}
			input.nextElement();
			continue;
		}
		else {
			zeroCheck = !(operatorOccurrence(stack,input, input.getFirst()));
			input.nextElement();
		}
	}
}

//add numbers and operators in full correct form to reversed notation output
void outputHandler(char tmp, List &output){
	int isNumber = (int)tmp - 48;

	//adding number
	if (isNumber >= 0 and isNumber <= 9){
		output.append(tmp);
		return;
	}
	output.append(' ');
	// adding min/max
	if (tmp == 'm'){
		output.append('M');
		output.append('I');
		output.append('N');
	}
	else if (tmp == 'M') {
		output.append('M');
		output.append('A');
		output.append('X');
	}
	//adding if
	else if (tmp == 'I'){
		output.append(tmp);
		output.append('F');
	}
	//adding anything else
	else{
		output.append(tmp);
	}
}

//check if they are logical operators which involve brackets or N
bool areLogicalOperators(char a, char b){
	if (a == 'N' or a == 'I' or a == 'M' or a == 'm') {
		if (b == 'I' or b == 'N' or b == 'M' or b == 'm') return true;
		else return false;
	}
	else return false;
}


//if user input is not recognised as a number manage placement of operator or other elements
void handleStackOutput(CHStack &stack, List &output, char element, Stack &countElInBrackets){
	//skip unnecessary info
	if (element == 'F') return;

	char tmp = stack.takeLast();
	//recognize if user added min or max
	if ((tmp == 'M' or tmp == 'm') and element != '('){
		if (element == 'X'){
			stack.add(tmp);
		} else if (element == 'N'){
			stack.add(tmp);
		}else if (element == 'I'){
			stack.add('m');
		}else if (element == 'A'){
			stack.add('M');
		}
		return;
	}
	//comma added
	//count elements in brackets
	else if (element == ','){
		int number  = countElInBrackets.takeFirst();
		number++;
		countElInBrackets.add(number);
		//comma appearance, empty stack with operators till (
		while (true){
			if (stack.getSize() == 0) break;
			if (tmp == '('){
				stack.add(tmp);
				return;
			}
			outputHandler(tmp, output);
			tmp = stack.takeLast();
		}
		stack.add(tmp);
		return;
	}
	else if (element == '('){
		countElInBrackets.add(1);
		stack.add(tmp);
		stack.add(element);
		return;
	}
	else if (tmp == '(' and element != ')'){
		stack.add(tmp);
		stack.add(element);
		return;
	}
	//close brackets return all operators inside
	else if (element == ')') {
		int number = countElInBrackets.takeFirst();
		while (tmp != '(') {
			outputHandler(tmp, output);
			tmp = stack.takeLast();
		}
		if (stack.getSize()) {
			tmp = stack.takeLast();
			//recognize min/max
			if (tmp == 'm' or tmp == 'M') {
				outputHandler(tmp, output);
				outputHandler(IntToChar(number), output);
			}
			else stack.add(tmp);
		}
		return;
	}
	//priority of operators checked
	else if ((operatorPriority(tmp) >= operatorPriority(element)) and
	!areLogicalOperators(tmp, element)) {
		outputHandler(tmp, output);
		while (true) {
			if (stack.getSize() == 0) break;
			tmp = stack.takeLast();
			if (tmp == '(') {
				stack.add(tmp);
				break;
			} else if (operatorPriority(tmp) >= operatorPriority(element)) {
				outputHandler(tmp, output);
			} else {
				stack.add(tmp);
				break;
			}
		}
		stack.add(element);
		return;
	}
	else {
		stack.add(tmp);
		stack.add(element);
		return;
	}
}

//receive char and sort it in to reversed notation
bool conversionToNotation(char element, List &convertedInput, CHStack &stack, Stack &countElInBrackets){
		if (element == '.'){
			while (stack.getSize() > 0){
				outputHandler(stack.takeLast(), convertedInput);
			}
			convertedInput.append(element);
			return true;
		//number appearance: adds the number to list
		} else if (isNumber(element)){
			convertedInput.append(element);
		//space appearance: adds space to list
		} else if (element == ' ') {
			if (convertedInput.getLast() == ' ') return false;
			convertedInput.append(element);
		}
		//enter in input: skip it
		else if (element == '\n') {
			return false;
		//operator occurrence
		} else{
			if (stack.getSize() == 0)stack.add(element);
			else handleStackOutput(stack, convertedInput, element, countElInBrackets);
		}
		//there was no dot: we are not finished with input
	return false;
}