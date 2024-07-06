#include "iGraphics.h"
#pragma comment(lib, "winmm.lib")
#define pi 3.1416
#define g 9.8 / 100

struct fruit
{
	char fimage1[10][20];
	char fcut[20];
	char fimage2[10][20];
	char Fruit_bomb[10][20];
	char splash[100];
} fruits[10];

int game_state = 1;
bool music = true;
char bg[10][20] = {"bg\\1.bmp", "bg\\26.bmp", "bg\\3.bmp", "bg\\5.bmp", "bg\\5_1.bmp"};
// menu page:
char cl[8][20] = {"menu\\c1.bmp", "menu\\c2.bmp", "menu\\c3.bmp", "menu\\c4.bmp", "menu\\c5.bmp", "menu\\c6.bmp", "menu\\c7.bmp", "menu\\c8.bmp"};
char zen[8][20] = {"menu\\z1.bmp", "menu\\z2.bmp", "menu\\z3.bmp", "menu\\z4.bmp", "menu\\z5.bmp", "menu\\z6.bmp", "menu\\z7.bmp"};
//char arcade[8][20] = {"menu\\ar1.bmp", "menu\\ar2.bmp", "menu\\ar3.bmp", "menu\\ar4.bmp", "menu\\ar5.bmp", "menu\\ar6.bmp", "menu\\ar7.bmp"};
char set[14][20] = {"menu\\11.bmp", "menu\\12.bmp", "menu\\n.bmp", "menu\\su.bmp", "menu\\mu.bmp", "menu\\mu0.bmp", "menu\\le.bmp", "menu\\pro.bmp", "menu\\help.bmp", "menu\\pause.bmp", "menu\\pa1.bmp", "menu\\pa0.bmp", "menu\\scr.bmp", "menu\\help1.bmp"};
char play[10][20] = {"menu\\p1.bmp", "menu\\p2.bmp", "menu\\p3.bmp", "menu\\p4.bmp", "menu\\p5.bmp", "menu\\p6.bmp", "menu\\p7.bmp", "menu\\p8.bmp"};
char plg[8][20] = {"menu\\plg1.bmp", "menu\\plg2.bmp", "menu\\plg3.bmp", "menu\\plg4.bmp", "menu\\plg5.bmp", "menu\\plg6.bmp", "menu\\plg7.bmp", "menu\\plg8.bmp"};
char ex[8][20] = {"menu\\e1.bmp", "menu\\e2.bmp", "menu\\e3.bmp", "menu\\e4.bmp", "menu\\e5.bmp", "menu\\e6.bmp", "menu\\e7.bmp", "menu\\e8.bmp"};
// Fruits
char cherry[10][20] = {"fruits\\ch1.bmp", "fruits\\ch2.bmp", "fruits\\ch3.bmp", "fruits\\ch4.bmp", "fruits\\ch5.bmp", "fruits\\ch6.bmp", "fruits\\ch7.bmp", "fruits\\ch9.bmp", "fruits\\ch10.bmp", "fruits\\ch11.bmp"};
char straw[10][20] = {"fruits\\s1.bmp", "fruits\\s2.bmp", "fruits\\s3.bmp", "fruits\\s4.bmp", "fruits\\s5.bmp", "fruits\\s6.bmp", "fruits\\s7.bmp", "fruits\\s8.bmp", "fruits\\s9.bmp", "fruits\\s10.bmp"};
char wtrmln[10][20] = {"fruits\\w1.bmp", "fruits\\w2.bmp", "fruits\\w3.bmp", "fruits\\w4.bmp", "fruits\\w5.bmp", "fruits\\w6.bmp", "fruits\\w7.bmp", "fruits\\w10.bmp", "fruits\\w11.bmp", "fruits\\w12.bmp"};
char mango[10][20] = {"fruits\\m1.bmp", "fruits\\m2.bmp", "fruits\\m3.bmp", "fruits\\m4.bmp", "fruits\\m5.bmp", "fruits\\m6.bmp", "fruits\\m7.bmp", "fruits\\m8.bmp", "fruits\\m9.bmp", "fruits\\m10.bmp"};
char ban[10][20] = {"fruits\\b1.bmp", "fruits\\b2.bmp", "fruits\\b3.bmp", "fruits\\b4.bmp", "fruits\\b5.bmp", "fruits\\b6.bmp", "fruits\\b7.bmp", "fruits\\b11.bmp", "fruits\\b12.bmp", "fruits\\b13.bmp"};
// Extras
char li[11][20] = {"menu\\l4.bmp", "menu\\l3.bmp", "menu\\l2.bmp", "menu\\l1.bmp", "menu\\sc2.bmp", "menu\\sc1.bmp", "menu\\l5.bmp", "menu\\quit.bmp", "menu\\quit1.bmp", "menu\\quit0.bmp", "menu\\su1.bmp"};
char bomb1[8][20] = {"menu\\bomb1.bmp", "menu\\bomb2.bmp", "menu\\bomb3.bmp", "menu\\bomb4.bmp", "menu\\bomb5.bmp", "menu\\bomb6.bmp", "menu\\bomb7.bmp"};
char bomb2[8][20] = {"menu\\b01.bmp", "menu\\b02.bmp", "menu\\b03.bmp", "menu\\b04.bmp", "menu\\b05.bmp", "menu\\b06.bmp", "menu\\b07.bmp"};
char splash[5][20] = {"fruits\\sp2.bmp", "fruits\\sp2.bmp", "fruits\\sp3.bmp", "fruits\\sp4.bmp", "fruits\\sp2.bmp"};

