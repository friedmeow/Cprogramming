#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char ch, *array;
    int re_size = 2, count = 0;
    printf("Please enter the line:\n");
    ch = getchar();
    array = malloc(2);
    do{
        printf("Store '%c' to array[%d]; Array size: %d\n", ch, count, re_size);
        array[count] = ch;
        count++;
        if( (count) == (re_size))
        {
            re_size *= 2;
            printf("The array size is reallocated from %d to %d\n", re_size / 2, re_size);
            array = realloc(array, re_size);
        }
        ch = getchar();
    } while(ch != '\n');

    printf("Store \'\\0\' to array[%d]; Array size: %d\n",count, re_size);
    array[count] = '\0';

    printf("\nString Length: %d\n", count);
    printf("Array Size: %d\n", re_size);
    printf("The String: %s\n", array);


    return 0;
}
