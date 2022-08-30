#include "parser.h"
#include "token.h"
#include "scanner.h"
#include "testTree.h"

token tk(ComTkn,"*Hello*");


TestTree parser(ifstream &file, bool willShowEoF) {
  tk = scanner(file);
  
  if (tk.getTokenType() == "Eof") {
  
    TestTree emptyTree;
    return emptyTree;
    
  } else {
  
      TestTree tempTree = S(file);
      return tempTree;
  }
}

TestTree S(ifstream &file) {
  TestTree p; 
  p.generateNode("S: ", 0);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Name") {
  
     //p.setToken1(p.getRoot(), tk);
     //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
     p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 1);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier") {
    
      //p.setToken2(p.getRoot(), tk);
      //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 1);
      //symbolTable.push_back(tk.getTokenName());
      tk = scanner(file);
      
      if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Spot") { 
      
        //p.setToken3(p.getRoot(), tk);
        //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 1);
        tk = scanner(file);  
        
        if (tk.getTokenType() == "Identifier") {
        
          //p.setToken4(p.getRoot(), tk);
          //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
          p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 4, 1);
          tk = scanner(file);
          
          if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Place") {
          
            p.setChild5(p.getRoot(), R(file), 1);
            
            if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") {
            
            p.setChild6(p.getRoot(), E(file), 1);
            return p;
            
            } else { error(tk);}
            
          } else { error(tk);}
          
        } else { error(tk);}
        
      } else { error(tk);}
      
    } else { error(tk);}
    
  }  else { error(tk);}
  
  return p;
}

TestTree R(ifstream &file) {
  TestTree p; 
  p.generateNode("R: ", 2);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Place") {
  
    //p.setToken1(p.getRoot(), tk);
    //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 2);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Name") {
    
      p.setChild2(p.getRoot(), A(file), 2);
      p.setChild3(p.getRoot(), B(file), 2);
      
      if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Home") {
      
        //p.setToken2(p.getRoot(), tk);
        //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 4, 2);
        tk = scanner(file);
        return p;
        
      } else { error(tk);}
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree E(ifstream &file) {
  TestTree p; 
  p.generateNode("E: ", 1);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") {
  
    //p.setToken1(p.getRoot(), tk);
    //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 2);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier") {
    
      //p.setToken2(p.getRoot(), tk);
      //p.appendNodeString(p.getRoot(), tk.getTokenType(), tk.getTokenName());
      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 2);
      tk = scanner(file);
      return p;
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree A(ifstream &file) {
  TestTree p; 
  p.generateNode("A: ", 2);
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Name") {
    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 3);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier") {
    
      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 3);
      tk = scanner(file);
      return p;
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree B(ifstream &file) {
  TestTree p;
  p.generateNode("B: ", 2);
  
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == ".") {
  
    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 3);
    tk = scanner(file);
    
    if ((tk.getTokenType() == "Operator" && tk.getTokenName() == "{") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Here")) {
    
      p.setChild2(p.getRoot(), C(file), 3);
      
      if (tk.getTokenType() == "Operator" && tk.getTokenName() == ".") {
      
      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 3);
      tk = scanner(file);
      
      p.setChild4(p.getRoot(), B(file), 3);
      return p;
      
      } else { error(tk);}
      
    } else { error(tk);}
    
  } else if ((tk.getTokenType() == "Operator" && tk.getTokenName() == "/") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Assign") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Spot") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Move") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") || (tk.getTokenType() == "Operator" && tk.getTokenName() == "{")) {
  
    p.setChild1(p.getRoot(), D(file), 3);
    p.setChild2(p.getRoot(), B(file), 3);
    return p;
    
  } else { 
  
  p.generateLeafNode(p, "Empty", "", 1, 3);
  return p;

  }
  return p;
}

