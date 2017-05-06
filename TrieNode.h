/************************************************************************
Title:			TrieNode.h
Author:			Usmaan Sahak
Purpose:		TrieNode.h helper file
Description:		Node used to be the building blocks to a Trie Tree
*************************************************************************/

#ifndef TRIENODE_H
#define TRIENODE_H

#include <vector> //Vectors.
#include <fstream> //file stream.
#include <iostream> //cout,cin.
#include <math.h> //case insensitive.
#include <map> //Hashes, used in a TrieNode member variable.
using namespace std;

class TrieNode
{
  public:
    TrieNode(); //Initialize to nullptr, etc
    bool containsChar(char c);
    void addChar(char c); //Adds to TrieNodes vector. 
    map<char,TrieNode*> getFollowing();
    void addFollowing(char c, TrieNode* newNode);
    void remFollowing(char c);
    char getLetter();
    void setLetter(char c);
    ~TrieNode();
  private:
    char letter;
    map<char,TrieNode*> following; //Map makes things simple while also being random access. 
};

#endif
