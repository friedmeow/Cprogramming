#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define time_delay 200
#define width 79
#define height 20

char map[height][width]; //two state:' ','X'
int i,j,k;

void Cell_life();
void load_file(char *file_name);
void init_map();
void show_map();
void replace_map();
void copy_map(char source_map[height][width],char target_map[height][width]);
void delay(int m_sec);

int main(int argc,char *argv[])
{
    init_map();
    load_file(argv[1]);
    replace_map();  // '.'->' '  'O'->'X'
    show_map();
    delay(time_delay);
    system("cls");
    while(1){
       Cell_life();
       show_map();
       delay(time_delay);
       system("cls");
    }
    return 0;
}


void Cell_life()
{
	//---write your code...----
    int i = 0, j = 0, count = 0, i_po = 0, j_po = 0;
// cell < 2 under-population.
// cell == 2 || cell == 3 lives on to the next generation.
// cell > 3 over-population.
// cell == 3 reproduction.
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            i_po = i, j_po = j;
            count = 0;
            if(j_po - 1 < 0 || i_po - 1 < 0);
            else
            {
                i = i_po - 1, j = j_po - 1;
                    if(map[i][j] == 'X') count++;
                j++;
                    if(map[i][j] == 'X') count++;
            }
            if(j_po + 1 >= width || i_po - 1 < 0);
            else
            {
                 i = i_po - 1, j = j_po + 1;
                    if(map[i][j] == 'X') count++;
                 i++;
                    if(map[i][j] == 'X') count++;
            }
            if(j_po + 1 >= width || i_po + 1 >= height);
            else
            {
                 i = i_po + 1, j = j_po + 1;
                    if(map[i][j] == 'X') count++;
                 j--;
                    if(map[i][j] == 'X') count++;
            }
// if(j_po + 1 >= width || j_po - 1 < 0 || i_po + 1 >= height || i_po - 1 < 0);
            if(j_po - 1 < 0 || i_po + 1 >= height );
            else
            {
                i = i_po + 1, j = j_po - 1;map[i][j] = 'X';
                    if(map[i][j] == 'X') count++;
                i--;
                    if(map[i][j] == 'X') count++;
            }
            if(map[i_po][j_po] == 'X')
            {
                if(count < 2) map[i_po][j_po] = ' ';
                else if(count == 2 || count == 3) map[i_po][j_po] = 'X';
                else if(count > 3) map[i_po][j_po] = ' ';
            }
            if(map[i_po][j_po] == ' ')
            {
                if(count == 3) map[i_po][j_po] = 'X';
            }

        }
    }
    //map[i][j] = 'X';
	//-------------------------
}

void load_file(char *file_name)
{
    FILE *fread;
    char line[width];
    int line_num=0;

    fread=fopen(file_name,"r");

    if(fread==NULL)
        fread=fopen("gosperglidergun.cells","r");

    while(fgets(line,width,fread)!=NULL){
        if(line[0]!='!'){
            for(j=0;j<width && line[j]!='\n';j++)
                map[line_num][j]=line[j];
            line_num++;
        }
    }
    fclose(fread);
}

void init_map()
{
    for(i=0;i<height;i++){
        for(j=0;j<width;j++)
            map[i][j]=' ';
    }
}

void show_map()
{
    for(i=0;i<height;i++){
        for(j=0;j<width;j++)
            printf("%c",map[i][j]);
        printf("\n");
    }
}

void replace_map() // '.'->' '  'O'->'X'
{
    for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(map[i][j]=='.')
                map[i][j] = ' ';
            else if(map[i][j]=='O')
                map[i][j] = 'X';
        }
    }
}

void copy_map(char source_map[height][width],char target_map[height][width])
{
    for(i=0;i<height;i++)
        for(j=0;j<width;j++)
            target_map[i][j] = source_map[i][j];
}


void delay(int m_sec)
{
    int start=clock();
    int end;
    while(1){
        end=clock();
        if(((end-start))>=m_sec)
            return;
    }
}

