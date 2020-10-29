#include "Editor.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

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

        case '.':
            break;

        case 'i':
            break;

        case 'c':
            break;

        case 'd':
            d.delete_line();
            break;

        case '/': // /test/
            break;

        case 's': //s/old/new/
            break;

        case 'j':
            break;

        case 'w': //w file
            break;

        case 'q':
            exit(EXIT_FAILURE);

        default:
            // std::cout << "?" << std::endl;
            break;
        }
    }
}
