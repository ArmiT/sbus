#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#ifndef SBUS_H_

#define SBUS_SELF_ADDRESS       0x01
#define SBUS_DATA_MAX_LENGTH    10
#define SBUS_PACKET_LENGTH      SBUS_DATA_MAX_LENGTH + 6;
#define SBUS_START_BYTE         0xAA
#define SBUS_STOP_BYTE          0x55

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
  char data[SBUS_DATA_MAX_LENGTH];
  unsigned char data_head;
} t_state;

t_state state;

// initializes sbus processor
// clears state
void sbus_init(void);

// process received byte as part of packet
void sbus_process(unsigned char *data, void (*handler)(char *data));

#ifdef UNIT_TEST
// process start byte
void process_start_byte(unsigned char *byte, t_state *state);
#endif

#endif
