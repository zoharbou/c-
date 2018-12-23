//
// Created by Dell on 12/22/2018.
//

#include <fstream>
#include <map>
#include "AuthorIdentify.h"

void AuthorIdentify::read_frequent_words(std::string &file_path)
{
    std::string word;
    std::ifstream frequent_words_file;
    frequent_words_file.open(file_path);
    if (!frequent_words_file)
    {
        std::cerr << "can't open file";
        return;
    }
    while (frequent_words_file >> word)
    {
        std::cout << word << std::endl;
        _frequency_of_words[word] = 0;
    }
    frequent_words_file.close();
}

void AuthorIdentify::count_frequency(std::string &file_name, Author &author)
{
    // set the author name with the file name
    author.setName(file_name);
    std::string word;
    std::ifstream unknown_file;
    unknown_file.open(file_name);
    if (!unknown_file)
    {
        std::cerr << "can't open file";
        return;
    }
    while (unknown_file >> word)
    {
        if (_frequency_of_words.find(word) != _frequency_of_words.end())
        {
            _frequency_of_words[word]++;
        }
    }
    unknown_file.close();

    std::vector<int> v;
    for (auto &it : _frequency_of_words)
    {
        v.push_back(it.second);
        it.second = 0;
    }
    // set the signature vector
    author.setSignature(v);
}

void AuthorIdentify::printDistances()
{
    //todo find best match with min
    Author best_match = known_authors[0];

    for (auto &it : known_authors)
    {
        std::cout << it.getName() << " " << _unknown_author.distance(it) << std::endl;
        if (_unknown_author.distance(it) < _unknown_author.distance(best_match))
        {
            best_match = it;
        }

    }
    std::cout << "Best matching author is " << best_match.getName() << " score "
              << _unknown_author.distance(best_match) << std::endl;

}

AuthorIdentify::AuthorIdentify(std::vector<std::string> files)
{
    read_frequent_words(files[0]);
    count_frequency(files[1], _unknown_author);
//    std::cout<<_unknown_author.getName()<<std::endl;
    for (int i = 2 ; i < files.size() ; ++i)
    {
        Author author;
        count_frequency(files[i], author);
        known_authors.push_back(author);
    }
    printDistances();
}

double Author::distance(Author &other)
{
    return (scalar_product(_signature, other._signature) /
            (scalar_product(_signature, _signature) *
             (scalar_product(other._signature, other._signature))));
}

double Author::scalar_product(std::vector<int> one, std::vector<int> other)
{
    double result = 0;
    for (int i = 0 ; i < one.size() ; ++i)
    {
        result += one[i] * other[i];
    }
    return result;
}
