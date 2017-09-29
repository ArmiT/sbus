char received_data[3];

void on_receive(char *data)
{
    received_data = data;
}

void on_transmit(void)
{
    // on successful transmit
}