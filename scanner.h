#ifndef SCANNER_H
#define SCANNER_H

#include <regex>
#include <iostream>
#include <string>
#include <iterator>
#include <stdlib.h> 
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <cctype>
#include "token.h"

using namespace std;

token FADriver(ifstream &file, char &nextChar);
void Error(char character);
void ErrorInvalidCharacter(char character);
void ErrorInvalidKeyword(string S);
void ErrorInvalidOperator(string S);
bool keywordCheck(string token);
bool operatorCheck(string token);
int getColumn(char character);

#endif