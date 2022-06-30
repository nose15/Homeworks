#include <iostream>
#include <string>

const std::string defaultAlphabet = "abcdefghijklmnopqrstuvwxyz";

bool isInsideOf(char character, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == character) return true;
    }

    return false;
}

int getIndex(char character, std::string word) 
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == character) return i;
    }

    return -1;
}

std::string clean(std::string word)
{
    std::string cleanWord;

    for (int i = 0; i < word.size(); i++)
    {
        if (!isInsideOf(word[i], cleanWord)) cleanWord += word[i];
    }

    return cleanWord;
}

std::string getEncryptionAlphabet(std::string key)
{
    key = clean(key);

    for (int i = 0; i < defaultAlphabet.size(); i++)
    {
        if (!isInsideOf(defaultAlphabet[i], key)) key += defaultAlphabet[i];
    }

    return key;
}

std::string encryption(std::string word, std::string key)
{
    std::string encryptionAlphabet = getEncryptionAlphabet(key);
    std::string encrypted;

    for (int i = 0; i < word.size(); i++)
    {
        int index = getIndex(word[i], encryptionAlphabet);
        encrypted += defaultAlphabet[index];
    }

    return encrypted;
}

int main()
{
    std::cout << encryption("", "");

    return 0;
}