//
// Created by Dell on 12/22/2018.
//

#ifndef EX2_AUTHORIDENTIFY_H
#define EX2_AUTHORIDENTIFY_H

#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>

class Author
{
public:
    void setSignature(std::vector<int> &v)
    {
        _signature = v;
    }

    void setName(std::string &name)
    {
        _name = name;
    }

    double distance(Author &other);

    std::string getName()
    {
        return _name;
    }

private:
    double scalar_product(std::vector<int> one, std::vector<int> other);

    std::string _name;
    std::vector<int> _signature;
};

class AuthorIdentify
{
public:
    explicit AuthorIdentify(std::vector<std::string> files);

    void read_frequent_words(std::string &file_path);

    void count_frequency(std::string &file_name, Author &author);

    void printDistances();

private:
    std::map<std::string, int> _frequency_of_words;
    Author _unknown_author;
    std::vector<Author> known_authors;
};

#endif //EX2_AUTHORIDENTIFY_H
