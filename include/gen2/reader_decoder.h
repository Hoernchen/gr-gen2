/* -*- c++ -*- */


#ifndef INCLUDED_RFID_READER_DECODER_H
#define INCLUDED_RFID_READER_DECODER_H

#include <gnuradio/sync_block.h>
#include <gnuradio/message.h>
#include <gnuradio/msg_queue.h>
#include "api.h"

namespace gr {
	namespace rfid {
		
		class GEN2_API reader_decoder : public gr::sync_block 
		{
		 
		 private:
		  reader_decoder (float us_per_sample, float tari);
		 
		  enum {BEGIN, DELIM_FOUND, TARI_FOUND, RTCAL_FOUND, DATA};
		  enum {READER_COMMAND, POWER_DOWN, START};

		  double d_us_per_sample;
		  int d_delim_width;          //Length of start delimiter, in samples
		  int d_max_tari, d_min_tari, d_tari, d_rtcal, d_trcal; //Samples
		  int d_state;                //Current state
		  float * d_window_samples;   //Array to hold samples for averaging amplitude
		  int d_window_length;        //Length of window
		  int d_window_index;         //Index to oldest sample
		  double d_avg_amp;           //Average amplitude over window
		  double d_min_amp_thresh;    //To filter out nearby readers
		  double d_thresh;            //Amplitude threshold for detecing edges
		  int d_high_count, d_low_count, d_command_count, d_interarrival_count; //Sample counters
		  bool neg_edge_found;        //True if found negative edge for bit
		  int d_pivot;                // RTCal / 2. Determines data-0, data-1

		  char d_bits[512];
		  int d_len_bits;
		  

		 

		 
		  void advance_decoder(int next_state);
		  bool is_negative_edge(float sample);
		  bool is_positive_edge(float sample);
		  void log_event(int event, int lag_samples);
		 
		 public:
		  typedef boost::shared_ptr<reader_decoder> sptr;
		  static sptr make(float us_per_sample, float tari);
				  
		  ~reader_decoder();
		  gr::msg_queue::sptr log_q;
		  gr::msg_queue::sptr get_log() const {return log_q;}
		  int work(int noutput_items, 
			   gr_vector_const_void_star &input_items,
			   gr_vector_void_star &output_items);

		};
	}
}
#endif

