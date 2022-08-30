#include "main.h"

int main(int argc, char *argv[]) {

  ifstream file(argv[1]);
  ifstream errFile(argv[2]);
  
  //If there are two files sent as input throw an error.
  if (file.is_open() && errFile.is_open()) {
    
      cout << "Fatal: ImproperUsage\nUsage:P1 [filename]" << endl;
      return 0;
    
   } else if (file.is_open()) {
    
    TestTree tree = parser(file, false);
    semanticCheck(tree.getRoot(), false, false, 0);
    generation(tree.getRoot());
    //traversePreOrder(tree.getRoot());
    
    //If file does not open, create new file and add contents into it. Then call testScanner.
  } else {
  
    ofstream file("newFile.txt");
    writeToFile(file, argv, argc);
    
    ifstream newFile("newFile.txt");
    TestTree tree = parser(newFile, true);
    semanticCheck(tree.getRoot(), false, false, 0);
    generation(tree.getRoot());
    //traversePreOrder(tree.getRoot());
    
  }
}

void callScanner(ifstream &file, bool willShowEoF) {
  
  //Get first char to send to scanner.
  nextChar = file.get();
  
  //While not at end of file, get tokens and print.
  while (nextChar != EOF) {  //!file.eof()
  
    //Call scanner to get token object.
    token nextToken = FADriver(file, nextChar);
    
    //Prints token.
    nextToken.printToken();
  }

  //If I provided a file, my project would not print an EoFToken.
  //So I had to include this code to read the EoFToken.
  if((willShowEoF == false)) {
    nextChar = file.get();
    token finalToken = FADriver(file, nextChar);
    finalToken.printToken();
  }
}

//A function that adds arguments into a file.
void writeToFile(ofstream &file, char *argv[], int argc) {

   for (int x = 1; x < argc; x++) {
       file << argv[x];
       file << " ";
   }
   file.close();
}
