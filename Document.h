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

    void plus(); //+

    void minus(); //.-

    void add_lines_after(); //a

    void add_lines_before(); //i

    void replace_line(); //c

    void delete_line(); //d

    void search(); // /text/

    void change(); // s/old/new/

    void connect(); //j

    void write(); //w file
};