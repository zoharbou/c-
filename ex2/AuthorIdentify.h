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
    /**
     * sets the signature of the author
     * @param v the signature frequency vector
     */
    void setSignature(std::vector<int> &v)
    {
        _signature = v;
    }

    /**
     * sets the name of the author to the file name
     * @param name the file name
     */
    void setName(std::string &name)
    {
        _name = name;
    }

    /**
     * returns the distance between the signature of the current author and the other author.
     * @param other the other author
     * @return
     */
    double distance(Author &other);

    /**
     * returns the author name
     * @return
     */
    std::string getName()
    {
        return _name;
    }

private:
    /**
     * the name of the author
     */
    std::string _name;
    /**
     * the signature vector of the author
     */
    std::vector<int> _signature;
};


class AuthorIdentify
/**
 * this class activates the process of finding the best match for the unknown author
 */
{
public:
    /**
     * the constructor of the class. activates the process.
     * @param files
     */
    explicit AuthorIdentify(std::vector<std::string> files);

    /**
     * reads the frequent words from the given file and saves them for identification later
     * @param file_path
     */
    void read_frequent_words(std::string &file_path);

    /**
     * counts the frequency of the saved words in the given file that represents the given author
     * @param file_name the path
     * @param author
     */
    void count_frequency(std::string &file_name, Author &author);

    /**
     * prints the resulted distances and the best match
     */
    void printDistances();

private:
    /**
     * saves the frequent words as keys. the values are the counters for the words
     */
    std::map<std::string, int> _frequency_of_words;
    /**
     * the unknown author
     */
    Author _unknown_author;
    /**
     * the vector of the known author objects
     */
    std::vector<Author> known_authors;
};

#endif //EX2_AUTHORIDENTIFY_H
