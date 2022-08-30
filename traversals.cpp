#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <vector>

#include "traversals.h"
#include "node.h"
#include "testTree.h"
#include "token.h"

using namespace std;

string lastOperator;
string lastKeyword;
bool zFlag = false;
bool kFlag = false;
bool vFlag = false;
bool doFlag = false;
bool flipFlag = false;
bool flipFlag2 = false;
bool fFlag = false;
bool ifFlag = false;
bool ifFlag2 = false;
bool ifFlag3 = false;
bool loadFlag = false;

void semanticCheck(node_t *nodePtr, bool nameFlag, bool spotFlag, int level) {
     if (nodePtr) {
     queue <node_t*> que;
     node_t *item;
     que.push(nodePtr); //insert the root at first
     
     while (!que.empty()) {
     
        item = que.front(); //get the element from the front end
        if (nameFlag == true) {
        if (checkTheList(item) == false) {
          addToList(item);
        }
          nameFlag = false;
          
      } else if(spotFlag == true) {
          addToList(item);
          spotFlag = false;
      }
      if(item->tokens == "Identifier") {
        checkList(item);
      }
    
      if (item->tokenName == "Name" || item->tokenName == "Show") {
        nameFlag = true;
      } else if (item->tokenName == "Spot") {
        spotFlag = true;
        }


        if (item->child1 != NULL) que.push(item->child1); //When left child is present, insert into queue
        if (item->child2 != NULL) que.push(item->child2);
        if (item->child3 != NULL) que.push(item->child3);
        if (item->child4 != NULL) que.push(item->child4);
        if (item->child5 != NULL) que.push(item->child5);
        if (item->child6 != NULL) que.push(item->child6);
        if (item->child7 != NULL) que.push(item->child7); //When right child is present, insert into queue
        
        que.pop(); //remove the item from queue
     }
   }
   //print(symbolTable);
}

bool checkTheList(node_t *nodePtr) {
  for (auto i: symbolTable) {
        if(i == nodePtr->tokenName) {
          return true;
        }
  }
  return false;
}

void checkList(node_t *nodePtr) {
  if (find(begin(symbolTable), end(symbolTable), nodePtr->tokenName) == end(symbolTable)) {
   error(nodePtr);
  }
}

void addToList(node_t *nodePtr) {
  symbolTable.push_back(nodePtr->tokenName);
}

void generation(node_t* nodePtr) {
  generationTraverse(nodePtr);
  
  gen << "STOP" << endl; 
     for (auto i: symbolTable) {
        gen << i << " 0" << endl;
     }
  
}

