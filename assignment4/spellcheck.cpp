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

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  
  


};

/* Helper methods */

#include "utils.cpp"