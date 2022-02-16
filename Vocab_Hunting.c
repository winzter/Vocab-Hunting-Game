#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    char player[100];
    float score;
    int time;
}PLAYER;
PLAYER p;

typedef struct
{
    char player[100];
    float score;
    int time;
}PLAYER_READ;
PLAYER_READ pread[15];

typedef struct
{
    char words[100]; /*use to keep vocabs from file*/

}WORDS;
WORDS w[8][3];

typedef struct
{
    char username[100];
    char pass[100];

}PASSWORD;
PASSWORD pw;

typedef struct
{
    char username[100];
    char pass[100];

}PASSWORD_CHECK;
PASSWORD_CHECK pwc;

char decoy_n[100]; /*use with player name*/
char blank[1]; /*Space in game */
int time_p; /* Timer*/
float progress = 0;
char Stage[7];
char *underscore_stage[8][3];
char *u1 = "_",*u2 = "_ _",*u3 = "_ _ _",*u4 = "_ _ _ _",*u5 = "_ _ _ _ _",*u6 = "_ _ _ _ _ _";

/* GUI*/
void stage1();
void gotoxy(int x,int y);
void mainmenu();
void player_name();/*Input player name*/
void stage1_answers_file();
void stage1_alphabet();
void randalphabet();
void underscore();
float check_elements();
void result();/*End game result*/
void save_score();/*Save score to data file*/
void score_boards(); /*Scoreboard page1*/
void score_boards2();/*Scoreboard page2*/
void read_score();/*Read score from data file*/
void max2min(); /*Sort score max to min */
void admin();
void read_pass();
void edit_menu();
void edit_menu_alphabet();
void edit_menu_reset_scoreboard();
void edit_menu_vocabulary();
void addvocab();
void addvocab2file();
void delete_vocab();
void sort_vocab();
void username_decare();
void username_change();
void pass_change();
void pass_decare();

int main()
{
    mainmenu();
    return 0;
}


void player_name()
{
        system ("cls");
        gotoxy(45,7);printf("<< PLEASE ENTER PLAYER NAME >>");
        gotoxy(39,10);printf("+========================================+");
        gotoxy(39,11);printf("+");
        gotoxy(80,11);printf("+");
        gotoxy(39,12);printf("+");
        gotoxy(80,12);printf("+");
        gotoxy(39,13);printf("+");
        gotoxy(80,13);printf("+");
        gotoxy(39,14);printf("+========================================+");
        gotoxy(45,12);gets(decoy_n);
        if(decoy_n[0] == '0')
        {
            mainmenu();
        }
        else
        {
            strcpy(p.player,decoy_n);
        }
}

