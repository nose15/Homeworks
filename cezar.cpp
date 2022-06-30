#include <iostream>
#include <string>

const std::string alfabetJawny = "abcdefghijklmnopqrstuvwxyz";

enum Mode 
{
    encryption,
    decryption
};

std::string pozyskajAlfabetSzyfrowy(int klucz)
{
    std::string alfabetSzyfrowy;

    for (int i = 0; i < alfabetJawny.size(); i++)
        alfabetSzyfrowy += alfabetJawny[(i + klucz) % alfabetJawny.size()];

    return alfabetSzyfrowy;
}


std::string szyfrCezara(std::string haslo, int klucz, Mode tryb)
{
    std::string alfabetSzyfrowy = pozyskajAlfabetSzyfrowy(klucz);
    std::string output;
    int indexZnakuWAlfabecie;

    if (tryb == Mode(encryption)) 
    {
        for (int i = 0; i < haslo.size(); i++)
        {
            for (indexZnakuWAlfabecie = 0; indexZnakuWAlfabecie < alfabetJawny.size(); indexZnakuWAlfabecie++)
                if (haslo[i] == alfabetJawny[indexZnakuWAlfabecie]) break;

            output += alfabetSzyfrowy[indexZnakuWAlfabecie];
        }
    }
    else
    {
        for (int i = 0; i < haslo.size(); i++)
        {
            for (indexZnakuWAlfabecie = 0; indexZnakuWAlfabecie < alfabetSzyfrowy.size(); indexZnakuWAlfabecie++)
                if (haslo[i] == alfabetSzyfrowy[indexZnakuWAlfabecie]) break;

            output += alfabetJawny[indexZnakuWAlfabecie];
        }   
    }

    return output;
}


int main()
{
    Mode tryb;

    int klucz, opcja;
    std::string haslo;

    std::cout << "haslo = ";
    getline(std::cin, haslo);

    std::cout << "klucz = ";
    std::cin >> klucz;

    std::cout << "szyfrowanie(0) czy deszyfrowanie(1) = ";
    std::cin >> opcja;

    switch (opcja)
    {
        case 0:
            tryb = Mode(encryption);
            break;
        case 1:
            tryb = Mode(decryption);
            break;
        default:
            return -1;
    }

    std::cout << szyfrCezara(haslo, klucz, tryb);
}