#include "Document.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <iterator>

void Document::plus() //+
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        row += stoi(line);
    }
}

void Document::minus() //.-
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        row -= stoi(line);
    }
}
void Document::add_lines_after() //a
{
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
                return;
            document.emplace(document.begin() + (row + 1), line);
            row++;
        }
    }
}

void Document::add_lines_before() //i
{
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
            {
                row--;
                return;
            }
            document.emplace(document.begin() + row, line);
            row++;
        }
    }
}

void Document::replace_line() //c
{
    document.erase(document.begin() + row);
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
                return;
            document.emplace(document.begin() + row, line);
        }
    }
}
void Document::delete_line() //d
{
    document.erase(document.begin() + row);
}

void Document::search() // /text/
{
    std::string line;
    std::getline(std::cin, line);

    if (!line.empty())
    {

        line = line.substr(0, line.size() - 1);
        size_t found = document.at(row + 1).find(line);
        if (found != std::string::npos)
            row++;
        else
        {
            int i = -1;
            while (found == std::string::npos)
            {
                i++;
                found = document.at(i).find(line);
            }
            row = i;
        }
    }
}
void Document::change() // s/old/new/
{
    std::string line;
    std::getline(std::cin, line);

    if (!line.empty())
    {
        if (line.at(0) != '/' || line.at(line.length() - 1) != '/')
        {
            std::cout << "?" << std::endl;
            return;
        }

        line = line.substr(1, line.size() - 2);
        try
        {
            std::string old = line.substr(0, line.find("/"));
            std::string neword = line.substr(line.find("/") + 1, line.size() - 1);

            document.at(row).replace(document.at(row).find(old), old.size(), neword);
        }
        catch (std::out_of_range)
        {
            std::cout << "?" << std::endl;
        }
    }
}
void Document::connect() //j
{
    document.at(row) += document.at(row + 1);
    document.erase(document.begin() + (row + 1));
}

void Document::write() //w file
{
    std::string line;
    std::getline(std::cin, line);

    if (!line.empty())
    {
        line = line.substr(1, line.size()); //delete enter

        std::ofstream output_file(line);
        std::ostream_iterator<std::string> output_iterator(output_file, "\n");
        std::copy(document.begin(), document.end(), output_iterator);
    }
}
