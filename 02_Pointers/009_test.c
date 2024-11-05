#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "009.c"

// Test cases for freeArray()
static void test_freeArray_non_null_pointer(void **state)
{
	int *arr = malloc(5 * sizeof(int));
	freeArray(&arr);

	// After freeing, array pointer should be NULL
	assert_null(arr);
}

static void test_freeArray_null_pointer(void **state)
{
	int *arr = NULL;
	freeArray(&arr);

	// Ensures no crash or error on NULL input
	assert_null(arr);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_freeArray_non_null_pointer),
	    cmocka_unit_test(test_freeArray_null_pointer),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
