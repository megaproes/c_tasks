#include <cmocka.h>
#include <string.h>
#include "005.c"
static void test_strToFloat(void **state)
{
    // Test case 1: Negative float
    char str1[] = "-867.6921";
    assert_float_equal(strToFloat(str1), -867.6921, 0.0001);

    // Test case 2: Positive float
    char str2[] = "123.456";
    assert_float_equal(strToFloat(str2), 123.456, 0.0001);

    // Test case 3: Integer
    char str3[] = "500";
    assert_float_equal(strToFloat(str3), 500.0, 0.0001);

    // Test case 4: Negative integer
    char str4[] = "-500";
    assert_float_equal(strToFloat(str4), -500.0, 0.0001);

    // Test case 5: Zero
    char str5[] = "0.0";
    assert_float_equal(strToFloat(str5), 0.0, 0.0001);

    // Test case 6: Small decimal value
    char str6[] = "0.00123";
    assert_float_equal(strToFloat(str6), 0.00123, 0.0001);

    // Test case 7: Large value
    char str7[] = "123456789.987654321";
    assert_float_equal(strToFloat(str7), 123456789.987654321, 0.0001);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_strToFloat),
	};

	// Run the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
