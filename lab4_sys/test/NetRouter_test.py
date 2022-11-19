#=========================================================================
# NetRouter_test
#=========================================================================

import pytest

from pymtl3 import *
from pymtl3.stdlib.test_utils import mk_test_case_table, run_sim
from pymtl3.stdlib.stream import StreamSourceFL, StreamSinkFL

from lab4_sys.NetMsg import mk_net_msg
from lab4_sys.NetRouter import NetRouter

#-------------------------------------------------------------------------
# Message Types
#-------------------------------------------------------------------------

NetMsgType = mk_net_msg( 32 )

#-------------------------------------------------------------------------
# TestHarness
#-------------------------------------------------------------------------

class TestHarness( Component ):

  def construct( s ):

    # Instantiate models

    s.src0  = StreamSourceFL( NetMsgType )
    s.src1  = StreamSourceFL( NetMsgType )
    s.src2  = StreamSourceFL( NetMsgType )

    s.router = NetRouter( 44 )

    s.sink0 = StreamSinkFL  ( NetMsgType )
    s.sink1 = StreamSinkFL  ( NetMsgType )
    s.sink2 = StreamSinkFL  ( NetMsgType )

    # Connect

    s.src0.ostream    //= s.router.istream0
    s.src1.ostream    //= s.router.istream1
    s.src2.ostream    //= s.router.istream2

    s.router.ostream0 //= s.sink0.istream
    s.router.ostream1 //= s.sink1.istream
    s.router.ostream2 //= s.sink2.istream

  def done( s ):
    return s.src0.done()  and s.src1.done()  and s.src2.done() and \
           s.sink0.done() and s.sink1.done() and s.sink2.done()

  def line_trace( s ):
    return s.src0.line_trace()   + "|" + \
           s.src1.line_trace()   + "|" + \
           s.src2.line_trace()   + " > (" + \
           s.router.line_trace() + ") > " + \
           s.sink0.line_trace()  + "|" + \
           s.sink1.line_trace()  + "|" + \
           s.sink2.line_trace()

#-------------------------------------------------------------------------
# test
#-------------------------------------------------------------------------

def test_basic( cmdline_opts ):

  th = TestHarness()

  msgs = [
    #           dest src  opaq  payload
    NetMsgType( 0,   0,   0x10, 0x10101010 ),
    NetMsgType( 1,   1,   0x11, 0x11111111 ),
    NetMsgType( 2,   2,   0x12, 0x12121212 ),
  ]

  th.set_param("top.src.construct",   msgs=msgs  )
  th.set_param("top.src0.construct",  msgs=[ m for m in msgs if m.src  == 0 ] )
  th.set_param("top.src1.construct",  msgs=[ m for m in msgs if m.src  == 1 ] )
  th.set_param("top.src2.construct",  msgs=[ m for m in msgs if m.src  == 2 ] )
  th.set_param("top.sink0.construct", msgs=[ m for m in msgs if m.dest == 0 ] )
  th.set_param("top.sink1.construct", msgs=[ m for m in msgs if m.dest == 1 ] )
  th.set_param("top.sink2.construct", msgs=[ m for m in msgs if m.dest == 2 ] )

  th.elaborate()

  run_sim( th, cmdline_opts, duts=['router'] )

#-------------------------------------------------------------------------
# Test Cases: Very Simple
#-------------------------------------------------------------------------

one = [
  #           dest src  opaq  payload
  NetMsgType( 0,   0,   0x10, 0x10101010 ),
]

rotate0 = [
  #           dest src  opaq  payload
  NetMsgType( 0,   0,   0x10, 0x10101010 ),
  NetMsgType( 1,   1,   0x11, 0x11111111 ),
  NetMsgType( 2,   2,   0x12, 0x12121212 ),
]

rotate1 = [
  #           dest src  opaq  payload
  NetMsgType( 1,   0,   0x10, 0x10101010 ),
  NetMsgType( 2,   1,   0x11, 0x11111111 ),
  NetMsgType( 0,   2,   0x12, 0x12121212 ),
]

rotate2 = [
  #           dest src  opaq  payload
  NetMsgType( 2,   0,   0x10, 0x10101010 ),
  NetMsgType( 0,   1,   0x11, 0x11111111 ),
  NetMsgType( 1,   2,   0x12, 0x12121212 ),
]

all_to_dest0 = [
  #           dest src  opaq  payload
  NetMsgType( 0,   0,   0x10, 0x10101010 ),
  NetMsgType( 0,   1,   0x11, 0x11111111 ),
  NetMsgType( 0,   2,   0x12, 0x12121212 ),
]

all_to_dest1 = [
  #           dest src  opaq  payload
  NetMsgType( 1,   0,   0x10, 0x10101010 ),
  NetMsgType( 1,   1,   0x11, 0x11111111 ),
  NetMsgType( 1,   2,   0x12, 0x12121212 ),
]

all_to_dest2 = [
  #           dest src  opaq  payload
  NetMsgType( 2,   0,   0x10, 0x10101010 ),
  NetMsgType( 2,   1,   0x11, 0x11111111 ),
  NetMsgType( 2,   2,   0x12, 0x12121212 ),
]

#-------------------------------------------------------------------------
# Test Cases: Stream to One Port
#-------------------------------------------------------------------------

stream_to_dest0 = []
for i in range(16):
  msg = NetMsgType( dest=0, src=0, opaque=i, payload=i )
  stream_to_dest0.append( msg )

stream_to_dest1 = []
for i in range(16):
  msg = NetMsgType( dest=1, src=0, opaque=i, payload=i )
  stream_to_dest1.append( msg )

