#include <cmocka.h>
#include "007.c" // Your intToStr implementation

static void test_intToStr(void **state)
{
    // Test case 1: Positive number
    int num1 = 12345;
    char *result1 = intToStr(num1);
    assert_string_equal(result1, "12345");
    free(result1); // Free the allocated memory after the test

    // Test case 2: Negative number
    int num2 = -12345;
    char *result2 = intToStr(num2);
    assert_string_equal(result2, "-12345");
    free(result2);

    // Test case 3: Zero
    int num3 = 0;
    char *result3 = intToStr(num3);
    assert_string_equal(result3, "0");
    free(result3);

    // Test case 4: Large positive number
    int num4 = 987654321;
    char *result4 = intToStr(num4);
    assert_string_equal(result4, "987654321");
    free(result4);

    // Test case 5: Large negative number
    int num5 = -987654321;
    char *result5 = intToStr(num5);
    assert_string_equal(result5, "-987654321");
    free(result5);

    // Test case 6: Small negative number (-1)
    int num6 = -1;
    char *result6 = intToStr(num6);
    assert_string_equal(result6, "-1");
    free(result6);

    // Test case 7: Small positive number (1)
    int num7 = 1;
    char *result7 = intToStr(num7);
    assert_string_equal(result7, "1");
    free(result7);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_intToStr),
    };

    // Run the tests
    return cmocka_run_group_tests(tests, NULL, NULL);
}
