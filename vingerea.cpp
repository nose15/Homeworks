#include <iostream>
#include <string>

const std::string defaultAlphabet = "abcdefghijklmnopqrstuvwxyz";

enum Mode 
{
    encryption,
    decryption
};


int getIndex(char character, std::string word) 
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == character) return i;
    }

    return -1;
}


bool isInsideOf(char character, std::string word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == character) return true;
    }

    return false;
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


std::string * generateEncryptionArray(std::string key)
{
    std::string * encryptionArray;
    encryptionArray = new std::string[key.size()];

    for (int i = 0; i < key.size(); i++)
    {
        std::string customAlphabet;

        int keyLetterIndex = getIndex(key[i], defaultAlphabet);

        for (int j = 0; j < defaultAlphabet.size(); j++)
        {
            customAlphabet += defaultAlphabet[(keyLetterIndex + j) % defaultAlphabet.size()];
        }
        encryptionArray[i] = customAlphabet;
    }

    return encryptionArray;
}


std::string vigenere(std::string word, std::string key, Mode mode)
{
    key = clean(key);

    std::string * encryptionArray = generateEncryptionArray(key);

    int encryptionArrayHeight = key.size();
    int wordLength = word.size();

    std::string encrypted;

    if (mode == Mode(encryption)) 
    {
        for (int i = 0; i < wordLength; i++)
        {
            int index = getIndex(word[i], defaultAlphabet);
            encrypted += encryptionArray[i % encryptionArrayHeight][index];
        }
    }
    else
    {
        for (int i = 0; i < wordLength; i++)
        {
            int index = getIndex(word[i], encryptionArray[i % encryptionArrayHeight]);
            encrypted += defaultAlphabet[index];
        }
    }

    return encrypted;
}




int main()
{
    Mode mode;
    std::string key, word;
    int selected;

    getline(std::cin, key);
    getline(std::cin, word);

    std::cout << "szyfrowanie(0) czy deszyfrowanie(1) = ";
    std::cin >> selected;

    switch (selected)
    {
        case 0:
            mode = Mode(encryption);
            break;
        case 1:
            mode = Mode(decryption);
            break;
        default:
            return -1;
    }

    std::cout << vigenere(word, key, mode);
}