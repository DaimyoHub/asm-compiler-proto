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

/**
 * All kinds of tokens are there
 */
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

/**
 * It represents the set of "words" in the program. Each word has a special
 * meaning, and this class associates each of them with there respective
 * meaning.
 */
class TokenTable {
public:
  using token_type = std::vector<std::pair<std::string, TokenKind>>;

private:
  token_type _token_table;

public:
  /**
   * Constructs a token table from a raw text program.
   *
   * @param text_source The raw text program
   * @return TokenTable
   */
  static TokenTable from_text_source(TextSource const &text_source);

public:
  /**
   * Gets tokens as a vector of the couple (word, meaning).
   *
   * @return token_type const&
   */
  token_type const &get_table() const;
};

namespace detail {

/**
 * Removes white spaces at the left side of a string.
 *
 * @param word The given string to trim
 * @return std::string The trimmed string
 */
std::string left_trim(std::string const &word);

/**
 * Checks if the given character is a white character (return, space, tab...)
 *
 * @param c The given character
 * @return true if it is a white character, else, false
 */
bool is_white_character(char c);

/**
 * Decomposes a given text program to extract words from it.
 *
 * @param text_source The text program
 * @return TokenTable::token_type A vector of couples (word, meaning)
 */
TokenTable::token_type
extract_words_from_text_source(TextSource const &text_source);

/**
 * Associates a correct meaning with the given word
 *
 * @param word The word
 * @return TokenKind The meaning of the word
 */
TokenKind tokenize_word(std::string word);

/**
 * Checks if the given word is an instruction (add, ld, br...)
 *
 * @param word The given word
 * @return true if it is an instruction, else, false
 */
bool is_instruction(std::string word);

/**
 * Parses an instruction word to associate it with its instruction meaning
 *
 * @param word The given word
 * @return TokenKind The associated meaning
 */
TokenKind parse_instruction(std::string word);

} // namespace detail

} // namespace fnt

} // namespace cmp