int lin = 0;
int clin = 0, zin = 0, plin = 0, plgin = 0, ein = 0;
int sett = 0;
int stin = 0, win = 0;
int bin = 0;
int x = 0, y = 0;
int theta = 85, xstraw = 350, ystraw = -10;
int v = 8;
int t = 2;
int life = 3, fruit_index;
int music_icon = 0;
int profile = 0, lead = 0, help = 0;
int score = 0, fruit_cut = 0, slicing = 0, y_during_cut, x_during_cut;
char scr[1000];
char s[1000];
char file_name[100] = "E:\\Project\\Project 1\\score.txt";
int i = 0;
int player, temp;
char name[100];
int first, second, third;
int p = 0;
int zenTime = 0;
int quit = 0, bomb = 0, best = 0;
char lead1[100];
int scores[100];

void initializefruits(void)
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		strcpy(fruits[0].fimage1[i], straw[i]);
		strcpy(fruits[1].fimage1[i], wtrmln[i]);
		strcpy(fruits[2].fimage1[i], mango[i]);
		strcpy(fruits[3].fimage1[i], ban[i]);
		strcpy(fruits[4].fimage1[i], cherry[i]);
		strcpy(fruits[5].fimage1[i], bomb1[i]);
		strcpy(fruits[6].fimage1[i], bomb2[i]);
	}
	strcpy(fruits[0].fcut, straw[7]);
	strcpy(fruits[1].fcut, wtrmln[7]);
	strcpy(fruits[2].fcut, mango[7]);
	strcpy(fruits[3].fcut, ban[7]);
	strcpy(fruits[4].fcut, cherry[7]);
	strcpy(fruits[0].splash, splash[0]);
	strcpy(fruits[1].splash, splash[1]);
	strcpy(fruits[2].splash, splash[2]);
	strcpy(fruits[3].splash, splash[3]);
	strcpy(fruits[4].splash, splash[4]);
	i++;
	for (j = 0; j < 2; j++, i++)
	{
		strcpy(fruits[0].fimage2[j], straw[i]);
		strcpy(fruits[1].fimage2[j], wtrmln[i]);
		strcpy(fruits[2].fimage2[j], mango[i]);
		strcpy(fruits[3].fimage2[j], ban[i]);
		strcpy(fruits[4].fimage2[j], cherry[i]);
	}
}
void iDraw()
{
	// iClear();
	// Loading page
	if (game_state == 1)
	{

		iShowBMP(0, 0, bg[0]);
		// loading
		iSetColor(102, 0, 0);
		iRectangle(300, 39, 401, 12);
		iSetColor(204, 102, 0);
		iFilledRectangle(300, 40, 400, 11);
		iSetColor(249, 193, 39);
		iFilledRectangle(300, 40, lin, 10);
	}
	// settings page
	else if (game_state == 2)
	{
		iPauseTimer(0);
		iShowBMP(0, 0, bg[1]);
		iShowBMP2(350, 380, set[2], 0);	  // fruit ninja
		iShowBMP2(350, 200, cl[clin], 0); // classic
		iShowBMP2(550, 200, zen[zin], 0); // zen
		if (sett == 1)
		{
			iShowBMP2(720, 320, set[1], 0); // settings page
			if (music)
				iShowBMP2(800, 520, set[4], 0); // music on
			else
				iShowBMP2(800, 520, set[5], 0); // music off
			iShowBMP2(800, 470, set[6], 0);		// leaderboard
			iShowBMP2(800, 420, set[7], 0);		// profile
			iShowBMP2(800, 370, set[8], 0);		// help
			if (profile)
			{
				iShowBMP2(200, 50, set[3], 0);
				iSetColor(0,0,0);
				iText(400,450,"Profile", GLUT_BITMAP_TIMES_ROMAN_24);
				iSetColor(0, 0, 0);
				iRectangle(320, 380, 250, 50); // profile box
				iSetColor(0, 0, 0);
				iText(330,400, s, GLUT_BITMAP_TIMES_ROMAN_24); // profile name
			}
			if (lead)
			{
				iShowBMP2(200, 50, li[10], 0);
				iSetColor(0, 0, 0);
				iText(430, 420, lead1, GLUT_BITMAP_TIMES_ROMAN_24);
				iText(310, 300, name, GLUT_BITMAP_TIMES_ROMAN_24);
				
			}
			if (help)
			{
				iShowBMP2(200, 50, set[13], 0);
			}
		}
		iShowBMP2(950, 550, set[0], 0); // settings icon
	}
	// Classic play page
	else if (game_state == 3)
	{
		iShowBMP(0, 0, bg[2]);
		iShowBMP2(900, 560, li[life], 0); // life
		iShowBMP2(5, 540, li[4], 0);	  // score count fruit
		sprintf(scr, "%d", score);		  // score
		iSetColor(255, 123, 28);
		iText(75, 565, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 520, li[5], 0); // best score
		char string[100];
		sprintf(string, "%d", best);
		iText(90, 526, string, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 5, li[6], 0); // pause button
		// fruits
		if (!fruit_cut)
		{ // fruit is alive
			iShowBMP2(x + xstraw, ystraw + y, fruits[fruit_index].fimage1[stin], 0);
		}

		else
		{ // fruit is dead
			iPauseTimer(3);
			iShowBMP2(x_during_cut - 70, y_during_cut - 70, fruits[fruit_index].splash, 0);
			if (slicing == 1)
			{
				iShowBMP2(x + xstraw, y + ystraw, fruits[fruit_index].fcut, 0);
			}
			else
			{
				iShowBMP2(x + xstraw - 40, y + ystraw, fruits[fruit_index].fimage2[0], 0);
				iShowBMP2(x + xstraw, y + ystraw, fruits[fruit_index].fimage2[1], 0);
			}
		}

		if (stin != 7 && y > 0)
		{
			iResumeTimer(3);
		}
		if (p)
		{
			iPauseTimer(2);
			iPauseTimer(3);
			iShowBMP2(300, 50, set[9], 0);	 // pause page
			iShowBMP2(410, 150, set[10], 0); // yes button
			iShowBMP2(610, 150, set[11], 0); // no button
		}
		else
		{
			iResumeTimer(2);
			iResumeTimer(3);
		}
	}
	// game over page
	else if (game_state == 4)
	{
		iPauseTimer(2);
		iPauseTimer(3);
		iShowBMP(0, 0, bg[3]);
		iShowBMP2(5, 540, li[4], 0); // score count fruit
		sprintf(scr, "%d", score);	 // score
		iSetColor(255, 123, 28);
		iText(75, 565, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(900, 560, li[0], 0); // life
		iShowBMP2(5, 520, li[5], 0);   // best
		char string[100];
		sprintf(string, "%d", best);
		iText(90, 526, string, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 5, li[6], 0); // pause button
	}
	// score state classic
	else if (game_state == 5)
	{
		iShowBMP(0, 0, bg[2]);
		iShowBMP2(150, 50, set[12], 0); // score page
		iSetColor(0, 0, 0);
		iRectangle(350, 200, 100, 50);
		iSetColor(0, 0, 0);
		iText(390, 220, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(700, 100, plg[plgin], 0); // playagain
		iShowBMP2(700, 300, ex[ein], 0);
	}
	// zen play state
	else if (game_state == 6)
	{
		iShowBMP(0, 0, bg[2]);
		iSetColor(0, 0, 0);
		iRectangle(860, 560, 120, 20);
		iSetColor(204, 102, 0);
		iFilledRectangle(860, 560, 120, 20);
		iSetColor(249, 193, 39);
		iFilledRectangle(860, 560, zenTime, 20); // time rectangle
		iShowBMP2(5, 540, li[4], 0);			 // score count fruit
		sprintf(scr, "%d", score);				 // score
		iSetColor(255, 123, 28);
		iText(75, 565, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 520, li[5], 0); // best score
		char string[100];
		sprintf(string, "%d", best);
		iText(90, 526, string, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 5, li[6], 0); // pause button
		if (!fruit_cut)
		{
			// fruit is alive
			iShowBMP2(x + xstraw, ystraw + y, fruits[fruit_index].fimage1[stin], 0);
		}

		else
		{
			// fruit is dead
			iPauseTimer(3);
			iShowBMP2(x_during_cut - 70, y_during_cut - 70, fruits[fruit_index].splash, 0);
			if (slicing == 1)
			{
				iShowBMP2(x + xstraw, y + ystraw, fruits[fruit_index].fcut, 0);
			}
			else
			{
				iShowBMP2(x + xstraw - 40, y + ystraw, fruits[fruit_index].fimage2[0], 0);
				iShowBMP2(x + xstraw, y + ystraw, fruits[fruit_index].fimage2[1], 0);
			}
		}

		if (stin != 7 && y > 0)
		{
			iResumeTimer(3);
		}
		if (p)
		{
			iPauseTimer(2);
			iPauseTimer(3);
			iShowBMP2(300, 50, set[9], 0);
			iShowBMP2(410, 150, set[10], 0);
			iShowBMP2(610, 150, set[11], 0);
		}
		else
		{
			iResumeTimer(2);
			iResumeTimer(3);
		}
	}
	// times up page
	else if (game_state == 7)
	{
		iPauseTimer(2);
		iPauseTimer(3);
		iShowBMP(0, 0, bg[4]);
		iShowBMP2(5, 540, li[4], 0); // score count fruit
		sprintf(scr, "%d", score);	 // score
		iSetColor(255, 123, 28);
		iText(75, 565, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 520, li[5], 0); // best
		char string[100];
		sprintf(string, "%d", best);
		iText(90, 526, string, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(5, 5, li[6], 0); // pause button
	}
	// score state zen
	else if (game_state == 8)
	{
		iShowBMP(0, 0, bg[2]);
		iShowBMP2(150, 50, set[12], 0); // score page
		iSetColor(0, 0, 0);
		iRectangle(350, 200, 100, 50);
		iSetColor(0, 0, 0);
		iText(390, 220, scr, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(700, 100, plg[plgin], 0); // playagain
		iShowBMP2(700, 300, ex[ein], 0);
	}
	
	if (quit == 1)
	{
		iShowBMP2(250, 50, li[7], 0);  // exit page
		iShowBMP2(340, 150, li[8], 0); // yes button
		iShowBMP2(520, 150, li[9], 0); // exit button
	}
}

void iMouseMove(int mx, int my)
{
}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (game_state == 2)
		{
			// settings click
			if (mx > 955 && mx < 995 && my > 550 && my < 595)
			{
				if (sett == 0)
					sett = 1;
				else
					sett = 0;
			}
			// classic click
			if (mx > 350 && mx < 500 && my > 200 && my < 350 && profile == 0 && lead == 0 && help == 0)
			{
				iPauseTimer(6);
				game_state = 3;
				xstraw = 300;
				ystraw = -10;
				t = 1;
				slicing = 0;
				fruit_cut = 0;
			}
			// zen_click
			if (mx > 550 && mx < 700 && my > 200 && my < 350 && profile == 0 && lead == 0 && help == 0)
			{
				iResumeTimer(6);
				game_state = 6;
				xstraw = 300;
				ystraw = -10;
				t = 1;
				slicing = 0;
				fruit_cut = 0;
			}
			if (sett == 1)
			{
				/// profile work

				if (mx > 800 && mx < 950 && my > 420 && my < 450)
				{
					if (!profile)
					{
						profile = 1;
						lead = 0;
						help = 0;
					}
					else
						profile = 0;
				}
				// leaderboard work
				if (mx > 800 && mx < 950 && my > 470 && my < 500)
				{
					if (!lead)
					{
						lead = 1;
						profile = 0;
						help = 0;
						FILE *scoreFile = fopen("score.txt", "r");
						fscanf(scoreFile, "%s %d", name, &temp);
						fclose(scoreFile);
						FILE *bestFile = fopen("best.txt", "r");
						fscanf(bestFile, "%s", lead1);
						fclose(bestFile);
					}
					else
						lead = 0;
				}
				// music click
				if (mx > 800 && mx < 950 && my > 520 && my < 550)
				{
					lead = 0;
					profile = 0;
					help = 0;
					if (music)
					{
						music = false;
						PlaySound(0, 0, 0);
					}
					else
					{
						music = true;
						PlaySound("music\\1.wav.wav", NULL, SND_LOOP | SND_ASYNC);
					}
				}
				/// help
				if (mx > 800 && mx < 900 && my > 370 && my < 400)
				{
					if (help)
					{
						help = 0;
					}
					else
					{
						help = 1;
						lead = 0;
						profile = 0;
					}
				}
			}
		}
		// classic mode play
		if (game_state == 3)
		{

			if (mx > 610 && mx < 710 && my > 150 && my < 200 && p == 1)
			{
				game_state = 5;
			}

			if (mx > x + xstraw && mx < x + 100 + xstraw && my > y + ystraw && my < y + ystraw + 100 && !fruit_cut)
			{

				if (fruit_index > 4)
				{
					game_state = 4;

					fruit_cut = 0;
				}
				else
				{
					iPauseTimer(3);
					slicing = 1;
					fruit_cut = 1;
					score++;
				}
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				y_during_cut = my;
				x_during_cut = mx;
			}
			// pause button
			if (mx > 5 && mx < 35 && my > 5 && my < 35)
			{
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				FILE *scoreFile = fopen("score.txt", "a");
				fprintf(scoreFile, "%s %d\n", s, score);
				fclose(scoreFile);
				if (!p)
				{
					p = 1;
				}
				else
				{
					p = 0;
				}
			}
			// resume play

			if (mx > 410 && mx < 510 && my > 150 && my < 200 && p == 1)
			{
				p = 0;
			}
		}
		//  zen mode play
		if (game_state == 6)
		{

			if (mx > 610 && mx < 710 && my > 150 && my < 200 && p == 1)
			{
				game_state = 8;
			}

			if (mx > x + xstraw && mx < x + 100 + xstraw && my > y + ystraw && my < y + ystraw + 100 && !fruit_cut)
			{

				if (fruit_index > 4)
				{
					game_state =7;

					fruit_cut = 0;
				}
				else
				{
					iPauseTimer(3);
					slicing = 1;
					fruit_cut = 1;
					score++;
				}
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				y_during_cut = my;
				x_during_cut = mx;
			}
			// pause button
			if (mx > 5 && mx < 35 && my > 5 && my < 35)
			{
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				FILE *scoreFile = fopen("score.txt", "a");
				fprintf(scoreFile, "%s %d\n", s, score);
				fclose(scoreFile);
				if (!p)
				{
					p = 1;
				}
				else
				{
					p = 0;
				}
			}
			// resume play

			if (mx > 410 && mx < 510 && my > 150 && my < 200 && p == 1)
			{
				p = 0;
			}
		}
		if (game_state == 5)
		{
			// play again click
			if (mx > 700 && mx < 850 && my > 100 && my < 250)
			{
				game_state = 3;
				p = 0;
				life = 3;
				zenTime=0;
				score = 0;
				xstraw = 300;
				ystraw = -10;
				fruit_cut = 0;
				slicing = 0;
				t = 1;
			}
			// exit
			if (mx > 700 && mx < 850 && my > 300 && my < 450)
			{

				game_state = 2;
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				FILE *scoreFile = fopen("score.txt", "a");
				fprintf(scoreFile, "%s %d\n", s, score);
				fclose(scoreFile);
				life = 3;
				score = 0;
				zenTime = 0;
				p = 0;
				life = 3;
				ystraw = -10;
				// printf("%d",game_state);
			}
		}

		if (game_state == 8)
		{
			// play again click
			if (mx > 700 && mx < 850 && my > 100 && my < 250)
			{
				game_state = 6;
				p = 0;
				zenTime=0;
				score = 0;
				xstraw = 300;
				ystraw = -10;
				fruit_cut = 0;
				slicing = 0;
				t = 1;
			}
			// exit
			if (mx > 700 && mx < 850 && my > 300 && my < 450)
			{

				game_state = 2;
				if (score > best)
				{
					best = score;
					FILE *bestFile = fopen("best.txt", "w");
					fprintf(bestFile, "%d", best);
					fclose(bestFile);
				}
				FILE *scoreFile = fopen("score.txt", "a");
				fprintf(scoreFile, "%s %d\n", s, score);
				fclose(scoreFile);
				life = 3;
				score = 0;
				zenTime = 0;
				p = 0;
				life = 3;
				ystraw = -10;
				// printf("%d",game_state);
			}
		}
		if (quit == 1)
		{
			if (mx > 340 && mx < 490 && my > 150 && my < 200)
				quit = 0;
			else if (mx > 520 && mx < 670 && my > 150 && my < 200)
				exit(0);
		}
	}
}
	void iKeyboard(unsigned char key)
	{
		/*if(game_state==4 && key=='\r'){
		   game_state=5;
		   if(score > best){
				best = score;
				FILE* bestFile = fopen("best.txt", "w");
				fprintf(bestFile, "%d", best);
				fclose(bestFile);
			}
		} */
		if (key == '\x1B')
		{
			if (score > best)
			{
				best = score;
				FILE *bestFile = fopen("best.txt", "w");
				fprintf(bestFile, "%d", best);
				fclose(bestFile);
			}
			FILE *scoreFile = fopen("score.txt", "a");
			fprintf(scoreFile, "%s %d\n", s, score);
			fclose(scoreFile);
			if (quit == 0)
				quit = 1;
			else
				quit = 0;
		}
		if (game_state==2 && profile == 1)
		{
			if (key != '\r')
			{
				if (key != '\b')
				{
					s[i] = key;
					i++;
				}
				else
				{
					if (i >= 0)
					{
						s[i - 1] = 0;
						i--;
					}
					else
					{
						i = 0;
					}
				}
			}
			else
			{
				FILE *scoreFile = fopen("score.txt", "a");
			fprintf(scoreFile, "%s\n", s);
			fclose(scoreFile);
				for (int j = 0; j < i; j++)
				{
					s[j] = 0;
				}
				i = 0;
				profile = 0;
			}
		}
		if (quit == 1 && key == '\r')
		{
			exit(0);
		}
		if (game_state == 5 && key == '\r')
		{
			game_state = 2;
			if (score > best)
			{
				best = score;
				FILE *bestFile = fopen("best.txt", "a");
				fprintf(bestFile, "%d", best);
				fclose(bestFile);
			}
			FILE *scoreFile = fopen("score.txt", "a");
			fprintf(scoreFile, "%s %d\n", s,score);
			fclose(scoreFile);
			life = 3;
			score = 0;
			zenTime = 0;
			p = 0;
			life = 3;
			ystraw = -10;
			// printf("%d",game_state);
		}
		
		else if (key == '\r' && sett == 1 && lead == 1)
		{
			lead = 0;
		}
		else if (key == '\r' && sett == 1 && profile == 0 && lead == 0)
		{
			sett = 0;
		}
	}
	void iSpecialKeyboard(unsigned char key)
	{
	}
	void load()
	{
		lin += 2;
		if (lin > 400)
		{
			game_state = 2;
		}
	}
	void cl_zen()
	{
		clin++;
		if (clin > 7)
			clin = 0;
		zin++;
		if (zin > 6)
			zin = 0;
		plgin++;
		if (plgin > 7)
			plgin = 0;
		ein++;
		if (ein > 7)
			ein = 0;
	}
	void fruitmotion()
	{

		x = v * cos(theta * pi / 180) * t;
		y = x * tan(theta * pi / 180) - 0.5 * g * x * x / (v * cos(theta * pi / 180)) / (v * cos(theta * pi / 180));
		t++;
		if (game_state == 3)
		{
			if (fruit_cut == 0 && y < -10 && fruit_index < 5)
			{

				life--;
				/// printf("Life -1 = %d\n", life);
			}
			if (life == 0)
			{
				game_state = 4;
			}
		}
		if (y < -10)
		{
			t = 1;
			fruit_index = rand() % 7;
			if (fruit_index > 4)
			{
				bomb = 1;
			}
			else
			{
				bomb = 0;
			}
			xstraw = 30 + rand() % 800;
			theta = 80 + rand() % 10;
		}

		if (fruit_cut && y < -10)
		{
			fruit_cut = 0; // fruit is alive again
			slicing = 0;
		}
	}
	void fruit()
	{
		stin++;
		if (stin > 6 || x == xstraw)
			stin = 0;
	}
	void function_change()
	{
		if (game_state == 4)
			game_state = 5;
		if (game_state == 7)
			game_state = 8;
	}
	void zen_function_change()
	{
		zenTime += 2;
		if (zenTime == 120)
			game_state = 7;
	}
	void fruit_change()
	{
		if (fruit_cut && y > 0 && slicing == 1)
			slicing = 0;
	}

	int main()
	{
		initializefruits();
		iSetTimer(0.01, load);
		iSetTimer(200, cl_zen);
		iSetTimer(2, fruitmotion);
		iSetTimer(200, fruit);
		iSetTimer(5000, function_change);
		iSetTimer(100, fruit_change);
		iSetTimer(1000, zen_function_change);
		if (music)
		{
			PlaySound("music\\1.wav.wav", NULL, SND_LOOP | SND_ASYNC);
			Sleep(5000);
			if (slicing)
				PlaySound("music\\slice.wav.wav", NULL, SND_ASYNC);
		}
		iInitialize(1000, 600, "Fruit ninja");
		return 0;
	}
