//
//  TextQuery.cpp
//  textQuery
//
//  Created by 宇 杨 on 16/6/20.
//  Copyright (c) 2016年 edu.self. All rights reserved.
//

#include "TextQuery.h"
#include "QueryResult.h"
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
using namespace std;

TextQuery::TextQuery(ifstream &is):file( new vector<string>){
    string text;
    while( getline(is,text) ){
        file->push_back(text);
        line_no lineNum = file->size()-1;
        istringstream line(text);
        string word;
        while(line >> word){
            auto &lines = lineNums[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(lineNum);
        }
    }
}

QueryResult TextQuery::query(const std::string &str) const{
    static shared_ptr<set<line_no>> lineNum(new set<line_no>);
    if(lineNums.find(str) == lineNums.end()){
        return QueryResult(str,file,lineNum);
    }
    return QueryResult(str,file,lineNums.find(str)->second);
}
    