void stage1()
{
    system("cls");
    char words[100];
    char decoy;
    progress = 0;

    /*Functions*/
    stage1_answers_file();
    stage1_alphabet();
    underscore();

    for(time_p = 150;time_p>0;time_p --)
    {
        int y = 9;
        system ("cls");
        printf("+====================================================================================================================+\n");
        printf("+                                                                                                                    +\n");
        printf("+                      PLAYER : %-10s            PROGRESS : %6.2f %%            TIME : %3d s                    +\n",p.player,progress,time_p);
        printf("+                                                                                                                    +\n");
        printf("+====================================================================================================================+\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t#################################################\n");
        gotoxy(5,15);
        for(int i=0;i<7;i++)
        {
            if(i==0)
            {
                printf("\t\t\t");
            }
            printf("%c",Stage[i]);
            printf("  ");
        }
        gotoxy(1,8); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,9); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,10); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,11); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,12); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,13); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,14); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,15); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,16); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,17); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,18); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,19); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,20); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,21); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,22); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,23); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(1,24); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,8); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,9); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,10); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,11); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,12); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,13); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,14); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,15); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,16); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,17); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,18); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,19); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,20); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,21); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,22); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,23); printf("\t\t\t\t\t\t\t\t#");
        gotoxy(55,24); printf("\t\t\t\t\t\t\t\t#");
        printf("\n");

        /*print underscore*/
        for(int i=0;i<8;i++)
        {
            int x = 70;
            for(int j=0;j<3;j++)
            {
                if(underscore_stage[i][j] != NULL)
                {
                    gotoxy(x,y);printf("%-7s",underscore_stage[i][j]);
                }
                x+=15;
            }
            y+=2;
        }

        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t\t#################################################\n");
        Sleep(1000);

        /*User's input*/
        if(kbhit())
        {
            printf("Enter Word: ");
            strupr(gets(words));
            if(words[0]=='0')
            {
                break;
            }
            if(words[0]=='1')
            {
                randalphabet();
            }
        }

        /*Checking Answers*/
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(underscore_stage[i][j] != NULL)
                {
                    if(strcmp(words,w[i][j].words) == 0)
                    {
                        if(strcmp(words,underscore_stage[i][j]) == 0)
                        {
                            words[0] = '\0';
                            break;
                        }
                        else
                        {
                            underscore_stage[i][j] = w[i][j].words;
                            progress += 100/check_elements();
                            time_p+=2;
                            words[0] = '\0';
                            break;
                        }
                    }
                }
            }
        }
        if(progress == 100.00)
        {
            break;
        }
    }
    if(words[0] != '0')
    {
        p.score = progress;
        p.time = time_p;
        result();
    }
    else
    {
        mainmenu();
    }
}

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void mainmenu()
{
    show : system("cls");

    char choice_menu;

    printf("\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             << MAIN MENU >>                               +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              1. NEW GAME                                  +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              2. SCOREBOARD                                +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              3. EDITOR (ADMINSTRATOR ONLY)                +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              4. EXIT                                      +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    choice_menu = getch();
    switch(choice_menu)
    {
        case'1':
            player_name();
            stage1();
            break;
        case'2':
            score_boards();
            break;
        case'3':
            admin();
            break;
        case'4':
            exit(0);
            break;
        default :
            goto show;
            break;
    }

}
float check_elements()
{
    char num[25];
    int elements,k=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            num[k] = strlen(w[i][j].words);
            k++;
        }
    }
    elements = strlen(num);
    return elements;
}
void stage1_answers_file()
{
    FILE *fpt;
    if((fpt = fopen("Answerskey.txt","r")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
          fscanf(fpt,"%s",&w[i][j].words);
        }
    }
    fclose(fpt);
    sort_vocab();
}
void stage1_alphabet()
{
    FILE *fpt;
    if((fpt = fopen("StageAlphabet.txt","r")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    for(int i=0;i<7;i++)
    {
        fscanf(fpt,"%c",&Stage[i]);
    }
    fclose(fpt);
}
void randalphabet()
{
    char temp;
    int random;
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
    {
        temp = Stage[i];
        random = rand() % 7;
        Stage[i] = Stage[random];
        Stage[random] = temp;
    }
}
void underscore()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(strlen(w[i][j].words) != 0)
            {
                if(strlen(w[i][j].words) == 1)
                {
                    underscore_stage[i][j] = u1;
                }
                if(strlen(w[i][j].words) == 2)
                {
                    underscore_stage[i][j] = u2;
                }
                if(strlen(w[i][j].words) == 3)
                {
                    underscore_stage[i][j] = u3;
                }
                if(strlen(w[i][j].words) == 4)
                {
                    underscore_stage[i][j] = u4;
                }
                if(strlen(w[i][j].words) == 5)
                {
                   underscore_stage[i][j] = u5;
                }
                if(strlen(w[i][j].words) == 6)
                {
                    underscore_stage[i][j] = u6;
                }
            }
        }
    }
}

