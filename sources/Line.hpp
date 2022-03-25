#pragma once

#include<vector>
#include<string>

using namespace std;
using index_t = std::vector<int>::size_type;
class Line{
    vector<char> line;
    public:
    Line() : line(100,'_'){};
    void set_char(index_t, char c);
    char get_char(index_t index);

};