declare receiver interface {
  input p_reset;
  input m_clock;
  input data[4];
  input valid;
  input error;

  output mac[48], ip[32];

  func_out received;
  func_in getMAC : mac;
  func_in getIP  : ip;
  
  func_out error_detected;
}
