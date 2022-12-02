// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call VNetRouterRouteUnit__p_msg_nbits_44::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "VNetRouterRouteUnit__p_msg_nbits_44__Dpi.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44.h"

#ifndef _VL_DPIDECL_line_trace
#define _VL_DPIDECL_line_trace
void line_trace(svBitVecVal* trace_str) {
    // DPI export at lab4_sys/NetRouterRouteUnit.v:86:8
    return VNetRouterRouteUnit__p_msg_nbits_44::line_trace(trace_str);
}
#endif

