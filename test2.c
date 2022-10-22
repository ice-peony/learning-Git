#include <stdio.h>

int main()
{
    struct student{
        struct {
            int x;
            int y;
        }m;
        int a;
        int b;
    }n;
    n.a = 1;
    n.b = 2;
    n.m.x = n.a + n.b ;
    n.m.y = n.a - n.b ;
    printf("%d, %d", n.m.x, n.m.y);
    return 0;
}
