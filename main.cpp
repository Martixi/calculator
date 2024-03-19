#include <iostream>
#include "List.h"
#include "functions.h"

using namespace std;


int main() {

	int NOperations;
	char element;
	bool endOfLine = false;
	CHStack operationsStack;
	Stack countElInBrackets;
	List convertedInput;

	cin >> NOperations;

	for (int i = 0; i <NOperations;) {
		element = (char)getchar();
		endOfLine = conversionToNotation(element, convertedInput, operationsStack, countElInBrackets);
		if (endOfLine){
			i++;
			convertedInput.print();
			cout << '\n';
			calculate(convertedInput);
			cout << '\n';
			convertedInput.clear();
		}
	}

	return 0;
}
