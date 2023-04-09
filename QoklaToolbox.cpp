#include "QoklaToolbox.h"

std::string QoklaToolbox::getFileContents(std::string pathToFile, char separator)
{
    std::ifstream file(pathToFile);
    if (!file.is_open())
    {
        perror((pathToFile + " NOT OPEN!").c_str());
        exit(1);
    }
    std::string temp, output; 
    while (getline(file, temp)) 
    {
        output += temp;
        if (separator != NULL) { output += separator; }
    }
    return output;
}

std::vector<std::string> QoklaToolbox::getFileContents(std::string pathToFile)
{
    std::ifstream file(pathToFile);
    if (!file.is_open())
    {
        perror((pathToFile + " NOT OPEN!").c_str());
        exit(1);
    }  
    std::vector<std::string> output;
    std::string temp;
    while (getline(file, temp)) 
    {
        output.push_back(temp);
    }
    return output;
}