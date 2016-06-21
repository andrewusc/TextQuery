//
//  QueryResult.cpp
//  textQuery
//
//  Created by Yu Yang on 16/6/20.
//  Copyright (c) 2016 edu.self. All rights reserved.
//

#include "QueryResult.h"
using namespace std;


QueryResult::QueryResult(std::string qword, std::shared_ptr<std::vector<std::string>> file, std::shared_ptr<std::set<line_no>> lines) : queryWord(qword), lines(lines), file(file){
    
    
    
}


ostream& operator<<(ostream& os, const QueryResult &qt){
    os << qt.queryWord << " occurs " << qt.lines->size() << " times:" << endl;
    
    for(auto num : *qt.lines){
        os << "\t (line " << num+1 << ")"
        << *(qt.file->begin()+num) << endl;
    }
    
    return os;
}