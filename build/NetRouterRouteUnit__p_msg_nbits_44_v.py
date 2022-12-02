
#=========================================================================
# VNetRouterRouteUnit__p_msg_nbits_44_v.py
#=========================================================================
"""Provide a template of PyMTL wrapper to import verilated models.

This wrapper makes a Verilator-generated C++ model appear as if it were a
normal PyMTL model. This template is based on PyMTL v2.
"""

import os

from cffi import FFI

from pymtl3.datatypes import *
from pymtl3.dsl import Component, connect, InPort, OutPort, Wire, update, update_ff

#-------------------------------------------------------------------------
# NetRouterRouteUnit__p_msg_nbits_44
#-------------------------------------------------------------------------

class NetRouterRouteUnit__p_msg_nbits_44( Component ):
  id_ = 0

  def __init__( s, *args, **kwargs ):
    s._finalization_count = 0

    # initialize FFI, define the exposed interface
    s.ffi = FFI()
    s.ffi.cdef("""
      typedef struct {

        // Exposed port interface
        unsigned char * clk;        
        unsigned char * reset;        
        unsigned char * router_id;        
        unsigned long * istream_msg;        
        unsigned char * istream_rdy;        
        unsigned char * istream_val;        
        unsigned long * ostream0_msg;        
        unsigned char * ostream0_rdy;        
        unsigned char * ostream0_val;        
        unsigned long * ostream1_msg;        
        unsigned char * ostream1_rdy;        
        unsigned char * ostream1_val;        
        unsigned long * ostream2_msg;        
        unsigned char * ostream2_rdy;        
        unsigned char * ostream2_val;

        // Verilator model
        void * model;

      } VNetRouterRouteUnit__p_msg_nbits_44_t;

      VNetRouterRouteUnit__p_msg_nbits_44_t * create_model( const char * );
      void destroy_model( VNetRouterRouteUnit__p_msg_nbits_44_t *);
      void comb_eval( VNetRouterRouteUnit__p_msg_nbits_44_t * );
      void seq_eval( VNetRouterRouteUnit__p_msg_nbits_44_t * );
      void assert_en( bool en );
      void trace( VNetRouterRouteUnit__p_msg_nbits_44_t *, char * );

    """)

    # Print the modification time stamp of the shared lib
    # print 'Modification time of {}: {}'.format(
    #   'libNetRouterRouteUnit__p_msg_nbits_44_v.so', os.path.getmtime( './libNetRouterRouteUnit__p_msg_nbits_44_v.so' ) )

    # Import the shared library containing the model. We defer
    # construction to the elaborate_logic function to allow the user to
    # set the vcd_file.
    s._ffi_inst = s.ffi.dlopen('./libNetRouterRouteUnit__p_msg_nbits_44_v.so')

    # increment instance count
    NetRouterRouteUnit__p_msg_nbits_44.id_ += 1

  def finalize( s ):
    """Finalize the imported component.

    This method closes the shared library opened through CFFI. If an imported
    component is not finalized explicitly (i.e. if you rely on GC to collect a
    no longer used imported component), importing a component with the same
    name before all previous imported components are GCed might lead to
    confusing behaviors. This is because once opened, the shared lib
    is cached by the OS until the OS reference counter for this lib reaches
    0 (you can decrement the reference counter by calling `dl_close()` syscall).

    Fortunately real designs tend to always have the same shared lib corresponding
    to the components with the same name. If you are doing translation testing and
    use the same component class name even if they refer to different designs,
    you might need to call `imported_object.finalize()` at the end of each test
    to ensure correct behaviors.
    """
    assert s._finalization_count == 0,      'Imported component can only be finalized once!'
    s._finalization_count += 1
    s._ffi_inst.destroy_model( s._ffi_m )
    s.ffi.dlclose( s._ffi_inst )
    s.ffi = None
    s._ffi_inst = None

  def __del__( s ):
    if s._finalization_count == 0:
      s._finalization_count += 1
      s._ffi_inst.destroy_model( s._ffi_m )
      s.ffi.dlclose( s._ffi_inst )
      s.ffi = None
      s._ffi_inst = None

  def construct( s, *args, **kwargs ):
    # Set up the VCD file name
    verilator_vcd_file = ""
    if 0:
      if False:
        verilator_vcd_file = ".verilator1.vcd"
      else:
        verilator_vcd_file = "NetRouterRouteUnit__p_msg_nbits_44.verilator1.vcd"

    # Convert string to `bytes` which is required by CFFI on python 3
    verilator_vcd_file = verilator_vcd_file.encode('ascii')

    # Construct the model
    s._ffi_m = s._ffi_inst.create_model( s.ffi.new("char[]", verilator_vcd_file) )

    # Buffer for line tracing
    s._line_trace_str = s.ffi.new('char[512]')
    s._convert_string = s.ffi.string

    # Use non-attribute varialbe to reduce CPython bytecode count
    _ffi_m = s._ffi_m
    _ffi_inst_comb_eval = s._ffi_inst.comb_eval
    _ffi_inst_seq_eval  = s._ffi_inst.seq_eval

    # declare the port interface
    s.router_id = InPort( Bits4 )
    s.istream = IStreamIfc( NetMsg__dest_2__src_2__opaque_8__payload_32 )
    s.ostream0 = OStreamIfc( NetMsg__dest_2__src_2__opaque_8__payload_32 )
    s.ostream1 = OStreamIfc( NetMsg__dest_2__src_2__opaque_8__payload_32 )
    s.ostream2 = OStreamIfc( NetMsg__dest_2__src_2__opaque_8__payload_32 )

    # update blocks that converts ffi interface to/from pymtl ports
    
    s.s_DOT_reset = Wire( Bits1 )
    @update
    def isignal_s_DOT_reset():
      s.s_DOT_reset @= s.reset
    
    s.s_DOT_router_id = Wire( Bits4 )
    @update
    def isignal_s_DOT_router_id():
      s.s_DOT_router_id @= s.router_id
    
    s.s_DOT_istream_DOT_msg = Wire( Bits44 )
    @update
    def istruct_s_DOT_istream_DOT_msg():
      s.s_DOT_istream_DOT_msg @= s.istream.msg
    
    s.s_DOT_istream_DOT_val = Wire( Bits1 )
    @update
    def isignal_s_DOT_istream_DOT_val():
      s.s_DOT_istream_DOT_val @= s.istream.val
    
    s.s_DOT_ostream0_DOT_rdy = Wire( Bits1 )
    @update
    def isignal_s_DOT_ostream0_DOT_rdy():
      s.s_DOT_ostream0_DOT_rdy @= s.ostream0.rdy
    
    s.s_DOT_ostream1_DOT_rdy = Wire( Bits1 )
    @update
    def isignal_s_DOT_ostream1_DOT_rdy():
      s.s_DOT_ostream1_DOT_rdy @= s.ostream1.rdy
    
    s.s_DOT_ostream2_DOT_rdy = Wire( Bits1 )
    @update
    def isignal_s_DOT_ostream2_DOT_rdy():
      s.s_DOT_ostream2_DOT_rdy @= s.ostream2.rdy
    
    s.s_DOT_istream_DOT_rdy = Wire( Bits1 )
    @update
    def osignal_s_DOT_istream_DOT_rdy():
      s.istream.rdy @= s.s_DOT_istream_DOT_rdy
    
    s.s_DOT_ostream0_DOT_msg = Wire( Bits44 )
    @update
    def ostruct_s_DOT_ostream0_DOT_msg():
      s.ostream0.msg.payload @= s.s_DOT_ostream0_DOT_msg[0:32]
      s.ostream0.msg.opaque @= s.s_DOT_ostream0_DOT_msg[32:40]
      s.ostream0.msg.src @= s.s_DOT_ostream0_DOT_msg[40:42]
      s.ostream0.msg.dest @= s.s_DOT_ostream0_DOT_msg[42:44]
    
    s.s_DOT_ostream0_DOT_val = Wire( Bits1 )
    @update
    def osignal_s_DOT_ostream0_DOT_val():
      s.ostream0.val @= s.s_DOT_ostream0_DOT_val
    
    s.s_DOT_ostream1_DOT_msg = Wire( Bits44 )
    @update
    def ostruct_s_DOT_ostream1_DOT_msg():
      s.ostream1.msg.payload @= s.s_DOT_ostream1_DOT_msg[0:32]
      s.ostream1.msg.opaque @= s.s_DOT_ostream1_DOT_msg[32:40]
      s.ostream1.msg.src @= s.s_DOT_ostream1_DOT_msg[40:42]
      s.ostream1.msg.dest @= s.s_DOT_ostream1_DOT_msg[42:44]
    
    s.s_DOT_ostream1_DOT_val = Wire( Bits1 )
    @update
    def osignal_s_DOT_ostream1_DOT_val():
      s.ostream1.val @= s.s_DOT_ostream1_DOT_val
    
    s.s_DOT_ostream2_DOT_msg = Wire( Bits44 )
    @update
    def ostruct_s_DOT_ostream2_DOT_msg():
      s.ostream2.msg.payload @= s.s_DOT_ostream2_DOT_msg[0:32]
      s.ostream2.msg.opaque @= s.s_DOT_ostream2_DOT_msg[32:40]
      s.ostream2.msg.src @= s.s_DOT_ostream2_DOT_msg[40:42]
      s.ostream2.msg.dest @= s.s_DOT_ostream2_DOT_msg[42:44]
    
    s.s_DOT_ostream2_DOT_val = Wire( Bits1 )
    @update
    def osignal_s_DOT_ostream2_DOT_val():
      s.ostream2.val @= s.s_DOT_ostream2_DOT_val

    @update
    def comb_upblk():

      # Set inputs
      
      _ffi_m.reset[0] = int(s.s_DOT_reset)
      
      _ffi_m.router_id[0] = int(s.s_DOT_router_id)
      
      _ffi_m.istream_msg[0] = int(s.s_DOT_istream_DOT_msg)
      
      _ffi_m.istream_val[0] = int(s.s_DOT_istream_DOT_val)
      
      _ffi_m.ostream0_rdy[0] = int(s.s_DOT_ostream0_DOT_rdy)
      
      _ffi_m.ostream1_rdy[0] = int(s.s_DOT_ostream1_DOT_rdy)
      
      _ffi_m.ostream2_rdy[0] = int(s.s_DOT_ostream2_DOT_rdy)

      _ffi_inst_comb_eval( _ffi_m )

      # Write all outputs
      
      s.s_DOT_istream_DOT_rdy @= _ffi_m.istream_rdy[0]
      
      s.s_DOT_ostream0_DOT_msg @= _ffi_m.ostream0_msg[0]
      
      s.s_DOT_ostream0_DOT_val @= _ffi_m.ostream0_val[0]
      
      s.s_DOT_ostream1_DOT_msg @= _ffi_m.ostream1_msg[0]
      
      s.s_DOT_ostream1_DOT_val @= _ffi_m.ostream1_val[0]
      
      s.s_DOT_ostream2_DOT_msg @= _ffi_m.ostream2_msg[0]
      
      s.s_DOT_ostream2_DOT_val @= _ffi_m.ostream2_val[0]

    @update_ff
    def seq_upblk():
      # seq_eval will automatically tick clock in C land
      _ffi_inst_seq_eval( _ffi_m )

  def assert_en( s, en ):
    # TODO: for verilator, any assertion failure will cause the C simulator
    # to abort, which results in a Python internal error. A better approach
    # is to throw a Python exception at the time of assertion failure.
    # Verilator allows user-defined `stop` function which is called when
    # the simulation is expected to stop due to various reasons. We might
    # be able to raise a Python exception through Python C API (although
    # at this moment I'm not sure if the C API's are compatible between
    # PyPy and CPython).
    assert isinstance( en, bool )
    s._ffi_inst.assert_en( en )

  def line_trace( s ):
    if 1:
      s._ffi_inst.trace( s._ffi_m, s._line_trace_str )
      return s._convert_string( s._line_trace_str ).decode('ascii')
    else:
      return f' clk={s.clk}, reset={s.reset}, router_id={s.router_id}, istream.msg={s.istream.msg}, istream.rdy={s.istream.rdy}, istream.val={s.istream.val}, ostream0.msg={s.ostream0.msg}, ostream0.rdy={s.ostream0.rdy}, ostream0.val={s.ostream0.val}, ostream1.msg={s.ostream1.msg}, ostream1.rdy={s.ostream1.rdy}, ostream1.val={s.ostream1.val}, ostream2.msg={s.ostream2.msg}, ostream2.rdy={s.ostream2.rdy}, ostream2.val={s.ostream2.val},'

  def internal_line_trace( s ):
    return ''
