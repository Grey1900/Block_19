#include <iostream>
#include <string>
#include <fstream>

std::ifstream words;
std::ifstream key_words;

bool openTxt(void)
{
    words.open("words.txt");
    key_words.open("key_words.txt");
    
    if(!words.is_open() || !key_words.is_open())
        return false;
    
    return true;
}

void checkKeyWords(std::ifstream words, std::ifstream key_words)
{   

}

void outputResult(std::ifstream key_words)
{
    
}

int main()
{
    std::cout   << "Opening files Words.txt and Key_Words.txt"
                << std::endl;
    std::cout   << (openTxt() ? 
                    "The files have been opened successfully":
                    "Error opening files")
                << std::endl;
    
}
