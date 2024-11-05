#include <cmocka.h>
#include <string.h>
#include "003.c"
static void test_insertString(void **state)
{
	char result[100] = {0}; // Initialize the array

	// Test case 1: Insert string into the middle of a valid string
	strcpy(result, "the wrong son");
	insertString(result, "per", 10);
	assert_string_equal(result, "the wrong person");

	// Test case 2: Insert string at the beginning of the source string
	strcpy(result, "world");
	insertString(result, "hello ", 0);
	assert_string_equal(result, "hello world");

	// Test case 3: Insert string at the end of the source string
	strcpy(result, "hello");
	insertString(result, " world", 5);
	assert_string_equal(result, "hello world");

	// Test case 4: Insert string beyond the end of the source string (append)
	strcpy(result, "hey");
	insertString(result, "noob", 50);		// Out-of-bounds case
	assert_string_equal(result, "heynoob"); // Should append "noob" at the end

	// Test case 5: Insert empty string (should not change the source)
	strcpy(result, "hello");
	insertString(result, "", 3);
	assert_string_equal(result, "hello");

	// Test case 6: Insert into an empty source string
	strcpy(result, "");
	insertString(result, "new", 0);
	assert_string_equal(result, "new");

	// Test case 7: Insert at position 0 in an empty string (empty string with non-zero position)
	strcpy(result, "");
	insertString(result, "start", 0);
	assert_string_equal(result, "start");

	// Test case 8: Insert at a negative position (invalid case)
	strcpy(result, "invalid");
	insertString(result, "start", -1); // Negative positions should probably do nothing
	assert_string_equal(result, "invalid");
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_insertString),
	};

	// Run the tests
	return cmocka_run_group_tests(tests, NULL, NULL);
}
