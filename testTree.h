#ifndef TESTTREE_H
#define TESTTREE_H

#include <string>
#include <stdio.h>
#include "node.h"
#include "token.h"


using namespace std;

//A header file containing the declaration of the BuildTree class and its function prototypes.
class TestTree {
    public:
        //see node.h
        node_t *root;
    
        //constructor
        TestTree();
    
        //Binary tree operations
        void insert(node_t *&, node_t *&);
        void destroySubTree(node_t *);
              
        void setChild1(node_t *, TestTree, int);
        void setChild2(node_t *, TestTree, int);
        void setChild3(node_t *, TestTree, int);
        void setChild4(node_t *, TestTree, int);
        void setChild5(node_t *, TestTree, int);
        void setChild6(node_t *, TestTree, int);
        void setChild7(node_t *, TestTree, int);
        
        void setChild1(node_t *, TestTree);
        void setChild2(node_t *, TestTree);
        void setChild3(node_t *, TestTree);
        void setChild4(node_t *, TestTree);
        void setChild5(node_t *, TestTree);
        void setChild6(node_t *, TestTree);
        void setChild7(node_t *, TestTree);
        void generateLeafNode(TestTree, string, string, int, int);
        void appendNodeString(node_t *, string, string);
        void genLeafNode(string s, string r, int level);
        void generateNode(string, int);
        node_t* getRoot();
        void setRoot(node_t* ,node_t*);
};

#endif