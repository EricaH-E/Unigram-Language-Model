//  Prof Jia XU
//  Class Language Technology
//  main.cpp
//  UnigramLM
//
//  Created by Erica Elliston on 12/2/18.
//  Copyright © 2018 Erica Elliston. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "UnigramLM.h"

using namespace std;

int main(int argc, const char * argv[]) {
    if(argc < 2 ){
        cout<<"Please enter a valid amount of arguments:"<<endl;
        cout<<"Example: './UnigramLM <filename> ' "<<endl;
    }
    
    else{
        string model;
        if(strncmp(argv[1],"ca",2)== 0)
            model ="LanguageModel1";
        if(strncmp(argv[1],"all",3)== 0)
            model ="LanguageModel2";
        //cout<< argv[0] <<" " << argv[1] << endl;
        UnigramLM LM(argv[1],model);
        LM.SaveModel();
        cout<< "The Language model for "<< argv[1] <<" has now been created, Please check your current directory for resulting "<< model<<" file"<< endl;
    }
    return 0;
}

