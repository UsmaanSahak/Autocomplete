/************************************************************************
Title:			README.txt
Author:			Usmaan Sahak
Purpose:		README file
Description:		Program performs autocomplete function for a given 
			string and number of responses.
*************************************************************************/


Build instructions of makefile:
CC = g++
LFLAGS = -std=c++11
CFLAGS = -c -Wall

SOURCES = main.cpp TrieNode.cpp Trie.cpp Dictionary.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE_NAME = Project3

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(OBJECTS)
	$(CC) -o $(EXECUTABLE_NAME) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE_NAME)

Parts complete:
Assignment completed to its entirety.

Description of known bugs:
No bugs found.

Report on Operation, Algorithms, and Class Structure:
Usage: ./Project3 <file>

There are a total of three classes, TrieNode, Trie, and Dictionary, that build on top of one another.
TrieNode holds a single letter as well as a map<char,TrieNode*>. It is used in the Trie class, where a
link of these nodes are formed with the purpose of making a tree to initiate the Trie search function.
The Dictionary class is simply a wrapper to the Trie class, which makes operation more simple and the
member functions less abstract to utilize. 

To use, simply write the name of the file you want to be loaded to the Dictionary object, and you may
start querying it for suggested words. The user must give a string as well as the number of suggestions
it wants back before the program operates. It will give 'No suggestions!' if no result is given,
otherwise a number of suggested strings, up to the number requested by the user, will be given. If there
are not enough suggestions in the database, it will give all responses available and ask for the
next string. 

The algorithm of the program uses maps to branch each node as a tree. Each node can have as many as
27 different branching nodes; one for each of the 26 letters, and another character used to signal
the end of a word, '$'. '$' is the equivalent of the null character used in C for strings in 
function for the Trie. To insert into the Trie, the string's characters is iterated through down
the tree until it reaches the end, in which it adds nodes until the end of the string (with an
additional '$' character, to signify a word ended here.) To remove a word, we simply delete the
'$' character. To count nodes, we recursively call a function that counts the two branching subroots
of a node, with leaf nodes simply returning 1. The suggest Dictionary member function, works also
by recursion. It has a parent TrieNode pointer and a parent string, where said parents are passed
into a recursive helper function. The function checks to see if a map key, which is a letter, 
exists, and if so, go down the tree at that direction. Once down, look for a '$' and output it if
this is present, as it is a legal word. Otherwise, go back to the parent, and repeat the process.
This is done first via character number (additional characters = a), which dictates how many 
recursive calls are made, or how far down the list the function is permitted to go to search for
legal words, and chooses which nodes to check first via alphabetical order. Alphabetical order
is done via ascii incrementation. Once a legal word has been found, as long as the number of 
outputs, or variable 'o', is smaller than the number of requested outputs by the user. 
