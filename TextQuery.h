//
//  TextQuery.h
//  textQuery
//
//  Created by Yu Yang on 16/6/20.
//  Copyright (c) 2016 edu.self. All rights reserved.
//

#ifndef __textQuery__TextQuery__
#define __textQuery__TextQuery__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>


class QueryResult;

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    
    TextQuery(std::ifstream &is);
    QueryResult query(const std::string &str) const;
    
private:
    //std::vector<std::string> lines;
    std::map<std::string, std::shared_ptr< std::set<line_no>>> lineNums;
    std::shared_ptr<std::vector<std::string>> file;
    
};

#endif /* defined(__textQuery__TextQuery__) */
