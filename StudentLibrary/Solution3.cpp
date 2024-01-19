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

void Solution3::SortWords() {
    if (words.empty())
    {
        throw std::runtime_error("Vector is null or empty");
    }
    std::transform(words.begin(), words.end(), words.begin(), ToLowercase);
    std::sort(words.begin(), words.end());

    std::cout << "Sorted words:" << std::endl;
    for (const std::string& word : words)
    {
        std::cout << word << std::endl;
    }
}

std::vector<std::string> Solution3::GetSortedWords() const
{
	return words;
}

#endif
