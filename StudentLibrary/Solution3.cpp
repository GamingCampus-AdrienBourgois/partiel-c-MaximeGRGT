#include "Solution3.h"
#include <vector>
#include <algorithm>
#include <iostream>

// Don't fortget to enable the exercise in the SudentConfiguration.h file !
#include "StudentConfiguration.h"
#ifdef COMPILE_EXERCICE_3

void Solution3::SetWords(const std::vector<std::string>& _words)
{
	words = _words;
}

std::string Solution3::ToLowercase(const std::string& str)
{
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

bool Solution3::CompareWordPairs(const WordPair& a, const WordPair& b)
{
    return a.lowercase < b.lowercase;
}

void Solution3::SortWords() {
    if (words.empty())
    {
        throw std::runtime_error("Vector is null or empty");
    }

    std::vector<WordPair> wordPairs;
    for (const std::string& word : words)
    {
        wordPairs.push_back({ word, ToLowercase(word) });
    }

    std::sort(wordPairs.begin(), wordPairs.end(), CompareWordPairs);

    words.clear();
    for (const auto& entry : wordPairs)
    {
        words.push_back(entry.original);
    }
}

std::vector<std::string> Solution3::GetSortedWords() const
{
	return words;
}

#endif
