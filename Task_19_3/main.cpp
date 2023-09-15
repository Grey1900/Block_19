#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>


bool filePathAndOpen (std::ifstream& file, std::string& filePath)
{
    try{
        file.open(filePath);
        if(!file.is_open())
            throw std::runtime_error("Error opening file");
        else
            return true;
    } catch (const std::exception& e) {
        std::cout   << "Exception catch: "
                    << e.what()
                    << std::endl;
        return false;
    }
}


std::vector<std::string> checkStatementName (std::ifstream& file)
{
    std::string line;
    std::string name;
    
    std::vector<std::string> statement;
    while(std::getline(file, line))
    {
        std::stringstream ss (line);
        ss >> name;
        statement.push_back(name);
    }
    return statement;
}


std::vector<int> checkStatementNumber (std::ifstream& file)
{
    std::string line;
    int number;
    
    std::vector<int> statement;
    while(std::getline(file, line))
    {
        std::stringstream ss (line);
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
        ss >> number;
        statement.push_back(number);
    }
    return statement;
}


int checkMaxPayment (std::vector<int>& statement)
{
    int _max = statement[0];
    int maxIndex = 0;

    for(int i = 1; i < statement.size(); i++){
        if(_max < statement[i])
            maxIndex = i;
    }
    return maxIndex;
}


int totalPayment (std::vector<int>& statement)
{
    int sum = 0;
    for(int i=0; i < statement.size(); i++){
        sum += statement[i];
    }
    return sum;
}


int main()
{
    std::ifstream file;
    std::string filePath;

    std::cout   << "Enter the path of file: ";
    std::cin    >> filePath;

    if(filePathAndOpen(file, filePath)){
        std::cout   << "The file has been opened successfully"
                    << std::endl;
        checkMaxPayment(checkStatementNumber(file));

    } else {
        std::cout   << "Error opening file";
        return -1;
    }
}
