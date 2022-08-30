#include "token.h"
#include "scanner.h"

using namespace std;

//Implementation of scanner
token FADriver(ifstream &file, char &nextChar) {

  //This table handles state/rules defined for the project. Values are shown as enum state to improve readablity.
  state table[9][9] = {
  //{a-z, A-Z, 0-9, *, OP, WS, EoF, <, -}
    {S4, S3, S6, S1, S7, S0, EofTkn, S7, ErrorTkn},
    {S1, S1, S1, S2, S1, S1, ErrorTkn, S1, S1},
    {ComTkn, ComTkn, ComTkn, ComTkn, ComTkn, ComTkn, ComTkn, ComTkn, ComTkn},
    {S3, KeyTkn, KeyTkn, KeyTkn, KeyTkn, KeyTkn, KeyTkn, KeyTkn, KeyTkn},
    {S5, S5, S5, ErrorTkn, ErrorTkn, ErrorTkn, ErrorTkn, ErrorTkn, ErrorTkn},
    {S5, S5, S5, IdTkn, IdTkn, IdTkn, IdTkn, IdTkn, IdTkn},
    {NumTkn, NumTkn, S6, NumTkn, NumTkn, NumTkn, NumTkn, NumTkn, NumTkn},
    {OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, S8, S8},
    {OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn, OpTkn}
  };
 
  state currentState = S0;
  state nextState;
  string S = "";
  
  //Skip spaces.
  while (isspace(nextChar)) {
    nextChar = file.get();
  }
  
  //Skip comments
  if(nextChar == '*') {
    do {
    nextChar = file.get();
    } while (nextChar != '*');
    nextChar = file.get();
  }
  
  //While currentState is less than a FINAL state.
  while (currentState < 9) {
    nextState = table[currentState][getColumn(nextChar)];

    if (nextState == ErrorTkn) {
      Error(nextChar);
      exit(EXIT_FAILURE);
      
    //If the state is considered to be a FINAL state:
    } else if (nextState > 9) {
      if(nextState == EofTkn) {
        token tempToken(EofTkn, "EofToken");
        return tempToken;
        
      } else if (nextState == ComTkn) {
        token tempToken(ComTkn, S);
        return tempToken;
        
      } else if (nextState == KeyTkn) {
          bool keywordFlag = keywordCheck(S);
          if(keywordFlag == true) {
            token tempToken(KeyTkn, S);
            return tempToken;
        
          } else {
            ErrorInvalidKeyword(S);
            exit(EXIT_FAILURE);
          }
          
      } else if (nextState == IdTkn) {
          token tempToken(IdTkn, S);
          return tempToken;
        
      } else if (nextState == NumTkn) {
          token tempToken(NumTkn, S);
          return tempToken;
        
      } else if (nextState == OpTkn) {
          bool operatorFlag = operatorCheck(S);
          if (operatorFlag == true) {
            token tempToken(OpTkn, S);
            return tempToken;
          } else {
          ErrorInvalidOperator(S);
          exit(EXIT_FAILURE);
          }
      }
      
    } else {
        currentState = nextState;
        S += nextChar;
        nextChar = file.get();
    }
  }
  exit(EXIT_FAILURE);
}

int getColumn(char character) {
  int nextColumn = -1;
  
  if (islower(character)) {
    nextColumn = 0;
    return nextColumn;
    
  } else if (isupper(character)) {
      nextColumn = 1;
      return nextColumn;
      
  } else if (isdigit(character)) {
      nextColumn = 2;
      return nextColumn;
      
  } else if ((character == '*')) {
      nextColumn = 3;
      return nextColumn;
      
  } else if ((character == '&') | (character == '+') | (character == '/') | (character == '%') | (character == '.') | (character == '{') | (character == '}')) {
      nextColumn = 4;
      return nextColumn;
      
  } else if ((isspace(character))) {
      nextColumn = 5;
      return nextColumn;
      
  } else if ((character == EOF)) {
      nextColumn = 6;
      return nextColumn;
      
  } else if ((character == '<')) {
      nextColumn = 7;
      return nextColumn;
      
  } else if ((character == '-')) {
      nextColumn = 8;
      return nextColumn;
  }
    ErrorInvalidCharacter(character);
    exit(EXIT_FAILURE);
}

void Error(char character){
  cout << "Error: Error token encountered at: " << character <<endl;
}

void ErrorInvalidCharacter(char character) {
  cout << "Error: Invalid Character: " << character << endl;
}

void ErrorInvalidKeyword(string S) {
  cout << "Error: Invalid Keyword: " << S << endl;
}

void ErrorInvalidOperator(string S) {
  cout << "Error: Invalid operator: " << S << endl;
}

bool keywordCheck(string token) {
  for (int i= 0; i < 13; i++) {
    if (keywords[i] == token) 
      return true;
  }
  return false;
}

bool operatorCheck(string token) {
  for (int i= 0; i < 9; i++) {
    if (operators[i] == token) 
      return true;
  }
  return false;
}

