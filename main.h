#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>

#include "token.h"
#include "scanner.h"
#include "parser.h"
#include "testTree.h"
#include "traversals.h"

using namespace std;

void callScanner(ifstream &file, bool willShowEoF);
void writeToFile(ofstream &newFile, char *argv[], int argc);

#endif