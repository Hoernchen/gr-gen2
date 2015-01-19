/* -*- c++ -*- */

#ifndef INCLUDED_rfid_clock_recovery_zc_ff_H
#define INCLUDED_rfid_clock_recovery_zc_ff_H

#include <gnuradio/block.h>
#include "api.h"

namespace gr {
	namespace rfid {
class gri_mmse_fir_interpolator;

		class GEN2_API clock_recovery_zc_ff : public gr::block
		{  
		  clock_recovery_zc_ff(int samples_per_pulse, int interp_factor);

		  public:
		  typedef boost::shared_ptr<clock_recovery_zc_ff> sptr;
		  static sptr make(int samples_per_pulse, int interp_factor);
		  
		  ~clock_recovery_zc_ff();
		  
		  private:
		  int general_work(int noutput_items,
			   gr_vector_int &ninput_items,
			   gr_vector_const_void_star &input_items,
			   gr_vector_void_star &output_items);

		  void forecast (int noutput_items, gr_vector_int &ninput_items_required); 


		  float d_nominal_sp_pulse;
		  float d_samples_per_pulse;
		  float d_last_zc_count;
		  bool d_last_was_pos;
		  float d_max_drift;
		  float d_alpha;
		  int d_interp_factor; //Kill this.
		 

		};
	}
}
#endif /* INCLUDED_rfid_clock_recovery_zc_ff_H*/
