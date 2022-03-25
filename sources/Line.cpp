#include "Line.hpp"
#include<vector>
using namespace std;
using index_t = std::vector<int>::size_type;

void Line::set_char(index_t index, char c){
    line.at(index) = c;
}
char Line::get_char(index_t index){
    return line.at(index);
}
