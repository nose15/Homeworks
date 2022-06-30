#include <iostream>
#include <string>

enum Mode
{
    encryption,
    decryption
};

std::string kolumnyEncryption(std::string word, int numOfColumns, int * key)
{
    std::string encrypted;

    if (word.size() % numOfColumns != 0)
    {
        for (int i = 0; i < word.size() % numOfColumns; i++)
        {
            word += '\0';
        }
    }

    std::string * columns;
    columns = new std::string[numOfColumns];

    int currentLetterIndex = 0;

    for (int j = 0; j < word.size() / numOfColumns; j++)
    {
        for (int i = 0; i < numOfColumns; i++)
        {
            columns[i] += word[currentLetterIndex];
            currentLetterIndex++;
        }
    }

    for (int i = 0; i < numOfColumns; i++)
    {
        encrypted += columns[key[i]];
    }


    return encrypted;
}   

std::string kolumnyDecryption(std::string word, int numOfColumns, int * key)
{
    std::string decrypted;
    std::string * columns;
    columns = new std::string[numOfColumns];

    int currentLetterIndex = 0;

    int * lengths;
    lengths = new int[numOfColumns];

    for (int i = 0; i < numOfColumns; i++)
        lengths[i] = 0;

    for (int i = numOfColumns; i > word.size() % numOfColumns; i--)
        lengths[i] = -1;

    if (word.size() % numOfColumns != 0)
    {
        for (int i = 0; i < word.size() % numOfColumns; i++)
            word += '\0';
    }

    for (int i = 0; i < numOfColumns; i++)
        lengths[i] += word.size() / numOfColumns;

    for (int i = 0; i < numOfColumns; i++)
    {   
        for (int j = 0; j < lengths[key[i]]; j++)
        {
            columns[key[i]] += word[currentLetterIndex];
            currentLetterIndex++;
        }
    }
    
    for (int i = 0; i < word.size() / numOfColumns; i++)
    {
        for (int j = 0; j < numOfColumns; j++)
        {
            decrypted += columns[j][i];
        }
    }

    return decrypted;

}

int main()
{
    Mode mode;
    std::string word;
    


    int selected, columns;

    int * order;

    std::cout << "Ilosc kolumn = ";
    std::cin >> columns;

    order = new int[columns];

    for (int i = 0; i < columns; i++)
    {
        int colIndex;
        
        std::cout << "Kolumna nr." << i << " = ";
        std::cin >> colIndex;

        order[i] = colIndex;
    }

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

    std::cout << kolumnyDecryption("", columns, order);
}