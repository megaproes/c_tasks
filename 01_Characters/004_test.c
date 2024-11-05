#include <cmocka.h>
#include <string.h>
#include "004.c"
#include <cmocka.h>

static void test_strToInt(void **state)
{
	// Basic positive number
	assert_int_equal(strToInt("123"), 123);

	// Negative number
	assert_int_equal(strToInt("-456"), -456);

	// Zero
	assert_int_equal(strToInt("0"), 0);

	// Single digit positive number
	assert_int_equal(strToInt("9"), 9);

	// Single digit negative number
	assert_int_equal(strToInt("-7"), -7);

	// Large positive number
	assert_int_equal(strToInt("987654321"), 987654321);

	// Large negative number
	assert_int_equal(strToInt("-987654321"), -987654321);

	// Leading zeros
	assert_int_equal(strToInt("000123"), 123);

	// Negative with leading zeros
	assert_int_equal(strToInt("-000123"), -123);

	// Non-numeric characters after digits (should only consider valid prefix)
	assert_int_equal(strToInt("123abc"), 123);

	// Non-numeric characters at the start (should result in 0)
	assert_int_equal(strToInt("abc123"), 0);

	// Empty string (should return 0)
	assert_int_equal(strToInt(""), 0);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_strToInt),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