void generationTraverse(node_t* nodePtr) {

 if (nodePtr != nullptr) {
   if(nodePtr->tokens == "S: " || nodePtr->tokens == "A: ") {
      gen << "LOAD 0" << endl;
      
    } else if (nodePtr->tokens == "Identifier" || nodePtr->tokens == "Number" ) {
        gen << nodePtr->tokenName << endl;
        
        if (ifFlag == true) {
            ifFlag = false;
            ifFlag2 = true;
            
        } else if(flipFlag == true) {
            flipFlag = false;
            flipFlag2 = true;
            loadFlag = true;
            
            gen << "MULT -1" << endl;
            
          } else if(zFlag == true) {
            gen << "SUB 1" << endl;
            zFlag = false;
            }
            
    } else if (nodePtr->tokenName == "There") {
        gen << "STORE T1" << endl;
        symbolTable.push_back("T1");
        gen << "BRZNEG Done" << endl << "Repeat: WRITE T1" << endl << "SUB 1" << endl << "BRPOS Repeat" << endl << "Done: NOOP" << endl;
        
    } else if(nodePtr->tokenName == "If") {
        gen << "LOAD ";
        fFlag = true;
        
    } else if (ifFlag2 == true && lastOperator == "<-") {
        gen << "BRNEG Done" << endl;
        ifFlag2 = false;
        ifFlag3 = true;
        
    } else if (ifFlag2 == true && lastOperator == "<<") {
        gen << "BRZPOS Done" << endl;
        ifFlag2 = false;
        ifFlag3 = true;
        
    } else if(nodePtr->tokenName == "<-" && fFlag == true) {
        gen << "SUB ";
        lastOperator = nodePtr->tokenName;
        ifFlag = true;
        
    } else if(nodePtr->tokenName == "<<" && fFlag == true) {
        gen << "SUB ";
        lastOperator = nodePtr->tokenName;
        ifFlag = true;
        
    } else if (nodePtr->tokenName == "Do") {
        gen << "LOOP: NOOP " << endl;
        doFlag = true;
        
    } else if (nodePtr->tokenName == "Flip") {
        gen << "LOAD ";
        flipFlag = true;
        lastKeyword = nodePtr->tokenName;
    }
    
     if(nodePtr->tokenName == "+") {
        gen << "ADD ";
        vFlag = false;
        
    } else if(nodePtr->tokenName == "%") {
        gen << "DIV ";
        vFlag = false;
        
    } else if(nodePtr->tokenName == "&") {
        gen << "MULT ";
        vFlag = false;
    }
    
    if (nodePtr->tokens == "V: "){
      vFlag = true;
      
    } else if(nodePtr->tokens == "Z: ") {
       zFlag = true;
       
    } else if(nodePtr->tokens == "K: ") {
       kFlag = true;
    }
    
    if (loadFlag == true) {
        gen << "LOAD ";
        loadFlag = false;
        
    } else if (doFlag == true && nodePtr->tokenName == "<<") {
        lastOperator = nodePtr->tokenName;
        doFlag = false;

    } else if (doFlag == true && nodePtr->tokenName == "<-") {
        lastOperator = nodePtr->tokenName;
        doFlag = false;

    }
    
    
    
    if (nodePtr->tokenName == "Here") {
        gen << "LOAD ";
        
    } else if (nodePtr->tokenName == "Name") {
        gen << "STORE ";
        
    } else if (nodePtr->tokenName == "Spot" && kFlag == false) {
        gen << "READ ";
        
    } else if (nodePtr->tokenName == "Spot" && kFlag == true) {
        gen << "LOAD ";
        kFlag = false;
        
    } else if (nodePtr->tokenName == "Show") {
        gen << "WRITE ";
        
    } else if (ifFlag3 == true && nodePtr->tokens == "Identifier") {
        gen << "Done: NOOP" << endl;
        ifFlag3 = false;
        
    } else if (flipFlag2 == true && nodePtr->tokenName == "}") {
    
        if(lastOperator == "<<") {
        gen << "BRNEG LOOP" << endl;
        
        } else if (lastOperator == "<-") {
        gen << "BRZPOS LOOP" << endl;
        }
        
        flipFlag = false;
        flipFlag2 = false;
        
    } else if (nodePtr->tokenName == "Move") {
     gen << "LOAD ";
    }
    
    generationTraverse(nodePtr->child1);
    generationTraverse(nodePtr->child2);
    generationTraverse(nodePtr->child3);
    generationTraverse(nodePtr->child4);
    generationTraverse(nodePtr->child5);
    generationTraverse(nodePtr->child6);
    generationTraverse(nodePtr->child7);
  }   
}

void error(node_t *nodePtr) {
  cout <<"Fatal error at: " << nodePtr->tokens << " " << nodePtr->tokenName << endl;
  exit(-1);
}

//Simple preOrder to print tree in preorder
void traversePreOrder(node_t *nodePtr) {

    if (nodePtr) {
            for(int space = 0; space < (nodePtr->level) * 2; space++) {
                cout << " ";
            }
            cout << nodePtr->tokens << " " << nodePtr->tokenName << endl;
            
        traversePreOrder(nodePtr->child1);
        traversePreOrder(nodePtr->child2);
        traversePreOrder(nodePtr->child3);
        traversePreOrder(nodePtr->child4);
        traversePreOrder(nodePtr->child5);
        traversePreOrder(nodePtr->child6);
        traversePreOrder(nodePtr->child7);
    }

}

//https://www.techiedelight.com/print-std-list-cpp/
void print(list<string> list)
{
    cout << "The symbolTable is:" << endl;
    for (auto i: list) {
        cout << i << endl;
    }
}

/* switch(nodePtr->tokens) {
   case ("S: " || "A: ")  :
      gen << "LOAD 0" << endl;
      break; //optional
   case "Identifier"  :
      gen << nodePtr->tokenName << endl;
      break; //optional
   case "Number"  :
      gen << nodePtr->tokenName << endl;
      break; //optional

   // you can have any number of case statements.
   default : 
      break;
}
  
    switch(nodePtr->tokenName) {
   case "There"  :
      gen << "STORE t1" << endl;
      symbolTable.push_back("t1");
      gen << "BRZNEG Done" << endl << "Repeat: WRITE t1" << endl << "SUB 1" << endl << "BRPOS Repeat" << endl << "Done: NOOP" << endl;
      break; //optional
   case "Here"  :
      gen << "LOAD ";
      break; //optional
   case "Name"  :
      gen << "STORE ";
      break; //optional
   case "Spot"  :
      gen << "READ ";
      break; //optional
   case "Show"  :
      gen << "WRITE ";
      break; //optional
  
   // you can have any number of case statements.
   default : //Optional
      break;
   }*/

