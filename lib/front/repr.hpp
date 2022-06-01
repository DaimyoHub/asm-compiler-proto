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

/**
 * Serves as a kind of AST, but it is not a tree. It's just an abstract
 * representation of then program
 */
class ProgramRepr {
public:
  using instr_sequence_type = std::vector<std::unique_ptr<Instr>>;

private:
  instr_sequence_type _instr_sequence;

public:
  /**
   * Constructs a program representation from a token table.
   *
   * @param table The initial token table
   * @return ProgramRepr
   */
  static ProgramRepr from_token_table(TokenTable const &table);

public:
  /**
   * Gets the representation as a vector containing pointers to instructions or
   * labels
   *
   * @return instr_sequence_type const&
   */
  instr_sequence_type const &get_instructions() const;
};

namespace detail {

/**
 * Gathers tokens to make instructions for the abstract representation.
 *
 * @param table The token table
 * @return ProgramRepr::instr_sequence_type
 */
ProgramRepr::instr_sequence_type gather_tokens(TokenTable const &table);

} // namespace detail

} // namespace fnt

} // namespace cmp