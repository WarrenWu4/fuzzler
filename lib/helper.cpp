#include "helper.h"
#include <algorithm>

std::string Helper::endFile(std::string path) {
    // starting from end of the path
    // add to string var until it reaches a \\ or / 
    std::string name = "";
    for (int i = path.size()-1; i >= 0; i--) {
        if (path.at(i) == '/') {
            break;
        }
        name += path.at(i);
    }
    std::reverse(name.begin(), name.end()); 
    return name;
}

std::vector<std::pair<std::string, FileType>> Helper::filesInDir(std::string path) {
    std::vector<std::pair<std::string, FileType>> files;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string path = entry.path().string();
        if (entry.is_regular_file()) {
            files.push_back(std::pair(path, file));
        } else if (entry.is_directory()) {
            files.push_back(std::pair(path, dir));
        }
    }
    return files;
}

