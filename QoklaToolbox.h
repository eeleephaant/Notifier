#pragma once

#include <string>
#include <fstream>
#include <vector>

class QoklaToolbox
{
private:
public:
    static std::string getFileContents(std::string pathToFile, char separator);
    static std::vector<std::string> getFileContents(std::string pathToFile);
};
