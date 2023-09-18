#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <stdexcept>


bool filePathAndOpen (std::ifstream& file, std::string& filePath)
{
    try {
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


std::vector<std::pair<std::string, int>> checkStatement (std::ifstream& file)
{
    std::string line;
    std::string name;
    int salary;
    
    std::vector<std::pair<std::string, int>> employeeData;

    while(std::getline(file, line))
    {
        std::istringstream ss (line);
        ss >> name;
        ss >> salary;
        employeeData.emplace_back(name, salary);
    }

    return employeeData;
}


int checkMaxSalary (std::vector<std::pair<std::string, int>>& employeeData)
{
    int _max = employeeData[0].second;
    int maxIndex = 0;

    for(int i = 1; i < employeeData.size(); i++){
        if(_max < employeeData[i].second)
            maxIndex = i;
    }
    return maxIndex;
}


int totalSalary (std::vector<std::pair<std::string, int>>& employeeData)
{
    int sum = 0;

    for(int i=0; i < employeeData.size(); i++) {
        sum += employeeData[i].second;
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
        
        std::vector<std::pair<std::string, int>> employeeData = checkStatement(file);

        std::cout   << "Total Salary: " 
                    << totalSalary(employeeData)
                    << std::endl;

        int maxIndex = checkMaxSalary(employeeData);

        std::cout   << "The highest salary at: "
                    << employeeData[maxIndex].first
                    << " = "
                    << employeeData[maxIndex].second
                    << std::endl;

    } else {
        std::cout   << "Error opening file";
        return -1;
    }
}
