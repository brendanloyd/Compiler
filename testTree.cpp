#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <queue>

#include "node.h"
#include "traversals.h"
#include "testTree.h"
#include "token.h"

//This file contains the buildTree function declarations and implementation.
using namespace std;

//Functions to set children

void TestTree::setChild1(node_t *nodePtr,TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;
    nodePtr->child1 = newNode.getRoot();
}

void TestTree::setChild2(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;
    nodePtr->child2 = newNode.getRoot();
}

void TestTree::setChild3(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;
    nodePtr->child3 = newNode.getRoot();

}

void TestTree::setChild4(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;   
    nodePtr->child4 = newNode.getRoot();

}

void TestTree::setChild5(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;    
    nodePtr->child5 = newNode.getRoot();

}

void TestTree::setChild6(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;    
    nodePtr->child6 = newNode.getRoot();

}

void TestTree::setChild7(node_t *nodePtr, TestTree newNode, int lvl) {
    node_t *newode = nullptr;
    newode = newNode.getRoot();
    newode -> level = lvl;    
    nodePtr->child7 = newNode.getRoot();

}

void TestTree::setChild1(node_t *nodePtr,TestTree newNode) {
    nodePtr->child1 = newNode.getRoot();
}

void TestTree::setChild2(node_t *nodePtr, TestTree newNode) {
    nodePtr->child2 = newNode.getRoot();
}

void TestTree::setChild3(node_t *nodePtr, TestTree newNode) {
    nodePtr->child3 = newNode.getRoot();

}

void TestTree::setChild4(node_t *nodePtr, TestTree newNode) {
    nodePtr->child4 = newNode.getRoot();

}

void TestTree::setChild5(node_t *nodePtr, TestTree newNode) {
    nodePtr->child5 = newNode.getRoot();

}

void TestTree::setChild6(node_t *nodePtr, TestTree newNode) {
    nodePtr->child6 = newNode.getRoot();

}

void TestTree::setChild7(node_t *nodePtr, TestTree newNode) {
    nodePtr->child7 = newNode.getRoot();

}

//Adds tokens consumed to node.
void TestTree::appendNodeString(node_t *nodePtr, string s, string r) {
    nodePtr->tokens += (" " + s + " " + r);
}

void TestTree::genLeafNode(string s, string r, int level) {
  node_t *newNode = nullptr;
    newNode = new node_t;
    newNode->tokens += s;
    newNode->tokenName += r;
    newNode->level = level; //new line
    newNode->child1 = newNode->child2 = newNode->child3 = newNode->child4 = newNode->child5 = newNode->child6 = newNode->child7 = nullptr;
    
    insert(root, newNode);
}

void TestTree::generateLeafNode(TestTree tree, string s, string r, int child, int level) {
    TestTree p;
    p.genLeafNode(s, r, level);
        
    switch(child) {
      case 1 :
         setChild1(tree.getRoot(), p);
         break;
      case 2 :
        setChild2(tree.getRoot(), p);
        break;
      case 3 :
         setChild3(tree.getRoot(), p);
         break;
      case 4 :
         setChild4(tree.getRoot(), p);
         break;
      case 5 :
         setChild5(tree.getRoot(), p);
         break;
      case 6 :
         setChild6(tree.getRoot(), p);
         break;
      case 7 :
         setChild7(tree.getRoot(), p);
         break;
   }
}

//Creates a new node.
void TestTree::generateNode(string s, int level) {
    node_t *newNode = nullptr;
    newNode = new node_t;
 
    newNode->tokens += s;
    newNode->level = level; //new line
    newNode->child1 = newNode->child2 = newNode->child3 = newNode->child4 = newNode->child5 = newNode->child6 = newNode->child7 = nullptr;
 
    // Insert a new node
    insert(root, newNode);
}

void TestTree::insert(node_t *&nodePtr, node_t *&newNode) {
    if (nodePtr == nullptr) nodePtr = newNode;
    
}

//Default constructor
TestTree::TestTree() {
    root = nullptr;
}

// Returns root
node_t* TestTree::getRoot() {
    return root;
}

void TestTree::setRoot(node_t* nodePtr, node_t* root) {
    nodePtr = root;
}
