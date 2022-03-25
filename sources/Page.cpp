#include<string>
#include<iostream>
#include"Page.hpp"
// #include "Line.cpp"


/*
return - line from this page
paramaters - row - the index of the line we want
*/
const char ERASE_CHAR = '~';
const int NOT_ERASE = 0;
const int LEN_LINE = 100;

Line* Page::get_line(int row){ 
    if(page.count(row) == 0){ // its a 'new' line
        Line line;
        page[row] = line;
    }
    return &page.at(row);
}


void Page::writeByDirection(Line* line,Direction d,int row,int column, string change, int length){
    if(length != NOT_ERASE){
        if( d == Direction::Horizontal){
            for (int i = 0; i < length; i++){
                line->set_char((index_t)(i + column) ,change[0]); 
            }  
        }else{
            int currentRow = row;
            for (int i = 0; i < length; i++){
                line->set_char((index_t)(column) ,change[0]);
                currentRow ++;
                line = get_line(currentRow);
            }
        }
    }
    else if( d == Direction::Horizontal){
        for (index_t i = 0; i < change.size(); i++){
            if(line->get_char(i + (index_t)column) == '_' ){
                line->set_char(i + (index_t)column ,change.at(i));
            }else{
                throw("this line has been writed");
            }
        }  
    }else{
        int currentRow = row;
        for (index_t i = 0; i < change.size(); i++){
            if(line->get_char((index_t)column) == '_'){
                line->set_char((index_t)column,change.at(i));
                currentRow ++;
                line = get_line(currentRow);

            }else{
                throw("this line has been writed");
            }
        }
    }
}

void Page::write_line(int row, int column,Direction d, const string &change){
    if(d == Direction::Horizontal && (index_t)column + change.size()> LEN_LINE ){
                throw out_of_range("the text too big");
    }
    Line* currentLine = get_line(row);
    writeByDirection(currentLine ,d ,row ,column ,change , NOT_ERASE);
}

void Page::erase_line(int row , int column ,Direction d, int length){
    if(d == Direction::Horizontal && column + length > LEN_LINE ){
                throw out_of_range(" too much erase");
    }
    Line* currentLine = get_line(row);
    writeByDirection(currentLine ,d ,row ,column ,&ERASE_CHAR , length);
}

string Page::read_line(int row ,int column ,Direction d ,int length){
    if(d == Direction::Horizontal && column + length > LEN_LINE ){
                throw out_of_range("too much to read");
    }
    string ans;
    Line* l = get_line(row);
    if( d == Direction::Horizontal){
        for (index_t i = 0; i < length ; i++){
            ans += l->get_char((index_t)column + i);
        }  
    }else{
        int currentRow = row;
        for (index_t i = 0; i < length; i++){
            ans += get_line(currentRow)->get_char((index_t)column);
            currentRow ++;
            // line = get_line(currentRow);
        }
    }
    return ans;
}

// int main(){
//     Page p;
//     Line l;
//     p.write_line(4,4,Direction::Horizontal,"abcd");
//     // p.erase_line(4,4,Direction::Horizontal,4);
//     // l = *p.get_line(4);
//     string s = p.read_line(4,6,Direction::Vertical,5);
//     for (int i = 0; i < s.size(); i++)
//     {
//         // l = *p.get_line(i);
//         cout<< s.at(i)<<" ";
//     }
//     cout<< endl;
//     return 0;
// }

