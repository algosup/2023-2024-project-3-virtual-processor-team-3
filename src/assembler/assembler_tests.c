#include "test-framework/unity.h"
#include "assembler.h"
#include "test-framework/unity_internals.h"

void setUp(void)
{

}

void tearDown(void)
{

}

// Function to test the reading of the file
static void testRead(void)
{
    // TEST_IGNORE();
    TEST_ASSERT_EQUAL_INT16(1, read("asmTest.txt"));

}

int main (void)
{
        UNITY_BEGIN();
        RUN_TEST(testRead);
        return UNITY_END();
}
