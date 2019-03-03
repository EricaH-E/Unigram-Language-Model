//
//  UnigramLM.h
//  UnigramLM
//
//  Created by Erica Elliston on 12/2/18.
//  Copyright © 2018 Erica Elliston. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef UnigramLM_h
#define UnigramLM_h

class UnigramLM{
    
public:
    explicit UnigramLM(string file, string model);// constructor
    void SaveModel(); //Saves result of language model to a file
    
private:
    //stores words and their relative frequency
    struct Words{
        Words(string w, double f): word(w), frequency(f) {}
        string word;
        double frequency;
    };
    string filename;
    string languageModel;
    double totalWordCount;// number of words from file
    vector<Words>dictionary;
    void addWord(string nw);
    double wordCount();//counts total number of words in a file
    void createModel();//creates language model;
    
};


#endif /* UnigramLM_h */
