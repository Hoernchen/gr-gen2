/* -*- c++ -*- */


#ifndef INCLUDED_RFID_COMMAND_GATE_CC_H
#define INCLUDED_RFID_COMMAND_GATE_CC_H

#include <gnuradio/block.h>
#include <gnuradio/message.h>
#include <gnuradio/msg_queue.h>
#include "api.h"

#ifndef READER_VARS
#include "global_vars.h"
#endif

namespace gr {
	namespace rfid {
class GEN2_API command_gate_cc : public gr::block 
{
 
 private:
  command_gate_cc (int pw, int T1, int sample_rate);
 
  float                   d_us_per_rcv;
  int	                d_pw;  //Reader pulsewidth in us
  int                   d_T1;  //T1 value according to spec
  int			d_sample_rate;
  int                   d_pass_count;
  int                   d_pw_num_samples, d_T1_num_samples;
  double                d_max_rssi, d_min_rssi, d_avg_rssi, d_std_dev_rssi;
  int                   d_sample_count;
  int                   d_num_pulses;
  
 
  #define AVG_WIN 1500.0f // Window to average amplitude over, in us
  #define THRESH_FRACTION 0.75f //Percent of avg amplitude to detect edges
  #define MIN_AMP_THRESH 0.0d     //Eventually, expose as user parameter
  float * d_window_samples;   //Array to hold samples for averaging amplitude
  int d_window_length;        //Length of window
  int d_window_index;         //Index to oldest sample
  double d_avg_amp;           //Average amplitude over window
  bool neg_edge_found;        //True if found negative edge for bit
  double d_thresh;            //Amplitude threshold for detecing edges
  double d_min_amp_thresh;    //To filter out nearby readers

  gr::msg_queue::sptr	d_ctrl_out;  //Pipe control messages to reader block.

  void forecast (int noutput_items, gr_vector_int &ninput_items_required);
  bool is_negative_edge(float sample);
  bool is_positive_edge(float sample);
  void calc_signal_stats(float * buffer, int len, double * max, double * min, double* avg, double * std_dev );
  


  
 
 public:
 typedef boost::shared_ptr<command_gate_cc> sptr;
 static sptr make(int pw, int T1, int sample_rate);
		  
  ~command_gate_cc();
    
  int general_work(int noutput_items, 
		   gr_vector_int &ninput_items,
		   gr_vector_const_void_star &input_items,
		   gr_vector_void_star &output_items);

  void	set_ctrl_out(const gr::msg_queue::sptr msgq) { d_ctrl_out = msgq; }

};
}
}

#endif

