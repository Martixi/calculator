#include <iostream>
#include "List.h"
#include "functions.h"

using namespace std;


int main() {

	int NOperations;
	char ch;
	List input, convertedInput;

	cin >> NOperations;

	for (int i = 0; i <NOperations;) {
	 	ch = (char)getchar();

		 input.append(ch);
		if (ch == '.'){
			i++;
			conversionToNotation(input, convertedInput);
			convertedInput.print();
			cout << '\n';
			calculate(convertedInput);
			cout << '\n';
			convertedInput.clear();
		}
	}


	return 0;
}
