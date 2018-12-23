#include <iostream>
#include "AuthorIdentify.h"

int main(int argc, char *argv[])
{
    std::vector<std::string> files;
    for (int i = 1 ; i < argc ; ++i)
    {
        files.emplace_back(argv[i]);
    }
    AuthorIdentify a(files);
    return 0;
}

