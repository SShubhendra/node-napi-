#include <stdio.h>
#include <stdlib.h>

int helloUser(int n)
{
    if (n > 0)
    {
        return helloUser(n - 1) + n;
    }
    return 0;
}

int main()
{
    int x = 5;
    // ("Enter value of x %d", &x);
    printf("\n%d", helloUser(x));
    return 0;
}