stream_to_dest2 = []
for i in range(16):
  msg = NetMsgType( dest=2, src=0, opaque=i, payload=i )
  stream_to_dest2.append( msg )

#-------------------------------------------------------------------------
# Test Cases: Stream All to Each Port
#-------------------------------------------------------------------------

stream_all_to_dest0 = []

for i in range(16):
  msg = NetMsgType( dest=0, src=0, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest0.append(msg)

for i in range(16):
  msg = NetMsgType( dest=0, src=1, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest0.append(msg)

for i in range(16):
  msg = NetMsgType( dest=0, src=2, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest0.append(msg)

stream_all_to_dest1 = []

for i in range(16):
  msg = NetMsgType( dest=1, src=0, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest1.append(msg)

for i in range(16):
  msg = NetMsgType( dest=1, src=1, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest1.append(msg)

for i in range(16):
  msg = NetMsgType( dest=1, src=2, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest1.append(msg)

stream_all_to_dest2 = []

for i in range(16):
  msg = NetMsgType( dest=2, src=0, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest2.append(msg)

for i in range(16):
  msg = NetMsgType( dest=2, src=1, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest2.append(msg)

for i in range(16):
  msg = NetMsgType( dest=2, src=2, opaque=0x00+i, payload=0x0000+i )
  stream_all_to_dest2.append(msg)

#-------------------------------------------------------------------------
# Test Cases: Stream All to All Ports
#-------------------------------------------------------------------------

stream_all_to_all = []
stream_all_to_all.extend( stream_all_to_dest0 )
stream_all_to_all.extend( stream_all_to_dest1 )
stream_all_to_all.extend( stream_all_to_dest2 )

#-------------------------------------------------------------------------
# Test Case Table
#-------------------------------------------------------------------------

test_case_table = mk_test_case_table([
  (                                  "msgs          src_delay sink_delay delay_mode"),
  [ "one",                            one,                 0,  0,  'fixed'  ],
  [ "rotate0",                        rotate0,             0,  0,  'fixed'  ],
  [ "rotate1",                        rotate1,             0,  0,  'fixed'  ],
  [ "rotate2",                        rotate2,             0,  0,  'fixed'  ],
  [ "all_to_dest0",                   all_to_dest0,        0,  0,  'fixed'  ],
  [ "all_to_dest1",                   all_to_dest1,        0,  0,  'fixed'  ],
  [ "all_to_dest2",                   all_to_dest2,        0,  0,  'fixed'  ],
  [ "stream_to_dest0",                stream_to_dest0,     0,  0,  'fixed'  ],
  [ "stream_to_dest1",                stream_to_dest1,     0,  0,  'fixed'  ],
  [ "stream_to_dest2",                stream_to_dest2,     0,  0,  'fixed'  ],
  [ "stream_all_to_dest0",            stream_all_to_dest0, 0,  0,  'fixed'  ],
  [ "stream_all_to_dest1",            stream_all_to_dest1, 0,  0,  'fixed'  ],
  [ "stream_all_to_dest2",            stream_all_to_dest2, 0,  0,  'fixed'  ],
  [ "stream_all_to_all",              stream_all_to_all,   0,  0,  'fixed'  ],

  [ "stream_to_dest0_fixed_2x0",      stream_to_dest0,     2,  0,  'fixed'  ],
  [ "stream_to_dest1_fixed_2x0",      stream_to_dest1,     2,  0,  'fixed'  ],
  [ "stream_to_dest2_fixed_2x0",      stream_to_dest2,     2,  0,  'fixed'  ],

  [ "stream_all_to_dest0_fixed_0x2",  stream_all_to_dest0, 0,  2,  'fixed'  ],
  [ "stream_all_to_dest1_fixed_0x2",  stream_all_to_dest1, 0,  2,  'fixed'  ],
  [ "stream_all_to_dest2_fixed_0x2",  stream_all_to_dest2, 0,  2,  'fixed'  ],
  [ "stream_all_to_all_fixed_0x2",    stream_all_to_all,   0,  2,  'fixed'  ],

  [ "stream_all_to_dest0_rand_delay", stream_all_to_dest0, 0, 20,  'random' ],
  [ "stream_all_to_dest1_rand_delay", stream_all_to_dest1, 0, 20,  'random' ],
  [ "stream_all_to_dest2_rand_delay", stream_all_to_dest2, 0, 20,  'random' ],
  [ "stream_all_to_all_rand_delay",   stream_all_to_all,   0, 20,  'random' ],
])

#-------------------------------------------------------------------------
# test
#-------------------------------------------------------------------------

@pytest.mark.parametrize( **test_case_table )
def test_basic( test_params, cmdline_opts ):

  th = TestHarness()

  th.set_param("top.src0.construct",
    msgs                = [ m for m in test_params.msgs if m.src == 0 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.src_delay,
    interval_delay      = test_params.src_delay )

  th.set_param("top.src1.construct",
    msgs                = [ m for m in test_params.msgs if m.src == 1 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.src_delay,
    interval_delay      = test_params.src_delay )

  th.set_param("top.src2.construct",
    msgs                = [ m for m in test_params.msgs if m.src == 2 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.src_delay,
    interval_delay      = test_params.src_delay )

  th.set_param("top.sink0.construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 0 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.set_param("top.sink1.construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 1 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.set_param("top.sink2.construct",
    msgs                = [ m for m in test_params.msgs if m.dest == 2 ],
    interval_delay_mode = test_params.delay_mode,
    initial_delay       = test_params.sink_delay,
    interval_delay      = test_params.sink_delay )

  th.elaborate()

  run_sim( th, cmdline_opts, duts=['router'] )

