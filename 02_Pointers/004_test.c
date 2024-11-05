#include <cmocka.h>
#include "004.c"

static int add_ten(int x)
{
	return x + 10;
}

static int multiply_two(int x)
{
	return x * 2;
}

static void test_dispatcher_basic(void **state)
{
	(void)state; // Unused variable

	int (*functions[])(int) = {add_ten, multiply_two};
	int args[] = {5, 7};
	int results[2] = {0};

	dispatcher(functions, args, 2, results);

	assert_int_equal(results[0], 15);
	assert_int_equal(results[1], 14);
}

static void test_dispatcher_with_null_function(void **state)
{
	(void)state; // Unused variable

	int (*functions[])(int) = {add_ten, NULL, multiply_two};
	int args[] = {5, 8, 2};
	int results[3] = {0};

	dispatcher(functions, args, 3, results);

	assert_int_equal(results[0], 15);
	assert_int_equal(results[1], 0); // NULL function should not modify result
	assert_int_equal(results[2], 4);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_dispatcher_basic),
	    cmocka_unit_test(test_dispatcher_with_null_function),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
