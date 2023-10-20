#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <random>
#include <set>


bool filePathAndOpen (std::ifstream& file, std::string name)
{
    try
    {
        file.open(name);
        if(!file.is_open())
            throw std::runtime_error("Error opening file");
        else
            return true;
    }
    catch(const std::exception& e)
    {
        std::cerr   << "Exception catch: "
                    << e.what() 
                    << std::endl;
        return false;
    }
}


int randomOffset (std::set<int>& usedOffsets, int& offset)
{
    std::random_device num;
    std::mt19937 gen(num());
    std::uniform_int_distribution<int> dis(1, 13);

    offset = dis(gen);
    
    usedOffsets.insert(offset);

    return offset;
}

int main()
{
    std::ifstream file;
    std::set<int> usedOffsets;
    int offset = 0;

    std::string question = "";
    std::string answer = "";

    while(usedOffsets.size() < 13)
    {
        do{
            std::string answer;
            std::string begin;
            std::cout   << "Enter 'Start' for begin: ";
            std::cin    >> begin;
            if(begin == "Start" || begin == "start"){
                std::string nameQuestion = "Question " + 
                std::to_string(randomOffset(usedOffsets, offset)) + ".txt";

                std::cout   << "Your question is " 
                            << offset;
                std::cout   <<std::endl;
                filePathAndOpen(file, nameQuestion);
                std::getline(file, question);
                std::cout   << question;
                file.close();
                
                std::cout   << "Enter your answer: ";
                std::getline(std::cin, answer);

                std::string nameAnswer = "Answer " +
                std::to_string(offset) + ".txt";
                filePathAndOpen(file, nameAnswer);
                std::string line;
                while(std::getline(file, line))
                {
                    if(line == answer){
                        std::cout   << "Answer is correct";
                        std::cout   << std::endl;
                        file.close();
                    } else {
                        std::cout   << "Answer is wrong";
                        std::cout   << std::endl;
                        file.close();
                    }
                }
            } else {
                std::cout   << "Invalid command. Try again";
            }
        } while(usedOffsets.count(offset) > 0);
    }     
}
