/************************************************************************
Title:			Dictionary.cpp
Author:			Usmaan Sahak
Purpose:		Dictionary.h implementation file
Description:		Make a class called 'dictionary' to wrap Trie
*************************************************************************/

#include "Dictionary.h"

/*Default Constructor*/
Dictionary::Dictionary() {
  tree = new Trie();
}

/*Constructor with file stream*/
Dictionary::Dictionary(ifstream& file) {
  delete tree;
  tree = new Trie(file);
}

/*load tree with file stream */
bool Dictionary::load(ifstream& file) {
  tree->load(file);
  return true;
}

/*Checks to see if word is legal*/
bool Dictionary::isLegalWord(const string& entry) { 
  if (tree->contains(entry)) {
    return true;
  } else {
    return false;
  }
}

/*get number of words in Dictionary.*/
int Dictionary::numWords() {
  return tree->numWords();
}

/*Get a vector of strings full of autocomplete suggestions.
Go through the tree until you get to the end in respect to the 
inputted string, and then start giving string suggestions, shortest
first, then alphabetically, that branch off of the argument. 
*/
vector<string> Dictionary::suggest(const string& s, int n) {
  TrieNode* it = tree->getRoot(); //Start at root.
  vector<string> suggestions; //Will eventually be returned.

  //Iterate through tree with argument string. 
  for (int i = 0; i < s.length(); i++) {
    if (it->getFollowing()[s[i]]) {
      it = it->getFollowing()[s[i]];
    } else {
      cout << "Not contained." << endl;
      return suggestions;
    }
  }
  //Now lets start getting suggestions.
  int a = 0; int o = 0;
  //15 characters longer than the argument string should be more than enough.
  while (o < n && a < 15) { 
    string s2 = s; //Don't change parent string. 
    TrieNode* it2 = it; //Don't change parent iterator.
    sugHelper(a,it2,o,n, s2, suggestions);
    ++a;
  }
  return suggestions; //Return empty.
}


/*Helper to suggest, it is a recursive function that goes down the tree
and fills the suggestions vector with strings. */
void Dictionary::sugHelper(int a, TrieNode* it2, int& o, const int n, string& s2, vector<string>& sug) {
  TrieNode* it3; 
  if (a == 0) { //Now lets check if this iteration contains a legal word.
    if (it2->getFollowing()['$'] && o < n) {
      //If legal word (Has '$' at end), then push back into answer.
      sug.push_back(s2);
      ++o;
      return;
    }
  } else {
    int ascii = 65; //equal to 'A' in ascii. 
    while (ascii < 91) { //Iterate alphabetically, 'A' to 'Z'.
      if (it2->getFollowing()[(char)ascii]) {
        it3 = it2->getFollowing()[(char)ascii]; //Don't change parent iterator.
        string s3 = s2 + it3->getLetter(); //Don't change parent string.
        sugHelper(a-1,it3,o,n,s3,sug); //Go further down.
      }
      ascii++;
    }
  } 
}        

/*Destructor*/
Dictionary::~Dictionary() {
  delete tree;
}

















  
