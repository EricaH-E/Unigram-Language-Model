# Unigram-Language-Model

Program Instructions:

----------------------------------------
About:
----------------------------------------
    This program is written in c++
    This program is a simple implementaion of the unigram language model

----------------------------------------
To compile:
----------------------------------------
    From command line type:  make all

-----------------------------------------
To run:
-----------------------------------------
1. First create the language models:

    From command line type:  ./UnigramLM <file>
    //ca file will create language model 1
    //all file will create language model 2

    Example: ./UnigramLM ca

    type ls to see resulting language model files in directory

    **Please note that the language model for all file will take longer**


2.Test each language model
    From command line type:  ./StringProbability <LM#> <sentence to test>

    // LM# should either be LM1 for 'ca' file OR LM2 for 'all' file
    // sentence to test should be in quotes

    Example:
    ./StringProbability LM2 "This is my sentence"

 **Please note probabilities are calculated using log; some probabilities will return a negative result**



