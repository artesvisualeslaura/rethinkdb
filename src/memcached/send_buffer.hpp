struct send_buffer_callback_t {
    virtual void on_send_buffer_flush() = 0;
    virtual void on_send_buffer_socket_closed() = 0;
};

struct send_buffer_t :
    public net_conn_write_external_callback_t
{
public:
    send_buffer_t(net_conn_t *conn);
    void write(size_t bytes, const char *buffer);
    void flush(send_buffer_callback_t *cb);

private:
    std::vector<char> buffer;
    void on_net_conn_write_external();
    void on_net_conn_close();
};
