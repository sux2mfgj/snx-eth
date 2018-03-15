declare arp_receiver interface {
  input p_reset;
  input m_clock;
  input data[4];
  input valid;
  input error;

  output mac[48], ip[32];

  func_in start;
  func_out received;
  func_in getSMAC : mac;
  func_in getSIP  : ip;
  func_in getDMAC : mac;
  func_in getDIP  : ip;
  
  func_out error_detected;
}
