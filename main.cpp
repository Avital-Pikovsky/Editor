#include "Editor.h"
#include <string>

int main(int argc, char *argv[])
{
    Editor editor(argv[1]);

    editor.loop();
    return 0;
}