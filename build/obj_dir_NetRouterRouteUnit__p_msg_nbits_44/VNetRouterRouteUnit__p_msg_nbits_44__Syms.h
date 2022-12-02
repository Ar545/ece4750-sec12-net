// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VNETROUTERROUTEUNIT__P_MSG_NBITS_44__SYMS_H_
#define _VNETROUTERROUTEUNIT__P_MSG_NBITS_44__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "VNetRouterRouteUnit__p_msg_nbits_44.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)
typedef void (*VNetRouterRouteUnit__p_msg_nbits_44__Vcb_line_trace_t) (VNetRouterRouteUnit__p_msg_nbits_44__Syms* __restrict vlSymsp, WData/*4095:0*/ (&trace_str)[128]);

// SYMS CLASS
class VNetRouterRouteUnit__p_msg_nbits_44__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VNetRouterRouteUnit__p_msg_nbits_44* TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_NetRouterRouteUnit___05Fp_msg_nbits_44__v;
    
    // CREATORS
    VNetRouterRouteUnit__p_msg_nbits_44__Syms(VNetRouterRouteUnit__p_msg_nbits_44* topp, const char* namep);
    ~VNetRouterRouteUnit__p_msg_nbits_44__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
