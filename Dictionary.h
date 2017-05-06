/************************************************************************
Title:			Dictionary.h
Author:			Usmaan Sahak
Purpose:		Dictionary.h header file
Description:		Header for Dictionary class, wrapper for Trie
*************************************************************************/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Trie.h"

class Dictionary {
  public:
    Dictionary();
    Dictionary(ifstream& file); //Load using below, constructor
    bool load(ifstream& file); //Clear before loading
    bool isLegalWord(const string& entry); //If contained, true. else, false. 
    int numWords(); //Return number of words. 
    vector<string> suggest(const string& s, int n); //Legal, organized length then alphabet. 
    
    ~Dictionary();
  private:
    Trie* tree; //Dictonary wraps this.
    void sugHelper(int a, TrieNode* node, int& o, const int n, string& s2, 
						vector<string>& sug);
};

#endif
