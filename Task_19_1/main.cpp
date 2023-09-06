#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


bool openTxt(std::ifstream* words, std::ifstream* key_words)
{
    (*words).open("words.txt");
    (*key_words).open("key_words.txt");
    
    if(!(*words).is_open() || !(*key_words).is_open())
        return false;
    
    return true;
}

void keyWordsArray(std::ifstream* key_words, std::vector<std::string>& keyWordsArray)
{  
    std::string line;

    while(std::getline(*key_words, line))
    {
        keyWordsArray.push_back(line);
    }
    (*key_words).close();
}


void checkKeyWords  (std::ifstream* words, 
                    std::vector<std::string>& keyWordsArray)
{   
    std::string line = " ";
    int count = 0;
     
    for(int i = 0; i < keyWordsArray.size(); i++)
    {
        while(std::getline((*words), line))
        {
            std::istringstream x(line);
            std::string word;
            while(x >> word)
            {
                if(word == keyWordsArray[i]){
                    count++;
                }
            }
        }
        std::string result = keyWordsArray[i] + " = " + (std::to_string(count));
        keyWordsArray.at(i) = result;
        count = 0;
    }
}

void outputResultToTxt(std::vector<std::string>& keyWords)
{
    std::ofstream outputResult("key_words.txt");
    if(outputResult.is_open()){
        for(auto key : keyWords)
        {
            outputResult << key << std::endl;
        }
        outputResult.close();
        std::cout << "Results written to key_words.txt" << std::endl;
        system("key_words.txt");
    } else {
        std::cout << "Error opening file";
    }
}

int main()
{
    std::ifstream words;
    std::ifstream key_words;

    std::cout   << "Opening files Words.txt and Key_Words.txt: ";
                
    std::cout   << (openTxt(&words, &key_words) ? 
                    "The files have been opened successfully":
                    "Error opening files")
                << std::endl;
    
    std::vector<std::string> keyWords;

    keyWordsArray(&key_words, keyWords);
    checkKeyWords(&words, keyWords);

    outputResultToTxt(keyWords);
}
