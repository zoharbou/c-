#include <iostream>
#include "AuthorIdentify.h"
/**
 * the main function that drives the hole process
 * @param argc num of arguments
 * @param argv list of arguments
 * @return
 */
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

