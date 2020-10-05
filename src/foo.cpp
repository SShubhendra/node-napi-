#include "foo.h"
#include <stdio.h>

extern "C"
{
    void foo(int id, char *name)
    {
        fprintf(stderr, "111 foo(%d, \"%s\");\n", id, name);
        /* This will print how foo was called to stderr - standard error.
        * e.g., foo(42, "Hi!") will print `foo(42, "Hi!")`
        */
    }
}

/**
 * This is the function definition.
 * It is the actual body of the function which was declared elsewhere.
 */
// void foo(int id, char *name)
// {
//     fprintf(stderr, "foo(%d, \"%s\");\n", id, name);
//     /* This will print how foo was called to stderr - standard error.
//      * e.g., foo(42, "Hi!") will print `foo(42, "Hi!")`
//      */
// }