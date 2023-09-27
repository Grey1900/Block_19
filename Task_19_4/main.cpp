#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>


bool filePathAndOpen (std::ifstream& file, std::string& filePath)
{
    try
    {
        file.open(filePath, std::ios::binary);
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


std::vector<unsigned char> signature (std::ifstream& file)
{
    std::vector<unsigned char> signature(8);
    
}

int main()
{
    std::ifstream file;
    std::string pathFile;

    std::cout   << "Enter the path of file: ";
    std::cin    >> pathFile;

    if(filePathAndOpen(file, pathFile)){
        std::vector<unsigned char> signature{0x89, 'P', 'N', 'G'};
    }

}
