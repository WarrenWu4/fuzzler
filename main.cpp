#include <string>
#include <filesystem>
#include <iostream>
#include <utility>
#include <vector>
#include "algos/levenshteinDistance.h"

std::vector<std::string> pathSplit(std::string path) {
    std::vector<std::string> words;
    std::string word = "";
    for (char c : path) {
        if (c == '/' || c == '\\') {
            if (word != "") {
                words.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }
    if (word != "") {
        words.push_back(word);
    }
    return words;
}

int maxPathScore(std::string query, std::string path) {
    LevenshteinDistance ld;
    // break path down into words
    std::vector<std::string> pathWords = pathSplit(path);
    int maxScore = 0;
    // get score of each word
    for (int i = 0; i < pathWords.size(); i++) {
        maxScore = std::max(maxScore, ld.score(query, pathWords[i]));
    }
    // return max score
    return maxScore;
}

void recurseFile(std::string query, const std::filesystem::path& directory, int maxDepth, std::vector<std::pair<std::string, int>> &results,  int currentDepth=0) {
    if (currentDepth > maxDepth) {
        return;
    }
    // score similarity of file name based on input
    // use different algorithm based on input flag
    // print out top 20 results
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            std::string path = entry.path().string();
            results.push_back(
                std::make_pair(path, maxPathScore(query, path))
            );
        } else if (entry.is_directory()) {
            std::cout << entry.path() << std::endl;
            recurseFile(query, entry.path(), maxDepth, results, currentDepth + 1);
        }
    }
}

int main(int argc, char* argv[]) {
    // input arguments
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <query>" << std::endl;
        return 1;
    }
    std::string query = argv[1];

    // set max depth level
    const int MAX_DEPTH = 50;
    // for each directory level
    std::string dir = ".";
    // top 20 results
    std::vector<std::pair<std::string, int>> results;
    try {
        recurseFile(query, dir, MAX_DEPTH, results);
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }

    for (const auto& result : results) {
        std::cout << result.first << " " << result.second << std::endl;
    }
    return 0;
}
