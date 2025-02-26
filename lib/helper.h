#pragma once

#include <string>
#include <vector>
#include <utility>
#include <filesystem>

enum FileType {
    file,
    dir,
};

class Helper {
public:
    // gets the file or directory name at end of the path
    std::string endFile(std::string path);
    // gets all the file names of the given path
    std::vector<std::pair<std::string, FileType>> filesInDir(std::string path);
};
