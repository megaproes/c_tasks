#include <cmocka.h>
#include "001.c"

static void test_rotate_array_positive(void **state)
{
	(void)state; // Unused variable

	int arr1[] = {1, 2, 3, 4, 5};
	rotate_array(arr1, 5, 2);
	int expected1[] = {4, 5, 1, 2, 3};
	assert_memory_equal(arr1, expected1, sizeof(expected1));

	int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
	rotate_array(arr2, 8, 3);
	int expected2[] = {6, 7, 8, 1, 2, 3, 4, 5};
	assert_memory_equal(arr2, expected2, sizeof(expected2));
}

static void test_rotate_array_negative(void **state)
{
	(void)state; // Unused variable

	int arr1[] = {1, 2, 3, 4, 5};
	rotate_array(arr1, 5, -2);
	int expected1[] = {3, 4, 5, 1, 2};
	assert_memory_equal(arr1, expected1, sizeof(expected1));

	int arr2[] = {10, 20, 30, 40, 50};
	rotate_array(arr2, 5, -1);
	int expected2[] = {20, 30, 40, 50, 10};
	assert_memory_equal(arr2, expected2, sizeof(expected2));
}

static void test_rotate_array_large_n(void **state)
{
	(void)state; // Unused variable

	int arr[] = {1, 2, 3, 4, 5};
	rotate_array(arr, 5, 12); // Equivalent to rotating by 2 (12 % 5 = 2)
	int expected[] = {4, 5, 1, 2, 3};
	assert_memory_equal(arr, expected, sizeof(expected));
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_rotate_array_positive),
	    cmocka_unit_test(test_rotate_array_negative),
	    cmocka_unit_test(test_rotate_array_large_n),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
