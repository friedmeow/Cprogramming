#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int sub(int, int);
int mul(int, int);
int add(int, int);
int neg(int);
int divi(int, int);
int neg(int);
int main(int argc, const char * argv[])
{
    char ch;
    int first_num = 0, second_num = 0, res = 0;
    printf("formula:");
    do{
    scanf("%d", &first_num);
    ch = getchar();
    if(ch == 'a')
    {
        scanf("%d", &second_num);
        res = add(first_num, second_num);
    }
    else if(ch == 's')
    {
        scanf("%d", &second_num);
        res = sub(first_num, second_num);
    }
    else if(ch == 'm')
    {
        scanf("%d", &second_num);
        res = mul(first_num, second_num);
    }
    else if(ch == 'd')
    {
        scanf("%d", &second_num);
        res = divi(first_num, second_num);
    }
    else exit(EXIT_SUCCESS);
        printf("%d%c%d = %d\n", first_num, ch, second_num, res);
        printf("formula:");
    } while(ch != '!');
    return 0;
}


int neg(int i)
{
    return ~i + 1;
}
int sub(int a, int b)
{
    b = neg(b);
    return add(a, b);
}
int add(int a, int b)
{
    return a + b;
}
int mul(int a, int b)
{
    int tempres = 0;
    while(b != 0)
    {
        if((b & 01) == 1) tempres += a;
        a = a << 1;
        b = b >> 1;
    }
    return tempres;
}
int divi(int a, int b)
{
    int t = 0, tempmul, count = -2, temp_t = -1;
    while(a > tempmul)
    {
        tempmul = mul(b, t++);
        count++;
        temp_t++;
    }
    if(a == mul(b, temp_t)) count++;
    return count;
}
