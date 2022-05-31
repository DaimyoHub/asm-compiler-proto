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

namespace fnt {

namespace detail {

/**
 * Tries to open the file at the given path. If it fails, throw an exception.
 *
 * @param filename The path to the file to open
 * @return std::ifstream The input stream to the opened file
 */
std::ifstream try_open_source_file(std::string filename);

/**
 * Converts a source file into a text containing the whole program.
 *
 * @param file_handler The source file
 * @return std::string The whole program as a text
 */
std::string convert_source_to_text(std::ifstream &file_handler);

} // namespace detail

class TextSource {
private:
  std::string _text_source;

public:
  /**
   * Constructs a text source from a source file. The content of the file is put
   * in a buffer handled by TextSource.
   *
   * @param filename The path to the source file
   * @return TextSource The handler of the source text
   */
  static TextSource from_file(std::string filename);

public:
  /**
   * Gets a reference to the raw source text.
   *
   * @return std::string const&
   */
  std::string const &get_text() const;
};

} // namespace fnt

} // namespace cmp