TestTree C(ifstream &file) {
  TestTree p; 
  p.generateNode("C: ", 3);
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == "{") {
  
    p.setChild1(p.getRoot(), F(file), 4);
    return p;
    
  } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Here") {
  
    p.setChild1(p.getRoot(), G(file), 4);
    return p;
    
  } else { error(tk);}
  return p;
}

TestTree D(ifstream &file) {
  TestTree p; 
  p.generateNode("D: ", 3);
  
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == "/") {
  
    p.setChild1(p.getRoot(), H(file), 4);
    return p;
    
  } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Assign") {
  
    p.setChild1(p.getRoot(), J(file), 4);
    return p;
    
  } else if ((tk.getTokenType() == "Keyword" && tk.getTokenName() == "Spot") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Move")) {
  
    p.setChild1(p.getRoot(), K(file), 4);
    return p;
    
  } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Flip") {
  
    p.setChild1(p.getRoot(), L(file), 4);
    return p;
    
  } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") {
  
    p.setChild1(p.getRoot(), E(file), 4);
    return p;
    
  } else if (tk.getTokenType() == "Operator" && tk.getTokenName() == "{") {
  
    p.setChild1(p.getRoot(), F(file), 4);
    return p;
    
  }  else { error(tk);}
  return p;
}

TestTree F(ifstream &file) {
  TestTree p; 
  p.generateNode("F: ", 5);
  
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == "{") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 6);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "If") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 6);
      tk = scanner(file);
      
        if (tk.getTokenType() == "Identifier") {

          p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 6);
          tk = scanner(file);
          
          if ((tk.getTokenType() == "Operator" && tk.getTokenName() == "<<") || (tk.getTokenType() == "Operator" && tk.getTokenName() == "<-")) {
          
            p.setChild4(p.getRoot(), T(file), 6);
            p.setChild5(p.getRoot(), W(file), 6);
            p.setChild6(p.getRoot(), D(file), 6);
            
            if(tk.getTokenType() == "Operator" && tk.getTokenName() == "}") {
            
              p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 7, 6);
              tk = scanner(file);
              return p;
              
            } else { error(tk);}
            
          } else { error(tk);}
          
        } else { error(tk);}
        
      } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Do") {

        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 6);
        tk = scanner(file);
        
        if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Again") {

          p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 6);
          tk = scanner(file);
          
          p.setChild4(p.getRoot(), D(file), 6);
          p.setChild5(p.getRoot(), T(file), 6);
          p.setChild6(p.getRoot(), W(file), 6);
          
          if(tk.getTokenType() == "Operator" && tk.getTokenName() == "}") {

            p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 7, 6);
            tk = scanner(file);
            return p;
          }
        } else { error(tk);}
        
      } else { error(tk);}
      
  }
  return p;
}

TestTree G(ifstream &file) {
  TestTree p; 
  p.generateNode("G: ", 4);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Here") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Number") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 5);
      tk = scanner(file);
      
      if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "There") {

        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 5);
        tk = scanner(file);
        return p;
        
      } else { error(tk);}
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree T(ifstream &file) {
  TestTree p; 
  p.generateNode("T: ", 7);
  
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == "<<") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 7);
    tk = scanner(file);
    return p;
    
  } else if (tk.getTokenType() == "Operator" && tk.getTokenName() == "<-") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 7);
      tk = scanner(file);
      return p;
      
    } else { error(tk);}
    
    return p;
}

TestTree H(ifstream &file) {
  TestTree p; 
  p.generateNode("H: ", 4);
  
  if (tk.getTokenType() == "Operator" && tk.getTokenName() == "/") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier" || tk.getTokenType() == "Number") {
      p.setChild2(p.getRoot(), Z(file), 5);
      return p;
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree J(ifstream &file) {
  TestTree p; 
  p.generateNode("J: ", 4);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Assign") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 5);
      tk = scanner(file);
      
      if ((tk.getTokenType() == "Operator" && tk.getTokenName() == "/") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Assign") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Spot") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Move") || (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") || (tk.getTokenType() == "Operator" && tk.getTokenName() == "{")) {
      
      p.setChild3(p.getRoot(), D(file), 5);
      return p;
      
      } else { error(tk);}
      
    } else { error(tk);}
    
  } else { error(tk);}
  
  return p;
}

