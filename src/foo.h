// #ifndef FOO_DOT_H /* This is an "include guard" */
// #define FOO_DOT_H /* prevents the file from being included twice. */
//                   /* Including a header file twice causes all kinds */
//                   /* of interesting problems.*/

// /**
//  * This is a function declaration.
//  * It tells the compiler that the function exists somewhere.
//  */
// void foo(int id, char *name);

//#endif /* FOO_DOT_H */

// #if __cplusplus
// extern "C"
// {
// #endif
//     void foo(int id, char *name);
//     // declarations go here

// #if __cplusplus
// }
// #endif

extern "C"
{
    void foo(int id, char *name);

    //more declarations...
}
