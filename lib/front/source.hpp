/**
 * @file source.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-05-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <exception>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <string>
#include <string_view>

namespace cmp {

namespace detail {

std::ifstream try_open_source_file(std::string filename) {
  auto file_handler = std::ifstream(filename);

  if (not file_handler.is_open())
    throw std::runtime_error("Source file could not be open.");

  return file_handler;
}

std::string source_to_text(std::ifstream &file_handler) {
  auto res = std::string{};
  auto line = std::string{};

  while (std::getline(file_handler, line))
    res.append(line);

  return res;
}

} // namespace detail

class TextSource {
private:
  std::string _text_source;

public:
  static TextSource from_file(std::string filename) {
    auto res = TextSource{};

    auto file_handler = detail::try_open_source_file(std::move(filename));
    res._text_source = std::move(detail::source_to_text(file_handler));

    file_handler.close();

    return res;
  }

public:
  std::string const &get_text() const { return _text_source; }
};

} // namespace cmp