/************************************************************************
Title:			main.cpp
Author:			Usmaan Sahak
Purpose:		main.cpp file
Description:		Take a file as a command line argument to load a 
			dictionary, and allow users to query a string with 
			a certain number of responses in an autocomplete fashion.
*************************************************************************/

#include "Dictionary.h"



int main(int argc, char *argv[]) {

/*
  //Test TrieNode class
  TrieNode node;
  cout << node.getLetter() << endl;
  node.setLetter('a');
  node.addChar('a');
  node.addChar('b');
  node.addChar('c');
  cout << node.getLetter() << endl;
  cout << endl;

  if (node.containsChar('a')) { cout << "yes\n"; } else { cout << "no\n"; }
  if (node.containsChar('d')) { cout << "yes\n"; } else { cout << "no\n"; }
*/
 
 
  //Test Trie Class
  /*
  Trie tree;
  cout << tree.numWords() << endl;
  tree.insert("a");
  tree.insert("aa");
  tree.insert("aa");
  tree.insert("steve");
  tree.insert("bbb");
  tree.insert("abb");
  tree.insert("cbb");
  tree.insert("aba");
  tree.insert("steven");
  tree.insert("dafadafa");
  tree.insert("sam");
  tree.insert("steve");
  cout << tree.countNodes() << " is the number of nodes\n";
  cout << tree.numWords() << " is numWords." << endl;
  tree.remove("steven");
  tree.remove("aa");
  cout << tree.countNodes() << " is the number of nodes\n";
  cout << tree.numWords() << " is numWords." << endl;
  */

/*Lets create a Dictionary instance, and if included, 
load it with the file on the command line. */
  Dictionary D;
  ifstream file(argv[1]); 
  if (!file) {
    cout << "Not opened!" << endl;
  } else {
    D.load(file);
  }
  //cout << tree.countNodes() << " is the number of nodes\n";
  //cout << D.numWords() << " is the number of words.\n";
  string resp;
  int numSug;

  //Keep looping until user enters 'done'.
  while (resp != "DONE") {
    cout << "Enter a string to be autocompleted:" << endl;
    cin >> resp;

    //Make everything in entry all uppercase first.
    for (int i = 0; i < resp.length(); i++) {
    //cast the ascii'd upper case character to a char. e=>69=>E
    resp[i] = (char)toupper(resp[i]);
    }

    cout << "Enter number of suggestions:" << endl;
    cin >> numSug;

    //Lets get the result of the query from the Dictionary.
    vector<string> suggestions = D.suggest(resp,numSug);
    if (suggestions.size() == 0) { 
      cout << "No suggestions!" << endl;
    } else {
      cout << "Suggestions:" << endl;

      //Output the suggestions.
      for (int i = 0; i < suggestions.size(); i++) {
        cout << suggestions[i] << endl;
      }
    }
  } //While loop terminates.

}


