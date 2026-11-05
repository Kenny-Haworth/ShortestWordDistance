#include "Problem2.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

Problem2::Problem2(const std::vector<std::string>& doc)
{
    for (int i = 0; i < doc.size(); i++)
    {
        wordIndices[doc[i]].push_back(i);
    }
}

/**
 * Solution 2:
 *
 * Maintain an std::unordered_map<std::string, std::vector<int>> where
 * you store a word and all the locations that the word occurs in the
 * document. When the user queries 2 words, I can immediately lookup all
 * places in the document those two words exist, so no need to parse the
 * array again.
 *
 * For any given lookup, maintain two pointers - one in word1's vector
 * and one in word2's vector. Advance whichever number is smaller to
 * keep them somewhat equal, calculating the distance along the way.
 *
 * Optimization:
 *      If you've reached the end of one vector, you can abandon the comparisons
 *      as subsequent comparisons are guaranteed to be greater than the minimum.
 *
 * Minor unimplemented optimization:
 *      If you have a distance of 1, abandon the comparisons as 1 is the
 *      smallest possible distance.
 *
 * Time Complexity: O(n) for preprocessing, O(m + n) for each query where m is
 *                  the number of occurrences of word1 and n is the number of
 *                  occurrences of word2
 * Space Complexity: O(n)
 */
int Problem2::minimumDistance(const std::string& word1, const std::string& word2)
{
    const std::vector<int>& word1Indices = wordIndices[word1];
    const std::vector<int>& word2Indices = wordIndices[word2];

    int word1Ptr = 0;
    int word2Ptr = 0;
    int minDistance = std::numeric_limits<int>::max();

    while (word1Ptr < word1Indices.size() && word2Ptr < word2Indices.size())
    {
        minDistance = std::min(minDistance, std::abs(word1Indices[word1Ptr] - word2Indices[word2Ptr]));

        if (word1Indices[word1Ptr] < word2Indices[word2Ptr])
        {
            word1Ptr++;
        }
        else
        {
            word2Ptr++;
        }
    }

    return minDistance;
}
