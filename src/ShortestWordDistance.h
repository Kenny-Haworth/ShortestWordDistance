#include <string>
#include <vector>

#ifndef SHORTEST_WORD_DISTANCE_H
#define SHORTEST_WORD_DISTANCE_H

struct TestCase
{
    std::string name;
    std::vector<std::string> doc;
    std::string word1;
    std::string word2;
    int expected;
};

void runProblem1Tests();

void runProblem2Tests();

int minimumDistance(const std::vector<std::string>& doc,
                    const std::string& word1,
                    const std::string& word2);

#endif
