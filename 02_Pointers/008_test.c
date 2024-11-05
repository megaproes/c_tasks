#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "008.c"

// Test cases for resizeArray()
static void test_resizeArray_increase_size(void **state)
{
	int currentSize = 3, newSize = 5;
	int *arr = malloc(currentSize * sizeof(int));
	for (int i = 0; i < currentSize; i++)
		arr[i] = i;

	int *resizedArr = resizeArray(arr, currentSize, newSize);
	assert_non_null(resizedArr);

	// Original elements should be retained
	for (int i = 0; i < currentSize; i++)
	{
		assert_int_equal(resizedArr[i], i);
	}

	// New elements should be initialized to 0
	for (int i = currentSize; i < newSize; i++)
	{
		assert_int_equal(resizedArr[i], 0);
	}

	free(resizedArr); // Free memory after test
}

static void test_resizeArray_decrease_size(void **state)
{
	int currentSize = 5, newSize = 3;
	int *arr = malloc(currentSize * sizeof(int));
	for (int i = 0; i < currentSize; i++)
		arr[i] = i;

	int *resizedArr = resizeArray(arr, currentSize, newSize);
	assert_non_null(resizedArr);

	// Array should retain only the first `newSize` elements
	for (int i = 0; i < newSize; i++)
	{
		assert_int_equal(resizedArr[i], i);
	}

	free(resizedArr); // Free memory after test
}

static void test_resizeArray_same_size(void **state)
{
	int currentSize = 4, newSize = 4;
	int *arr = malloc(currentSize * sizeof(int));
	for (int i = 0; i < currentSize; i++)
		arr[i] = i;

	int *resizedArr = resizeArray(arr, currentSize, newSize);
	assert_non_null(resizedArr);

	// Array should remain unchanged
	for (int i = 0; i < newSize; i++)
	{
		assert_int_equal(resizedArr[i], i);
	}

	free(resizedArr); // Free memory after test
}

static void test_resizeArray_null_array(void **state)
{
	int *resizedArr = resizeArray(NULL, 0, 5);

	// Expect a newly allocated array with zeros
	assert_non_null(resizedArr);
	for (int i = 0; i < 5; i++)
	{
		assert_int_equal(resizedArr[i], 0);
	}

	free(resizedArr); // Free memory after test
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_resizeArray_increase_size),
	    cmocka_unit_test(test_resizeArray_decrease_size),
	    cmocka_unit_test(test_resizeArray_same_size),
	    cmocka_unit_test(test_resizeArray_null_array),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
