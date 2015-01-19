/* -*- c++ -*- */

#define GEN2_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "gen2_swig_doc.i"

%{
#include "gen2/clock_recovery_zc_ff.h"
#include "gen2/reader_decoder.h"
#include "gen2/center_ff.h"
#include "gen2/tag_decoder_f.h"
#include "gen2/command_gate_cc.h"
#include "gen2/reader_f.h"
#include "gen2/test.h"
%}


%include "gen2/tag_decoder_f.h"
GR_SWIG_BLOCK_MAGIC2(rfid, tag_decoder_f);

%include "gen2/reader_f.h"
GR_SWIG_BLOCK_MAGIC2(rfid, reader_f);

%include "gen2/reader_decoder.h"
GR_SWIG_BLOCK_MAGIC2(rfid, reader_decoder);

%include "gen2/command_gate_cc.h"
GR_SWIG_BLOCK_MAGIC2(rfid, command_gate_cc);

%include "gen2/clock_recovery_zc_ff.h"
GR_SWIG_BLOCK_MAGIC2(rfid, clock_recovery_zc_ff);

%include "gen2/center_ff.h"
GR_SWIG_BLOCK_MAGIC2(rfid, center_ff);

%include "gen2/test.h"
GR_SWIG_BLOCK_MAGIC2(gen2, test);
