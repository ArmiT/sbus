#include <stdio.h>
#include <stdlib.h>
#include "sbus.h"
#include "unity.h"
#include "mocks.h"

#ifdef UNIT_TEST

void test_sbus_init(void)
{   
    sbus_init();
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
    TEST_ASSERT_EQUAL(state.address, 0x00);
    TEST_ASSERT_EQUAL(state.length, 0x00);
    TEST_ASSERT_EQUAL(state.crc_msb, 0x00);
    TEST_ASSERT_EQUAL(state.crc_lsb, 0x00);
    TEST_ASSERT_EQUAL(state.data_head, 0x00);

    for(unsigned char i; i < SBUS_DATA_MAX_LENGTH;i++) {
        TEST_ASSERT_EQUAL(state.data[i], 0x00);
    }
}

void test_valid_start_byte(void)
{
    unsigned char byte = SBUS_START_BYTE;

    sbus_init();
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
    sbus_process(&byte, 0x00);
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_ADDRESS);

}

void test_invalid_start_byte(void)
{
    unsigned char byte = 0x01;

    sbus_init();
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
    sbus_process(&byte, 0x00);
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);

}

void test_process_address(void)
{   
    unsigned char i = 0;
    unsigned char packet[2] = {0xAA, 0xEE};

    sbus_init();
    for(i;i<2;i++) {
        sbus_process(&packet[i], 0x00);
    }
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_LENGTH);
    TEST_ASSERT_EQUAL(state.address, 0xEE);
}

void test_process_length(void) 
{   
    unsigned char i = 0;
    unsigned char packet[3] = {0xAA, 0xEE, 0x02};

    sbus_init();
    for(i;i<3;i++) {
        sbus_process(&packet[i], 0x00);
    }
    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_DATA);
    TEST_ASSERT_EQUAL(state.length, 0x02);
}

void test_process_data(void)
{   
    unsigned char i = 0;
    unsigned char packet[5] = {0xAA, 0xEE, 0x02, 0xE1, 0xE2};

    sbus_init();
    for(i;i<5;i++) {
        sbus_process(&packet[i], 0x00);
    }

    printf("%#010x; %#010x\n",state.data[0], 0xE1);

    TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_CRC_MSB);
    TEST_ASSERT_EQUAL(state.data[0], 0xE1);
    TEST_ASSERT_EQUAL(state.data[1], 0xE2);
    TEST_ASSERT_EQUAL(state.data[2], 0x00);
}
// void test_process_valid_start_byte(void)
// {   
//     unsigned char byte = 0xAA;

//     sbus_init();
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
//     process_start_byte(&byte, &state);
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_ADDRESS);
// }

// void test_process_invalid_start_byte(void)
// {
//     unsigned char byte = 0x01;
    
//     sbus_init();
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
//     process_start_byte(&byte, &state);
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
// }

// void test_process_address(void)
// {
//     unsigned char byte = 0x01;
//     sbus_init();
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
//     process_address(&byte, &state);
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_LENGTH);

// }

// void test_sbus_process_start(void)
// {   
//     unsigned char byte = 0xAA;

//     sbus_init();
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_START);
//     sbus_process(&byte, 0x00);
//     TEST_ASSERT_EQUAL(state.stage, STAGE_WAIT_ADDRESS);
// }

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_sbus_init);
    RUN_TEST(test_valid_start_byte);
    RUN_TEST(test_invalid_start_byte);
    RUN_TEST(test_process_address);
    RUN_TEST(test_process_length);
    //RUN_TEST(test_process_data);
    
    // RUN_TEST(test_process_valid_start_byte);
    // RUN_TEST(test_process_invalid_start_byte);
    // RUN_TEST(test_sbus_process_start);

    UNITY_END();
}

#endif