// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNetRouterSwitchUnit__p_msg_nbits_44.h for the primary calling header

#include "VNetRouterSwitchUnit__p_msg_nbits_44.h"
#include "VNetRouterSwitchUnit__p_msg_nbits_44__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VNetRouterSwitchUnit__p_msg_nbits_44) {
    VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp = __VlSymsp = new VNetRouterSwitchUnit__p_msg_nbits_44__Syms(this, name());
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VNetRouterSwitchUnit__p_msg_nbits_44::__Vconfigure(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VNetRouterSwitchUnit__p_msg_nbits_44::~VNetRouterSwitchUnit__p_msg_nbits_44() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VNetRouterSwitchUnit__p_msg_nbits_44::_eval_initial(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_eval_initial\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VNetRouterSwitchUnit__p_msg_nbits_44::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::final\n"); );
    // Variables
    VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp = this->__VlSymsp;
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNetRouterSwitchUnit__p_msg_nbits_44::_eval_settle(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_eval_settle\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void VNetRouterSwitchUnit__p_msg_nbits_44::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    istream0_msg = VL_RAND_RESET_Q(44);
    istream0_rdy = VL_RAND_RESET_I(1);
    istream0_val = VL_RAND_RESET_I(1);
    istream1_msg = VL_RAND_RESET_Q(44);
    istream1_rdy = VL_RAND_RESET_I(1);
    istream1_val = VL_RAND_RESET_I(1);
    istream2_msg = VL_RAND_RESET_Q(44);
    istream2_rdy = VL_RAND_RESET_I(1);
    istream2_val = VL_RAND_RESET_I(1);
    ostream_msg = VL_RAND_RESET_Q(44);
    ostream_rdy = VL_RAND_RESET_I(1);
    ostream_val = VL_RAND_RESET_I(1);
    NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(4096, NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__str);
    NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 = VL_RAND_RESET_I(32);
    NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 = VL_RAND_RESET_I(32);
    NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 = VL_RAND_RESET_I(32);
}
