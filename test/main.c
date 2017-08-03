#include "../lib/sbus/src/sbus.h"
#include "unity.h"

#ifdef UNIT_TEST

void test_f(void)
{
    TEST_ASSERT_EQUAL(2, 2);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_f);

    UNITY_END();
}

#endif