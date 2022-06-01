#include <front/repr.hpp>
#include <front/token.hpp>
#include <stdexcept>

namespace cmp {

namespace fnt {

ProgramRepr ProgramRepr::from_token_table(const TokenTable &table) {
  auto res = ProgramRepr{};

  res._instr_sequence = detail::gather_tokens(table);

  return res;
}

namespace detail {

ProgramRepr::instr_sequence_type gather_tokens(const TokenTable &table) {
  auto res = ProgramRepr::instr_sequence_type{};
  auto const &raw_table = table.get_table();

  size_t i = 0;
  while (i < raw_table.size()) {
    switch (raw_table[i].second) {
    case TokenKind::BR_INST:
      res.emplace_back(make_br_instr(raw_table, i));
      break;
    case TokenKind::LD_INST:
      res.emplace_back(make_ld_instr(raw_table, i));
      break;
    case TokenKind::STR_INST:
      res.emplace_back(make_str_instr(raw_table, i));
      break;
    case TokenKind::OUT_INST:
      res.emplace_back(make_out_instr(raw_table, i));
      break;
    case TokenKind::ADD_INST:
      res.emplace_back(make_add_instr(raw_table, i));
      break;
    case TokenKind::SUB_INST:
      res.emplace_back(make_sub_instr(raw_table, i));
      break;
    case TokenKind::MUL_INST:
      res.emplace_back(make_mul_instr(raw_table, i));
      break;
    case TokenKind::DIV_INST:
      res.emplace_back(make_div_instr(raw_table, i));
      break;
    case TokenKind::INC_INST:
      res.emplace_back(make_inc_instr(raw_table, i));
      break;
    case TokenKind::DEC_INST:
      res.emplace_back(make_dec_instr(raw_table, i));
      break;
    case TokenKind::BE_INST:
      res.emplace_back(make_be_instr(raw_table, i));
      break;
    case TokenKind::BN_INST:
      res.emplace_back(make_bn_instr(raw_table, i));
      break;
    case TokenKind::BG_INST:
      res.emplace_back(make_bg_instr(raw_table, i));
      break;
    case TokenKind::BS_INST:
      res.emplace_back(make_bs_instr(raw_table, i));
      break;
    case TokenKind::BGE_INST:
      res.emplace_back(make_bge_instr(raw_table, i));
      break;
    case TokenKind::BSE_INST:
      res.emplace_back(make_bse_instr(raw_table, i));
      break;
    case TokenKind::LABEL:
      res.emplace_back(make_label(raw_table, i));
      break;
    default:
      throw std::runtime_error("Erreur. :(");
    }
  }
}

} // namespace detail

} // namespace fnt

} // namespace cmp