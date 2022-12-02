#=========================================================================
# NetRouterRouteUnit_test
#=========================================================================

import pytest

from pymtl3 import *
from pymtl3.stdlib.test_utils import mk_test_case_table, run_sim
from pymtl3.stdlib.stream import StreamSourceFL, StreamSinkFL

from lab4_sys.NetMsg import mk_net_msg
from lab4_sys.NetRouterRouteUnit import NetRouterRouteUnit

#-------------------------------------------------------------------------
# Message Types
#-------------------------------------------------------------------------

NetMsgType = mk_net_msg( 32 )

#-------------------------------------------------------------------------
# TestHarness
#-------------------------------------------------------------------------

class TestHarness( Component ):

  def construct( s, router_id=0 ):

    # Instantiate models

    s.src   = StreamSourceFL( NetMsgType )
    s.runit = NetRouterRouteUnit( p_msg_nbits=44 )
    s.sinks = [ StreamSinkFL( NetMsgType ) for _ in range(3) ]

    # Connect

    s.runit.router_id  //= router_id
    s.src.ostream      //= s.runit.istream
    s.runit.ostream[0] //= s.sinks[0].istream
    s.runit.ostream[1] //= s.sinks[1].istream
    s.runit.ostream[2] //= s.sinks[2].istream

  def done( s ):
    return s.src.done() and s.sinks[0].done() and s.sinks[1].done() and s.sinks[2].done()

  def line_trace( s ):
    return s.src.line_trace()   + " > (" + \
           s.runit.line_trace() + ") > " + \
           s.sinks[0].line_trace() + "|" + \
           s.sinks[1].line_trace() + "|" + \
           s.sinks[2].line_trace()

#-------------------------------------------------------------------------
# test
#-------------------------------------------------------------------------

def test_basic( cmdline_opts ):

  th = TestHarness( router_id=0 )

  msgs = [
    #           src  dest opaq  payload
    NetMsgType( 0,   0,   0x10, 0x10101010 ),
    NetMsgType( 0,   1,   0x11, 0x11111111 ),
    NetMsgType( 0,   2,   0x12, 0x12121212 ),
  ]

  th.set_param("top.src.construct",      msgs=msgs  )
  th.set_param("top.sinks[0].construct", msgs=[ m for m in msgs if m.dest == 0 ] )
  th.set_param("top.sinks[1].construct", msgs=[ m for m in msgs if m.dest == 1 ] )
  th.set_param("top.sinks[2].construct", msgs=[ m for m in msgs if m.dest == 2 ] )

  th.elaborate()

  run_sim( th, cmdline_opts, duts=['runit'] )

#-------------------------------------------------------------------------
# Test Cases: Very Simple
#-------------------------------------------------------------------------

one = [
  #           src  dest opaq  payload
  NetMsgType( 0,   0,   0x10, 0x10101010 ),
]

three = [
  #           src  dest opaq  payload
  NetMsgType( 0,   0,   0x10, 0x10101010 ),
  NetMsgType( 0,   1,   0x11, 0x11111111 ),
  NetMsgType( 0,   2,   0x12, 0x12121212 ),
]

three_diff_src = [
  #           src  dest opaq  payload
  NetMsgType( 3,   0,   0x10, 0x10101010 ),
  NetMsgType( 2,   1,   0x11, 0x11111111 ),
  NetMsgType( 1,   2,   0x12, 0x12121212 ),
]

#-------------------------------------------------------------------------
# Test Cases: Stream to One Port
#-------------------------------------------------------------------------

stream_to_dest0 = []
for i in range(16):
  msg = NetMsgType( src=0, dest=0, opaque=i, payload=i )
  stream_to_dest0.append( msg )

stream_to_dest1 = []
for i in range(16):
  msg = NetMsgType( src=0, dest=1, opaque=i, payload=i )
  stream_to_dest1.append( msg )

stream_to_dest2 = []
for i in range(16):
  msg = NetMsgType( src=0, dest=2, opaque=i, payload=i )
  stream_to_dest2.append( msg )

#-------------------------------------------------------------------------
# Test Cases: Stream to All Ports
#-------------------------------------------------------------------------

stream_to_all = []
for i in range(16):
  m0 = NetMsgType( src=0, dest=0, opaque=0x00+i, payload=0x0000+i )
  m1 = NetMsgType( src=0, dest=1, opaque=0x40+i, payload=0x1000+i )
  m2 = NetMsgType( src=0, dest=2, opaque=0x80+i, payload=0x2000+i )
  stream_to_all.extend([m0, m1, m2])

#-------------------------------------------------------------------------
# Test Case Table
#-------------------------------------------------------------------------

test_case_table = mk_test_case_table([
  (                              "msgs          src_delay sink_delay delay_mode"),
  [ "one",                        one,                 0,  0,  'fixed'  ],
  [ "three",                      three,               0,  0,  'fixed'  ],
  [ "three_diff_src",             three_diff_src,      0,  0,  'fixed'  ],
  [ "stream_to_dest0",            stream_to_dest0,     0,  0,  'fixed'  ],
  [ "stream_to_dest1",            stream_to_dest1,     0,  0,  'fixed'  ],
  [ "stream_to_dest2",            stream_to_dest2,     0,  0,  'fixed'  ],
  [ "stream_to_all",              stream_to_all,       0,  0,  'fixed'  ],

  [ "stream_to_dest0_fixed_0x2",  stream_to_dest0,     0,  2,  'fixed'  ],
  [ "stream_to_dest0_fixed_2x0",  stream_to_dest0,     2,  0,  'fixed'  ],
  [ "stream_to_dest1_fixed_0x2",  stream_to_dest1,     0,  2,  'fixed'  ],
  [ "stream_to_dest1_fixed_2x0",  stream_to_dest1,     2,  0,  'fixed'  ],
  [ "stream_to_dest2_fixed_0x2",  stream_to_dest2,     0,  2,  'fixed'  ],
  [ "stream_to_dest2_fixed_2x0",  stream_to_dest2,     2,  0,  'fixed'  ],
  [ "stream_to_all_fixed_0x2",    stream_to_all,       0,  2,  'fixed'  ],
  [ "stream_to_all_fixed_2x0",    stream_to_all,       2,  0,  'fixed'  ],

  [ "stream_to_dest0_rand_delay", stream_to_dest0,     3, 20,  'random' ],
  [ "stream_to_dest1_rand_delay", stream_to_dest1,     3, 20,  'random' ],
  [ "stream_to_dest2_rand_delay", stream_to_dest2,     3, 20,  'random' ],
  [ "stream_to_all_rand_delay",   stream_to_all,       3, 20,  'random' ],
])

#-------------------------------------------------------------------------
# test
#-------------------------------------------------------------------------

@pytest.mark.parametrize( **test_case_table )
def test( test_params, cmdline_opts ):

  th = TestHarness( router_id=0 )

  th.set_param("top.src.construct",
    msgs                = test_params.msgs,
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.src_delay,
    interval_delay      = test_params.src_delay )

  th.set_param("top.sinks[0].construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 0 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.set_param("top.sinks[1].construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 1 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.set_param("top.sinks[2].construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 2 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.elaborate()

  run_sim( th, cmdline_opts, duts=['runit'] )

