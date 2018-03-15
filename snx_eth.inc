declare snx_eth interface {
    input p_reset;
    input m_clock;

    input data[4], valid, error;

    output ledo[8];
    output sip[32]; 

    func_in getled() : ledo;
    func_out received(); 
    func_in getSIP() : sip;
}
