// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
   BST<std::string>TREE;
    char change_registr = 'a' - 'A';
    std::ifstream file(filename);
    std::string words = "";
    if (!file) 
    {
        std::cout << "Your file is error!" << std::endl;
        return TREE;
    }
    while (!file.eof()) 
    {
        char lexeme = file.get();
        if ((lexeme >= 'a' && lexeme <= 'z') || (lexeme >= 'A' && lexeme <= 'Z')) 
        {
            if (lexeme >= 'A' && lexeme <= 'Z')
                lexeme += change_registr;
            words += lexeme;
        }
        else if (words != "") 
        {
            TREE.add(words);
            words = "";
        }
    }
    file.close();
    return TREE;
}
