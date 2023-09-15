#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

const int BUFFER_SIZE = 1024;

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
        std::cout   << "Exception caught: "
                    << e.what() 
                    << std::endl;
        return false;
    }
}

void outputFile(std::ifstream& file)
{
    char buffer[BUFFER_SIZE];
    while (file.read(buffer, BUFFER_SIZE)) {
        std::cout.write(buffer, BUFFER_SIZE);
    }
    int bytesRead = file.gcount();
    if (bytesRead > 0) {
        std::cout.write(buffer, bytesRead);
    }
}

int main()
{
    std::string filePath;
    std::ifstream file;

    std::cout   << "Enter the path to the file: "
                << std::endl;
    std::cin    >> filePath;
    
    if (filePathAndOpen(filePath, file)) {
        std::cout   << "The file has been opened successfully"
                    << std::endl;
        outputFile(file); 
        file.close();     
    } else {
        std::cout   << "Error opening file";
        return -1;
    }
    
    return 0;
}
