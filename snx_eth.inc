declare snx_eth interface {
    input p_reset;
    input m_clock;

    input data[4], valid, error;

    output ledo[8];

    func_in getled() : ledo;
}