void result()
{
    show : system("cls");

    char choice_menu;

    printf("\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             << YOUR SCORE >>                              +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+            PLAYER : %-10s                                            +\n",p.player);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+            PROGRESS : %6.2f%%                                             +\n",p.score);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+            TIME : %3d s                                                   +\n",p.time);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+      1. PLAY AGAIN          2. MAIN MENU         3. SCOREBOARD            +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    choice_menu = getch();
    switch(choice_menu)
    {
        case'1':
            progress = 0;
            time_p = 150;
            stage1();
            break;
        case'2':
            save_score();
            mainmenu();
            break;
        case'3':
            save_score();
            score_boards();
            break;
        default :
            goto show;
            break;
    }
}
void save_score()
{
    FILE *fpt;
    if((fpt = fopen("Score.txt","a")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    fprintf(fpt,"%s %.2f %d\n",p.player,p.score,p.time);
    fclose(fpt);
}
void score_boards()
{
    show:system("cls");
    read_score();
    char choice_menu;
    printf("+=======+======================================================================+===================+==================+\n");
    printf("+  RANK +                                  PLAYER                              +      PROGRESS     +       TIME       +\n");
    printf("+=======+======================================================================+===================+==================+\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  1ST  + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[0].player,pread[0].score,pread[0].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  2ND  + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[1].player,pread[1].score,pread[1].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  3RD  + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[2].player,pread[2].score,pread[2].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   4   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[3].player,pread[3].score,pread[3].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   5   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[4].player,pread[4].score,pread[4].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   6   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[5].player,pread[5].score,pread[5].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   7   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[6].player,pread[6].score,pread[6].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+-------+----------------------------------------------------------------------+-------------------+------------------+\n\n");
    printf("                                     1. MAIN MENU             2. NEXT PAGE                                               \n");
    choice_menu = getch();
    switch(choice_menu)
    {
        case'1':
            mainmenu();
            break;
        case'2':
            score_boards2();
            break;
        default :
            goto show;
            break;
    }
}
void score_boards2()
{
    show:system("cls");
    read_score();
    char choice_menu;
    printf("+=======+======================================================================+===================+==================+\n");
    printf("+  RANK +                                  PLAYER                              +      PROGRESS     +       TIME       +\n");
    printf("+=======+======================================================================+===================+==================+\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   8   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[7].player,pread[7].score,pread[7].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+   9   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[8].player,pread[8].score,pread[8].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  10   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[9].player,pread[9].score,pread[9].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  11   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[10].player,pread[10].score,pread[10].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  12   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[11].player,pread[11].score,pread[11].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  13   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[12].player,pread[12].score,pread[12].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+       +                                                                      +                   +                  +\n");
    printf("+  14   + %-10s                                                           +      %6.2f%%      +        %3d s     +\n",pread[13].player,pread[13].score,pread[13].time);
    printf("+       +                                                                      +                   +                  +\n");
    printf("+-------+----------------------------------------------------------------------+-------------------+------------------+\n\n");
    printf("                                     1. MAIN MENU             2. PREVIOUS PAGE                                           \n");
    choice_menu = getch();
    switch(choice_menu)
    {

        case'1':
            mainmenu();
            break;
        case'2':
            score_boards();
            break;
        default :
            goto show;
            break;
    }
}
void read_score()
{
    FILE *fpt;
    if((fpt = fopen("Score.txt","r")) == NULL )
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    for(int i=0;i<14;i++)
    {
        fscanf(fpt,"%s %f %d",pread[i].player,&pread[i].score,&pread[i].time);
    }
    fclose(fpt);
    max2min();
}

void max2min()
{
    char temp_player[100];
    int max_time = 0,temp_score,temp_time;
    float max_score = 0;
    for(int i=0;i<14;i++)
    {
        for(int j=i+1;j<14;j++)
        {
            if(pread[i].score <= pread[j].score && pread[i].time <= pread[j].time)
            {
                temp_score = pread[i].score;
                temp_time = pread[i].time;
                strcpy(temp_player,pread[i].player);
                pread[i].score = pread[j].score;
                pread[i].time = pread[j].time;
                strcpy(pread[i].player,pread[j].player);
                pread[j].score = temp_score;
                pread[j].time = temp_time;
                strcpy(pread[j].player,temp_player);
            }
        }
    }
}
void admin()
{
    show:system("cls");
    read_pass();
    int p=0;
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\tEDITOR (ADMINSTRATOR ONLY)\t\t\t\t\t      +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n\n");
    printf("                                                      ADMINSTRATOR                                                     ");
    gotoxy(38,10); printf("+=========================================+");
    gotoxy(38,11);printf("+                                         +");
    gotoxy(38,12);printf("+");
    gotoxy(80,12);printf("+");
    gotoxy(40,12); printf("USERNAME :");
    gotoxy(38,13);printf("+");
    gotoxy(80,13);printf("+");
    gotoxy(38,14);printf("+                                         +");
    gotoxy(40,15); printf("PASSWORD :");
    gotoxy(38,15);printf("+");
    gotoxy(80,15);printf("+");
    gotoxy(38,16);printf("+                                         +");
    gotoxy(38,17); printf("+=========================================+");
    gotoxy(51,12); gets(pw.username);
    gotoxy(51,15);
    do{
        pw.pass[p]=getch();
        if(pw.pass[p]!='\r'){
            printf("*");
        }
        p++;
    }while(pw.pass[p-1]!='\r');
    pw.pass[p-1] = '\0';
    if(strcmp(pw.username,pwc.username) == 0 && strcmp(pw.pass,pwc.pass) == 0)
    {
        gotoxy(55,20);printf("Logged In!");
        getch();
        edit_menu();
    }
    else
    {
        gotoxy(46,20); printf("Invalid Username or Password!\n");
        gotoxy(35,22); printf("Press Any Key to Continue or Press X to Main Menu\n");
        if(getch() == 'x')
        {
            mainmenu();
        }
        goto show;
    }
}

void read_pass()
{
    FILE *fpt;
    if((fpt = fopen("Admin.txt","r")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    fscanf(fpt,"%s %s",pwc.username,pwc.pass);
    fclose(fpt);
}

void edit_menu()
{
    show:system("cls");
    char choice_edit_menu;
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\tEDITOR (ADMINSTRATOR ONLY)\t\t\t\t\t      +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n");
    printf("\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              1. ALPHABET                                  +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              2. VOCABULARY                                +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              3. RESET SCOREBOARD                          +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              4. CHANGE USERNAME                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              5. CHANGE PASSWORD                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              6. MAIN MENU                                 +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    choice_edit_menu = getch();
    switch(choice_edit_menu)
    {
        case'1':
            edit_menu_alphabet();
            break;
        case'2':
            edit_menu_vocabulary();
            break;
        case'3':
            edit_menu_reset_scoreboard();
            break;
        case'4':
            username_change();
            break;
        case'5':
            pass_change();
            break;
        case'6':
            mainmenu();
            break;
        default :
            goto show;
            break;
    }
}

void edit_menu_alphabet()
{
    show:system("cls");
    char alpdecoy[100];
    alpdecoy[0] = '\0';
    stage1_alphabet();
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\t      EDIT ALPHABET\t\t\t\t\t              +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n\n");
    printf("\n\n\n\n\n\t\t\t                            ");
    for(int i=0;i<7;i++)
    {
        printf("%c",Stage[i]);
        printf("  ");
    }
    gotoxy(32,20);
    strupr(gets(alpdecoy));
    if(alpdecoy[0] == '0')
    {
        edit_menu();
    }
    else if(strlen(alpdecoy) == 6)
    {
        FILE *fpt;
        if((fpt = fopen("StageAlphabet.txt","w")) == NULL)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
            exit(1);
        }
        fprintf(fpt,"%s",alpdecoy);
        fclose(fpt);
        goto show;
    }
    else
    {
        gotoxy(47,22); printf("At least 6 Alphabet required!");
        getch();
        goto show;
    }
}
void edit_menu_reset_scoreboard()
{
    system("cls");
    FILE *fpt;
    if((fpt = fopen("Score.txt","w")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    fprintf(fpt,"%s",blank);
    fclose(fpt);
    for(int i=0;i<14;i++)
    {
        strcpy(pread[i].player,blank);
        pread[i].score = 0;
        pread[i].time = 0;
    }
    printf("\n\n\n\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             SCOREBOARD RESETED!                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                         Press any Key to Continue                         +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    getch();
    edit_menu();
}
void edit_menu_vocabulary()
{
    show:system("cls");
    char choice_edit_vocab;
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\t      EDIT VOCABULARY\t\t\t\t\t              +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n\n");
    printf("\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             1. ADD VOCABULARY                             +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             2. DELETE VOCABULARY                          +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             3. BACK TO EDITOR                             +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    choice_edit_vocab = getch();
    switch(choice_edit_vocab)
    {
        case'1':
            addvocab();
            break;
        case'2':
            delete_vocab();
            break;
        case'3':
            edit_menu();
            break;
        default :
            goto show;
            break;
    }
}
void addvocab()
{
    show:system("cls");
    stage1_answers_file();
    stage1_alphabet();
    int num_vocab = 0,vocab_left=0;
    char decoy_vocab[100];
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\t      ADD VOCABULARY\t\t\t\t\t              +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n\n");
    printf("\t\t\t\t\t\t    ");
    for(int i=0;i<7;i++)
    {
        printf("%c",Stage[i]);
        printf("  ");
    }
    printf("\n\n\n");
    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
           printf("\t\t\t\t\t");
        }
        for(int j=0;j<3;j++)
        {
                printf("%s\t",w[i][j].words);
                if(strlen(w[i][j].words) != 0)
                {
                    num_vocab++;
                }
        }
        if(i%2!=0)
        {
            printf("\n\n");
            printf("\t\t\t\t\t");
        }
    }
    vocab_left = 24 - num_vocab;
    printf("\n\t\t\t\t\tAdditional %d vocabulary can be added",vocab_left);
    printf("\n\n\t\t\t\t\t");
    if(vocab_left > 0)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(strlen(w[i][j].words) == 0)
                {
                    strupr(gets(decoy_vocab));
                    if(strlen(decoy_vocab) > 6)
                    {
                        printf("\n\n\t\t\t\t\t    Equal or less than 6 alphabets allowed!");
                        getch();
                        goto show;
                    }
                    if(decoy_vocab[0] == '0')
                    {
                        edit_menu_vocabulary();
                    }
                    strcpy(w[i][j].words,decoy_vocab);
                    sort_vocab();
                    addvocab2file();
                    printf("\n\n\n\t\t\t\t\t\t\t  SAVED!");
                    getch();
                    goto show;
                }
            }
        }
    }
    else
    {
        printf("     Cannot add more vocabulary!\n\n\n\n\n");
        printf("                                                 Press X to VOCABULARY MENU");
        getch();
        if(getch() == 'x')
        {
            edit_menu_vocabulary();
        }
        goto show;
    }
}

void addvocab2file()
{
    sort_vocab();
    FILE *fpt;
    if((fpt = fopen("Answerskey.txt","w")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
          fprintf(fpt,"%s\n",w[i][j].words);
        }
    }
    fclose(fpt);
}

void delete_vocab()
{
    show:system("cls");
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            strcpy(w[i][j].words,blank);
        }
    }
    stage1_answers_file();
    char deleted[100];
    printf("+=====================================================================================================================+\n");
    printf("+                                                                                                                     +");
    printf("\n+\t\t\t\t\t\t      DELETE VOCABULARY\t\t\t\t\t              +\n");
    printf("+                                                                                                                     +\n");
    printf("+=====================================================================================================================+\n\n\n");
    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
            printf("\t\t\t\t\t");
        }
        for(int j=0;j<3;j++)
        {
            printf("%s\t",w[i][j].words);
        }
        if(i%2!=0)
        {
            printf("\n\n");
            printf("\t\t\t\t\t");
        }
    }
    printf("\n\t\t\t\t\tInput unwanted vocabulary: ");
    strupr(gets(deleted));
    if(deleted[0] == '0')
    {
        edit_menu_vocabulary();
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(strcmp(deleted,w[i][j].words) == 0)
            {
                strcpy(w[i][j].words,blank);
                addvocab2file();
                printf("\n\n\n\t\t\t\t\t\t\t  DELETED!\n");
                getch();
                goto show;
            }
        }
    }
    goto show;
}

