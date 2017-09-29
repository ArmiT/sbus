#include <stdio.h>
#include <string.h>
#include "sbus.h"
#ifdef UNIT_TEST
#include <stdlib.h>
#endif

void handle_packet(char *data) {
  //printf("%#010x\n",state->stage);

}

void sbus_init(sbus_state_t *state)
{
  memset(state, 0x00, sizeof(sbus_state_t));
}

// void process_start_byte(unsigned char *byte, t_state *state)
// {   
//     if(*byte == SBUS_START_BYTE) {
            
//         state->stage = STAGE_WAIT_ADDRESS;
//     }
//     return;
// }

// void sbus_process(unsigned char *data, void (*handler)(char *data)) 
// {
//       switch(state.stage) {

//         case STAGE_WAIT_START:
//             // process_start_byte(data, &state);
//             if(*data == SBUS_START_BYTE) {
//                 state.stage = STAGE_WAIT_ADDRESS;
//             }
//             break;

//         case STAGE_WAIT_ADDRESS:
//             state.address = *data;
//             state.stage = STAGE_WAIT_LENGTH;
//             break;

//         case STAGE_WAIT_LENGTH:
//             state.length = *data;
//             state.stage = STAGE_WAIT_DATA;
//             break;

//         case STAGE_WAIT_DATA:
//           // if (state.data_head >= length-1) 
//           // state.crc_msb = data
//           // state.stage = STAGE_WAIT_CRC_LSB
//           // else 
//           // state.data[++data_head] = data
//             state.data[0] = 0xE1;
//             state.data[1] = 0xE2;
//             state.stage = STAGE_WAIT_CRC_MSB;
//           break;

//         case STAGE_WAIT_CRC_LSB:
//             state.crc_lsb = *data;
//             state.stage = STAGE_WAIT_STOP;
//             break;

//         case STAGE_WAIT_STOP:
            
//             // if(data == SBUS_STOP_BYTE) {
//             //     state.stage = STAGE_PROCESS;
//             // } else {
//             //     state.error = ERR_INTEGRITY;
//             // }
//             break;

//         default:
//           break;
//       }
//       // t_state p = {
//       //   .stage = STATE_WAIT_ADDRESS
//       // };     
//       //handler(&p);
// }


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