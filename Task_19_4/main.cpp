#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

const std::vector<unsigned char> signature {0x89, 'P', 'N', 'G'};

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


bool checkFileExtension (std::ifstream& file, std::string& filePath)
{
    size_t dotPos = filePath.find_last_of(".");

    if (dotPos == std::string::npos) {
        std::cerr   << "Error. Can't possible to check the file's extension.";
        return false; 
    } else {
        std::string fileExtension = filePath.substr(dotPos+1);

        if(fileExtension == "png" || fileExtension == "PNG"){
            return true;
        }
    }
}

bool checkSignature (std::ifstream& file)
{
    std::vector<unsigned char> fileSignature(4);

    if(file.read(reinterpret_cast<char*>(&fileSignature[0]), 4)){
        if(signature == fileSignature)
            return true;
        else
            return false;
    } 
}


int main()
{
    std::ifstream file;
    std::string pathFile;

    std::cout   << "Enter the path of file: ";
    std::cin    >> pathFile;

    if(filePathAndOpen(file, pathFile)){
        if(checkSignature(file) == true && checkFileExtension(file, pathFile) == true)
            std::cout   << "File is a PNG-image.";
        else
            std::cout   << "File is not a PNG-image.";
    }

    file.close();
}
