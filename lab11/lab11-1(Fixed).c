// Update Together

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define time_delay 200
#define width 79
#define height 20

char map[height][width], temp_map[height][width]; //two state:' ','X'
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
  system("pause");
    return 0;
}


void Cell_life()
{
	//---write your code...----
  int i_ = 0, j_ = 0, count = 0, row = 0, col = 0;
// cell < 2 under-population.
// cell == 2 || cell == 3 lives on to the next generation.
// cell > 3 over-population.
// cell == 3 reproduction.
    for(i_ = 0; i_ < height; i_++)
    {
        for(j_ = 0; j_ < width; j_++)
        {
            count = 0;
            for(row = i_ - 1, col = j_ - 1; col < j_ + 1; col++)
            {
                if(row < 0 || col < 0 || row > height - 1 || col > width - 1) ;
                else
                {
                    if (map[row][col] == 'X') count++;
                }
            }
            for(col = j_ + 1, row = i_ - 1; row < i_ + 1; row++)
            {
                if(row < 0 || col < 0 || row > height - 1 || col > width - 1) ;
                else
                {
                    if (map[row][col] == 'X') count++;
                }
            }
            for(col = j_ + 1, row = i_ + 1; col > j_ - 1; col--)
            {
                if(row < 0 || col < 0 || row > height - 1 || col > width - 1) ;
                else
                {
                    if (map[row][col] == 'X') count++;
                }
            }
            for(col = j_ - 1, row = i_ + 1; row > i_ - 1; row--)
            {
                if(row < 0 || col < 0 || row > height - 1 || col > width - 1) ;
                else
                {
                    if (map[row][col] == 'X') count++;
                }
            }

            if(map[i_][j_]  == 'X')
            {
                if(count < 2) temp_map[i_][j_] = '.';
                else if(count == 2 || count == 3) temp_map[i_][j_] = 'O';
                else if(count > 3) temp_map[i_][j_]  = '.';
            }
            else if(map[i_][j_]  == ' ')
            {
                if(count == 3) temp_map[i_][j_]  = 'O';
            }



        }
    }



    for(i_ = 0; i_ < height; i_++)
    {
        for(j_ = 0; j_ < width; j_++)
        {
            if(temp_map[i_][j_] == 'O') map[i_][j_] = 'X';
            else if(temp_map[i_][j_] == '.') map[i_][j_] = ' ';

        }
    }
	//-------------------------
}

void load_file(char *file_name)
{
    FILE *fread;
    char line[width];
    int line_num=0;

    fread=fopen(file_name,"r");

    if(fread==NULL)
        fread=fopen("gosperglidergun .cells","r");

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

