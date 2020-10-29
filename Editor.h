#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Document.h"

class Editor
{
public:
    Document d;

    Editor(std::string _file)
    {
        std::ifstream file(_file);

        if (!file)
            std::cout << "file doesn't opening!" << std::endl;

        for (std::string line; getline(file, line);)
        {
            d.document.push_back(line);
        }
        file.close();
    }
    void loop();
};
