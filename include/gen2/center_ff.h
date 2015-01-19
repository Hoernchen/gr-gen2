/* -*- c++ -*- */

#ifndef INCLUDED_rfid_center_ff_H
#define INCLUDED_rfid_center_ff_H

#include <gnuradio/sync_block.h>
#include "api.h"

namespace gr {
	namespace rfid {
		class GEN2_API center_ff : public gr::sync_block
		{  
		  center_ff(int samples_per_pulse);

		  public:
		  typedef boost::shared_ptr<center_ff> sptr;
		  static sptr make(int samples=1);
		  
		  ~center_ff();
		  int work(int noutput_items,
			   gr_vector_const_void_star &input_items,
			   gr_vector_void_star &output_items);
	  

		private:
		  float * d_window_samples;   //Array to hold samples for averaging amplitude
		  int d_window_length;        //Length of window
		  int d_window_index;         //Index to oldest sample
		  double d_avg_amp;           //Average amplitude over window
		  int d_samples_per_pulse;
 

		};
	}
}
#endif /* INCLUDED_rfid_center_ff_H*/
