#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

bool filePathAndOpen(const std::string& filePath, std::ifstream& file)
{
    try {
        file.open(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening file");
        } else {
            return true;
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
        return false;
    }
}

void outputFile(std::ifstream& file)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}

int main()
{
    std::string filePath;
    std::ifstream file;

    std::cout << "Enter the path to the file: " << std::endl;
    std::cin >> filePath;
    
    if (filePathAndOpen(filePath, file)) {
        std::cout << "The file has been opened successfully" << std::endl;
        outputFile(file); 
        file.close();     
    } else {
        std::cout << "Error opening file";
        return -1;
    }
    
    return 0;
}
