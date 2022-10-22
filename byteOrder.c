#include <stdio.h>
#define swap_endian_u16(x)   ((x & 0xFF00 >> 8) | (x & 0x00FF << 8))

int main() 
{
    int a;
    a = 0x11223344;
    char b;
    b = a;
    if (b == 0x44){
        printf("小端模式\n");
    }else{
        printf("大端模式\n");
    }
    
    swap_endian_u16(a);
    b = a;
    if (b == 0x44){
        printf("小端模式\n");
    }else{
        printf("大端模式\n");
    }
    
    return 0;
}