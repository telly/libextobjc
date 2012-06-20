/**
 * libextc metamacros testcase
 * ExtendedC
 *
 * by Justin Spahr-Summers
 *
 * Released 18. Jun 2012 into the public domain.
 */

#include "metamacros.h"
#include "metamacros_test.h"

#define test_stringify(INDEX, VALUE) \
    # INDEX metamacro_stringify(VALUE)

void metamacros_test (void) {
    assert(metamacro_argcount(a) == 1);
    assert(metamacro_argcount(a, b) == 2);
    assert(metamacro_argcount(a, b, c) == 3);
    assert(metamacro_argcount(a, b, c, d) == 4);
    assert(metamacro_argcount(a, b, c, d, e) == 5);
    assert(metamacro_argcount(a, b, c, d, e, f) == 6);
    assert(metamacro_argcount(a, b, c, d, e, f, g) == 7);
    assert(metamacro_argcount(a, b, c, d, e, f, g, h) == 8);
    assert(metamacro_argcount(a, b, c, d, e, f, g, h, i) == 9);

    assert(0 == strcmp(metamacro_foreach(test_stringify, 0), "00"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1), "0011"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2), "001122"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3), "00112233"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4), "0011223344"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5), "001122334455"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6), "00112233445566"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6, 7), "0011223344556677"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6, 7, 8), "001122334455667788"));

    assert(metamacro_first(5, 1) == 5);
    assert(metamacro_first(1, 5) == 1);
    assert(0 == strcmp(metamacro_first("foo", "bar"), "foo"));
}
