#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sbus.h>

#define SBUS_DATA_MAX_LEN 10

void handle_packet(sbus_connection_t *state) {
    //printf("%#010x\n",state->stage);
    // do something
    // sbus_send(&data);  
}

int main(void) 
{   
    unsigned char byte;
    unsigned char sbus_buffer[SBUS_DATA_MAX_LEN];    
    sbus_connection_t conn;

    conn.buffer = sbus_buffer;
    sbus_init(&conn);

    while(1) {
        //if(stream_data_is_available()) {
        //    byte = stream_get_data();
            sbus_process(&byte, *handle_packet);
        //}
    }
}

main();