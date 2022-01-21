#pragma once

#include <string>
#include <vector>

namespace FileManagement
{

void writeNoteToFile(const std::string contents, const std::string filename);
std::string readNoteFromFile(const std::string filename);

std::string strVecToStr(const std::vector<std::string>);
std::vector<std::string> strToStrVec(const std::string);

std::string createFilename(const std::string title, int noteNum)
{
    return title + "_Note" + std::to_string(noteNum);
}

} // namespace FileManagement