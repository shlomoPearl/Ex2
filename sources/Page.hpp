#pragma once

#include "Line.hpp"
#include "Direction.hpp"
#include <unordered_map>
#include <vector>
using ariel::Direction;
using namespace std;

class Page{
    unordered_map<int,Line> page;
    void writeByDirection(Line* line,Direction d,int row,int column, string change, int length);
    public:
    Line* get_line(int row); // for read and show
    void write_line(int row, int column,Direction d,const string& ); // for write and show
    void erase_line(int row, int column,Direction d, int length);
    string read_line(int row ,int column ,Direction d , int length);

   
};