#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <graphics.h>
struct human
{
    int runs;
} humanarr[6];
struct bot
{
    int runs;
} botarr[6];
void graphbase()
{
    {                             /*making lines and base of the graph*/
        line(90, 410, 90, 30);    // y-axis
        line(90, 410, 610, 410);  // x-axis
        line(85, 35, 90, 30);     // left arrow y-axis
        line(95, 35, 90, 30);     // right arrow y-axis
        line(605, 405, 610, 410); // upper arrow x-axis
        line(605, 415, 610, 410); // lower arrow x-axis
    }
    { /*naming of axes*/
        outtextxy(85, 10, "Y");
        outtextxy(620, 405, "X");
        outtextxy(77, 410, "O");
    }
}
void graphnaming()
{ /*placing names on the graphing plane*/
    int leny, lengra;
    char temp[2], xname[] = {"Overs"}, yname[26] = {"Runs Scored"}, graname[51] = {"Human vs Bot runs in a over"};
    int i = 0;
    { // placing graph name
        lengra = strlen(graname);
        if (lengra % 2 == 0)
        {
            outtextxy(300 - (lengra), 10, graname);
        }
        else
        {
            lengra = (300 - (lengra + 1));
            outtextxy(lengra, 10, graname);
        }
    }
    { // placing x axis name
        outtextxy(390, 450, xname);
        line(470, 460, 590, 460);
        line(585, 455, 590, 460);
        line(585, 465, 590, 460);
    }
    { // placing y axis name
        // outtextxy needs string not char
        while (yname[i] != '\0')
        {
            temp[0] = yname[i];
            outtextxy(17, 85 + (i * 15), temp);
            i++;
        }
        line(20, 80, 20, 50);
        line(15, 55, 20, 50);
        line(25, 55, 20, 50);
    }
}
void graphcreating(int over)
{
    int gm, gd = DETECT, i, j;
    initgraph(&gd, &gm, (char *)"c:\\TC\\BGI");

    graphbase();
    graphnaming();
    for (i = 1; i <= 36; i++)
    {
        char temp1[25];
        line(85, 410 - (10 * i), 90, 410 - (10 * i));
        if ((i + 1) % 5 == 0)
        {
            sprintf(temp1, "%d", i + 1);
            moveto(60, 403 - (10 * (i + 1)));
            outtext(temp1);
        }
    }
    setfillstyle(1, 3);
    bar(20, 440, 50, 470);
    outtextxy(55, 447, "Human");
    setfillstyle(1, 7);
    bar(125, 440, 155, 470);
    outtextxy(160, 447, "Bot");
    for (j = 0; j < over; j++)
    {
        char temp[10];
        int size;
        setfillstyle(1, 3);
        size = humanarr[j].runs;
        bar(110 + (80 * j), 410, 140 + (80 * j), 410 - (size * 10));
        setfillstyle(1, 7);
        size = botarr[j].runs;
        bar(140 + (80 * j), 410, 170 + (80 * j), 410 - (size * 10));
        sprintf(temp, "over %d", j + 1);
        outtextxy(110 + (80 * j), 412, temp);
        size = humanarr[j].runs;
        sprintf(temp, "%d", humanarr[j].runs);
        moveto(112 + (80 * j), 410 - (size * 10) - 20);
        outtext(temp);
        size = botarr[j].runs;
        sprintf(temp, "%d", botarr[j].runs);
        moveto(142 + (80 * j), 410 - (size * 10) - 20);
        outtext(temp);
    }
    getch();
    closegraph();
}
int botbat(int wick, int over);
int botbowl(int wick, int over);
int botbat(int wick, int over)
{
    int c, j = 0, r = 0, r1 = 0, r2 = 0, d, loop;//r is 
    for (j = 0; j < 6; j++)
    {
        botarr[j].runs = 0;
    }
    j = 0;
    printf("\n\n Terminal Handcricket Person vs Bot \n\n");
    for (loop = 0; loop < wick ; loop++)
    {
        r = 0;
        while (1)
        {
            j = j + 1;
            if (j == ((over * 6) + 1))
            {
                loop = 12;
                break;
            }
            srand(time(NULL));
            c = rand() % 7;
            printf("\n Input a number from 0 to 6 \n");
            scanf("%d", &d);
            r = r + c;
            r2 = r2 + c;
            if (d > 6 || d < 0)
            {
                printf("Input a valid number from 0 to 6");
                r = r - c;
                r2 = r2 - c;
                j = j - 1;
                continue;
            }
            else if (d == c && j % 6 == 0)
            {
                printf("Computer chose %d\n", d);
                printf("You bowled out your opponent");
                r = r - c;
                r2=r2-c;
                printf("The Bot scored %d runs in %d balls uptill now \n", r + r1, j);
                if (loop == (wick - 1))
                {
                    botarr[(int)((j - 1) / 6)].runs += r2;
                }
                botarr[j%6].runs=r2;
                r2=0;
                break;  
            }
            else if (d == c && j % 6 != 0)
            {
                printf("Computer chose %d\n", d);
                printf("You bowled out your opponent");
                r = r - c;
                r2 = r2 - c;
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
                if (loop == (wick - 1))
                {
                    botarr[(int)((j - 1) / 6)].runs += r2;
                }
                break;
            }
            else if (c == 6)
            {

                printf("Slogged sweeped on the up and its d hugee six. \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 5)
            {
                printf("An overthrow from the fielding team and its 5 \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 4)
            {
                printf("A classical cover drive into the gap for 4. \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 3)
            {
                printf("Some brave running and carefully placed into the gap, they take 3 runs \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 2)
            {
                printf("Some quick running on display here, 2 runs \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 1)
            {
                printf("Just d single on this one \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            else if (c == 0)
            {
                printf("Clean defence ,good bowl.Dot \n");
                printf("The Bot scored %d run in %d balls uptill now \n", r + r1, j);
            }
            if (j % 6 == 0 && j > 1)
            {
                botarr[(j / 6) - 1].runs = r2;
                r2 = 0;
            }
        }
        r1 = r1 + r;
    }
    return r1;
}
int botbowl(int wick, int over)
{
    int b, i = 0, s = 0, s1 = 0, s2 = 0, a, loop;
    for (i = 0; i < 6; i++)
    {
        humanarr[i].runs = 0;
    }
    i = 0;
    printf("\n\n Terminal Handcricket Person vs Bot \n\n");
    for (loop = 0; loop < wick; loop++)
    {
        // s1=s1+s;
        s = 0;
        while (1)
        {
            i = i + 1;
            if (i == ((over * 6) + 1))
            {
                loop = 12;
                break;
            }
            srand(time(NULL));
            a = rand() % 7;
            printf("Input a number from 0 to 6 \n");
            scanf("%d", &b);
            s = s + b;
            s2 = s2 + b;
            if (b > 6 || b < 0)
            {
                printf("Input a valid number from 0 to 6");
                s = s - b;
                s2 = s2 - b;
                i = i - 1;
                continue;
            }
            else if (a == b && i % 6 == 0)
            {
                printf("Computer chose %d\n", a);
                printf("You bowled out your opponent");
                s = s - b;
                s2 = s2 - b;
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
                if (loop == (wick - 1))
                {
                    humanarr[(int)((i - 1) / 6)].runs += s2;
                }
                humanarr[i%6].runs=s2;
                s2=0;
                break;  
            }
            else if (a == b)
            {
                printf("Computer chose %d\n", a);
                printf("You are out.");
                s = s - b;
                s2 = s2 - b;
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
                if (loop == (wick - 1))
                {
                    humanarr[(int)((i - 1) / 6)].runs += s2;
                }
                break;
            }
            else if (b == 6)
            {
                printf("Slogged sweeped on the up and its a hugee six. \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 5)
            {
                printf("An overthrow from the fielding team and its a 5 \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 4)
            {
                printf("A classical cover drive into the gap for a 4. \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 3)
            {
                printf("Some brave running and carefully placed into a gap, they take 3 runs \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 2)
            {
                printf("Some quick running on display here, 2 runs \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 1)
            {
                printf("Just a single on this one \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            else if (b == 0)
            {
                printf("Clean defence a good bowl.Dot \n");
                printf("Computer chose %d\n", a);
                printf("You scored %d run in %d balls uptill now \n", s + s1, i);
            }
            if (i % 6 == 0 && i > 1)
            {
                humanarr[(i / 6) - 1].runs = s2;
                s2 = 0;
            }
        }
        s1 = s1 + s;
    }
    return s1;
}
int main()
{
    int userrun, botrun, wick, over;
    char playerGuess[10];
    char playerChoice[10];
    int tossResult, botChoice;
    char *toss;
    char *botDecision;
    while (1)
    {
        printf("Decide Overs to be played:");
        scanf("%d", &over);
        if (over <= 0 || over > 5)
        {
            printf("Enter number between 1 and 5");
            continue;
        }
        else
            break;
    }
    while (1)
    {
        printf("Decide wickets per side(1-11):");
        scanf("%d", &wick);
        if (wick <= 0 || wick >= 11)
        {
            printf("Enter number between 1 and 11");
            continue;
        }
        else
            break;
    }
    printf("Enter your guess (heads/tails):\n");
    scanf("%s", playerGuess);
    strlwr(playerGuess);
    printf("%s\n", playerGuess);
    srand(time(0));
    tossResult = rand() % 2;
    if (tossResult == 0)
    {
        toss = "heads";
    }
    else
    {
        toss = "tails";
    }

    printf("Toss result: %s\n", toss);

    if (strcmp(playerGuess, toss) == 0)
    {
        printf("Congratulations! You won the toss.\n");
        printf("What do you choose (bat/bowl)?\n");
        scanf("%s", playerChoice);
        strlwr(playerChoice);
        printf("You chose to %s first.\n", playerChoice);
        if (strcmp(playerChoice, "bat") == 0)
        {
            userrun = botbowl(wick, over);
            printf("\ninnings completed you scored %d runs.", userrun);
            botrun = botbat(wick, over);
            printf("\ninnings completed bot scored %d runs.", botrun);
            graphcreating(over);
        }
        else
        {
            botrun = botbat(wick, over);
            printf("\ninnings completed bot scored %d runs.", botrun);
            userrun = botbowl(wick, over);
            printf("\ninnings completed you scored %d runs.", userrun);
            graphcreating(over);
        }
        if (botrun == userrun)
        {
            printf("\nIt's a draw");
            printf("\nThanks for playing \n");
            getch();

        }
        else if (botrun > userrun)
        {
            printf("\nYou lost. Better luck next time.");
            printf("\nThanks for playing \n");
            getch();

        }
        else
        {
            printf("\nCongratulations!! You won.");
            printf("\nThanks for playing \n");
            getch();

        }
    }
    if (strcmp(playerGuess, toss) != 0)
    {
        printf("Sorry, you lost the toss.\n");
        botChoice = rand() % 2;
        if (botChoice == 0)
        {
            botDecision = "bat";
            printf("Bot chooses to %s first.\n", botDecision);
            botrun = botbat(wick, over);
            printf("\ninnings completed bot scored %d runs.", botrun);
            userrun = botbowl(wick, over);
            printf("\ninnings completed you scored %d runs.", userrun);
            graphcreating(over);
        }
        else
        {
            botDecision = "bowl";
            printf("Bot chooses to %s first.\n", botDecision);
            userrun = botbowl(wick, over);
            printf("\ninnings completed you scored %d runs.", userrun);
            botrun = botbat(wick, over);
            printf("\ninnings completed bot scored %d runs.", botrun);
            graphcreating(over);
        }
        if (botrun == userrun)
        {
            printf("\nTt's a draw");
            printf("\nThanks for playing \n");
            getch();

        }
        else if (botrun > userrun)
        {
            printf("\nYou lost.Better luck next time.");
            printf("\nThanks for playing \n");\
            getch();

        }
        else
        {
            printf("\nCongratulations!! You won.");
            printf("\nThanks for playing \n");
            getch();
        }
    }
    return 0;
}