// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VNetRouterSwitchUnit__p_msg_nbits_44.h for the primary calling header

#ifndef _VNETROUTERSWITCHUNIT__P_MSG_NBITS_44___024UNIT_H_
#define _VNETROUTERSWITCHUNIT__P_MSG_NBITS_44___024UNIT_H_  // guard

#include "verilated_heavy.h"
#include "VNetRouterSwitchUnit__p_msg_nbits_44__Dpi.h"

//==========

class VNetRouterSwitchUnit__p_msg_nbits_44__Syms;

//----------

VL_MODULE(VNetRouterSwitchUnit__p_msg_nbits_44___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    VNetRouterSwitchUnit__p_msg_nbits_44__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VNetRouterSwitchUnit__p_msg_nbits_44___024unit);  ///< Copying not allowed
  public:
    VNetRouterSwitchUnit__p_msg_nbits_44___024unit(const char* name = "TOP");
    ~VNetRouterSwitchUnit__p_msg_nbits_44___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(VNetRouterSwitchUnit__p_msg_nbits_44__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
