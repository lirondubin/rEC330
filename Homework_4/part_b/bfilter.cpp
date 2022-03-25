#include <vector>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bfilter.h"

using namespace std;

// (a)

class SillyHashFun : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        long long int hash = 7;
        for (int i = 0; i < key.size(); i++)
        {
            hash = (hash * 31 + key[i]) % 330;
        }
        return hash % 330;
    }
};

class GoodHashFun_0 : public HashFun
{
    unsigned int operator()(const std::string &key)
    {
        long long int hash = 0;
        for (int i = 0; i < key.size(); i++)
        {
            hash = (hash + ((int)key[i]));
            hash = hash % 330;
        }
        return hash;
    }
};

// ...
// You can make as many hash functions as you want!
// ...

void BloomFilter::add_hash_funs()
{
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    SillyHashFun *h1 = new SillyHashFun();
    GoodHashFun_0 *h2 = new GoodHashFun_0();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string &key)
{
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.

    // Here's how you can call your hash functions that you added in add_hash_funs()
    // unsigned int first_hash_result = this->call_hash(0, key);
    // std::cout << "Hash of '" << key << "' is '" << first_hash_result << "' using the first hash function." << std::endl;
    // unsigned int second_hash_result = this->call_hash(1, key);
    // std::cout << "Hash of '" << key << "' is '" << second_hash_result << "' using the second hash function." << std::endl;

    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    int length = this->hash_funs.size();
    for (int i = 0; i < length; i++)
    {
        unsigned int result = this->call_hash(i, key);
        (this->filter)[result % 330] = 1;
    }
}

bool BloomFilter::member(const std::string &key)
{
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    int length = this->hash_funs.size();
    for (int i = 0; i < length; i++)
    {
        unsigned int result = this->call_hash(i, key);
        if (!(this->filter)[result % 330])
        {
            return false;
        }
    }
    return true;
}

// int main()
// {
//     BloomFilter BF;

//     BF.add_hash_funs();
//     ifstream activeLinks("phishing-links-ACTIVE.txt");
//     string line;
//     int i = 0;
//     while (getline(activeLinks, line))
//     {
//         line = activeLinks[i];
//         BF.insert(&line);
//         i++;
//     }
// }