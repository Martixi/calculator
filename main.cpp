#include <iostream>
#include "List.h"
#include "functions.h"

using namespace std;

struct Operator{
	const char plus = '+';
	const char minus = '-';
	const char multiply = '*';
	const char divide = '/';
};

int main() {
	int NOperations;
	char ch;
	List input;

	cin >> NOperations;

	for (int i = 0; i <NOperations;) {
	 	ch = (char)getchar();

		 input.append(ch);
		if (ch == '.'){
			i++;
			input.print();
			cout << endl;
			calculate(input, NOperations);
			cout << endl;
			input.clear();

		}
	}


	return 0;
}
