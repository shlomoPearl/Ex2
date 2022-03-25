#pragma once

#include <string.h>
#include<vector>
#include <unordered_map>
// #include"Line.hpp"
#include "Page.hpp"
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Notebook
    {
    unordered_map<int,Page> notebook;
    Page* get_page(int p);
    public:
        // Notebook(/* args */);
        // ~Notebook();
        void write(int page, int row ,int column , Direction d,const string&); //the static becosue tidy
        string read(int page, int row ,int column , Direction d, int len);
        void erase(int page, int row ,int column , Direction d, int len);  //the static becosue tidy
        string show(int page);
    };
}