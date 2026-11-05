#ifndef PROBLEM_2_H
#define PROBLEM_2_H

#include <string>
#include <unordered_map>
#include <vector>

class Problem2
{
    public:
        Problem2(const std::vector<std::string>& doc);
        int minimumDistance(const std::string& word1, const std::string& word2);

    private:
        std::unordered_map<std::string, std::vector<int>> wordIndices;
};

#endif
