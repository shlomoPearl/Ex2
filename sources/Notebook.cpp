#include "Notebook.hpp"
// #include "Line.cpp"
// #include "Page.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
namespace ariel{
    Page* Notebook::get_page(int p){
        if(notebook.count(p) == 0){
            Page page;
            notebook[p] = page;
        }
        return &notebook.at(p);
    }
    void Notebook::write(int page, int row ,int column , Direction d, const string &st){ // string st
        if(st.empty()){
            return;
        }
        if(page < 0 || row < 0 || column <0){
            throw("negative input");
        }
            Page* p = get_page(page);
            p->write_line(row,column,d,st);
        }
    string Notebook::read(int page, int row ,int column , Direction d, int len){
        if(len == 0){
            return " ";
        }
        if(page < 0 || row < 0 || column < 0 || len < 0){
            throw("negative input");
        }   
        Page* p = get_page(page);
        return p->read_line(row,column,d,len);
    }
    void Notebook::erase(int page, int row ,int column , Direction d, int len){
        if(len == 0 ){
            return;
        }
        if(page < 0 || row < 0 || column < 0 || len < 0){
            throw("negative input");
        }
        Page* p = get_page(page);
        p->erase_line(row,column,d,len);
    }
    string Notebook::show(int page){
        return "show";
    }
}

// int main(){
//     ariel::Notebook n;
//     // Page p;
//     n.write(3,4,4,Direction::Horizontal,"abcd");
//     // p.erase_line(4,4,Direction::Horizontal,4);
//     // l = *p.get_line(4);
//     string s = n.read(3,4,6,Direction::Vertical,5);
//     for (int i = 0; i < s.size(); i++)
//     {
//         // l = *p.get_line(i);
//         cout<< s.at(i)<<" ";
//     }
//     cout<< endl;
//     return 0;
// }
