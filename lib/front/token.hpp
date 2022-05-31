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
#include <vector>

namespace cmp {

namespace fnt {

namespace detail {

void left_trim(std::string &word);

bool is_white_character(char c);

std::vector<std::string>
extract_words_from_text_source(TextSource const &text_source);

} // namespace detail

class TokenTable {
private:
  std::vector<std::string> _token_table;

public:
  static TokenTable from_text_source(TextSource const &text_source);

public:
  std::string *begin();

  std::string *end();

  std::vector<std::string> const &get_table() const;
};

} // namespace fnt

} // namespace cmp