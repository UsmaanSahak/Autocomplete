/************************************************************************
Title:			TrieNode.cpp
Author:			Usmaan Sahak
Purpose:		TrieNode.h implementation file
Description:		Node used to be the building blocks to a Trie Tree
*************************************************************************/

#include "TrieNode.h"

/* Constructor */
TrieNode::TrieNode() {
  letter = ' ';
}

//Iterates through pointed nodes to see if we already have one with the arg letter. 
bool TrieNode::containsChar(char c) {
  if (following[c]) {
    return true;
  } else { 
    return false;
  }
}

/* Create a new node, and put the address into the letters map for that character. */
void TrieNode::addChar(char c) {

  if (!containsChar(c)) {
    TrieNode* temp = new TrieNode();
    temp->setLetter(c);
    following[c] = temp; //now following is pointing to node for that char. 
  }
}

//Return map of letters.
map<char,TrieNode*> TrieNode::getFollowing() {
  return following;
}

/*Add new pair to following variable.*/
void TrieNode::addFollowing(char c, TrieNode* newNode) {
  following[c] = newNode;
}

/*Remove pair from following variable.*/
void TrieNode::remFollowing(char c) {
  following.erase(c);
}


//Return letter
char TrieNode::getLetter() {
  return letter;
}

//Set letter
void TrieNode::setLetter(char c) {
  letter = c;  
}


/* Destructor, loop through following and delete all pointers to nodes. */
TrieNode::~TrieNode() {

  for (auto const &entry : getFollowing()) {
    delete entry.second;
  }
}







