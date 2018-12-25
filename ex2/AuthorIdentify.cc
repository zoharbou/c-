#include <fstream>
#include <map>
#include <numeric>
#include "AuthorIdentify.h"
#include <boost/tokenizer.hpp>
#include<bits/stdc++.h>

/***********************constants****************************/

typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
const std::string OPEN_ERROR = "can't open file";
const std::string BEST_MATCH_MSG = "Best matching author is ";
const std::string SCORE_MSG = " score ";


/*******************implementation of the functions********************/
void AuthorIdentify::read_frequent_words(std::string &file_path)
{
    std::string word;
    std::ifstream frequent_words_file{file_path};
    if (!frequent_words_file)
    {
        std::cerr << OPEN_ERROR;
        return;
    }
    while (frequent_words_file >> word)
    {
        _frequency_of_words[word] = 0;
    }
}

void AuthorIdentify::count_frequency(std::string &file_name, Author &author)
{
    // set the author name with the file name
    author.setName(file_name);
    std::ifstream file;
    file.open(file_name);
    std::stringstream strStream;
    strStream << file.rdbuf();
    std::string all_words = strStream.str();

    boost::char_separator<char> sep{" ,\n\r!;:\""};
    tokenizer tok{all_words, sep};
    for (const std::string &word : tok)
    {
        std::string str(word.begin(), word.end());
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        if (_frequency_of_words.find(str) != _frequency_of_words.end())
        {
            _frequency_of_words[str] += 1;
        }
    }

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
    Author best_match = known_authors[0];

    for (auto &it : known_authors)
    {
        std::cout << it.getName() << " " << _unknown_author.distance(it) << std::endl;
        if (_unknown_author.distance(it) < _unknown_author.distance(best_match))
        {
            best_match = it;
        }
    }
    std::cout << BEST_MATCH_MSG << best_match.getName() << SCORE_MSG
              << _unknown_author.distance(best_match) << std::endl;
}

AuthorIdentify::AuthorIdentify(std::vector<std::string> files)
{
    read_frequent_words(files[0]);
    count_frequency(files[1], _unknown_author);
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
    double scalar_a_b = std::inner_product(std::begin(_signature), std::end(_signature),
                                           std::begin(other._signature), 0.0);
    double norm_a = sqrt(std::inner_product(std::begin(_signature), std::end(_signature),
                                            std::begin(_signature), 0.0));
    double norm_b = sqrt(std::inner_product(std::begin(other._signature),
                                            std::end(other._signature),
                                            std::begin(other._signature), 0.0));
    return scalar_a_b / (norm_a * norm_b);
}
