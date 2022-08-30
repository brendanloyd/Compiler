#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "node.h"
#include "testTree.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//TestTree parser(node_t* rootPtr, ifstream &file, bool willShowEoF);
TestTree parser(ifstream &file, bool willShowEoF);
TestTree S(ifstream &file);
TestTree R(ifstream &file);
TestTree E(ifstream &file);
TestTree A(ifstream &file);
TestTree B(ifstream &file);
TestTree C(ifstream &file);
TestTree D(ifstream &file);
TestTree F(ifstream &file);
TestTree G(ifstream &file);
TestTree T(ifstream &file);
TestTree H(ifstream &file);
TestTree J(ifstream &file);
TestTree K(ifstream &file);
TestTree L(ifstream &file);
TestTree V(ifstream &file);
TestTree W(ifstream &file);
TestTree Z(ifstream &file);
token scanner(ifstream &file);
void error(token tk);

#endif