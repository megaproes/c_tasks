#include <cmocka.h>
#include "006.c"
static void test_uppercase(void **state)
{
    // Test case 1: Lowercase string
    char str1[] = "hello world";
    uppercase(str1);
    assert_string_equal(str1, "HELLO WORLD");

    // Test case 2: String with mixed case
    char str2[] = "HeLLo WoRLd";
    uppercase(str2);
    assert_string_equal(str2, "HELLO WORLD");

    // Test case 3: String with no lowercase characters
    char str3[] = "HELLO WORLD";
    uppercase(str3);
    assert_string_equal(str3, "HELLO WORLD");

    // Test case 4: String with special characters
    char str4[] = "hello @ 123";
    uppercase(str4);
    assert_string_equal(str4, "HELLO @ 123");

    // Test case 5: Empty string
    char str5[] = "";
    uppercase(str5);
    assert_string_equal(str5, "");

    // Test case 6: Single lowercase character
    char str6[] = "z";
    uppercase(str6);
    assert_string_equal(str6, "Z");

    // Test case 7: Single uppercase character (no change)
    char str7[] = "Z";
    uppercase(str7);
    assert_string_equal(str7, "Z");

    // Test case 8: Numbers only (no change)
    char str8[] = "1234567890";
    uppercase(str8);
    assert_string_equal(str8, "1234567890");

    // Test case 9: String with whitespace
    char str9[] = "   hello   ";
    uppercase(str9);
    assert_string_equal(str9, "   HELLO   ");
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_uppercase),
    };

    // Run the tests
    return cmocka_run_group_tests(tests, NULL, NULL);
}
