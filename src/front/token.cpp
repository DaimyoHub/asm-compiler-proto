#include <front/token.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace cmp {

namespace fnt {

namespace detail {

bool is_white_character(char c) {
  if (0 <= static_cast<unsigned int>(c) && static_cast<unsigned int>(c) <= 32)
    return true;

  return false;
}

void left_trim(std::string &word) {
  std::string const WHITESPACE = " \n\r\t\f\v";
  size_t start = word.find_first_not_of(WHITESPACE);

  if (start != std::string::npos)
    word = word.substr(start);
}

std::vector<std::string>
extract_words_from_text_source(const TextSource &text_source) {
  auto res = std::vector<std::string>{};
  auto word = std::string{};

  for (auto &&c : text_source.get_text()) {
    if (is_white_character(c) and not word.empty()) {
      res.emplace_back(word);
      word = "";
    } else {
      word.push_back(c);
    }
  }

  for (auto &word : res)
    left_trim(word);

  return res;
}

} // namespace detail

TokenTable TokenTable::from_text_source(const TextSource &text_source) {
  auto res = TokenTable{};

  res._token_table =
      std::move(detail::extract_words_from_text_source(text_source));

  return res;
}

std::vector<std::string> const &TokenTable::get_table() const {
  return _token_table;
}

} // namespace fnt

} // namespace cmp