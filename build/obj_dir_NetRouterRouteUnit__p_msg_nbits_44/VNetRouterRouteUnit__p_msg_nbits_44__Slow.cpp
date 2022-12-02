// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNetRouterRouteUnit__p_msg_nbits_44.h for the primary calling header

#include "VNetRouterRouteUnit__p_msg_nbits_44.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(VNetRouterRouteUnit__p_msg_nbits_44) {
    VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp = __VlSymsp = new VNetRouterRouteUnit__p_msg_nbits_44__Syms(this, name());
    VNetRouterRouteUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VNetRouterRouteUnit__p_msg_nbits_44::__Vconfigure(VNetRouterRouteUnit__p_msg_nbits_44__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VNetRouterRouteUnit__p_msg_nbits_44::~VNetRouterRouteUnit__p_msg_nbits_44() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VNetRouterRouteUnit__p_msg_nbits_44::_eval_initial(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterRouteUnit__p_msg_nbits_44::_eval_initial\n"); );
    VNetRouterRouteUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VNetRouterRouteUnit__p_msg_nbits_44::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterRouteUnit__p_msg_nbits_44::final\n"); );
    // Variables
    VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp = this->__VlSymsp;
    VNetRouterRouteUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VNetRouterRouteUnit__p_msg_nbits_44::_eval_settle(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterRouteUnit__p_msg_nbits_44::_eval_settle\n"); );
    VNetRouterRouteUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
}

void VNetRouterRouteUnit__p_msg_nbits_44::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterRouteUnit__p_msg_nbits_44::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    router_id = VL_RAND_RESET_I(4);
    istream_msg = VL_RAND_RESET_Q(44);
    istream_rdy = VL_RAND_RESET_I(1);
    istream_val = VL_RAND_RESET_I(1);
    ostream0_msg = VL_RAND_RESET_Q(44);
    ostream0_rdy = VL_RAND_RESET_I(1);
    ostream0_val = VL_RAND_RESET_I(1);
    ostream1_msg = VL_RAND_RESET_Q(44);
    ostream1_rdy = VL_RAND_RESET_I(1);
    ostream1_val = VL_RAND_RESET_I(1);
    ostream2_msg = VL_RAND_RESET_Q(44);
    ostream2_rdy = VL_RAND_RESET_I(1);
    ostream2_val = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(4096, NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__str);
    NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 = VL_RAND_RESET_I(32);
    NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 = VL_RAND_RESET_I(32);
    NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 = VL_RAND_RESET_I(32);
}
