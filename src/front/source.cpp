#include <front/source.hpp>

namespace cmp {

namespace fnt {

namespace detail {

std::ifstream try_open_source_file(std::string filename) {
  auto file_handler = std::ifstream(filename);

  if (not file_handler.is_open())
    throw std::runtime_error("Source file could not be open.");

  return file_handler;
}

std::string convert_source_to_text(std::ifstream &file_handler) {
  auto res = std::string{};
  auto line = std::string{};

  while (std::getline(file_handler, line))
    res.append(line + " ");

  return res;
}

} // namespace detail

TextSource TextSource::from_file(std::string filename) {
  auto res = TextSource{};

  auto file_handler = detail::try_open_source_file(std::move(filename));
  res._text_source = std::move(detail::convert_source_to_text(file_handler));

  file_handler.close();

  return res;
}

std::string const &TextSource::get_text() const { return _text_source; }

} // namespace fnt

} // namespace cmp