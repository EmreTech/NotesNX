#pragma once

#include <string>
#include <vector>

namespace FileManagement
{

void writeNoteToFile(const std::string contents, const std::string filename);
std::string readNoteFromFile(const std::string filename);

std::string strVecToStr(const std::vector<std::string>);
std::vector<std::string> strToStrVec(const std::string);

std::string createFilename(const std::string title)
{
    return title + ".note";
}

std::vector<std::string> getAllFilesInDir(const std::string dirpath);

} // namespace FileManagement