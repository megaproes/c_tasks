#include <cmocka.h>
#include "002.c" // Assuming the implementation file is named "segment_buffer.c"

static void test_segment_buffer_equal_segments(void **state) {
    (void) state; // Unused variable

    char buffer[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    void *segments[4];

    segment_buffer(buffer, 8, 4, segments);
    assert_ptr_equal(segments[0], &buffer[0]);
    assert_ptr_equal(segments[1], &buffer[2]);
    assert_ptr_equal(segments[2], &buffer[4]);
    assert_ptr_equal(segments[3], &buffer[6]);
}

static void test_segment_buffer_remainder(void **state) {
    (void) state; // Unused variable

    char buffer[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void *segments[3];

    segment_buffer(buffer, 9, 3, segments);
    assert_ptr_equal(segments[0], &buffer[0]);
    assert_ptr_equal(segments[1], &buffer[3]);
    assert_ptr_equal(segments[2], &buffer[6]);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_segment_buffer_equal_segments),
        cmocka_unit_test(test_segment_buffer_remainder),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
