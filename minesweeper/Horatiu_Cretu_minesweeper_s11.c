
void print(int h, int w, char t[h][w])
{
    int nr=1;
    char ch='A';
    printf("  ");
    for(int i =0; i < w; i++)
    {
        printf("%c",ch);
        ch++;
    }
    printf("\n");
    for(int i = 0; i < h; i++)
    {
        printf("%d ",nr);
        for(int j = 0; j < w; j++)
        {
            printf("%c",t[i][j]);
        }
        printf("% d",nr);
        nr++;
        printf("\n");
    }
    ch='A';
    printf("  ");
    for(int i =0; i < w; i++)
    {
        printf("%c",ch);
        ch++;
    }
}
void create(int nr_bombs, char cols[], int rows[], int h, int w, char t[h][w])
{
    for(int i = 0; i<h; i++)
        for(int j = 0; j<w; j++)
            t[i][j]='0';
    for(int i = 0; i<nr_bombs; i++)
    {
        int x1=(rows[i]-1);
        int x2=(cols[i]-65);
        t[x1][x2]='X';
        int rnd[]={-1,-1,-1,0,1,1,1,0};
        int col[]={-1,0,1,1,1,0,-1,-1};
        for(int k=0;k<8;k++)
        {
            int ik=x1+rnd[k];
            int jk=x2+col[k];
            if(t[ik][jk]!='X')
                t[ik][jk]++;
        }
    }
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(t[i][j]=='0')
                t[i][j]='.';
}
char** init_state(int h, int w)
{
    char** s=calloc(h,sizeof(char*));
    for(int i=0;i<h;i++)
    {
        s[i]=calloc(w,sizeof(char));
        for(int j=0;j<w;j++)
            s[i][j]='?';
    }
    return s;
}
int discover(int i, int j, int h, int w, char t[h][w], char** s)
{
    if(i<0 || i>h || j<0 || j>w)
        return -2;
    if(t[i][j]=='X')
        return -1;
    if(s[i][j]=='.')
        return 0;
    if(t[i][j]>='1' && t[i][j]<='9')
        {
            s[i][j]='.';
            return 1;
        }
    if(t[i][j]=='.')
    {
        s[i][j]='.';
        int rnd[]={-1,-1,-1,0,1,1,1,0};
        int col[]={-1,0,1,1,1,0,-1,-1};
        for(int k=0;k<8;k++)
        {
            int ik=i+rnd[k];
            int jk=j+col[k];
            discover(ik,jk,h,w,t,s);
        }
        return 2;
    }
}
void mark(int i, int j, int h, int w, char** s)
{
    if(s[i][j]=='?')
        s[i][j]='!';
    else
        if(s[i][j]=='!')
            s[i][j]='?';
        else
            printf("wrong command");
}
void player_view(int h,int w, char t[h][w], char ** s)
{
    int nr=1;
    char ch='A';
    printf("  ");
    for(int i =0; i < w; i++)
    {
        printf("%c ",ch);
        ch++;
    }
    printf("\n");
    for(int i = 0; i < h; i++)
    {
        printf("%d ",nr);
        for(int j = 0; j < w; j++)
        {
            if (s[i][j]=='.')
                printf("%c ",t[i][j]);
            else
                printf("%c ",s[i][j]);
        }
        printf("% d",nr);
        nr++;
        printf("\n");
    }
    ch='A';
    printf("  ");
    for(int i =0; i < w; i++)
    {
        printf("%c ",ch);
        ch++;
    }
}
