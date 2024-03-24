//
// Created by admin on 10.03.2024.
//

#ifndef CALCULATOR_FUNCTIONS_H
#define CALCULATOR_FUNCTIONS_H

#endif //CALCULATOR_FUNCTIONS_H
#include "List.h"
#include "Stack.h"

int CharToInt(char character);
char IntToChar(int number);
bool isNumber(char element);
int operatorPriority(char element);
void minMax(Stack &stack, List &list);
bool operatorOccurrence(Stack &stack, List &input, char op);
void calculate(List& input);
void outputHandler(char tmp, List &output);
bool areLogicalOperators(char a, char b);
void handleStackOutput(CHStack &stack, List &output, char element, Stack &countElInBrackets);
bool conversionToNotation(char element, List &convertedInput, CHStack &stack, Stack &countElInBrackets);
