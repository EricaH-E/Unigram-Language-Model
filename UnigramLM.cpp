//
//  UnigramLM.cpp
//  UnigramLM
//
//  Created by Erica Elliston on 12/2/18.
//  Copyright © 2018 Erica Elliston. All rights reserved.
//

#include <fstream>
#include <cmath>
#include "UnigramLM.h"


UnigramLM:: UnigramLM(string file, string model): filename(file), languageModel(model){
    totalWordCount = wordCount();
    createModel();
}

void UnigramLM:: SaveModel(){
    ofstream of;
    vector<Words>:: iterator save;
    
    of.open(languageModel);
    
    if(!of.is_open()){
        cout<< "ERROR CREATING MODEL FILE";
        return;
    }
    
    for(save = dictionary.begin(); save != dictionary.end(); save++){
        of<< save->word << " "<< (save->frequency)/(totalWordCount)<< endl;
    }
    
    of.close();
}

double UnigramLM:: wordCount(){
    double count = 0;
    string w;
    
    ifstream in;
    
    in.open(filename);
    
    if(!in.is_open()){
        cout <<"Could not Open file" << endl;
        return -1;
    }
    
    while(in >> w){
        count++;
    }
    in.close();
    return count;
}

void UnigramLM:: createModel(){
    ifstream in;
    string word;
    vector<Words>:: iterator search;
    
    cout<<"CREATING LANGUAGE MODEL ONE MOMENT PLEASE ....."<<endl;

    in.open(filename);
    
    if(!in.is_open()){
        cout <<"Could not Open file" << endl;
        return;
    }
    
    while(in >> word){
        bool found = false;
        //cout <<word << " "<< dictionary.size()<<endl;
        if(dictionary.empty()){
            addWord(word);
        }
        else{
            for(search = dictionary.begin(); search != dictionary.end(); search++){
                if(word == search->word){
                    search->frequency++;
                    found = true;
                     break;
                }
            }
            if(found == false){
                addWord(word);
            }
        }
    }
    
    in.close();
    
 /*   for(int i = 0; i<dictionary.size(); i++)
        cout << dictionary[i].word<<" " << dictionary[i].frequency << endl;*/
    cout<<endl;
    

}
void UnigramLM:: addWord(string nw){
    Words NW(nw,1);
    dictionary.push_back(NW);
}
