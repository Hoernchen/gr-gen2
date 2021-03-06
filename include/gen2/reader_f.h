/* -*- c++ -*- */

#ifndef INCLUDED_RFID_READER_F_H
#define INCLUDED_RFID_READER_F_H

#include <gnuradio/block.h>
#include <gnuradio/message.h>
#include <gnuradio/msg_queue.h>
#include "global_vars.h"
#include "api.h"

namespace gr {
	namespace rfid {
		
class GEN2_API reader_f : public gr::block {
  reader_f (int sample_rate);
  
  int my_Q;
  int d_sample_rate;

  float * d_one;
  float * d_zero;
  float * d_query_cmd;
  float * d_reader_framesync;
  float * d_qrep;
  float * d_nak;
  float * d_req_rn;
  float * d_read;
  float * d_count;
  int d_one_len, d_zero_len, d_query_len, d_reader_framesync_len, d_qrep_len, d_nak_len, d_req_rn_len, d_read_len, d_count_len;

  float * cw_buffer;
  float * zero_buffer;
  float d_us_per_xmit;
 
  gr::message::sptr tx_msg;
  gr::message::sptr d_ctrl_msg;
  gr::msg_queue::sptr out_q;
  gr::msg_queue::sptr d_ctrl_q;
  int d_msg_count;
  
  float collision_threshold;
  float Q_fp; 
  int d_num_empty_rounds; 
  int d_tags_read_in_cycle, d_slots_occupied;

  char last_handle[16];
  int which_handle ;

  //Gen 2 parameters
  char d_CMD[5];
  char d_DR[2];
  char d_M[3];
  char d_tr_ext[2];
  char d_sel[3];
  char d_session[3];
  char d_target[2];
  char d_Q[5];
  char d_CRC[6]; 


  gr::msg_queue::sptr log_q;
  enum {LOG_START_CYCLE, LOG_QUERY, LOG_ACK, LOG_QREP, LOG_NAK, LOG_REQ_RN, LOG_READ, LOG_RN16, LOG_EPC, LOG_HANDLE, LOG_DATA, LOG_EMPTY, LOG_COLLISION, LOG_OKAY, LOG_ERROR};

  public:
  
  typedef boost::shared_ptr<reader_f> sptr;
  static sptr make(int sample_rate);
  
  int general_work(int noutput_items, 
		   gr_vector_int &ninput_items,
		   gr_vector_const_void_star &input_items,
		   gr_vector_void_star &output_items);
  
  gr::msg_queue::sptr    ctrl_q() const {return d_ctrl_q;}
  gr::msg_queue::sptr get_log() const {return log_q;}

  private: 

  void gen_query_cmd();
  void gen_qrep_cmd();
  void gen_nak_cmd();
  void gen_req_rn_cmd();
  void gen_read_cmd(char * handle);
  void gen_count_cmd();

  void send_ack();
  void start_cycle();
  void send_query();
  void send_qrep();
  void send_nak();
  void send_req_rn();
  void send_read();

  bool send_another_query();
  void update_q(int slot_occupancy);

  int check_crc(char * bits, int num_bits);
  void set_num_samples_to_ungate();

  void forecast (int noutput_items, gr_vector_int &ninput_items_required); 
  void log_msg(int message, char * text, int error);
  
  
};

}
}


#endif
