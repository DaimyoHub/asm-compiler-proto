#include <front/source.hpp>
#include <front/token.hpp>
#include <iostream>

int main() {
  using namespace cmp::fnt;

  auto source = TextSource::from_file("/home/daimyo/dev/cmp/res/program.asm");
  auto tokens = TokenTable::from_text_source(source);

  for (auto const &tok : tokens.get_table())
    std::cout << '"' << tok << '"' << '\n';
}