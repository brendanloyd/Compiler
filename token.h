#ifndef TOKEN_H
#define TOKEN_H 

#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std; 

//Global char.
static char nextChar;

static ofstream gen("filename.asm");

static list <string> symbolTable;

//Handles state for the Table.
enum state {S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5, S6 = 6, S7 = 7, S8 = 8, ErrorTkn = 9, EofTkn = 10, ComTkn = 11, KeyTkn = 12, IdTkn = 13, NumTkn = 14, OpTkn = 15};

//Inline with enum state.
static string tokenNames[] = {"S0", "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "Errortkn", "Eof", "Comment", "Keyword", "Identifier", "Number", "Operator"}; 

//The list of possible keywords.
static string keywords[] = {"Again", "If", "Assign", "Move", "Show", "Flip", "Name", "Home", "Do", "Spot", "Place", "Here", "There"};

//The list of possible operators.
static string operators[] = {"&", "+", "/", "%", ".", "{", "}", "<<", "<-"};

//Stores token information.
struct token {
  state tokenType;
  string tokenName;
  int line;
  
  //Default Constructor
  token();
  
    //Constructor
  token(state tokenType, string tokenName) {
    this->tokenType = tokenType;
    this->tokenName = tokenName;
    this->line = 0;
  }
  
  //An additional constructor incase I figure out line.
  token(state tokenType, string tokenName, int line) {
    this->tokenType = tokenType;
    this->tokenName = tokenName;
    this->line = line;
  }

  //print token
  void printToken() const {
  cout << tokenNames[static_cast<int>(tokenType)] << " " << tokenName << endl;
  } 
  
  //A getter to return tokentype
  string getTokenType() const {
  return tokenNames[static_cast<int>(tokenType)];
  }
  
  //A getter to return name
  string getTokenName() const {
  return tokenName;
  }
};

#endif