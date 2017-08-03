#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SELF_ADDRESS            0x01
#define DATA_MAX_LENGTH         10
#define START_BIT               0xAA
#define STOP_BIT                0x55

#define STAGE_WAIT_START        0x00
#define STAGE_WAIT_ADDRESS      0x01
#define STAGE_WAIT_LENGTH       0x02
#define STAGE_WAIT_DATA         0x03
#define STAGE_WAIT_CRC_MSB      0x04
#define STAGE_WAIT_CRC_LSB      0x05
#define STAGE_WAIT_STOP         0x06

typedef struct {
  unsigned char stage;
  unsigned char address;
  unsigned char length;
  unsigned char crc_msb;
  unsigned char crc_lsb;
  char data[DATA_MAX_LENGTH];
  unsigned char data_head;
} t_state;

t_state state;

void handle_packet(t_state *state) {
  printf("%#010x\n",state->stage);
}

void sbus_init()
{
  memset(&state, 0x00, sizeof(t_state)); // clear state
}

void sbus_process(unsigned char *data, void (*handler)(t_state *state)) 
{
      switch(state.stage) {
        case STAGE_WAIT_START:
          //if data not eql START_BIT -> garbage -> return
          // else state.stage = STAGE_WAIT_ADDRESS
          break;
        case STAGE_WAIT_ADDRESS:
          // state.address = data
          // state.stage = STAGE_WAIT_LENGTH
          break;
        case STAGE_WAIT_LENGTH:
          // state.length = data
          // state.stage = STAGE_WAIT_DATA
          break;
        case STAGE_WAIT_DATA:
          // if (state.data_head >= length-1) 
          // state.crc_msb = data
          // state.stage = STAGE_WAIT_CRC_LSB
          // else 
          // state.data[++data_head] = data
          break;
        case STAGE_WAIT_CRC_LSB:
          // stage.crc_lsb = data
          // state.stage = STAGE_WAIT_STOP
          break;
        case STAGE_WAIT_STOP:
          // if data not eql STOP_BIT -> invalid packet -> return
          // else state.process = STAGE_PROCESS
          break;
        default:
          break;
      }
      // t_state p = {
      //   .stage = STATE_WAIT_ADDRESS
      // };     
      //handler(&p);
}


// int main() 
// {

//   sbus_init();
  
// //while(1) {
//   // while(uart_is_empty());
//   //sbus_process(uart_get_char(), *handle_packet);
//   sbus_process("a", *handle_packet);
// //}  


//   //printf("rwar");

// 	return 0;
// }
