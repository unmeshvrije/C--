#include<iostream>
#include<algorithm>
#include<queue>
#include "trie.h"

using namespace std;

TrieNode* TrieNode::findChild(char ch)
{
  for (int i = 0; i < children.size(); ++i) {
    if (children[i]->getChar() == ch) {
      return children[i];
    }
  }
  return NULL;
}

void TrieNode::removeAllChildren()
{
  for (int i = 0; i < children.size(); ++i) {
    children[i]->removeAllChildren();
    delete children[i];
  }
}

bool TrieNode::deleteChild(TrieNode *child)
{
  // Find the child in the vector
  vector<TrieNode*>::iterator it = std::find(children.begin(), children.end(), child);
  if (it == children.end()) {
    return false;
  }

  // child found. 
  // 1. Remove all its children
  child->removeAllChildren();
  // 2. Remove from the vector
  children.erase(std::remove(children.begin(), children.end(), child), children.end());
  // 3. Free memory for this child
  delete child;
}

void TrieNode::print()
{
  string markerString = (marker) ? "true" : "false";
  cout << "|" << character << "|" << markerString << "|-" << endl;
  for (int i = 0; i < children.size(); ++i) {
    children[i]->print();
  }
}

/**
 * Trie class functions
 * */
Trie::Trie()
{
  root = new TrieNode();
}

Trie::~Trie()
{
  cout << "destroying the trie" << endl;
  if (root) {
    root->removeAllChildren();
    delete root;
  }
}

void Trie::print()
{
  root->print();
}

void Trie::addWord(string word)
{
  TrieNode *current = root;
  if (word.length() == 0) {
    current->setMarker(true);
    return;
  }
  // Try to find the first character of the word.
  // If found, search next character in the children array of the returned node
  // If not, create new node and add to the children of root
  for (int i = 0; i < word.length(); ++i) {
    TrieNode *newnode = current->findChild(word[i]);
    if (newnode == NULL) {
      newnode = new TrieNode();
      newnode->setChar(word[i]);
      current->appendChild(newnode);
    }
    current = newnode;
    if (i == word.length()-1) {
      current->setMarker(true);
    }
    
  }
}

bool Trie::findWord(string word)
{
  TrieNode *current = this->root;
  TrieNode *next;
  for (int i = 0; i < word.size(); ++i) {
    next = current->findChild(word[i]);
    if (next == NULL) {
      return false;
    } else {
      current = next;
    }
  }

  // All characters of the word are found, but that word was never added
  if (next->getMarker() == false) {
    return false;
  }

  return true;
}

bool Trie::deleteWord(string word)
{
  TrieNode *current = this->root;
  TrieNode *next;
  for (int i = 0; i < word.size(); ++i) {
    next = current->findChild(word[i]);
    if (next == NULL) {
      return false;
    } else {
      current = next;
    }
  }

  // All characters of the word are found, set the marker to false
  next->setMarker(false);
  return true;
}

int main()
{
  Trie trie;
  trie.addWord("aaaaaa");
  trie.addWord("aaaaab");
  trie.addWord("aaaaac");
  trie.addWord("aaaaad");
  trie.addWord("aaaaae");

  trie.print();
  cout << trie.findWord("aa") << endl;
  cout << trie.findWord("aaaaaa") << endl;
 // trie.deleteWord("bat");
  //cout << "should be zero : " << trie.findWord("bat") << endl;
  //cout << trie.findWord("battery") << endl;
  
}
