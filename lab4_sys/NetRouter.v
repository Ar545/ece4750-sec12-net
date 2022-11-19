//========================================================================
// Network Router
//========================================================================

`ifndef LAB4_SYS_NET_ROUTER_V
`define LAB4_SYS_NET_ROUTER_V

`include "vc/net-msgs.v"
`include "vc/trace.v"
`include "vc/queues.v"

`include "lab4_sys/NetRouterRouteUnit.v"
`include "lab4_sys/NetRouterSwitchUnit.v"

module lab4_sys_NetRouter
#(
  parameter p_msg_nbits = 44
)
(
  input  logic                   clk,
  input  logic                   reset,

  // Router id (which router is this in the network?)

  input  logic     [1:0]         router_id,

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

  //----------------------------------------------------------------------
  // Input Queues
  //----------------------------------------------------------------------

  // Input queue 0

  logic [2:0] inq0_num_free_entries;

  logic [p_msg_nbits-1:0] inq0_deq_msg;
  logic                   inq0_deq_val;
  logic                   inq0_deq_rdy;

  vc_Queue#(`VC_QUEUE_NORMAL,p_msg_nbits,4) inq0
  (
    .clk     (clk),
    .reset   (reset),
    .num_free_entries(inq0_num_free_entries),

    .enq_msg (istream0_msg),
    .enq_val (istream0_val),
    .enq_rdy (istream0_rdy),

    .deq_msg (inq0_deq_msg),
    .deq_val (inq0_deq_val),
    .deq_rdy (inq0_deq_rdy)
  );

  // Input queue 1

  logic [2:0] inq1_num_free_entries;

  logic [p_msg_nbits-1:0] inq1_deq_msg;
  logic                   inq1_deq_val;
  logic                   inq1_deq_rdy;

  vc_Queue#(`VC_QUEUE_NORMAL,p_msg_nbits,4) inq1
  (
    .clk     (clk),
    .reset   (reset),
    .num_free_entries(inq1_num_free_entries),

    .enq_msg (istream1_msg),
    .enq_val (istream1_val),
    .enq_rdy (istream1_rdy),

    .deq_msg (inq1_deq_msg),
    .deq_val (inq1_deq_val),
    .deq_rdy (inq1_deq_rdy)
  );

  // Input queue 2

  logic [2:0] inq2_num_free_entries;

  logic [p_msg_nbits-1:0] inq2_deq_msg;
  logic                   inq2_deq_val;
  logic                   inq2_deq_rdy;

  vc_Queue#(`VC_QUEUE_NORMAL,p_msg_nbits,4) inq2
  (
    .clk     (clk),
    .reset   (reset),
    .num_free_entries(inq2_num_free_entries),

    .enq_msg (istream2_msg),
    .enq_val (istream2_val),
    .enq_rdy (istream2_rdy),

    .deq_msg (inq2_deq_msg),
    .deq_val (inq2_deq_val),
    .deq_rdy (inq2_deq_rdy)
  );

  //----------------------------------------------------------------------
  // Route Units
  //----------------------------------------------------------------------

  // Route unit 0

  logic [p_msg_nbits-1:0] runit0_ostream0_msg;
  logic                   runit0_ostream0_val;
  logic                   runit0_ostream0_rdy;

  logic [p_msg_nbits-1:0] runit0_ostream1_msg;
  logic                   runit0_ostream1_val;
  logic                   runit0_ostream1_rdy;

  logic [p_msg_nbits-1:0] runit0_ostream2_msg;
  logic                   runit0_ostream2_val;
  logic                   runit0_ostream2_rdy;

  lab4_sys_NetRouterRouteUnit#(44) runit0
  (
    .clk          (clk),
    .reset        (reset),
    .router_id    (router_id),

    .istream_msg  (inq0_deq_msg),
    .istream_val  (inq0_deq_val),
    .istream_rdy  (inq0_deq_rdy),

    .ostream0_msg (runit0_ostream0_msg),
    .ostream0_val (runit0_ostream0_val),
    .ostream0_rdy (runit0_ostream0_rdy),
    .ostream1_msg (runit0_ostream1_msg),
    .ostream1_val (runit0_ostream1_val),
    .ostream1_rdy (runit0_ostream1_rdy),
    .ostream2_msg (runit0_ostream2_msg),
    .ostream2_val (runit0_ostream2_val),
    .ostream2_rdy (runit0_ostream2_rdy)
  );

  // Route unit 1

  logic [p_msg_nbits-1:0] runit1_ostream0_msg;
  logic                   runit1_ostream0_val;
  logic                   runit1_ostream0_rdy;

  logic [p_msg_nbits-1:0] runit1_ostream1_msg;
  logic                   runit1_ostream1_val;
  logic                   runit1_ostream1_rdy;

  logic [p_msg_nbits-1:0] runit1_ostream2_msg;
  logic                   runit1_ostream2_val;
  logic                   runit1_ostream2_rdy;

  lab4_sys_NetRouterRouteUnit#(44) runit1
  (
    .clk          (clk),
    .reset        (reset),
    .router_id    (router_id),

    .istream_msg  (inq1_deq_msg),
    .istream_val  (inq1_deq_val),
    .istream_rdy  (inq1_deq_rdy),

    .ostream0_msg (runit1_ostream0_msg),
    .ostream0_val (runit1_ostream0_val),
    .ostream0_rdy (runit1_ostream0_rdy),
    .ostream1_msg (runit1_ostream1_msg),
    .ostream1_val (runit1_ostream1_val),
    .ostream1_rdy (runit1_ostream1_rdy),
    .ostream2_msg (runit1_ostream2_msg),
    .ostream2_val (runit1_ostream2_val),
    .ostream2_rdy (runit1_ostream2_rdy)
  );

  // Route unit 2

  logic [p_msg_nbits-1:0] runit2_ostream0_msg;
  logic                   runit2_ostream0_val;
  logic                   runit2_ostream0_rdy;

  logic [p_msg_nbits-1:0] runit2_ostream1_msg;
  logic                   runit2_ostream1_val;
  logic                   runit2_ostream1_rdy;

  logic [p_msg_nbits-1:0] runit2_ostream2_msg;
  logic                   runit2_ostream2_val;
  logic                   runit2_ostream2_rdy;

  lab4_sys_NetRouterRouteUnit#(44) runit2
  (
    .clk          (clk),
    .reset        (reset),
    .router_id    (router_id),

    .istream_msg  (inq2_deq_msg),
    .istream_val  (inq2_deq_val),
    .istream_rdy  (inq2_deq_rdy),

    .ostream0_msg (runit2_ostream0_msg),
    .ostream0_val (runit2_ostream0_val),
    .ostream0_rdy (runit2_ostream0_rdy),
    .ostream1_msg (runit2_ostream1_msg),
    .ostream1_val (runit2_ostream1_val),
    .ostream1_rdy (runit2_ostream1_rdy),
    .ostream2_msg (runit2_ostream2_msg),
    .ostream2_val (runit2_ostream2_val),
    .ostream2_rdy (runit2_ostream2_rdy)
  );

  //----------------------------------------------------------------------
  // Switch units
  //----------------------------------------------------------------------

  // Switch unit 0

  lab4_sys_NetRouterSwitchUnit#(44) sunit0
  (
    .clk          (clk),
    .reset        (reset),

    .istream0_msg (runit0_ostream0_msg),
    .istream0_val (runit0_ostream0_val),
    .istream0_rdy (runit0_ostream0_rdy),
    .istream1_msg (runit1_ostream0_msg),
    .istream1_val (runit1_ostream0_val),
    .istream1_rdy (runit1_ostream0_rdy),
    .istream2_msg (runit2_ostream0_msg),
    .istream2_val (runit2_ostream0_val),
    .istream2_rdy (runit2_ostream0_rdy),

    .ostream_msg  (ostream0_msg),
    .ostream_val  (ostream0_val),
    .ostream_rdy  (ostream0_rdy)
  );

  // Switch unit 1

  lab4_sys_NetRouterSwitchUnit#(44) sunit1
  (
    .clk          (clk),
    .reset        (reset),

    .istream0_msg (runit0_ostream1_msg),
    .istream0_val (runit0_ostream1_val),
    .istream0_rdy (runit0_ostream1_rdy),
    .istream1_msg (runit1_ostream1_msg),
    .istream1_val (runit1_ostream1_val),
    .istream1_rdy (runit1_ostream1_rdy),
    .istream2_msg (runit2_ostream1_msg),
    .istream2_val (runit2_ostream1_val),
    .istream2_rdy (runit2_ostream1_rdy),

    .ostream_msg  (ostream1_msg),
    .ostream_val  (ostream1_val),
    .ostream_rdy  (ostream1_rdy)
  );

  // Switch unit 2

  lab4_sys_NetRouterSwitchUnit#(44) sunit2
  (
    .clk          (clk),
    .reset        (reset),

    .istream0_msg (runit0_ostream2_msg),
    .istream0_val (runit0_ostream2_val),
    .istream0_rdy (runit0_ostream2_rdy),
    .istream1_msg (runit1_ostream2_msg),
    .istream1_val (runit1_ostream2_val),
    .istream1_rdy (runit1_ostream2_rdy),
    .istream2_msg (runit2_ostream2_msg),
    .istream2_val (runit2_ostream2_val),
    .istream2_rdy (runit2_ostream2_rdy),

    .ostream_msg  (ostream2_msg),
    .ostream_val  (ostream2_val),
    .ostream_rdy  (ostream2_rdy)
  );

  //----------------------------------------------------------------------
  // Line Tracing
  //----------------------------------------------------------------------

  `ifndef SYNTHESIS

  vc_NetMsgTrace#(p_msg_nbits) ostream0_trace
  (
    .clk   (clk),
    .reset (reset),
    .msg   (ostream0_msg),
    .val   (ostream0_val),
    .rdy   (ostream0_rdy)
  );

  vc_NetMsgTrace#(p_msg_nbits) ostream1_trace
  (
    .clk   (clk),
    .reset (reset),
    .msg   (ostream1_msg),
    .val   (ostream1_val),
    .rdy   (ostream1_rdy)
  );

  vc_NetMsgTrace#(p_msg_nbits) ostream2_trace
  (
    .clk   (clk),
    .reset (reset),
    .msg   (ostream2_msg),
    .val   (ostream2_val),
    .rdy   (ostream2_rdy)
  );

  logic [`VC_TRACE_NBITS-1:0] str;
  `VC_TRACE_BEGIN
  begin

    // Line tracing for input queues

    vc_trace.append_str( trace_str, "(" );

    case ( inq0_num_free_entries )
      4: vc_trace.append_str( trace_str, " " );
      3: vc_trace.append_str( trace_str, "." );
      2: vc_trace.append_str( trace_str, ":" );
      1: vc_trace.append_str( trace_str, "*" );
      0: vc_trace.append_str( trace_str, "#" );
    endcase

    case ( inq1_num_free_entries )
      4: vc_trace.append_str( trace_str, " " );
      3: vc_trace.append_str( trace_str, "." );
      2: vc_trace.append_str( trace_str, ":" );
      1: vc_trace.append_str( trace_str, "*" );
      0: vc_trace.append_str( trace_str, "#" );
    endcase

    case ( inq2_num_free_entries )
      4: vc_trace.append_str( trace_str, " " );
      3: vc_trace.append_str( trace_str, "." );
      2: vc_trace.append_str( trace_str, ":" );
      1: vc_trace.append_str( trace_str, "*" );
      0: vc_trace.append_str( trace_str, "#" );
    endcase

    vc_trace.append_str( trace_str, "|" );

    // Line tracing for switch units

    sunit0.line_trace( trace_str );
    sunit1.line_trace( trace_str );
    sunit2.line_trace( trace_str );

    vc_trace.append_str( trace_str, ")" );

    // Line tracing for output streams

    ostream0_trace.line_trace( trace_str );
    vc_trace.append_str( trace_str, "|" );
    ostream1_trace.line_trace( trace_str );
    vc_trace.append_str( trace_str, "|" );
    ostream2_trace.line_trace( trace_str );

  end
  `VC_TRACE_END

  `endif /* SYNTHESIS */

endmodule

`endif /* NET_ROUTER_V */
