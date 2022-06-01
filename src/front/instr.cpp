#include <front/instr.hpp>
#include <front/token.hpp>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>

namespace cmp {

namespace fnt {

namespace detail {

int get_register_id(std::string_view reg) {
  return std::stoi(std::string{reg[1]});
}

} // namespace detail

BrInstr::BrInstr(std::string_view l) { label = l; }

LdInstr::LdInstr(std::string_view reg, std::string_view val) {
  reg_id = detail::get_register_id(reg);
  value = std::stoi(std::string{val});
}

StrInstr::StrInstr(std::string_view reg, std::string_view mem) {
  reg_id = detail::get_register_id(reg);
  memory_cell = std::stoi(std::string{mem});
}

OutInstr::OutInstr(std::string_view reg) {
  reg_id = detail::get_register_id(reg);
}

AddInstr::AddInstr(std::string_view dst, std::string_view lhs,
                   std::string_view rhs) {
  dst_id = detail::get_register_id(dst);
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

SubInstr::SubInstr(std::string_view dst, std::string_view lhs,
                   std::string_view rhs) {
  dst_id = detail::get_register_id(dst);
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

MulInstr::MulInstr(std::string_view dst, std::string_view lhs,
                   std::string_view rhs) {
  dst_id = detail::get_register_id(dst);
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

DivInstr::DivInstr(std::string_view dst, std::string_view lhs,
                   std::string_view rhs) {
  dst_id = detail::get_register_id(dst);
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

IncInstr::IncInstr(std::string_view reg) {
  reg_id = detail::get_register_id(reg);
}

DecInstr::DecInstr(std::string_view reg) {
  reg_id = detail::get_register_id(reg);
}

BeInstr::BeInstr(std::string_view l, std::string_view lhs,
                 std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

BnInstr::BnInstr(std::string_view l, std::string_view lhs,
                 std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

BgInstr::BgInstr(std::string_view l, std::string_view lhs,
                 std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

BsInstr::BsInstr(std::string_view l, std::string_view lhs,
                 std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

BgeInstr::BgeInstr(std::string_view l, std::string_view lhs,
                   std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

BseInstr::BseInstr(std::string_view l, std::string_view lhs,
                   std::string_view rhs) {
  label = l;
  lhs_id = detail::get_register_id(lhs);
  rhs_id = detail::get_register_id(rhs);
}

Label::Label(std::string_view l) { label = l; }

std::unique_ptr<Instr> make_br_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &dst_label = table[index + 1];
  if (dst_label.second != TokenKind::LABEL)
    throw std::runtime_error("br <label>");

  index += 2;

  return std::make_unique<BrInstr>(dst_label.first);
}

std::unique_ptr<Instr> make_ld_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &dst_reg = table[index + 1];
  auto const &value = table[index + 2];

  if (dst_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("ld <register> <value>");

  if (value.second != TokenKind::INT_LIT)
    throw std::runtime_error("ld <register> <value>");

  index += 3;

  return std::make_unique<LdInstr>(dst_reg.first, value.first);
}

std::unique_ptr<Instr> make_str_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &src_reg = table[index + 1];
  auto const &mem_cell = table[index + 2];

  if (src_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("str <register> <memory>");

  if (mem_cell.second != TokenKind::INT_LIT)
    throw std::runtime_error("str <register> <memory>");

  index += 3;

  return std::make_unique<StrInstr>(src_reg.first, mem_cell.first);
}

std::unique_ptr<Instr> make_out_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &reg = table[index + 1];

  if (reg.second != TokenKind::REGISTER)
    throw std::runtime_error("out <register>");

  index += 2;

  return std::make_unique<OutInstr>(reg.first);
}

std::unique_ptr<Instr> make_add_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &dst_reg = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (dst_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("add <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("add <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("add <destination> <lhs> <rhs>");

  index += 4;

  return std::make_unique<AddInstr>(dst_reg.first, lhs_reg.first,
                                    rhs_reg.first);
}

std::unique_ptr<Instr> make_sub_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &dst_reg = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (dst_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("sub <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("sub <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("sub <destination> <lhs> <rhs>");

  index += 4;

  return std::make_unique<SubInstr>(dst_reg.first, lhs_reg.first,
                                    rhs_reg.first);
}

std::unique_ptr<Instr> make_mul_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &dst_reg = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (dst_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("mul <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("mul <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("mul <destination> <lhs> <rhs>");

  index += 4;

  return std::make_unique<MulInstr>(dst_reg.first, lhs_reg.first,
                                    rhs_reg.first);
}

std::unique_ptr<Instr> make_div_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &dst_reg = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (dst_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("div <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("div <destination> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("div <destination> <lhs> <rhs>");

  index += 4;

  return std::make_unique<DivInstr>(dst_reg.first, lhs_reg.first,
                                    rhs_reg.first);
}

std::unique_ptr<Instr> make_inc_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &reg = table[index + 1];

  if (reg.second != TokenKind::REGISTER)
    throw std::runtime_error("inc <register");

  index += 2;

  return std::make_unique<IncInstr>(reg.first);
}

std::unique_ptr<Instr> make_dec_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &reg = table[index + 1];

  if (reg.second != TokenKind::REGISTER)
    throw std::runtime_error("dec <register");

  index += 2;

  return std::make_unique<DecInstr>(reg.first);
}

std::unique_ptr<Instr> make_bn_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("bn <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bn <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bn <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BnInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_be_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("be <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("be <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("be <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BeInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_bg_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("bg <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bg <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bg <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BgInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_bs_instr(TokenTable::token_type const &table,
                                     size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("bs <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bs <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bs <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BsInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_bge_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("bge <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bge <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bge <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BgeInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_bse_instr(TokenTable::token_type const &table,
                                      size_t &index) {
  auto const &label = table[index + 1];
  auto const &lhs_reg = table[index + 2];
  auto const &rhs_reg = table[index + 3];

  if (label.second != TokenKind::LABEL)
    throw std::runtime_error("bse <label> <lhs> <rhs>");

  if (lhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bse <label> <lhs> <rhs>");

  if (rhs_reg.second != TokenKind::REGISTER)
    throw std::runtime_error("bse <label> <lhs> <rhs>");

  index += 4;

  return std::make_unique<BseInstr>(label.first, lhs_reg.first, rhs_reg.first);
}

std::unique_ptr<Instr> make_label(TokenTable::token_type const &table,
                                  size_t &index) {
  index++;
  return std::make_unique<Label>(table[index].first);
}

} // namespace fnt

} // namespace cmp