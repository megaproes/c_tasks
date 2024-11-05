
#include <cmocka.h>
#include "006.c" // Assuming the implementation file is named "data_holder.c"

static void test_set_and_get_integer(void **state)
{
	(void)state; // Unused variable

	struct DataHolder holder;
	int value = 42;

	set_data(&holder, INTEGER, &value);

	enum DataType type;
	int *retrieved_value = (int *)get_data(&holder, &type);

	assert_int_equal(type, INTEGER);
	assert_non_null(retrieved_value);
	assert_int_equal(*retrieved_value, 42);
}

static void test_set_and_get_pointer(void **state)
{
	(void)state; // Unused variable

	struct DataHolder holder;
	int arr[] = {1, 2, 3};

	set_data(&holder, POINTER, arr);

	enum DataType type;
	int *retrieved_value = (int *)get_data(&holder, &type);

	assert_int_equal(type, POINTER);
	assert_non_null(retrieved_value);
	assert_memory_equal(retrieved_value, arr, sizeof(arr));
}

static void test_set_and_get_float(void **state)
{
	(void)state; // Unused variable

	struct DataHolder holder;
	float value = 3.14f;

	set_data(&holder, FLOAT, &value);

	enum DataType type;
	float *retrieved_value = (float *)get_data(&holder, &type);

	assert_int_equal(type, FLOAT);
	assert_non_null(retrieved_value);
	assert_float_equal(*retrieved_value, 3.14f, 0.001);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_set_and_get_integer),
	    cmocka_unit_test(test_set_and_get_pointer),
	    cmocka_unit_test(test_set_and_get_float),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
