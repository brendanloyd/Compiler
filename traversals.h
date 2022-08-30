#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include <iostream>
#include <fstream>
#include <list>

#include "testTree.h"
#include "node.h"
#include "token.h"

using namespace std;

void semanticCheck(node_t*, bool, bool, int);
void addToList(node_t*);
void checkList(node_t*);
bool checkTheList(node_t*);
void generation(node_t*);
void generationTraverse(node_t*);
void error(node_t*);
void traversePreOrder(node_t*);
void print(list<string>);

#endif