TestTree K(ifstream &file) {
  TestTree p; 
  p.generateNode("K: ", 4);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Spot") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Number") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 5);
      tk = scanner(file);
      
      if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") {

        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 5);
        tk = scanner(file);
        
        if (tk.getTokenType() == "Number") {

          p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 4, 5);
          tk = scanner(file);
          return p;
          
        } else { error(tk);}
        
      } else { error(tk);}
      
    } else { error(tk);}
    
  } else if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Move") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
      tk = scanner(file);
      
      if (tk.getTokenType() == "Identifier") {

        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 5);
        tk = scanner(file);
        
        if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Show") {

          p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 5);
          tk = scanner(file);
          
          if (tk.getTokenType() == "Identifier") {

            p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 4, 5);
            tk = scanner(file);
            return p;
            
          } else { error(tk);}
          
        } else { error(tk);}
        
      } else { error(tk);}
      
    } else { error(tk);}
    
 return p;
}

TestTree L(ifstream &file) {
  TestTree p; 
  p.generateNode("L: ", 4);
  
  if (tk.getTokenType() == "Keyword" && tk.getTokenName() == "Flip") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 5);
    tk = scanner(file);
    
    if (tk.getTokenType() == "Identifier") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 5);
      tk = scanner(file);
      return p;
      
    } else {error(tk);}
    
  } else {error(tk);}
  return p;
}

TestTree V(ifstream &file) {
  TestTree p; 
  p.generateNode("V: ", 9);
  
  if (tk.getTokenName() == "+") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 10);
    tk = scanner(file);
    return p;
    
  } else if (tk.getTokenName() == "%") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 10);
    tk = scanner(file);
    return p;
    
  } else if (tk.getTokenName() == "&") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 10);
    tk = scanner(file);
    return p;
    
  } else {error(tk);}
  
  return p;
}

TestTree W(ifstream &file) {
  TestTree p; 
  p.generateNode("W: ", 7);
  
  if (tk.getTokenType() == "Number") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 8);
    tk = scanner(file);
    
    if ((tk.getTokenType() == "Operator" && tk.getTokenName() == "+") || (tk.getTokenType() == "Operator" && tk.getTokenName() == "%") || (tk.getTokenType() == "Operator" && tk.getTokenName() == "&")) {
    
      p.setChild2(p.getRoot(), V(file), 8);
      
      if (tk.getTokenType() == "Number") {

        p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 3, 8);
        tk = scanner(file);
        return p;
        
      } else {error(tk);}
      
    } else if (tk.getTokenType() == "Operator" && tk.getTokenName() == ".") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 2, 8);
      tk = scanner(file);
      return p;
      
    } else {error(tk);}
    
  } else {error(tk);}
  
  return p;
} 

TestTree Z(ifstream &file) {

  TestTree p; 
  p.generateNode("Z: ", 6);
  
  if (tk.getTokenType() == "Identifier") {

    p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 7);
    tk = scanner(file);
    return p;
    
  } else if (tk.getTokenType() == "Number") {

      p.generateLeafNode(p, tk.getTokenType(), tk.getTokenName(), 1, 7);
      tk = scanner(file);
      return p;
      
    } else { error(tk);}
    
    return p;
}

token scanner(ifstream &file) {

  //Get first char to send to scanner.
  nextChar = file.get();
  
   //Call scanner to get token object.
   token nextToken = FADriver(file, nextChar);
   
   //Return nextToken.
   return nextToken;
  
}

void error(token tk) {
  cout << "Error: Invalid token: " << tk.getTokenType() << " : " << tk.getTokenName() <<  endl;
  exit(-1);
}