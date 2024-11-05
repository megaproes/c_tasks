// substring_test.c
#include <cmocka.h>
#include <string.h>
#include "002.c"

// Test cases to test the findString function.
static void test_findString(void **state)
{
	// Basic substring match
	assert_int_equal(findString("a chatterbox", "hat"), 3);

	// Substring not found
	assert_int_equal(findString("a chatterbox", "sadas"), -1);

	// Match at the beginning of the string
	assert_int_equal(findString("chatterbox", "chat"), 0);

	// Match at the end of the string
	assert_int_equal(findString("chatterbox", "box"), 7);

	// Full string match
	assert_int_equal(findString("hello", "hello"), 0);

	// Empty substring
	assert_int_equal(findString("hello", ""), -1);

	// Substring longer than main string
	assert_int_equal(findString("hi", "hello"), -1);

	// Empty source string
	assert_int_equal(findString("", "hello"), -1);

	// Empty source string and empty substring
	assert_int_equal(findString("", ""), -1);

	// Multiple occurrences, should return the first occurrence
	assert_int_equal(findString("banana", "ana"), 1);

	// Case-sensitive check (doesn't match)
	assert_int_equal(findString("Hello", "hello"), -1);

	// Case-sensitive check (matches)
	assert_int_equal(findString("Hello", "Hell"), 0);

	// Single character match
	assert_int_equal(findString("abcdef", "d"), 3);

	// Single character not in string
	assert_int_equal(findString("abcdef", "z"), -1);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_findString),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}