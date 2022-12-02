// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VNetRouterRouteUnit__p_msg_nbits_44__Syms.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44.h"
#include "VNetRouterRouteUnit__p_msg_nbits_44___024unit.h"



// FUNCTIONS
VNetRouterRouteUnit__p_msg_nbits_44__Syms::VNetRouterRouteUnit__p_msg_nbits_44__Syms(VNetRouterRouteUnit__p_msg_nbits_44* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_NetRouterRouteUnit___05Fp_msg_nbits_44__v.configure(this, name(), "NetRouterRouteUnit__p_msg_nbits_44.v", "v", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_NetRouterRouteUnit___05Fp_msg_nbits_44__v.exportInsert(__Vfinal, "line_trace", (void*)(&VNetRouterRouteUnit__p_msg_nbits_44::__Vdpiexp_NetRouterRouteUnit___05Fp_msg_nbits_44__DOT__v__DOT__line_trace_TOP));
    }
}
