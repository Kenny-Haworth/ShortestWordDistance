# Shortest Word Distance Solutions in C++

An optimal solution to the shortest word distance problem as well as a follow-up pre-processing problem. The problems and solutions implemented are stated below:

## Problem 1
```cpp
    /**
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
```

## Solution 1
```cpp
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
```

## Problem 2
```cpp
    /**
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
```

## Solution 2
```cpp
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
```
