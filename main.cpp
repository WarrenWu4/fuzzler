#include <queue>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include "algos/levenshteinDistance.h"
#include "lib/helper.h"

int main(int argc, char* argv[]) {
    // input arguments
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <query>" << " <starting_dir>" << "\n";
        return 1;
    }
    std::string query = argv[1];
    std::string start_dir = (argc > 3) ? argv[2] : ".";
    
    Helper h;
    LevenshteinDistance ld;
    // set max depth level
    const int MAX_DEPTH = 50;

    // check start_dir is valid
    if (!h.isDirExists(start_dir)) {
        std::cerr << "Error: " << start_dir << " is an invalid starting directory" << "\n";
    }

    std::queue<std::string> dirs;
    dirs.push(start_dir);
    std::vector<std::pair<std::string, int>> results;

    for(int i = 0; i < MAX_DEPTH && !dirs.empty(); i++) {
        std::string dirName = dirs.front();
        std::vector<std::pair<std::string, FileType>> res = h.filesInDir(dirName);
        for (std::pair<std::string, FileType> r : res) {
            int tempScore  = ld.score(h.endFile(r.first), query);
            results.push_back(std::pair(r.first, tempScore));
            if (r.second == dir) {
                dirs.push(r.first);
            }
        }
        dirs.pop();
    }

    // sort and print results
    std::sort(results.begin(), results.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
              return a.second < b.second;
              });
    for (const auto& result : results) {
        std::cout << result.first << " " << result.second << std::endl;
    }

    return 0;
}
