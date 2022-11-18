//========================================================================
// Network Router Switch Unit
//========================================================================

`ifndef LAB4_SYS_NET_ROUTER_SWITCH_UNIT_V
`define LAB4_SYS_NET_ROUTER_SWITCH_UNIT_V

`include "vc/net-msgs.v"
`include "vc/trace.v"

module lab4_sys_NetRouterSwitchUnit
#(
  parameter p_msg_nbits = 44
)
(
  input  logic                   clk,
  input  logic                   reset,

  // Input stream 0

  input  logic [p_msg_nbits-1:0] istream0_msg,
  input  logic                   istream0_val,
  output logic                   istream0_rdy,

  // Input stream 1

  input  logic [p_msg_nbits-1:0] istream1_msg,
  input  logic                   istream1_val,
  output logic                   istream1_rdy,

  // Input stream 2

  input  logic [p_msg_nbits-1:0] istream2_msg,
  input  logic                   istream2_val,
  output logic                   istream2_rdy,

  // Output stream

  output logic [p_msg_nbits-1:0] ostream_msg,
  output logic                   ostream_val,
  input  logic                   ostream_rdy
);

  // For line tracing
  logic [1:0] selected_input;

  always_comb begin

    selected_input = 0;
    istream0_rdy   = 0;
    istream1_rdy   = 0;
    istream2_rdy   = 0;
    ostream_val    = 0;

    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    // SECTION TASK: Implement switch unit logic
    //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

  end

  //----------------------------------------------------------------------
  // Line Tracing
  //----------------------------------------------------------------------

  `ifndef SYNTHESIS

  logic [`VC_TRACE_NBITS-1:0] str;
  `VC_TRACE_BEGIN
  begin

    if ( ostream_val && ostream_rdy ) begin
      $sformat( str, "%d", selected_input );
      vc_trace.append_str( trace_str, str );
    end
    else
      vc_trace.append_str( trace_str, " " );

  end
  `VC_TRACE_END

  `endif /* SYNTHESIS */

endmodule

`endif /* NET_ROUTER_SWITCH_UNIT_V */
