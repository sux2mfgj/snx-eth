declare arp_receiver interface {
  input p_reset;
  input m_clock;
  input data[4];
  input valid;
  input error;

  output s_mac[48], s_ip[32];
  output d_mac[48], d_ip[32];

  func_in start;
  func_out received;
  func_in getSMAC : s_mac;
  func_in getSIP  : s_ip;
  func_in getDMAC : d_mac;
  func_in getDIP  : d_ip;
  
  func_out error_detected;
}
