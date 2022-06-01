/**
 * @file instr.hpp
 * @author Alexis Pocquet
 *
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "front/token.hpp"
#include <memory>

namespace cmp {

namespace fnt {

/**
 * Instruction base for the represxentation of a program
 */
struct Instr {
  virtual ~Instr() = default;
};

/**
 * Branch instruction
 */
struct BrInstr : public Instr {
  std::string label;
  BrInstr(std::string_view l);
};

/**
 * Load instruction
 */
struct LdInstr : public Instr {
  int reg_id;
  int value;
  LdInstr(std::string_view reg, std::string_view val);
};

/**
 * Store instruction
 */
struct StrInstr : public Instr {
  int reg_id;
  int memory_cell;
  StrInstr(std::string_view reg, std::string_view mem);
};

/**
 * Output instruction
 */
struct OutInstr : public Instr {
  int reg_id;
  OutInstr(std::string_view reg);
};

/**
 * Addition instruction
 */
struct AddInstr : public Instr {
  int dst_id;
  int lhs_id;
  int rhs_id;
  AddInstr(std::string_view dst, std::string_view lhs, std::string_view rhs);
};

/**
 * Substraction instruction
 */
struct SubInstr : public Instr {
  int dst_id;
  int lhs_id;
  int rhs_id;
  SubInstr(std::string_view dst, std::string_view lhs, std::string_view rhs);
};

/**
 * Multiplication instruction
 */
struct MulInstr : public Instr {
  int dst_id;
  int lhs_id;
  int rhs_id;
  MulInstr(std::string_view dst, std::string_view lhs, std::string_view rhs);
};

/**
 * Division instruction
 */
struct DivInstr : public Instr {
  int dst_id;
  int lhs_id;
  int rhs_id;
  DivInstr(std::string_view dst, std::string_view lhs, std::string_view rhs);
};

/**
 * Incrementation instruction
 */
struct IncInstr : public Instr {
  int reg_id;
  IncInstr(std::string_view reg);
};

/**
 * Decrementation instruction
 */
struct DecInstr : public Instr {
  int reg_id;
  DecInstr(std::string_view reg);
};

/**
 * Branch if not equal instruction
 */
struct BnInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BnInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Branch if equal instruction
 *
 */
struct BeInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BeInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Branch if greater instruction
 */
struct BgInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BgInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Branch if smaller instruction
 */
struct BsInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BsInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Branch if greater or equal instruction
 */
struct BgeInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BgeInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Branch if smaller or equal instruction
 */
struct BseInstr : public Instr {
  std::string label;
  int lhs_id;
  int rhs_id;
  BseInstr(std::string_view l, std::string_view lhs, std::string_view rhs);
};

/**
 * Label representation
 */
struct Label : public Instr {
  std::string label;
  Label(std::string_view l);
};

/*
 * All functions below are made to create a representation of an instruction or
 * a label from the initial token table
 */

std::unique_ptr<Instr> make_br_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_ld_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_str_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_out_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_add_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_sub_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_mul_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_div_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_inc_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_dec_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_be_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_bn_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_bg_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_bs_instr(TokenTable::token_type const &table,
                                     size_t &index);

std::unique_ptr<Instr> make_bge_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_bse_instr(TokenTable::token_type const &table,
                                      size_t &index);

std::unique_ptr<Instr> make_label(TokenTable::token_type const &table,
                                  size_t &index);

namespace detail {

/**
 * Extracts the id of the given register
 *
 * @param reg The given register, as a string
 * @return int The id of the register
 */
int get_register_id(std::string_view reg);

} // namespace detail

} // namespace fnt

} // namespace cmp