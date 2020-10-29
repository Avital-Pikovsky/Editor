#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>

class Document
{
public:
    std::vector<std::string> document;
    int row = 0;

    void go_to_line_3(); //3

    void move_2_lines_forward(); //+2

    void go_back_one_line(); //.-1

    void go_to_the_last_line(); //$

    void add_lines_after(); //a

    void point(); //.

    void add_lines_before(); //i

    void replace_line(); //c

    void delete_line(); //d

    void search(); // /text/

    void change(); // s/old/new/

    void connect(); //j

    void write(); //w file
};