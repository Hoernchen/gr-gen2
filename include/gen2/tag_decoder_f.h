/* -*- c++ -*- */


#ifndef INCLUDED_RFID_TAG_DECODER_F_H
#define INCLUDED_RFID_TAG_DECODER_F_H

#include <gnuradio/block.h>
#include "global_vars.h"
#include <gnuradio/message.h>
#include <gnuradio/msg_queue.h>
#include "api.h"

namespace gr {
	namespace rfid {

class GEN2_API tag_decoder_f : public gr::block 
{
 
 private:
  tag_decoder_f ();
 
  

  //std::vector<float>	d_preamble_cor_vec;
  int                   d_preamble_offset;
  int			d_one_vlen;
  char *                d_tag_bit_vector;
  int                   d_skip_count;
  int                   d_samples_since_reset;
  int                   d_preamble_miss_threshold;
  int                   d_last_score;
  int                   d_samples_processed;
 
  gr::msg_queue::sptr	d_ctrl_out;  //Pipe control messages to reader block.

  void forecast (int noutput_items, gr_vector_int &ninput_items_required); 
 
 public:
  typedef boost::shared_ptr<tag_decoder_f> sptr;
  static sptr make();
		  
  ~tag_decoder_f();
  
  int general_work(int noutput_items, 
		   gr_vector_int &ninput_items,
		   gr_vector_const_void_star &input_items,
		   gr_vector_void_star &output_items);

  void	set_ctrl_out(const gr::msg_queue::sptr msgq) { d_ctrl_out = msgq; }

};
}
}
#endif

