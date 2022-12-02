// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VNetRouterRouteUnit__p_msg_nbits_44.h for the primary calling header

#ifndef _VNETROUTERROUTEUNIT__P_MSG_NBITS_44___024UNIT_H_
#define _VNETROUTERROUTEUNIT__P_MSG_NBITS_44___024UNIT_H_  // guard

#include "verilated_heavy.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44__Dpi.h"

//==========

class VNetRouterRouteUnit__p_msg_nbits_44__Syms;

//----------

VL_MODULE(VNetRouterRouteUnit__p_msg_nbits_44___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    VNetRouterRouteUnit__p_msg_nbits_44__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VNetRouterRouteUnit__p_msg_nbits_44___024unit);  ///< Copying not allowed
  public:
    VNetRouterRouteUnit__p_msg_nbits_44___024unit(const char* name = "TOP");
    ~VNetRouterRouteUnit__p_msg_nbits_44___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(VNetRouterRouteUnit__p_msg_nbits_44__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
