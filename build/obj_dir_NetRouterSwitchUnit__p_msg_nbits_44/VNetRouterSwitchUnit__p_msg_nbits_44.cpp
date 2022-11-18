// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VNetRouterSwitchUnit__p_msg_nbits_44.h for the primary calling header

#include "VNetRouterSwitchUnit__p_msg_nbits_44.h"
#include "VNetRouterSwitchUnit__p_msg_nbits_44__Syms.h"

#include "verilated_dpi.h"

//==========

void VNetRouterSwitchUnit__p_msg_nbits_44::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VNetRouterSwitchUnit__p_msg_nbits_44::eval\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("lab4_sys/NetRouterSwitchUnit.v", 110, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VNetRouterSwitchUnit__p_msg_nbits_44::_eval_initial_loop(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("lab4_sys/NetRouterSwitchUnit.v", 110, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VNetRouterSwitchUnit__p_msg_nbits_44::__Vdpiexp_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__line_trace_TOP(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp, WData/*4095:0*/ (&trace_str)[128]) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::__Vdpiexp_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__line_trace_TOP\n"); );
    // Variables
    WData/*4095:0*/ __Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[128];
    WData/*4095:0*/ __Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[128];
    IData/*31:0*/ __Vilp;
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->ostream_val) & (IData)(vlTOPp->ostream_rdy))) {
        VL_SFORMAT_X(4096,vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__str
                     ,"%1#",2,vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input);
        __Vilp = 0U;
        while ((__Vilp <= 0x7fU)) {
            __Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[__Vilp] 
                = vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__str[__Vilp];
            __Vilp = ((IData)(1U) + __Vilp);
        }
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 = 1U;
        while ((0U != (0xffU & (((0U == (0x1fU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0)))
                                  ? 0U : (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[
                                          ((IData)(1U) 
                                           + (0x7fU 
                                              & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0) 
                                                 >> 5U)))] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0))))) 
                                | (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[
                                   (0x7fU & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0))))))) {
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 
                = ((IData)(1U) + vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0);
        }
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
            = trace_str[0U];
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
            = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 
               - (IData)(1U));
        while (VL_LTES_III(1,32,32, 0U, vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1)) {
            VL_ASSIGNSEL_WIII(8,(0xfffU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0)), trace_str, 
                              (0xffU & (((0U == (0x1fU 
                                                 & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1)))
                                          ? 0U : (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x7fU 
                                                    & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1))))) 
                                        | (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__0__str[
                                           (0x7fU & 
                                            (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1) 
                                             >> 5U))] 
                                           >> (0x1fU 
                                               & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1))))));
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
                = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
                   - (IData)(1U));
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
                = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
                   - (IData)(1U));
        }
        trace_str[0U] = vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0;
    } else {
        __Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[0U] = 0x20U;
        __Vilp = 1U;
        while ((__Vilp <= 0x7fU)) {
            __Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[__Vilp] = 0U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 = 1U;
        while ((0U != (0xffU & (((0U == (0x1fU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0)))
                                  ? 0U : (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[
                                          ((IData)(1U) 
                                           + (0x7fU 
                                              & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0) 
                                                 >> 5U)))] 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
                                                 & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0))))) 
                                | (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[
                                   (0x7fU & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0) 
                                             >> 5U))] 
                                   >> (0x1fU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0))))))) {
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 
                = ((IData)(1U) + vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0);
        }
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
            = trace_str[0U];
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
            = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0 
               - (IData)(1U));
        while (VL_LTES_III(1,32,32, 0U, vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1)) {
            VL_ASSIGNSEL_WIII(8,(0xfffU & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0)), trace_str, 
                              (0xffU & (((0U == (0x1fU 
                                                 & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1)))
                                          ? 0U : (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x7fU 
                                                    & (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1))))) 
                                        | (__Vtask_NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__append_str__1__str[
                                           (0x7fU & 
                                            (VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1) 
                                             >> 5U))] 
                                           >> (0x1fU 
                                               & VL_MULS_III(12,32,32, (IData)(8U), vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1))))));
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
                = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0 
                   - (IData)(1U));
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
                = (vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1 
                   - (IData)(1U));
        }
        trace_str[0U] = vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0;
    }
}

