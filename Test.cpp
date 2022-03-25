#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Bad input"){
    ariel::Notebook notebook;
    CHECK_THROWS(notebook.write(-1,0,0,Direction::Horizontal,"abcd"));
    CHECK_THROWS(notebook.write(0,-1,0,Direction::Horizontal,"abcd"));
    CHECK_THROWS(notebook.write(0,0,-1,Direction::Horizontal,"abcd"));

    CHECK_THROWS(notebook.read(-1,0,0,Direction::Horizontal,1));
    CHECK_THROWS(notebook.read(0,-1,0,Direction::Horizontal,1));
    CHECK_THROWS(notebook.read(0,0,-1,Direction::Horizontal,1));
    CHECK_THROWS(notebook.read(0,0,0,Direction::Horizontal,-1));

    CHECK_THROWS(notebook.erase(-1,0,0,Direction::Horizontal,1));
    CHECK_THROWS(notebook.erase(0,-1,0,Direction::Horizontal,1));
    CHECK_THROWS(notebook.erase(0,0,-1,Direction::Horizontal,1));
    CHECK_THROWS(notebook.erase(0,0,0,Direction::Horizontal,-1));
}
TEST_CASE("Bad action"){
    ariel::Notebook notebook;
    for (int j = 0; j < 4;j++){
        for (int i = 0; i < 10; i++){
            for(int k = 0; k < 100; k++){
                notebook.erase(j,i,k,Direction::Vertical,100);
            }
        }
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 100; k++){
                CHECK_THROWS(notebook.write(i,j,k,Direction::Vertical,"a"));
            }
        }
        
    }
}

TEST_CASE("Good action and input"){
    ariel::Notebook notebook;
	notebook.write(0, 0, 0, Direction::Horizontal, "abcd");
    notebook.write(0, 1, 0, Direction::Vertical, "bcde");
    //will be something like this:
    //    0: abcd_____
    //    1: b________
    //    2: c________
    //    3: d________
    //    4: e________
	string st1 = notebook.read(0, 0, 0, Direction::Horizontal, 4);  
	string st2 = notebook.read(0, 0, 0, Direction::Vertical, 5);  
    CHECK(st1 == "abcd");
    CHECK(st2 == "abcde");
	notebook.erase( 0, 0, 0, Direction::Horizontal, 4);
    notebook.erase( 0, 1, 0, Direction::Vertical, 4);
    //will be something like this:
    //    0: ~~~~_____
    //    1: ~________
    //    2: ~________
    //    3: ~________
    //    4: ~________
    string st3 = notebook.read(0, 0, 0, Direction::Horizontal, 4);  
	string st4 = notebook.read(0, 1, 0, Direction::Vertical, 4);
    CHECK(st3 == "~~~~");
    CHECK(st3 == st4); 
}	
		