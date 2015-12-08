#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#define CARDS 52
#define COLOR 13
void shuffle_card(int card[], int number_check[]);
int determine_number(int number);
int determine_color(int number);
int main()
{
    char ch1 = 0, ch2 = 0;
    int i = 0, k = 0, sum1 = 0, sum2 = 0;
    int card[52] = {0}, number_check[CARDS + 1] = {false};
    // number_check 1 - 52
    shuffle_card(card, number_check);
    // First two cards
    for(i = 0; i < 10; i++)
    {
        printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
    }
    printf("\n");
    sum1 = determine_number(card[k++]);
    sum2 = determine_number(card[k++]);
Player1:
    if(sum1 <= 21)
    {
        printf("player1 ,do you want a HIT?");
        while(isspace(ch1 = getchar()));
        if(ch1 == 'n')
        {
            printf("Player 1 pass\n");
            goto end1;
        }
        if(sum1 + determine_number(card[k]) > 21) goto end1;
        else sum1 += determine_number(card[k++]);
    }
end1:
    if(sum2 > 21 || sum1 > 21) goto Result;
    if(ch1 == 'n' && ch2 == 'n') goto Result;
    if(ch1 == 'n') goto Player2;
    else if(ch2 == 'n') goto Player1;
Player2:
    if(sum2 <= 21)
    {
        printf("player2 ,do you want a HIT?");
        while(isspace(ch2 = getchar()));
        if(ch2 == 'n')
        {
            printf("Player 2 pass\n");
            goto end2;
        }
        if(sum2 + determine_number(card[k]) > 21) goto end2;
        else sum2 += determine_number(card[k++]);
        goto Player1;
    }
end2:
    if(sum2 > 21 || sum1 > 21) goto Result;
    if(ch1 == 'n' && ch2 == 'n') goto Result;
    if(ch1 == 'n') goto Player2;
    else if(ch2 == 'n')goto Player1;

Result:
    i = 0;
    printf("Player1\n");
    for(i = 0; i < k; i += 2)
    {
        printf("%c%d,", determine_color(card[i]), determine_number(card[i]));
    }
    printf("SUM =%d", sum1);
    printf("\n\nPlayer2\n");
    for(i = 1; i < k; i += 2)
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
