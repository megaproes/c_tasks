#include <cmocka.h>
#include "005.c" // Assuming the implementation file is named "create_flex_array.c"
#include <stdlib.h>

static void test_create_flex_array_basic(void **state)
{
	(void)state; // Unused variable

	int values[] = {1, 2, 3};
	struct FlexArray *flex = create_flex_array(3, values);

	assert_non_null(flex);
	assert_int_equal(flex->count, 3);
	assert_int_equal(flex->values[0], 1);
	assert_int_equal(flex->values[1], 2);
	assert_int_equal(flex->values[2], 3);

	free(flex);
}

static void test_create_flex_array_zero_elements(void **state)
{
	(void)state; // Unused variable

	struct FlexArray *flex = create_flex_array(0, NULL);

	assert_non_null(flex);
	assert_int_equal(flex->count, 0);

	free(flex);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_create_flex_array_basic),
	    cmocka_unit_test(test_create_flex_array_zero_elements),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