void VNetRouterSwitchUnit__p_msg_nbits_44::line_trace(svBitVecVal* trace_str) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::line_trace\n"); );
    // Variables
    WData/*4095:0*/ trace_str__Vcvt[128];
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum==-1)) { __Vfuncnum = Verilated::exportFuncNum("line_trace"); }
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VNetRouterSwitchUnit__p_msg_nbits_44__Vcb_line_trace_t __Vcb = (VNetRouterSwitchUnit__p_msg_nbits_44__Vcb_line_trace_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    VL_SET_W_SVBV(4096,trace_str__Vcvt,trace_str);(*__Vcb)((VNetRouterSwitchUnit__p_msg_nbits_44__Syms*)(__Vscopep->symsp()), trace_str__Vcvt);
    VL_SET_SVBV_W(4096, trace_str, trace_str__Vcvt);
}

VL_INLINE_OPT void VNetRouterSwitchUnit__p_msg_nbits_44::_combo__TOP__2(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_combo__TOP__2\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->istream0_rdy = 0U;
    if (vlTOPp->istream0_val) {
        vlTOPp->istream0_rdy = vlTOPp->ostream_rdy;
    }
    vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input = 0U;
    if (vlTOPp->istream0_val) {
        vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input = 0U;
    } else {
        if (vlTOPp->istream1_val) {
            vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input = 1U;
        } else {
            if (vlTOPp->istream2_val) {
                vlTOPp->NetRouterSwitchUnit___05Fp_msg_nbits_44__DOT__v__DOT__selected_input = 2U;
            }
        }
    }
    vlTOPp->ostream_val = 0U;
    if (vlTOPp->istream0_val) {
        vlTOPp->ostream_val = 1U;
    } else {
        if (vlTOPp->istream1_val) {
            vlTOPp->ostream_val = 1U;
        } else {
            if (vlTOPp->istream2_val) {
                vlTOPp->ostream_val = 1U;
            }
        }
    }
    vlTOPp->istream1_rdy = 0U;
    if ((1U & (~ (IData)(vlTOPp->istream0_val)))) {
        if (vlTOPp->istream1_val) {
            vlTOPp->istream1_rdy = vlTOPp->ostream_rdy;
        }
    }
    vlTOPp->istream2_rdy = 0U;
    if ((1U & (~ (IData)(vlTOPp->istream0_val)))) {
        if ((1U & (~ (IData)(vlTOPp->istream1_val)))) {
            if (vlTOPp->istream2_val) {
                vlTOPp->istream2_rdy = vlTOPp->ostream_rdy;
            }
        }
    }
    if (vlTOPp->istream0_val) {
        vlTOPp->ostream_msg = vlTOPp->istream0_msg;
    } else {
        if (vlTOPp->istream1_val) {
            vlTOPp->ostream_msg = vlTOPp->istream1_msg;
        } else {
            if (vlTOPp->istream2_val) {
                vlTOPp->ostream_msg = vlTOPp->istream2_msg;
            }
        }
    }
}

void VNetRouterSwitchUnit__p_msg_nbits_44::_eval(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_eval\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData VNetRouterSwitchUnit__p_msg_nbits_44::_change_request(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_change_request\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VNetRouterSwitchUnit__p_msg_nbits_44::_change_request_1(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_change_request_1\n"); );
    VNetRouterSwitchUnit__p_msg_nbits_44* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VNetRouterSwitchUnit__p_msg_nbits_44::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VNetRouterSwitchUnit__p_msg_nbits_44::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((istream0_msg & 0ULL))) {
        Verilated::overWidthError("istream0_msg");}
    if (VL_UNLIKELY((istream0_val & 0xfeU))) {
        Verilated::overWidthError("istream0_val");}
    if (VL_UNLIKELY((istream1_msg & 0ULL))) {
        Verilated::overWidthError("istream1_msg");}
    if (VL_UNLIKELY((istream1_val & 0xfeU))) {
        Verilated::overWidthError("istream1_val");}
    if (VL_UNLIKELY((istream2_msg & 0ULL))) {
        Verilated::overWidthError("istream2_msg");}
    if (VL_UNLIKELY((istream2_val & 0xfeU))) {
        Verilated::overWidthError("istream2_val");}
    if (VL_UNLIKELY((ostream_rdy & 0xfeU))) {
        Verilated::overWidthError("ostream_rdy");}
}
#endif  // VL_DEBUG
