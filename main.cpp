//
//  main.cpp
//  textQuery
//
//  Created by Yu Yang on 16/6/20.
//  Copyright (c) 2016 edu.self. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"
#include "QueryResult.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream ifs("test.txt");
    if(!ifs){
        cout << "file open failed"<< endl;
        return 0;
    }
    
    TextQuery tq(ifs);
    while(true){
        cout << "Input the word you want ot query : ";
        string word;
        if(!(cin >> word))  break;
        
        cout << tq.query(word) << endl;
        
    }
    
    
    
    return 0;
}
