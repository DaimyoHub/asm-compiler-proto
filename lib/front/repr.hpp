/**
 * @file repr.hpp
 * @author Alexis Pocuqte
 *
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <front/instr.hpp>
#include <front/token.hpp>
#include <memory>
#include <vector>

namespace cmp {

namespace fnt {

class ProgramRepr {
public:
  using instr_sequence_type = std::vector<std::unique_ptr<Instr>>;

private:
  instr_sequence_type _instr_sequence;

public:
  static ProgramRepr from_token_table(TokenTable const &table);
};

namespace detail {

ProgramRepr::instr_sequence_type gather_tokens(TokenTable const &table);

}

} // namespace fnt

} // namespace cmp