#include <FileManagement.hpp>

#include <Constants.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
#include <exception>

namespace
{
    std::string getFilepath(const std::string filename)
    {
        return NOTES_NX_CONFIG_DIR + std::string("/") + filename;
    }
}

namespace FileManagement
{

void writeNoteToFile(const std::string contents, const std::string filename)
{
    std::ofstream file;
    file.open(getFilepath(filename));

    if (file.is_open() && file.good())
    {
        file << contents;
        file.close();
    }
    else
        throw std::logic_error("Failed to open file \"" + getFilepath(filename) + "\"");
}

std::string readNoteFromFile(const std::string filename)
{
    std::ifstream file;
    file.open(getFilepath(filename));

    if (file.is_open() && file.good())
    {
        std::string contents;
        std::string line;

        while (std::getline(file, contents))
            contents += line + '\n';

        file.close();
        return contents;
    }
    else
        throw std::logic_error("Failed to open file \"" + getFilepath(filename) + "\"");

    return "";    
}

std::string strVecToStr(const std::vector<std::string> vec)
{
    std::string str;

    for (auto e : vec)
        str += e + '\n';
    
    return str;
}

std::vector<std::string> strToStrVec(const std::string str)
{
    std::vector<std::string> vec;
    std::string buf;

    for (auto c : str)
    {
        if (c == '\n')
        {
            vec.push_back(buf);
            buf = "";
        }
        else
            buf += c;
    }

    return vec;
}

} // namespace FileManagement
