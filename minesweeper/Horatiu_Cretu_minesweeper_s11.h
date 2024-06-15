#ifndef MINESWEEPER_H_INCLUDED
#define MINESWEEPER_H_INCLUDED

void print(int h, int w, char t[h][w]);
void create(int nr_bombs, int cols[100], int rows[], int h, int w, char t[h][w]);
char** init_state(int h,int w);
int discover(int i,int j,int h,int w,int t,char** s);
void mark(int i,int j,int h,int w,char** s);
void player_view(int h,int w,char t[h][w],char** s);
#endif // MINESWEEPER_H_INCLUDED
