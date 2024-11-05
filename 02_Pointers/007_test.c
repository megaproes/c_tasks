#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "007.c"

// Test cases for dynamicArray()
static void test_dynamicArray_positive_size(void **state)
{
	int n = 5;
	int *arr = dynamicArray(n);
	assert_non_null(arr);

	// Check that elements are correctly initialized
	for (int i = 0; i < n; i++)
	{
		assert_int_equal(arr[i], 0);
	}

	free(arr);
}

static void test_dynamicArray_zero_size(void **state)
{
	int n = 0;
	int *arr = dynamicArray(n);

	// Expect either NULL or a valid pointer that shouldn't be used
	assert_null(arr);
}

static void test_dynamicArray_negative_size(void **state)
{
	int n = -1;
	int *arr = dynamicArray(n);

	// Expect NULL for invalid size input
	assert_null(arr);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_dynamicArray_positive_size),
	    cmocka_unit_test(test_dynamicArray_zero_size),
	    cmocka_unit_test(test_dynamicArray_negative_size),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
