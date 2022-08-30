#ifndef NODE_H
#define NODE_H

#include <string>
#include "token.h"
using namespace std;

struct node_t {
    string tokens;
    string tokenName;
    int level;
    //int value;
  
    node_t *child1;
    node_t *child2;
    node_t *child3;
    node_t *child4;
    node_t *child5;
    node_t *child6;
    node_t *child7;

};
    
#endif