/**
 * @file token.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-05-31
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <front/source.hpp>
#include <string>
#include <utility>
#include <vector>

namespace cmp {

namespace fnt {

enum class TokenKind {
  INT_LIT = 1,
  STR_LIT = 2,
  BR_INST = 3,
  LD_INST = 4,
  STR_INST = 5,
  OUT_INST = 6,
  ADD_INST = 7,
  SUB_INST = 8,
  MUL_INST = 9,
  DIV_INST = 10,
  INC_INST = 11,
  DEC_INST = 12,
  BE_INST = 13,
  BN_INST = 14,
  BG_INST = 15,
  BS_INST = 16,
  BGE_INST = 17,
  BSE_INST = 18,
  LABEL = 19,
  REGISTER = 20,
  _UNKNOWN,
};

class TokenTable {
public:
  using token_type = std::vector<std::pair<std::string, TokenKind>>;

private:
  token_type _token_table;

public:
  static TokenTable from_text_source(TextSource const &text_source);

public:
  std::string *begin();

  std::string *end();

  token_type const &get_table() const;
};

namespace detail {

std::string left_trim(std::string const &word);

bool is_white_character(char c);

TokenTable::token_type
extract_words_from_text_source(TextSource const &text_source);

TokenKind tokenize_word(std::string word);

bool is_instruction(std::string word);

TokenKind parse_instruction(std::string word);

} // namespace detail

} // namespace fnt

} // namespace cmp