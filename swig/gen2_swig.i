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
%}


GR_SWIG_BLOCK_MAGIC(rfid, tag_decoder_f);

rfid_tag_decoder_f_sptr
rfid_make_tag_decoder_f();

class rfid_tag_decoder_f: public gr::block{
  rfid_tag_decoder_f();

public:
  ~rfid_tag_decoder_f();
  void set_ctrl_out(gr::msg_queue::sptr msgq) const;
};

GR_SWIG_BLOCK_MAGIC(rfid, reader_f);

rfid_reader_f_sptr
rfid_make_reader_f(int sample_rate);

class rfid_reader_f: public gr::block{
  rfid_reader_f(int sample_rate);

public:
  ~rfid_reader_f();
  gr::msg_queue::sptr    ctrl_q();
  gr::msg_queue::sptr get_log();
};

GR_SWIG_BLOCK_MAGIC(rfid, reader_decoder);

rfid_reader_decoder_sptr 
rfid_make_reader_decoder (float us_per_sample, float tari);


class rfid_reader_decoder: public gr::sync_block{
 
  rfid_reader_decoder (float us_per_sample, float tari);

public: 
  ~rfid_reader_decoder();
  gr::msg_queue::sptr get_log() const;

  
};

GR_SWIG_BLOCK_MAGIC(rfid, command_gate_cc);

rfid_command_gate_cc_sptr
rfid_make_command_gate_cc(int pw, int T1, int sample_rate);

class rfid_command_gate_cc: public gr::block{
  rfid_command_gate_cc(int pw, int T1, int sample_rate);

public:
  ~rfid_command_gate_cc();
  void set_ctrl_out(gr::msg_queue::sptr msgq) const;
};

GR_SWIG_BLOCK_MAGIC(rfid, clock_recovery_zc_ff);

rfid_clock_recovery_zc_ff_sptr 
rfid_make_clock_recovery_zc_ff(int samples_per_pulse, int interp_factor);

class rfid_clock_recovery_zc_ff: public gr::block{
  rfid_clock_recovery_zc_ff(int samples_per_pulse, int interp_factor);

public:
  ~rfid_clock_recovery_zc_ff();
  
};

GR_SWIG_BLOCK_MAGIC(rfid, center_ff);

rfid_center_ff_sptr 
rfid_make_center_ff(int samples_per_pulse);

class rfid_center_ff: public gr::block{
  rfid_center_ff(int samples_per_pulse);

public:
  ~rfid_center_ff();
  
};
