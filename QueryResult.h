//
//  QueryResult.h
//  textQuery
//
//  Created by 宇 杨 on 16/6/20.
//  Copyright (c) 2016年 edu.self. All rights reserved.
//

#ifndef __textQuery__QueryResult__
#define __textQuery__QueryResult__


#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <map>
//using namespace std;

class QueryResult{
    friend std::ostream& operator<<(std::ostream&, const QueryResult &qt);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string, std::shared_ptr<std::vector<std::string>> file, std::shared_ptr<std::set<line_no>> lines);
private:
    std::string queryWord;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<line_no>> lines;
};

#endif /* defined(__textQuery__QueryResult__) */
