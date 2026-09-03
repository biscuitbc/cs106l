#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  // Step 1
  auto spaces = find_all(source.begin(), source.end(), ::isspace);
  // Step 2
  Corpus Tok;

  std::transform(spaces.begin(), spaces.end() - 1, spaces.begin() + 1, std::inserter(Tok, Tok.end()), 
            [&source](auto it1, auto it2){
              return Token(source, it1, it2);
            });
  // Step 3
  std::erase_if(Tok, [](const Token& token) {
    return token.content.empty();
  });

  

  return Tok;
}

// Corpus = std::set<Token>;

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view = source | rv::filter([&dictionary](const Token& token) {
    if(dictionary.find(token.content) != dictionary.end()) return 0;
    else return 1;
  }) | rv::transform( [&dictionary](const Token& token){
    auto temp_view = dictionary | rv::filter([&token](auto& word){
      if(levenshtein(word, token.content) == 1) return 1;
      else return 0;
    });
    std::set<std::string> sugg(temp_view.begin(), temp_view.end());
    return Misspelling(token, sugg);
  } ) | rv::filter([](const auto& word){
    if(word.suggestions.empty()) return 0;
    else return 1;
  }) ;


  return std::set<Misspelling>(view.begin(), view.end());


};

/* Helper methods */

#include "utils.cpp"