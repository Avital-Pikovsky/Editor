#include "Editor.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <mutex>

void Editor::loop()
{
    while (true)
    {
        char c = getchar();

        switch (c)
        {
        case '3':
            d.row = 3;
            break;

        case '+': //+2
            d.row += 2;
            break;

        case '-': // .-1
            d.row--;
            break;

        case '$':
            d.row = d.document.size() - 1;
            break;

        case 'a':
            d.add_lines_after();
            break;

        case 'i':
            d.add_lines_before();
            break;

        case 'c':
            d.replace_line();
            break;

        case 'd':
            d.delete_line();
            break;

        case '/': // /test/
            d.search();
            break;

        case 's': //s/old/new/
            d.change();
            break;

        case 'j':
            d.connect();
            break;

        case 'w': //w file
            d.write();
            break;

        case 'q':
            exit(EXIT_FAILURE);

        default:
            if (c != '\n')
                std::cout << "?" << std::endl;

            break;
        }
    }
}
