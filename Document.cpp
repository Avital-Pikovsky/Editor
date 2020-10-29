#include "Document.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>

void Document::add_lines_after() //a
{
    for (std::string line; std::getline(std::cin, line);)
    {
        row++;
        document.emplace(document.begin() + row, line);
        std::cout << " in row: " << row << ", " << document[row] << std::endl;
    }
    // std::cout << " in vector: " << document[row + 1] << std::endl;
    // std::cout << " row: " << row << std::endl;
}

void Document::point() //.
{
}

void Document::add_lines_before() //i
{
}

void Document::replace_line() //c
{
}
void Document::delete_line() //d
{
    document.erase(document.begin() + (row - 1));
}

void Document::search() // /text/
{
}
void Document::change() // s/old/new/
{
}
void Document::connect() //j
{
}

void Document::write() //w file
{
}
