
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#define CARDS 52
#define COLOR 13
void shuffle_card(int card[], int number_check[]);
int determine_number(int number);
int determine_color(int number);
int determine_game_number(int number);

int main()
{
    char ch1 = 0, ch2 = 0;
    int i = 0, k = 0, sum1 = 0, sum2 = 0, cards1 = 1000, cards2 = 1000;
    int card[52] = {0}, number_check[CARDS + 1] = {false};
    // number_check 1 - 52
    shuffle_card(card, number_check);
    // First two cards
    for(i = 0; i < 10; i++)
    {
        printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
    }
    printf("\n");
    sum1 = determine_game_number(card[k++]);
    sum2 = determine_game_number(card[k++]);
Player1:
    if(sum1 < 21)
    {
        printf("player1 ,do you want a HIT?");
        while(isspace(ch1 = getchar()));
        if(ch1 == 'n')
        {
            printf("Player 1 pass\n");
            cards1 = k;
            goto end1;
        }
        if((sum1 + determine_game_number(card[k])) > 21)
        {
            sum1 += determine_game_number(card[k]);
            k++;
            goto Result;
        }
        else sum1 += determine_game_number(card[k++]);
        //cards1 = cards1 * 100 + k;
    }
end1:
    if(ch1 == 'n' && ch2 == 'n') goto Result;
    if(ch2 == 'n') goto Player1;
Player2:
    if(sum2 < 21)
    {
        printf("player2 ,do you want a HIT?");
        while(isspace(ch2 = getchar()));
        if(ch2 == 'n')
        {
            printf("Player 2 pass\n");
            cards2 = k;
            goto end2;
        }
        if((sum2 + determine_game_number(card[k])) > 21)
        {
            sum2 += determine_game_number(card[k]);
            k++;
            goto Result;
        }
        else sum2 += determine_game_number(card[k++]);

    }
end2:
    if(ch1 == 'n' && ch2 == 'n') goto Result;
    if(ch1 == 'n') goto Player2;
    if(sum1 >= 21) goto Result;
    if(sum2 >= 21) goto Result;
    else goto Player1;
Result:
    if(sum1 > 21) printf("\nPlayer2 wins!!!\n");
    else if(sum2 > 21) printf("\nPlayer1 wins!!!\n");
    else if(sum1 == 21) printf("\nPlayer1 wins!!!\n");
    else if(sum2 == 21) printf("\nPlayer2 wins!!!\n");
    else if(sum1 > sum2) printf("\nPlayer1 wins!!!\n");
    else if(sum2 > sum1)printf("\nPlayer2 wins!!!\n");

    i = 0;
    printf("Player1\n");
    for(i = 0; i < cards1 && i < k; i += 2)
    {
        printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
    }
    if(ch2 == 'n')
        for(i = cards2; i < k; i++)
        {
            printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
        }
    printf("SUM =%d", sum1);
    printf("\n\nPlayer2\n");
    for(i = 1; i < k - 1 && i < cards2; i += 2)
    {
        printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
    }
    if(ch1 == 'n')
        for(i = cards1; i < k; i++)
        {
            printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
        }
    printf("SUM =%d", sum2);

    return 0;
}
// ASCII Code
// ♠=6, ♥=3,◆=4, ♣=5
int determine_color(int number)
{
    if(number / 13 <= 1) return 6;
    else if(number / 13 <= 2) return 3;
    else if(number / 13 <= 3) return 4;
    else if (number / 13 <= 4) return 5;
    
}
int determine_number(int number)
{
    return number % 13 + 1;
    
}
int determine_game_number(int number)
{
    number = number % 13 + 1;
    if(number >= 10) return 10;
    else return number;
}
void shuffle_card(int card[], int number_check[])
{
    int assign_card = 0, i = 0;
    srand((unsigned) time(NULL));
    // ♠= 1 - 13, ♥= 14 - 26,◆= 27 - 39, ♣= 40 - 52
    for(i = 0; i < CARDS; i++)
    {
        assign_card = rand() % 52 + 1;
        while(number_check[assign_card])
        {
            assign_card = rand() % 52 + 1;
        }
        number_check[assign_card] = true;
        card[i] = assign_card;
        
    }
    
}
