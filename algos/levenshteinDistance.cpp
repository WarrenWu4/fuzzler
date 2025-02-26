#include "levenshteinDistance.h"

int LevenshteinDistance::score(std::string s1, std::string s2) {
    const int len1 = s1.length();
    const int len2 = s2.length();
    int prevRow[len2 + 1];
    int currRow[len2 + 1];
    for (int i = 0; i < len2 + 1; i++) {
        prevRow[i] = i;
        currRow[i] = 0;
    }
    for (int i = 1; i < len1 + 1; i++) {
        currRow[0] = i;
        for (int j = 1; j < len2 + 1; j++) {
            if (s1[i-1] == s2[j-1]) {
                currRow[j] = prevRow[j-1];
            } else {
                currRow[j] = 1 + std::min({currRow[j-1], prevRow[j], prevRow[j-1]});
            }
        }
        for (int j = 0; j < len2; j++) {
            prevRow[j] = currRow[j];
        }
    }
    return currRow[len2];
}

