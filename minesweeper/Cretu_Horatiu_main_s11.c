#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Horatiu_Cretu_minesweeper_s11.h"


int main()
{
    int nr_bombs = 6;
    char cols[100] = {'B', 'D','I','F','J','B'},t[100][100];
    int rows[100] = {1, 2, 2, 4, 5, 4};
    int h = 5, w = 10;
    create(nr_bombs,cols,rows,h,w,t);
    print(h,w,t);
    char** s=init_state(h,w);
    printf("\n\n");
    puts("your view\n");
    player_view(h,w,t,s);
    discover(1,5,h,w,t,s);
    puts("\n");
    player_view(h,w,t,s);



    return 0;
}
