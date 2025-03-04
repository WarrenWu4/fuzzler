#pragma once

#include <string>
#include <algorithm>

class LevenshteinDistance {
public:
    int score(std::string s1, std::string s2);
    float normalize(int score, int s1Len, int s2Len);
};
