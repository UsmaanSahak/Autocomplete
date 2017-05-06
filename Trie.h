/************************************************************************
Title:			Trie.h
Author:			Usmaan Sahak
Purpose:		Trie.h header file
Description:		Trie Tree made up of linking TrieNodes.
*************************************************************************/

#ifndef TRIE_H
#define TRIE_H


#include "TrieNode.h"
class Trie {
  public:
    Trie();
    Trie(ifstream& file); //Read the file and make tree
    bool load(const string& file); //Creates trie based on file. (Clear previous entries.)
    bool load(ifstream& file); //Overloaded function of above.
    bool insert(const string& entry); //If not contained, then add and increment num. 
    bool contains(const string& entry); //Pass by value.
    bool remove(const string& entry);
    void clear();
    int numWords(); //returns num
    int countNodes(); //returns number of nodes in tree. 
    TrieNode* getRoot();
    void setRoot(TrieNode* newRoot);
    
    
    ~Trie();
  private:
    int countNodes(TrieNode* node); //Helper for countNodes().
    TrieNode* root; //Dummy root, $
    int num; //number of words
};

#endif
