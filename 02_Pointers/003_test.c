#include <cmocka.h>
#include "003.c"

static void test_remove_middle_node(void **state)
{
	(void)state; // Unused variable

	struct Node node1 = {1, NULL, NULL};
	struct Node node2 = {2, NULL, NULL};
	struct Node node3 = {3, NULL, NULL};
	struct Node node4 = {4, NULL, NULL};

	node1.next = &node2;
	node2.prev = &node1;
	node2.next = &node3;
	node3.prev = &node2;
	node3.next = &node4;
	node4.prev = &node3;

	struct Node *head = &node1;

	remove_node(&head, &node3);

	assert_ptr_equal(node2.next, &node4);
	assert_ptr_equal(node4.prev, &node2);
	assert_null(node3.next);
	assert_null(node3.prev);
}

static void test_remove_head_node(void **state)
{
	(void)state; // Unused variable

	struct Node node1 = {1, NULL, NULL};
	struct Node node2 = {2, NULL, NULL};

	node1.next = &node2;
	node2.prev = &node1;

	struct Node *head = &node1;

	remove_node(&head, &node1);

	assert_ptr_equal(head, &node2);
	assert_null(node2.prev);
	assert_null(node1.next);
	assert_null(node1.prev);
}

static void test_remove_tail_node(void **state)
{
	(void)state; // Unused variable

	struct Node node1 = {1, NULL, NULL};
	struct Node node2 = {2, NULL, NULL};

	node1.next = &node2;
	node2.prev = &node1;

	struct Node *head = &node1;

	remove_node(&head, &node2);

	assert_ptr_equal(head, &node1);
	assert_null(node1.next);
	assert_null(node2.next);
	assert_null(node2.prev);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
	    cmocka_unit_test(test_remove_middle_node),
	    cmocka_unit_test(test_remove_head_node),
	    cmocka_unit_test(test_remove_tail_node),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
