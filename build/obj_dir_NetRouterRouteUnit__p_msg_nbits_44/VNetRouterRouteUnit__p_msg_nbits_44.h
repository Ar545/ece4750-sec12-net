// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VNETROUTERROUTEUNIT__P_MSG_NBITS_44_H_
#define _VNETROUTERROUTEUNIT__P_MSG_NBITS_44_H_  // guard

#include "verilated_heavy.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44__Dpi.h"

//==========

class VNetRouterRouteUnit__p_msg_nbits_44__Syms;

//----------

VL_MODULE(VNetRouterRouteUnit__p_msg_nbits_44) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(router_id,3,0);
    VL_OUT8(istream_rdy,0,0);
    VL_IN8(istream_val,0,0);
    VL_IN8(ostream0_rdy,0,0);
    VL_OUT8(ostream0_val,0,0);
    VL_IN8(ostream1_rdy,0,0);
    VL_OUT8(ostream1_val,0,0);
    VL_IN8(ostream2_rdy,0,0);
    VL_OUT8(ostream2_val,0,0);
    VL_IN64(istream_msg,43,0);
    VL_OUT64(ostream0_msg,43,0);
    VL_OUT64(ostream1_msg,43,0);
    VL_OUT64(ostream2_msg,43,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    WData/*4095:0*/ NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__str[128];
    IData/*31:0*/ NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__len0;
    IData/*31:0*/ NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx0;
    IData/*31:0*/ NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__vc_trace__DOT__idx1;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VNetRouterRouteUnit__p_msg_nbits_44__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VNetRouterRouteUnit__p_msg_nbits_44);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VNetRouterRouteUnit__p_msg_nbits_44(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VNetRouterRouteUnit__p_msg_nbits_44();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VNetRouterRouteUnit__p_msg_nbits_44__Syms* symsp, bool first);
    static void __Vdpiexp_NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__line_trace_TOP(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp, WData/*4095:0*/ (&trace_str)[128]);
  private:
    static QData _change_request(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp);
    static QData _change_request_1(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void line_trace(svBitVecVal* trace_str);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
