#include <stdio.h>
#include <stdlib.h>

int main()
{
    int file_num = 0, word_num = 0, re = 0;
    FILE *fp;
    char file_name[1000];
    char temp[1000][1000];
    int i = 0, j = 0, k = 0, l = 0;
    printf("How many files would you input: ");
    scanf("%d", &file_num);
    for(;file_num > 0; file_num--)
    {
        printf("Please input file path: ");
        scanf("%s", file_name);
        fp = fopen(file_name, "r");
        while((fscanf(fp, "%s", temp[i++])!=EOF))
        {
            re = 0;
            for(j = 0;temp[i-1][j]!='\0';j++)
            {
                if('A' <= temp[i-1][j] && temp[i-1][j] <= 'Z')
                    temp[i-1][j] = temp[i-1][j] - 'A' + 'a';
            }

            k = i - 2;
            for(l = 0;l <= k; l++)
            {
                if (!(strcmp(temp[i-1],temp[l])))
                {
                    re = 1;
                    break;
                }
            }

            if(re == 1);
            else word_num++;
            re = 0;
        }
    }
    printf("There are %d different string in those files.", word_num);
    return 0;
}
