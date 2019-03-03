//
//  main2.cpp
//  UnigramLM
//
//  Created by Erica Elliston on 12/2/18.
//  Copyright © 2018 Erica Elliston. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double file_search(string word, string model){
    double p, relativeFrequency= log(0.00001);
    string w;
    
    ifstream search;
    search.open(model);
    
    if(!search.is_open()){
        cout<< "Error reading "<< model << " file" << endl;
        return -1;
    }
    
    while(search>>w>>p){
        if(w == word){
            relativeFrequency = log(p);
            break;
        }
    }
    
    search.close();
    
    
    return relativeFrequency;
    
}


double calculateProbability(string sentence, string model){
    double probability = 0;
    string word;
   
    istringstream iss (sentence);
    
    while(iss>> word){
        probability += file_search(word,model);
    }
    

    return probability;

}



int main(int argc, const char * argv[]){
    string sentence;

    if(argc< 3){
        cout <<"Please Enter correct number of arguments in command line"<< endl;
        cout <<"Example: ./StringProbability 'LM#' 'sentence you would like to test' "<< endl;
    }
    
    else{
        string model;
        
        if(strncmp(argv[1],"LM1",3) == 0){
            model ="LanguageModel1";
            cout <<"MODEL: "<< model<< endl;;
            cout<<"SENTENCE: "<< argv[2] << endl;
            cout<<"PROBABILTY: "<< calculateProbability(argv[2], model)<< endl;
            
        }
        else if(strncmp(argv[1],"LM2",3) == 0){
             model = "LanguageModel1";
            cout <<"MODEL: "<< model <<endl;
            cout<<"SENTENCE: "<< argv[2] <<endl;
            cout<<"PROBABILTY: "<< calculateProbability(argv[2], model) << endl;
        }
        else{
            cout <<"ERROR: Language Model Not Found! :"<<endl;
            cout<<"Please consult README.txt to ensure correct usage of program" << endl;
        }
        
    }
return 0;
}