void sort_vocab()
{
    int t, i, j;
    char temp[100];
    for(t=1;t<24;t++)
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<2;j++)
            {
                if (strlen(w[i][j].words) != 0 && strlen(w[i][j+1].words) != 0 && strlen(w[i][j].words)>=strlen(w[i][j+1].words))
                {
                    strcpy(temp,w[i][j].words);
                    strcpy(w[i][j].words,w[i][j+1].words);
                    strcpy(w[i][j+1].words,temp);
                }
            }
        }
        for(i=0;i<7;i++)
        {
            if (strlen(w[i][2].words) != 0 && strlen(w[i+1][0].words) != 0 && strlen(w[i][2].words)>=strlen(w[i+1][0].words))
            {
                strcpy(temp,w[i][2].words);
                strcpy(w[i][2].words,w[i+1][0].words);
                strcpy(w[i+1][0].words,temp);
            }
        }
    }
}

void username_change()
{
    read_pass();
    show:system("cls");
    char name[100];
    printf("\n\n\n\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             USERNAME CHANGE                               +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                        YOUR USERNAME IS %-10s                        +\n",pwc.username);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                       +===========================+                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +===========================+                       +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    gotoxy(50,16);
    gets(name);
    if(name[0] == '0')
    {
        edit_menu();
    }
    strcpy(pwc.username,name);
    FILE *fpt;
    if((fpt = fopen("Admin.txt","w")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    fprintf(fpt,"%s\n%s",pwc.username,pwc.pass);
    fclose(fpt);
    username_decare();
}
void username_decare()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              NEW USERNAME IS                              +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                   %-10s                              +\n",pwc.username);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                         Press any Key to continue                         +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    getch();
    username_change();
}

void pass_change()
{
    read_pass();
    show:system("cls");
    char pass[100];
    printf("\n\n\n\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                             PASSWORD CHANGE                               +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                        YOUR PASSWORD IS %-10s                        +\n",pwc.pass);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                       +===========================+                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +                           +                       +\n");
    printf("\t\t\t+                       +===========================+                       +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    gotoxy(50,16);
    gets(pass);
    if(pass[0] == '0')
    {
        edit_menu();
    }
    strcpy(pwc.pass,pass);
    FILE *fpt;
    if((fpt = fopen("Admin.txt","w")) == NULL)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t       File not found!\n\n\n\n\n\n\n\n");
        exit(1);
    }
    fprintf(fpt,"%s\n%s",pwc.username,pwc.pass);
    fclose(fpt);
    pass_decare();
}

void pass_decare()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t+===========================================================================+\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                              NEW PASSWORD IS                              +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                   %-10s                              +\n",pwc.pass);
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                         Press any Key to continue                         +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+                                                                           +\n");
    printf("\t\t\t+===========================================================================+\n");
    getch();
    pass_change();
}
