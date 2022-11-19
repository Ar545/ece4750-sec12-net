//========================================================================
// Network Router Route Unit
//========================================================================

`ifndef LAB4_SYS_NET_ROUTER_ROUTE_UNIT_V
`define LAB4_SYS_NET_ROUTER_ROUTE_UNIT_V

`include "vc/net-msgs.v"
`include "vc/trace.v"

module lab4_sys_NetRouterRouteUnit
#(
  parameter p_msg_nbits = 44
)
(
  input  logic                   clk,
  input  logic                   reset,

  // Router id (which router is this in the network?)

  input  logic     [1:0]         router_id,

  // Input stream

  input  logic [p_msg_nbits-1:0] istream_msg,
  input  logic                   istream_val,
  output logic                   istream_rdy,

  // Output stream 0

  output logic [p_msg_nbits-1:0] ostream0_msg,
  output logic                   ostream0_val,
  input  logic                   ostream0_rdy,

  // Output stream 1

  output logic [p_msg_nbits-1:0] ostream1_msg,
  output logic                   ostream1_val,
  input  logic                   ostream1_rdy,

  // Output stream 2

  output logic [p_msg_nbits-1:0] ostream2_msg,
  output logic                   ostream2_val,
  input  logic                   ostream2_rdy
);

  logic [1:0] istream_msg_dest;
  assign istream_msg_dest = istream_msg[p_msg_nbits-1:p_msg_nbits-2];

  assign ostream0_msg = istream_msg;
  assign ostream1_msg = istream_msg;
  assign ostream2_msg = istream_msg;

  always_comb begin

    istream_rdy  = 0;
    ostream0_val = 0;
    ostream1_val = 0;
    ostream2_val = 0;

    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // SECTION TASK: Implement route unit logic
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  end

  //----------------------------------------------------------------------
  // Line Tracing
  //----------------------------------------------------------------------

  `ifndef SYNTHESIS

  logic [`VC_TRACE_NBITS-1:0] str;
  `VC_TRACE_BEGIN
  begin

    if ( istream_val && istream_rdy ) begin
      $sformat( str, "%d", istream_msg_dest );
      vc_trace.append_str( trace_str, str );
    end
    else
      vc_trace.append_str( trace_str, " " );

  end
  `VC_TRACE_END

  `endif /* SYNTHESIS */

endmodule

`endif /* NET_ROUTER_ROUTE_UNIT_V */
