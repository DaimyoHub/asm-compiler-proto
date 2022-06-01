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

class Instr {};

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

} // namespace fnt

} // namespace cmp