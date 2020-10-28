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

    Editor(string _file)
    {
        ifstream file(_file);

        if (!file)
            cout << "file doesn't opening!" << endl;

        for (std::string line; getline(file, line);)
        {
            document.d.push_back(line);
        }
        file.close();
    }
    loop();
};
