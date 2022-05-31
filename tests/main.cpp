#include <front/source.hpp>
#include <iostream>

int main() {
  auto source =
      cmp::TextSource::from_file("/home/daimyo/dev/cmp/res/program.asm");
  std::cout << '"' << source.get_text() << '"' << std::endl;
}