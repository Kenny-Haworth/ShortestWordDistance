#include "ShortestWordDistance.h"
#include "Problem2.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>

int main()
{
    /**
     * Problem 1:
     *
     * You are given an array of strings wordsDict and two strings word1 and
     * word2 that both exist in the array. Your task is to find the shortest
     * distance between these two words in the array.
     *
     * The distance between two words is calculated as the absolute difference
     * between their indices in the array. For example, if word1 appears at
     * index i and word2 appears at index j, the distance between them is |i -
     * j|.
     *
     * Since the same word can appear multiple times in the array, there might
     * be multiple pairs of positions for word1 and word2. You need to find the
     * minimum distance among all possible pairs.
     *
     * Example:
     *
     *     If wordsDict = ["practice", "makes", "perfect", "coding", "makes"],
     *            word1 = "coding",
     *            word2 = "practice"
     *     "coding" is at index 3 and "practice" is at index 0
     *     The distance is |3 - 0| = 3
     */
    runProblem1Tests();

    /**
     * Problem 2:
     *
     * Similar to problem 1, but now you are given a very large document that
     * you can preprocess. After preprocessing, you will be asked to find the
     * shortest distance between word1 and word2. During the preprocessing step,
     * you do not know which words will be queried, so you need to design a data
     * structure that allows for efficient queries of the shortest distance
     * between any two words in the document.
     *
     * Speed is paramount, so you should optimize for the query time, not
     * storage space.
     */
    runProblem2Tests();
}

void runProblem1Tests()
{
    const std::vector<TestCase> tests =
    {
        // Easy
        {
            "1. Adjacent words",
            {"a", "b"},
            "a", "b",
            1
        },
        {
            "2. Words separated by one word",
            {"a", "x", "b"},
            "a", "b",
            2
        },
        {
            "3. Words at opposite ends",
            {"a", "x", "y", "z", "b"},
            "a", "b",
            4
        },
        {
            "4. Closest pair at the beginning",
            {"a", "b", "x", "x", "x", "a"},
            "a", "b",
            1
        },

        // Medium
        {
            "5. Multiple occurrences of both words",
            {"a", "x", "b", "x", "x", "a", "b"},
            "a", "b",
            1
        },
        {
            "6. Closest pair at the end",
            {"a", "x", "x", "x", "b", "a", "b"},
            "a", "b",
            1
        },
        {
            "7. Alternating words",
            {"a", "b", "a", "b", "a", "b"},
            "a", "b",
            1
        },
        {
            "8. Closest pair in the middle",
            {"a", "x", "x", "b", "a", "b", "x"},
            "a", "b",
            1
        },

        // Harder edge cases
        {
            "9. Many irrelevant words",
            {"x", "y", "z", "a", "p", "q", "r",
             "b", "x", "y", "z", "p", "a", "b"},
            "a", "b",
            1
        },
        {
            "10. Reverse order is closest",
            {"b", "x", "x", "x", "a", "x", "b"},
            "a", "b",
            2
        },
        {
            "11. Closest pair near the final element",
            {"x", "x", "a", "x", "x", "x", "b"},
            "a", "b",
            4
        },
        {
            "12. Long document with competing distances",
            {"a", "x", "x", "x", "x", "b", "x", "x",
             "x", "a", "x", "b", "x", "x", "x", "x",
             "x", "x", "b", "a"},
            "a", "b",
            1
        }
    };

    int passed = 0;

    for (const auto& test : tests)
    {
        int actual = minimumDistance(test.doc, test.word1, test.word2);

        bool success = actual == test.expected;
        passed += success;

        std::cout << (success ? "[PASS] " : "[FAIL] ") << test.name
                  << " | expected: " << test.expected << ", actual: "
                  << actual << std::endl;
    }

    std::cout << "\nResults: "
              << passed << "/" << tests.size()
              << " passed\n";
}

void runProblem2Tests()
{
    std::ifstream file("res/king_james_bible.txt");

    if (!file.is_open())
    {
        std::cerr << "Failed to open king_james_bible.txt" << std::endl;
        exit(1);
    }

    std::vector<std::string> words;
    std::string word;

    while (file >> word)
    {
        words.push_back(word);
    }

    Problem2 problem2(words);
    std::cout << "Number of words between \"Jesus\" and \"olive\": " << problem2.minimumDistance("Jesus", "olive") << std::endl;
    std::cout << "Number of words between \"saint\" and \"Peter\": " << problem2.minimumDistance("saint", "Peter") << std::endl;
    std::cout << "Number of words between \"king\" and \"lord\": " << problem2.minimumDistance("king", "lord") << std::endl;
}

/**
 * Solution to Problem 1:
 *      Iterate through the array maintaining a pointer to the last index word1
 *      or word2 was seen.
 *
 *      Each time word1 or word2 is seen, calculate the distance between word1
 *      and word2 (provided both have been seen thus far) and update the global
 *      minimum with this value if it is smaller than the current global min.
 *
 * Runtime Complexity: O(n)
 * Space Complexity: O(1)
 */
int minimumDistance(const std::vector<std::string>& doc,
                    const std::string& word1,
                    const std::string& word2)
{
    int word1Index = -1,
        word2Index = -1,
        minDistance = std::numeric_limits<int>::max();

    for (int i = 0; i < doc.size(); i++)
    {
        const std::string& word = doc[i];

        if (word == word1)
        {
            word1Index = i;

            if (word2Index != -1)
            {
                minDistance = std::min(word1Index - word2Index, minDistance);
            }
        }
        else if (word == word2)
        {
            word2Index = i;

            if (word1Index != -1)
            {
                minDistance = std::min(word2Index - word1Index, minDistance);
            }
        }
    }

    return minDistance;
}
