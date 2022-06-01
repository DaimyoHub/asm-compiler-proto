#include <front/token.hpp>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace cmp {

namespace fnt {

namespace detail {

bool is_white_character(char c) {
  if (0 <= static_cast<unsigned int>(c) && static_cast<unsigned int>(c) <= 32)
    return true;

  return false;
}

std::string left_trim(std::string const &word) {
  std::string const WHITESPACE = " \n\r\t\f\v";
  size_t start = word.find_first_not_of(WHITESPACE);

  if (start != std::string::npos)
    return word.substr(start);
  else
    return "";
}

TokenTable::token_type
extract_words_from_text_source(const TextSource &text_source) {
  auto res = TokenTable::token_type{};
  auto word = std::string{};

  for (auto &&c : text_source.get_text()) {
    if (is_white_character(c) and not word.empty()) {
      word = std::move(left_trim(word));
      res.emplace_back(word, tokenize_word(word));
      word.clear();
    } else if (not is_white_character(c))
      word.push_back(c);
  }

  return res;
}

bool is_instruction(std::string word) {
  if (word == "br" or word == "ld" or word == "str" or word == "out" or
      word == "add" or word == "sub" or word == "mul" or word == "div" or
      word == "inc" or word == "dec" or word == "be" or word == "bn" or
      word == "bg" or word == "bs" or word == "bge" or word == "bse")
    return true;

  return false;
}

TokenKind parse_instruction(std::string word) {
  if (word == "br")
    return TokenKind::BR_INST;
  else if (word == "ld")
    return TokenKind::LD_INST;
  else if (word == "str")
    return TokenKind::STR_INST;
  else if (word == "out")
    return TokenKind::OUT_INST;
  else if (word == "add")
    return TokenKind::ADD_INST;
  else if (word == "sub")
    return TokenKind::SUB_INST;
  else if (word == "mul")
    return TokenKind::MUL_INST;
  else if (word == "div")
    return TokenKind::DIV_INST;
  else if (word == "inc")
    return TokenKind::INC_INST;
  else if (word == "dec")
    return TokenKind::DEC_INST;
  else if (word == "be")
    return TokenKind::BE_INST;
  else if (word == "bn")
    return TokenKind::BN_INST;
  else if (word == "bg")
    return TokenKind::BG_INST;
  else if (word == "bs")
    return TokenKind::BS_INST;
  else if (word == "bge")
    return TokenKind::BGE_INST;
  else if (word == "bse")
    return TokenKind::BSE_INST;
  else
    return TokenKind::_UNKNOWN;
}

TokenKind tokenize_word(std::string word) {
  auto int_lit = std::regex("^[1-9][0-9]*|0$");
  auto reg = std::regex("^r[0-9]$");
  auto label = std::regex("^[a-zA-Z_$][a-zA-Z_$0-9]*$");

  if (is_instruction(word))
    return parse_instruction(word);
  if (std::regex_match(std::move(word), int_lit)) {
    return TokenKind::INT_LIT;
  } else if (std::regex_match(std::move(word), reg))
    return TokenKind::REGISTER;
  else if (std::regex_match(std::move(word), label))
    return TokenKind::LABEL;
  else
    return TokenKind::_UNKNOWN;
}

} // namespace detail

TokenTable TokenTable::from_text_source(const TextSource &text_source) {
  auto res = TokenTable{};

  res._token_table =
      std::move(detail::extract_words_from_text_source(text_source));

  return res;
}

TokenTable::token_type const &TokenTable::get_table() const {
  return _token_table;
}

} // namespace fnt

} // namespace cmp