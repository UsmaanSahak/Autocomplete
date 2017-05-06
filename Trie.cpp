/************************************************************************
Title:			Trie.cpp
Author:			Usmaan Sahak
Purpose:		Trie.h implementation file
Description:		Trie Tree made up of linking TrieNodes.
*************************************************************************/

#include "Trie.h"

/*Default Constructor*/
Trie::Trie() {
  root = new TrieNode();
  num = 0;
  root->setLetter('^'); //Dummy root.
}
/*One parameter constructor*/
Trie::Trie(ifstream& file) {
  string entry;
  while (file >> entry) {
    insert(entry);
  }
}
/*Create Trie based on given dictionary file, string name.*/
bool Trie::load(const string& file) {
  clear();
  ifstream handle(file);
  string entry;
  while (handle >> entry) {
    insert(entry);
  }
  return true;
}

/*Create Trie based on given dictionary file, file stream.*/
bool Trie::load(ifstream& file) {
  string entry;
  while (file >> entry) {
    insert(entry);
  }
  return true;
}








/*
Insert string into the tree. If there are already letters provided for the
entry, we use those and start branching off when this is no longer the case. 
*/
bool Trie::insert(const string& entry) {
  
  TrieNode* it = root;
  string tentry = entry;

//Make everything in entry all uppercase first.
  for (int i = 0; i < tentry.length(); i++) {
    //cast the ascii'd upper case character to a char. e=>69=>E
    tentry[i] = (char)toupper(tentry[i]);
  }


  tentry = tentry + '$'; //Mark the end of the word in the tree. 
  
  //While there is a map provided for each character in entry, keep iterating down the tree. 
  
  map<char,TrieNode*>::iterator tt;

  int i = 0;
  while (it->getFollowing()[tentry[i]]) { //While able to go further down..
    it = it->getFollowing()[tentry[i]]; 
    i++;
  } 

  //Case 1: The word already exists in the tree. 
  if (i == tentry.length()) {
    return true;
  }
  //Case 2: Extend branch for rest of entry.
  while (i < tentry.length()) {
    //Make new node, initialize and add to following of iterated node. 
    TrieNode* temp = new TrieNode;
    temp->setLetter(tentry[i]);
    it->addFollowing(tentry[i],temp);
    temp = nullptr; //Avoid dangling pointers.
    it = it->getFollowing()[tentry[i]];
    ++i;
  }
  num++;
  return true;
}

    



/*
Similar to insert(), it checks if the characters are were they are supposed to be if
it was inserted.
*/
bool Trie::contains(const string& entry) {

  string tentry = entry;
  for (int i = 0; i < tentry.length(); i++) {
    //cast the ascii'd upper case character to a char. e=>69=>E
    tentry[i] = (char)toupper(tentry[i]);
  }

  tentry = tentry + '$';
  TrieNode* it = root;
  //Iterate through tree
  int i = 0;
  while (it->getFollowing()[tentry[i]]) {
    it = it->getFollowing()[tentry[i]];
    ++i;
  }
  //If entire string is in tree, then return true.
  if (i == tentry.length()) { return true; }
  else { return false; }

}

/* If contains(entry) is true, iterate down the tree and remove the node that has the '$'. */
bool Trie::remove(const string& entry) {
  if (!contains(entry)) {
    return false; //Not present in the first place!
    cout << "Not found in tree!\n";
  }
  string tentry = entry;
  //Uppercase.
  for (int i = 0; i < tentry.length(); i++) {
    //cast the ascii'd upper case character to a char. e=>69=>E
    tentry[i] = (char)toupper(tentry[i]);
  }
  TrieNode* it = root;
  int i = 0;
  while (it->getFollowing()[tentry[i]]) { 
    it = it->getFollowing()[tentry[i]]; //Keep going down tree
    ++i;
  }
  //Remove the $ node.

  it->remFollowing('$');//Removes pair with '$' in map.

  num--;
  return true;
}


/*Clears the tree.*/
void Trie::clear() {
  delete root;
  root = new TrieNode(); //New dummy root
}

/*returns number of words in tree.*/
int Trie::numWords() {
  return num;
}




/*returns number of nodes in tree.*/
int Trie::countNodes() {
  int result = 0;
  //Iterate through all of root node's branching nodes and call helper.
  for (auto const &entry : root->getFollowing()) {
    result = result + countNodes(entry.second);
  }
  return result;
}

/*Helper function for countNodes()*/
int Trie::countNodes(TrieNode* node) {
  int result = 1; //Count the argument node in the count.
  //Iterate through all argument nodes and call recursively.
  for (auto const &entry : node->getFollowing()) {
    result = result + countNodes(entry.second);
  }
  return result;
}

/*get root*/
TrieNode* Trie::getRoot() {
  return root;
}

/*set root*/
void Trie::setRoot(TrieNode* newRoot) {
  root = newRoot;
}


/*Destructor*/
Trie::~Trie() {
  delete root; //Should cause chain reaction, where entire tree is deleted. 
  root = nullptr;
}


