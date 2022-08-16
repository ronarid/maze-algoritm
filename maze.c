

#define wmaze0 42001





unsigned int wmaze=wmaze0;

char mapmaze[wmaze0][wmaze0];


unsigned int  slcg8;

unsigned int  lcg8()
{
  return ((slcg8=((slcg8*0x5b1f95)+0x16365))>>24);
}

#define rand8 lcg8()
#define rand16 ((slcg8 = ((slcg8 *  0x5b1f95) + 0x16365))>>16)


unsigned char  var8rand;
//unsigned short rand16;
unsigned int var32rand;

unsigned char  bivis;

struct coords
{
    int x;
    int y;
};




int main()
{
  slcg8=(time(0));lcg8();



//wmaze=27;








    for(int x1=0;x1<wmaze;x1++)
    {
        mapmaze[x1][0]=1;
        mapmaze[0][x1]=1;
        mapmaze[x1][wmaze-1]=1;
        mapmaze[wmaze-1][x1]=1;
    }
    for(int x1=1;x1<wmaze-1;x1++)
    {
        for(int y1=1;y1<wmaze-1;y1++)
        {
            if((x1&1) || (y1&1))
                mapmaze[x1][y1]=0;
            else
                mapmaze[x1][y1]=1;
        }
    }


//    unsigned long long  totwall = ( (wmaze/2) * ((wmaze/2)-1) *2 );
    unsigned long long  maxwall = (((wmaze-9)/4)*((wmaze-5)/4))+1;
    unsigned long long  maxwall2 = ((maxwall/2)*3);
    unsigned long long  wallcount = 0;

//    unsigned int highestx = 0;
//    unsigned int highesty = 0;
//    unsigned int lowestx = wmaze ;
//    unsigned int lowesty = wmaze ;
    struct coords highestx = {0,0},
    highesty = {0,0},
    lowestx = {wmaze,wmaze},
    lowesty = {wmaze,wmaze};
    unsigned char  lastextreme = 0;



    //prima parete
    struct coords startcords={ wmaze/2,wmaze/2 };
    struct coords nowcords=startcords;
    struct coords lastsuperbivio=startcords;


    struct coords lastbivio=nowcords;
     bivis=4;
    if(lastbivio.x==4)
        bivis--;
    if(lastbivio.y==4)
        bivis--;
    if(lastbivio.x==wmaze-4)
        bivis--;
    if(lastbivio.y==wmaze-4)
        bivis--;

    unsigned char  direction=rand8%4;
    if((nowcords.y==4)&&(direction==0))
        direction++;
    if((nowcords.x==wmaze-4)&&(direction==1))
        direction++;
    if((nowcords.y==wmaze-4)&&(direction==2))
        direction++;
    if((nowcords.x==4)&&(direction==3))
        direction=0;
    if((nowcords.y==4)&&(direction==0))
        direction++;
    if((nowcords.x==wmaze-4)&&(direction==1))
        direction++;
    if((nowcords.y==wmaze-4)&&(direction==2))
        direction++;
    if((nowcords.x==4)&&(direction==3))
        direction++;

//printf("3");
//
//unsigned int ct03=0;

    do
    {
        do
        {

//printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);

            if(direction==0)//su
            {
                if( ((int)nowcords.y-4>0)  && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)
                   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)  )
                {
                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                    nowcords.y-=2;
                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                    nowcords.y-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5)&&(mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)  && (mapmaze[nowcords.x+3][nowcords.y]==0) )
                        possible++;
                    if( ((int)nowcords.x-4>0)&&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)  && (mapmaze[(int)nowcords.x-3][nowcords.y]==0) )
                        possible+=2;
                    if( (nowcords.y<wmaze-5)&&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)  && (mapmaze[nowcords.x][nowcords.y+3]==0) )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=2;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==1)//destra
            {
                if( (nowcords.x<wmaze-5)&&(mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)
                   && (mapmaze[nowcords.x+3][nowcords.y]==0)  )
                {
                    mapmaze[nowcords.x+1][nowcords.y]=1;
                    nowcords.x+=2;
                    mapmaze[nowcords.x+1][nowcords.y]=1;
                    nowcords.x+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-4>0) &&(mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0) )
                        possible++;
                    if( (nowcords.y<wmaze-5)&&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)  && (mapmaze[nowcords.x][nowcords.y+3]==0) )
                        possible+=2;
                    if( ((int)nowcords.x-4>0)&&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)  && (mapmaze[(int)nowcords.x-3][nowcords.y]==0) )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=3;
                        continue;
                    }
                    else
                        break;
                }

            }
            if(direction==2)//giu
            {
                if( (nowcords.y<wmaze-5)&&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)
                   && (mapmaze[nowcords.x][nowcords.y+3]==0)  )
                {
                    mapmaze[nowcords.x][nowcords.y+1]=1;
                    nowcords.y+=2;
                    mapmaze[nowcords.x][nowcords.y+1]=1;
                    nowcords.y+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5)&&(mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)  && (mapmaze[nowcords.x+3][nowcords.y]==0) )
                        possible++;
                    if( ((int)nowcords.x-4>0)&&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)  && (mapmaze[(int)nowcords.x-3][nowcords.y]==0) )
                        possible+=2;
                    if( ((int)nowcords.y-4>0) &&(mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0) )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=0;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==3)//sinix
            {
                if( ((int)nowcords.x-4>0)&&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)
                   && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)  )
                {
                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                    nowcords.x-=2;
                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                    nowcords.x-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-4>0) &&(mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0) )
                        possible++;
                    if( (nowcords.y<wmaze-5)&&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)  && (mapmaze[nowcords.x][nowcords.y+3]==0) )
                        possible+=2;
                    if( (nowcords.x<wmaze-5)&&(mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)  && (mapmaze[nowcords.x+3][nowcords.y]==0) )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=1;
                        continue;
                    }
                    else
                        break;
                }
            }
            wallcount+=2;

//printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);
//getch();


             bivis=4;
            if(((int)nowcords.y-5<0)? 1  : ( (mapmaze[nowcords.x][(int)nowcords.y-5]) || (mapmaze[nowcords.x][(int)nowcords.y-3]) || (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]) || (mapmaze[nowcords.x+1][(int)nowcords.y-4])    ) )
                bivis--;
            if(((int)nowcords.x-5<0)? 1  : ( (mapmaze[(int)nowcords.x-5][nowcords.y]) || (mapmaze[(int)nowcords.x-3][nowcords.y]) || (mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]) || (mapmaze[(int)nowcords.x-4][nowcords.y+1])    ) )
                bivis--;
            if((nowcords.y+5>=wmaze)? 1 : ( (mapmaze[nowcords.x][nowcords.y+5]) || (mapmaze[nowcords.x][nowcords.y+3]) || (mapmaze[(int)nowcords.x-1][nowcords.y+4]) || (mapmaze[nowcords.x+1][nowcords.y+4])    ) )
                bivis--;
            if((nowcords.x+5>=wmaze)? 1  : ( (mapmaze[nowcords.x+5][nowcords.y]) || (mapmaze[nowcords.x+3][nowcords.y]) || (mapmaze[nowcords.x+4][(int)nowcords.y-1]) || (mapmaze[nowcords.x+4][nowcords.y+1])    ) )
                bivis--;

            if(bivis>1)
            {
                lastbivio.x=nowcords.x;
                lastbivio.y=nowcords.y;

                if(nowcords.x>=highestx.x)
                {
                    highestx.x=nowcords.x;
                    highestx.y=nowcords.y;
                    lastextreme&=0b11111110;
                }
                if(nowcords.y>=highesty.y)
                {
                    highesty.x=nowcords.x;
                    highesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111101);
                }
                if(nowcords.x<=lowestx.x)
                {
                    lowestx.x=nowcords.x;
                    lowestx.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111011);
                }
                if(nowcords.y<=lowesty.y)
                {
                    lowesty.x=nowcords.x;
                    lowesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11110111);
                }

//            printf("%u ",ct03++);

                //check superbivio
                bivis+=8;
                if(((int)nowcords.y-9<0)? 1  : ( (mapmaze[nowcords.x][(int)nowcords.y-9]) || (mapmaze[nowcords.x][(int)nowcords.y-7]) || (mapmaze[(int)nowcords.x-1][(int)nowcords.y-8]) || (mapmaze[nowcords.x+1][(int)nowcords.y-8])    ) )
                    {bivis--;}
                if(((int)nowcords.x-9<0)? 1  : ( (mapmaze[(int)nowcords.x-9][nowcords.y]) || (mapmaze[(int)nowcords.x-7][nowcords.y]) || (mapmaze[(int)nowcords.x-8][(int)nowcords.y-1]) || (mapmaze[(int)nowcords.x-8][nowcords.y+1])    ) )
                    {bivis--;}
                if((nowcords.y+9>=wmaze)? 1 : ( (mapmaze[nowcords.x][nowcords.y+9]) || (mapmaze[nowcords.x][nowcords.y+7]) || (mapmaze[(int)nowcords.x-1][nowcords.y+8]) || (mapmaze[nowcords.x+1][nowcords.y+8])    ) )
                    bivis--;
                if((nowcords.x+9>=wmaze)? 1  : ( (mapmaze[nowcords.x+9][nowcords.y]) || (mapmaze[nowcords.x+7][nowcords.y]) || (mapmaze[nowcords.x+8][(int)nowcords.y-1]) || (mapmaze[nowcords.x+8][nowcords.y+1])    ) )
                    bivis--;
                if((((int)nowcords.y-9<0)||((int)nowcords.x-9<0))? 1  : ( (mapmaze[(int)nowcords.x-8][(int)nowcords.y-9]) || (mapmaze[(int)nowcords.x-8][(int)nowcords.y-7]) || (mapmaze[(int)nowcords.x-9][(int)nowcords.y-8]) || (mapmaze[(int)nowcords.x-7][(int)nowcords.y-8])    ) )
                    bivis--;
                if((((int)nowcords.x-9<0)||(nowcords.y+9>=wmaze))? 1  : ( (mapmaze[(int)nowcords.x-9][nowcords.y+8]) || (mapmaze[(int)nowcords.x-7][nowcords.y+8]) || (mapmaze[(int)nowcords.x-8][nowcords.y+8-1]) || (mapmaze[(int)nowcords.x-8][nowcords.y+8+1])    ) )
                    bivis--;
                if(((nowcords.y+9>=wmaze)||(nowcords.x+9>=wmaze))? 1 : ( (mapmaze[nowcords.x+8][nowcords.y+9]) || (mapmaze[nowcords.x+8][nowcords.y+7]) || (mapmaze[nowcords.x+8-1][nowcords.y+8]) || (mapmaze[nowcords.x+8+1][nowcords.y+8])    ) )
                    bivis--;
                if((((int)nowcords.y-9<0)||(nowcords.x+9>=wmaze))? 1  : ( (mapmaze[nowcords.x+8][(int)nowcords.y-9]) || (mapmaze[nowcords.x+8][(int)nowcords.y-7]) || (mapmaze[nowcords.x+9][(int)nowcords.y-8]) || (mapmaze[nowcords.x+7][(int)nowcords.y-8])    ) )
                    bivis--;

                if(bivis>5)
                {
                    lastsuperbivio.x=nowcords.x;
                    lastsuperbivio.y=nowcords.y;
                }
            }
//            else if(bivis==2)
//            {
//                lastbivio.x=nowcords.x;
//                lastbivio.y=nowcords.y;
//
//                if(nowcords.x>=highestx.x)
//                {
//                    highestx.x=nowcords.x;
//                    highestx.y=nowcords.y;
//                    lastextreme&=0b11111110;
//                }
//                if(nowcords.y>=highesty.y)
//                {
//                    highesty.x=nowcords.x;
//                    highesty.y=nowcords.y;
//                    lastextreme=(lastextreme&0b11111101);
//                }
//                if(nowcords.x<=lowestx.x)
//                {
//                    lowestx.x=nowcords.x;
//                    lowestx.y=nowcords.y;
//                    lastextreme=(lastextreme&0b11111011);
//                }
//                if(nowcords.y<=lowesty.y)
//                {
//                    lowesty.x=nowcords.x;
//                    lowesty.y=nowcords.y;
//                    lastextreme=(lastextreme&0b11110111);
//                }
//            }
            else if(bivis==0)
                break;

//    printf(" 7 ");
            var8rand=rand8;
            if(var8rand<85)
                direction=((direction-1)&3);
            else if(var8rand>170)
                direction=(direction+1)%4;






        }while(wallcount<maxwall);




        if((nowcords.x==lastbivio.x)&&(nowcords.y==lastbivio.y))
        {
            if( (!(lastextreme&1)) && (highestx.x<highesty.y) && (highestx.x<(wmaze-lowestx.x)) && (highestx.x<(wmaze-lowesty.y)) )
            {
                nowcords.x=highestx.x;
                nowcords.y=highestx.y;
                lastextreme=(lastextreme|1);
            }
            else if((!(lastextreme&0b10)) && (highesty.y<(wmaze-lowestx.x)) && (highesty.y<(wmaze-lowesty.y)) )
            {
                nowcords.x=highesty.x;
                nowcords.y=highesty.y;
                lastextreme=(lastextreme|0b10);
            }
            else if( (!(lastextreme&0b100)) && (lowestx.x>lowesty.y) )
            {
                nowcords.x=lowestx.x;
                nowcords.y=lowestx.y;
                lastextreme=(lastextreme|0b100);
            }
            else if(!(lastextreme&0b1000))
            {
                nowcords.x=lowesty.x;
                nowcords.y=lowesty.y;
                lastextreme=(lastextreme|0b1000);
            }
            else if((nowcords.x!=lastsuperbivio.x)||(nowcords.y!=lastsuperbivio.y))
            {
                nowcords.x=lastsuperbivio.x;
                nowcords.y=lastsuperbivio.y;
            }
            else
                break;
//                nowcords={ ((rand16%((wmaze/4)-1))*4)+4 , ((rand16%((wmaze/4)-1))*4)+4 };
            lastbivio.x=nowcords.x;
            lastbivio.y=nowcords.y;
             bivis=4;
            if(lastbivio.x==4)
                bivis--;
            if(lastbivio.y==4)
                bivis--;
            if(lastbivio.x==wmaze-4)
                bivis--;
            if(lastbivio.y==wmaze-4)
                bivis--;

            unsigned char  direction=rand8%4;
            if((nowcords.y==4)&&(direction==0))
                direction++;
            if((nowcords.x==wmaze-4)&&(direction==1))
                direction++;
            if((nowcords.y==wmaze-4)&&(direction==2))
                direction++;
            if((nowcords.x==4)&&(direction==3))
                direction=0;
            if((nowcords.y==4)&&(direction==0))
                direction++;
            if((nowcords.x==wmaze-4)&&(direction==1))
                direction++;
            if((nowcords.y==wmaze-4)&&(direction==2))
                direction++;
            if((nowcords.x==4)&&(direction==3))
                direction++;
        }
//            break;
        else
        {
            {
                nowcords.x=lastbivio.x;
                nowcords.y=lastbivio.y;
                direction=((direction+1)&3);
            }
        }


    }while(wallcount<maxwall);
    //fine prima parete (e fin qua funziona eh)



//return 9;



    //seconda parete
do{
//    unsigned int rand33=rand16;
//    unsigned int rand34=rand16;
    nowcords.x = ((rand16%((wmaze/4)))*4)+2 ;
    nowcords.y =  ((rand16%((wmaze/4)))*4)+2 ;

    lastbivio.x=nowcords.x;
    lastbivio.y=nowcords.y;
    lastsuperbivio.x=nowcords.x;
    lastsuperbivio.y=nowcords.y;

    highestx.x = 0;
    highestx.y = 0;
    highesty.x = 0;
    highesty.y = 0;
    lowestx.x =lowestx.y = wmaze;
    lowesty.x =lowesty.y = wmaze;
    lastextreme = 0;

    bivis=4;
    if(lastbivio.x==2)
        bivis--;
    if(lastbivio.y==2)
        bivis--;
    if(lastbivio.x==wmaze-2)
        bivis--;
    if(lastbivio.y==wmaze-2)
        bivis--;

    direction=rand8%4;
    if((nowcords.y==2)&&(direction==0))
        direction++;
    if((nowcords.x==wmaze-2)&&(direction==1))
        direction++;
    if((nowcords.y==wmaze-2)&&(direction==2))
        direction++;
    if((nowcords.x==2)&&(direction==3))
        direction=0;
    if((nowcords.y==2)&&(direction==0))
        direction++;
    if((nowcords.x==wmaze-2)&&(direction==1))
        direction++;
    if((nowcords.y==wmaze-2)&&(direction==2))
        direction++;
    if((nowcords.x==2)&&(direction==3))
        direction++;

//    wallcount = 0;

//printf("6");
    do
    {
        do
        {

//printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);

            if(direction==0)//su
            {
                if( ((int)nowcords.y-2>0)  && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)
                   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                {
                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                    nowcords.y-=2;
                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                    nowcords.y-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)
                   && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                        possible++;
                    if( (nowcords.x-4>0) &&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)
                   && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=2;
                    if( (nowcords.y<wmaze-5) &&(mapmaze[nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)
                   && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=2;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==1)//destra
            {
                if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)
                   && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                {
                    mapmaze[nowcords.x+1][nowcords.y]=1;
                    nowcords.x+=2;
                    mapmaze[nowcords.x+1][nowcords.y]=1;
                    nowcords.x+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)
                   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                        possible++;
                    if( (nowcords.y<wmaze-5) &&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)
                   && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                         possible+=2;
                    if( ((int)nowcords.x-4>0) &&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)
                   && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=3;
                        continue;
                    }
                    else
                        break;
                }

            }
            if(direction==2)//giu
            {
                if( (nowcords.y<wmaze-5) &&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)
                   && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                {
                    mapmaze[nowcords.x][nowcords.y+1]=1;
                    nowcords.y+=2;
                    mapmaze[nowcords.x][nowcords.y+1]=1;
                    nowcords.y+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)
                   && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                        possible++;
                    if( ((int)nowcords.x-4>0) &&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)
                    && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=2;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)
                   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=0;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==3)//sinix
            {
                if( ((int)nowcords.x-4>0) &&(mapmaze[(int)nowcords.x-4][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-4][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-5][nowcords.y]==0)
                   && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                {
                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                    nowcords.x-=2;
                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                    nowcords.x-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-4]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-4]==0)  && (mapmaze[nowcords.x][(int)nowcords.y-5]==0)
                   && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                        possible++;
                    if( (nowcords.y<wmaze-5) &&(mapmaze[(int)nowcords.x-1][nowcords.y+4]==0) && (mapmaze[nowcords.x+1][nowcords.y+4]==0) && (mapmaze[nowcords.x][nowcords.y+5]==0)
                   && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                        possible+=2;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+4][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+4][nowcords.y+1]==0) && (mapmaze[nowcords.x+5][nowcords.y]==0)
                   && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=1;
                        continue;
                    }
                    else
                        break;
                }
            }
            wallcount+=2;
//printf("5");

             bivis=4;
            if(((int)nowcords.y-5<0)? 1  : ( (mapmaze[nowcords.x][nowcords.y-5]) || (mapmaze[nowcords.x][nowcords.y-3]) || (mapmaze[nowcords.x-1][nowcords.y-4]) || (mapmaze[nowcords.x+1][nowcords.y-4])
                                       || (mapmaze[nowcords.x][nowcords.y-1])  || (mapmaze[nowcords.x-1][nowcords.y-2]) || (mapmaze[nowcords.x+1][nowcords.y-2])    ) )
                bivis--;
            if(((int)nowcords.x-5<0)? 1  : ( (mapmaze[nowcords.x-5][nowcords.y]) || (mapmaze[nowcords.x-3][nowcords.y]) || (mapmaze[nowcords.x-4][nowcords.y-1]) || (mapmaze[nowcords.x-4][nowcords.y+1])
                                       || (mapmaze[nowcords.x-1][nowcords.y]) ||  (mapmaze[nowcords.x-2][nowcords.y-1]) || (mapmaze[nowcords.x-2][nowcords.y+1])    ) )
                bivis--;
            if((nowcords.y+5>=wmaze)? 1 : ( (mapmaze[nowcords.x][nowcords.y+5]) || (mapmaze[nowcords.x][nowcords.y+3]) || (mapmaze[nowcords.x-1][nowcords.y+4]) || (mapmaze[nowcords.x+1][nowcords.y+4])
                                            || (mapmaze[nowcords.x][nowcords.y+1]) || (mapmaze[nowcords.x-1][nowcords.y+2]) || (mapmaze[nowcords.x+1][nowcords.y+2])    ) )
                bivis--;
            if((nowcords.x+5>=wmaze)? 1  : ( (mapmaze[nowcords.x+5][nowcords.y]) || (mapmaze[nowcords.x+3][nowcords.y]) || (mapmaze[nowcords.x+4][nowcords.y-1]) || (mapmaze[nowcords.x+4][nowcords.y+1])
                                             || (mapmaze[nowcords.x+1][nowcords.y]) || (mapmaze[nowcords.x+2][nowcords.y-1]) || (mapmaze[nowcords.x+2][nowcords.y+1])    ) )
                bivis--;
                if(bivis>2)
            {
                lastbivio.x=nowcords.x;
                lastbivio.y=nowcords.y;
                lastsuperbivio.x=nowcords.x;
                lastsuperbivio.y=nowcords.y;

                if(nowcords.x>=highestx.x)
                {
                    highestx.x=nowcords.x;
                    highestx.y=nowcords.y;
                    lastextreme&=0b11111110;
                }
                if(nowcords.y>=highesty.y)
                {
                    highesty.x=nowcords.x;
                    highesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111101);
                }
                if(nowcords.x<=lowestx.x)
                {
                    lowestx.x=nowcords.x;
                    lowestx.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111011);
                }
                if(nowcords.y<=lowesty.y)
                {
                    lowesty.x=nowcords.x;
                    lowesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11110111);
                }
            }
            else if(bivis==2)
            {
                lastbivio.x=nowcords.x;
                lastbivio.y=nowcords.y;

                if(nowcords.x>=highestx.x)
                {
                    highestx.x=nowcords.x;
                    highestx.y=nowcords.y;
                    lastextreme&=0b11111110;
                }
                if(nowcords.y>=highesty.y)
                {
                    highesty.x=nowcords.x;
                    highesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111101);
                }
                if(nowcords.x<=lowestx.x)
                {
                    lowestx.x=nowcords.x;
                    lowestx.y=nowcords.y;
                    lastextreme=(lastextreme&0b11111011);
                }
                if(nowcords.y<=lowesty.y)
                {
                    lowesty.x=nowcords.x;
                    lowesty.y=nowcords.y;
                    lastextreme=(lastextreme&0b11110111);
                }
            }
            else if(bivis==0)
                break;


            var8rand=rand8;
            if(var8rand<85)
                direction=((direction-1)&3);
            else if(var8rand>170)
                direction=(direction+1)%4;





        }while(1);


//printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);
//getch();

        if((nowcords.x==lastbivio.x)&&(nowcords.y==lastbivio.y))
        {

            if( (!(lastextreme&1)) && (highestx.x<highesty.y) && (highestx.x<(wmaze-lowestx.x)) && (highestx.x<(wmaze-lowesty.y)) )
            {
                nowcords.x=highestx.x;
                nowcords.y=highestx.y;
                lastextreme=(lastextreme|1);
            }
            else if((!(lastextreme&0b10)) && (highesty.y<(wmaze-lowestx.x)) && (highesty.y<(wmaze-lowesty.y)) )
            {
                nowcords.x=highesty.x;
                nowcords.y=highesty.y;
                lastextreme=(lastextreme|0b10);
            }
            else if( (!(lastextreme&0b100)) && (lowestx.x>lowesty.y) )
            {
                nowcords.x=lowestx.x;
                nowcords.y=lowestx.y;
                lastextreme=(lastextreme|0b100);
            }
            else if(!(lastextreme&0b1000))
            {
                nowcords.x=lowesty.x;
                nowcords.y=lowesty.y;
                lastextreme=(lastextreme|0b1000);
            }
            else if((nowcords.x!=lastsuperbivio.x)||(nowcords.y!=lastsuperbivio.y))
            {
                nowcords.x=lastsuperbivio.x;
                nowcords.y=lastsuperbivio.y;
            }
            else
                break;

            lastbivio.x=nowcords.x;
            lastbivio.y=nowcords.y;
             bivis=4;
            if(lastbivio.x==4)
                bivis--;
            if(lastbivio.y==4)
                bivis--;
            if(lastbivio.x==wmaze-4)
                bivis--;
            if(lastbivio.y==wmaze-4)
                bivis--;

            unsigned char  direction=rand8%4;
            if((nowcords.y==4)&&(direction==0))
                direction++;
            if((nowcords.x==wmaze-4)&&(direction==1))
                direction++;
            if((nowcords.y==wmaze-4)&&(direction==2))
                direction++;
            if((nowcords.x==4)&&(direction==3))
                direction=0;
            if((nowcords.y==4)&&(direction==0))
                direction++;
            if((nowcords.x==wmaze-4)&&(direction==1))
                direction++;
            if((nowcords.y==wmaze-4)&&(direction==2))
                direction++;
            if((nowcords.x==4)&&(direction==3))
                direction++;
        }
        else
        {
            {
                nowcords.x=lastbivio.x;
                nowcords.y=lastbivio.y;
                direction=((direction+1)&3);
            }
        }


    }while(1);

}while(wallcount<maxwall);
    //fine seconda parete (e pure fin qua funziona)



//    printf("3");
//    getch();







    //terza serie di pareti
do{
    nowcords.x= ((rand16%(((wmaze/2)-1)))*2)+2 ;
    nowcords.y= ((rand16%(((wmaze/2)-1)))*2)+2 ;

    lastbivio.x=nowcords.x;
    lastbivio.y=nowcords.y;


    direction=rand8%4;

    do
    {
        do
        {

//printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);

            if(direction==0)//su
            {
                if( ((int)nowcords.y-2>0) && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                {
                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                    nowcords.y-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                        possible++;
                    if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=2;
                    if( (nowcords.y<wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=2;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==1)//destra
            {
                if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                {
                    mapmaze[nowcords.x+1][nowcords.y]=1;
                    nowcords.x+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                        possible++;
                    if( (nowcords.y<wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                         possible+=2;
                    if( (nowcords.x-4>0) && (mapmaze[nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && ((int)mapmaze[nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=3;
                        continue;
                    }
                    else
                        break;
                }

            }
            if(direction==2)//giu
            {
                if( (nowcords.y<wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                {
                    mapmaze[nowcords.x][nowcords.y+1]=1;
                    nowcords.y+=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                        possible++;
                    if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                        possible+=2;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=1;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=3;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=1;
                            continue;
                        }
                        else
                        {
                            direction=3;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=0;
                        continue;
                    }
                    else
                        break;
                }
            }
            else if(direction==3)//sinix
            {
                if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                {
                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                    nowcords.x-=2;
                }
                else
                {
                    unsigned char  possible=0;
                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                        possible++;
                    if( (nowcords.y<wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                        possible+=2;
                    if( (nowcords.x<wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                         possible+=4;

                    if((possible&3)==1)
                    {
                        direction=0;
                        continue;
                    }
                    else if((possible&3)==2)
                    {
                        direction=2;
                        continue;
                    }
                    else if((possible&3)==3)
                    {
                        var8rand=rand8;
                        if(var8rand<128)
                        {
                            direction=0;
                            continue;
                        }
                        else
                        {
                            direction=2;
                            continue;
                        }
                    }
                    else if(possible>0)
                    {
                        direction=1;
                        continue;
                    }
                    else
                        break;
                }
            }
            wallcount++;


             bivis=4;
            if(((int)nowcords.y-5<0)? 1  : ( (mapmaze[nowcords.x][(int)nowcords.y-3])
                                       || (mapmaze[nowcords.x][(int)nowcords.y-1])  || (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]) || (mapmaze[nowcords.x+1][(int)nowcords.y-2])    ) )
                bivis--;
            if(((int)nowcords.x-5<0)? 1  : ( (mapmaze[(int)nowcords.x-3][nowcords.y])
                                       || (mapmaze[(int)nowcords.x-1][nowcords.y]) ||  (mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]) || (mapmaze[(int)nowcords.x-2][nowcords.y+1])    ) )
                bivis--;
            if((nowcords.y+5>=wmaze)? 1 : ( (mapmaze[nowcords.x][nowcords.y+3])
                                            || (mapmaze[nowcords.x][nowcords.y+1]) || (mapmaze[(int)nowcords.x-1][nowcords.y+2]) || (mapmaze[nowcords.x+1][nowcords.y+2])    ) )
                bivis--;
            if((nowcords.x+5>=wmaze)? 1  : ( (mapmaze[nowcords.x+3][nowcords.y])
                                             || (mapmaze[nowcords.x+1][nowcords.y]) || (mapmaze[nowcords.x+2][(int)nowcords.y-1]) || (mapmaze[nowcords.x+2][nowcords.y+1])    ) )
                bivis--;

            if(bivis>1)
            {
                lastbivio.x=nowcords.x;
                lastbivio.y=nowcords.y;
            }
            else if(bivis==0)
                break;


            var8rand=rand8;
            if(var8rand<85)
                direction=(((int)direction-1)&3);
            else if(var8rand>170)
                direction=(direction+1)%4;





        }while(1);

        if((nowcords.x==lastbivio.x)&&(nowcords.y==lastbivio.y))
        {
            break;
        }
        else
        {
            {
                nowcords.x=lastbivio.x;
                nowcords.y=lastbivio.y;
                direction=((direction+1)&3);
            }
        }


    }while(1);
}while(wallcount<maxwall2);
    //fine terza serie pareti









    //le ultime pareti




//    unsigned int lastcheckedx = 2;
//    unsigned int lastcheckedy = 2;

    do
    {
        for(unsigned int lastcheckedy = 2; lastcheckedy<(int)wmaze-2; lastcheckedy+=2)
        {
            for(unsigned int lastcheckedx = 2; lastcheckedx<(int)wmaze-2; lastcheckedx+=2)
            {

                unsigned char  freeway=4;
                if ( (lastcheckedx==2)? 1 : (  (mapmaze[(int)lastcheckedx-3][lastcheckedy]) || (mapmaze[(int)lastcheckedx-1][lastcheckedy]) ||
                                              (mapmaze[(int)lastcheckedx-2][(int)lastcheckedy-1]) || (mapmaze[(int)lastcheckedx-2][lastcheckedy+1]) )  )
                   freeway--;
                if ( (lastcheckedy==2)? 1 : (  (mapmaze[lastcheckedx][(int)lastcheckedy-3]) || (mapmaze[lastcheckedx][(int)lastcheckedy-1]) ||
                                              (mapmaze[(int)lastcheckedx-1][(int)lastcheckedy-2]) || (mapmaze[lastcheckedx+1][(int)lastcheckedy-2]) )  )
                   freeway--;
                if ( (lastcheckedx==(int)wmaze-3)? 1 : (  (mapmaze[lastcheckedx+3][lastcheckedy]) || (mapmaze[lastcheckedx+1][lastcheckedy]) ||
                                              (mapmaze[lastcheckedx+2][(int)lastcheckedy-1]) || (mapmaze[lastcheckedx+2][lastcheckedy+1]) )  )
                   freeway--;
                if ( (lastcheckedy==(int)wmaze-3)? 1 : (  (mapmaze[lastcheckedx][lastcheckedy+3]) || (mapmaze[lastcheckedx][lastcheckedy+1]) ||
                                              (mapmaze[(int)lastcheckedx-1][(int)lastcheckedy+2]) || (mapmaze[lastcheckedx+1][lastcheckedy+2]) )  )
                   freeway--;

                //se fa il muro da li
                if(freeway>0)
                {
                    nowcords.x= lastcheckedx ;
                    nowcords.y = lastcheckedy ;

                    if(freeway>1)
                    {
                        lastbivio.x=nowcords.x;
                        lastbivio.y=nowcords.y;
                    }

//                    unsigned char  latoparete = 0;
                    if( (nowcords.y<(int)wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )

                        direction=2;
                    else
                        direction=1;

                    do
                    {
                        do
                        {

                //printf("%u, %u; %u, %u; %u\n",lastbivio.x,lastbivio.y,nowcords.x,nowcords.y,direction);

                            if(direction==0)//su
                            {
                                if( ((int)nowcords.y-2>0) && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                                {
                                    mapmaze[nowcords.x][(int)nowcords.y-1]=1;
                                    nowcords.y-=2;
                                }
                                else
                                {
                                    unsigned char  possible=0;
                                    if( (nowcords.x<(int)wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                                        possible++;
                                    if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                                        possible+=2;
                                    if( (nowcords.y<(int)wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                                         possible+=4;

                                    if((possible&3)==1)
                                    {
                                        direction=1;
                                        continue;
                                    }
                                    else if((possible&3)==2)
                                    {
                                        direction=3;
                                        continue;
                                    }
                                    else if((possible&3)==3)
                                    {
                                        var8rand=rand8;
                                        if(var8rand<128)
                                        {
                                            direction=1;
                                            continue;
                                        }
                                        else
                                        {
                                            direction=3;
                                            continue;
                                        }
                                    }
                                    else if(possible>0)
                                    {
                                        direction=2;
                                        continue;
                                    }
                                    else
                                        break;
                                }
                            }
                            else if(direction==1)//destra
                            {
                                if( (nowcords.x<(int)wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                                {
                                    mapmaze[nowcords.x+1][nowcords.y]=1;
                                    nowcords.x+=2;
                                }
                                else
                                {
                                    unsigned char  possible=0;
                                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                                        possible++;
                                    if( (nowcords.y<(int)wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                                         possible+=2;
                                    if( (nowcords.x-4>0) && (mapmaze[nowcords.x-3][nowcords.y]==0)
                                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                                        possible+=4;

                                    if((possible&3)==1)
                                    {
                                        direction=0;
                                        continue;
                                    }
                                    else if((possible&3)==2)
                                    {
                                        direction=2;
                                        continue;
                                    }
                                    else if((possible&3)==3)
                                    {
                                        var8rand=rand8;
                                        if(var8rand<128)
                                        {
                                            direction=0;
                                            continue;
                                        }
                                        else
                                        {
                                            direction=2;
                                            continue;
                                        }
                                    }
                                    else if(possible>0)
                                    {
                                        direction=3;
                                        continue;
                                    }
                                    else
                                        break;
                                }

                            }
                            if(direction==2)//giu
                            {
                                if( (nowcords.y<(int)wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                                {
                                    mapmaze[nowcords.x][nowcords.y+1]=1;
                                    nowcords.y+=2;
                                }
                                else
                                {
                                    unsigned char  possible=0;
                                    if( (nowcords.x<(int)wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                                        possible++;
                                    if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                                        possible+=2;
                                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                                         possible+=4;

                                    if((possible&3)==1)
                                    {
                                        direction=1;
                                        continue;
                                    }
                                    else if((possible&3)==2)
                                    {
                                        direction=3;
                                        continue;
                                    }
                                    else if((possible&3)==3)
                                    {
                                        var8rand=rand8;
                                        if(var8rand<128)
                                        {
                                            direction=1;
                                            continue;
                                        }
                                        else
                                        {
                                            direction=3;
                                            continue;
                                        }
                                    }
                                    else if(possible>0)
                                    {
                                        direction=0;
                                        continue;
                                    }
                                    else
                                        break;
                                }
                            }
                            else if(direction==3)//sinix
                            {
                                if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                                {
                                    mapmaze[(int)nowcords.x-1][nowcords.y]=1;
                                    nowcords.x-=2;
                                }
                                else
                                {
                                    unsigned char  possible=0;
                                    if( ((int)nowcords.y-2>0)  && (mapmaze[nowcords.x][(int)nowcords.y-3]==0)
                                    && (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x+1][(int)nowcords.y-2]==0) && (mapmaze[nowcords.x][(int)nowcords.y-1]==0)  )
                                        possible++;
                                    if( (nowcords.y<(int)wmaze-5) && (mapmaze[nowcords.x][nowcords.y+3]==0)
                                    &&(mapmaze[(int)nowcords.x-1][nowcords.y+2]==0) && (mapmaze[nowcords.x+1][nowcords.y+2]==0) && (mapmaze[nowcords.x][nowcords.y+1]==0) )
                                        possible+=2;
                                    if( (nowcords.x<(int)wmaze-5) && (mapmaze[nowcords.x+3][nowcords.y]==0)
                                    && (mapmaze[nowcords.x+2][(int)nowcords.y-1]==0) && (mapmaze[nowcords.x+2][nowcords.y+1]==0) && (mapmaze[nowcords.x+1][nowcords.y]==0) )
                                         possible+=4;

                                    if((possible&3)==1)
                                    {
                                        direction=0;
                                        continue;
                                    }
                                    else if((possible&3)==2)
                                    {
                                        direction=2;
                                        continue;
                                    }
                                    else if((possible&3)==3)
                                    {
                                        var8rand=rand8;
                                        if(var8rand<128)
                                        {
                                            direction=0;
                                            continue;
                                        }
                                        else
                                        {
                                            direction=2;
                                            continue;
                                        }
                                    }
                                    else if(possible>0)
                                    {
                                        direction=1;
                                        continue;
                                    }
                                    else
                                        break;
                                }
                            }
                            wallcount++;


                             bivis=4;
                            if(((int)nowcords.y-5<0)? 1  : ( (mapmaze[nowcords.x][(int)nowcords.y-3])
                                                       || (mapmaze[nowcords.x][nowcords.y-1])  || (mapmaze[(int)nowcords.x-1][(int)nowcords.y-2]) || (mapmaze[nowcords.x+1][(int)nowcords.y-2])    ) )
                                bivis--;
                            if(((int)nowcords.x-5<0)? 1  : ( (mapmaze[(int)nowcords.x-3][nowcords.y])
                                                       || (mapmaze[nowcords.x-1][nowcords.y]) ||  (mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]) || (mapmaze[(int)nowcords.x-2][nowcords.y+1])    ) )
                                bivis--;
                            if((nowcords.y+5>=wmaze)? 1 : ( (mapmaze[nowcords.x][nowcords.y+3])
                                                            || (mapmaze[nowcords.x][nowcords.y+1]) || (mapmaze[(int)nowcords.x-1][nowcords.y+2]) || (mapmaze[nowcords.x+1][nowcords.y+2])    ) )
                                bivis--;
                            if((nowcords.x+5>=wmaze)? 1  : ( (mapmaze[nowcords.x+3][nowcords.y])
                                                             || (mapmaze[nowcords.x+1][nowcords.y]) || (mapmaze[nowcords.x+2][(int)nowcords.y-1]) || (mapmaze[nowcords.x+2][nowcords.y+1])    ) )
                                bivis--;

                            if(bivis>1)
                            {
                                lastbivio.x=nowcords.x;
                                lastbivio.y=nowcords.y;
                            }
                            else if(bivis==0)
                                break;


                            if(direction == 2)
                            {
                                if( ((int)nowcords.x-4>0) && (mapmaze[(int)nowcords.x-3][nowcords.y]==0)
                                    &&(mapmaze[(int)nowcords.x-2][(int)nowcords.y-1]==0) && (mapmaze[(int)nowcords.x-2][nowcords.y+1]==0) && (mapmaze[(int)nowcords.x-1][nowcords.y]==0)  )
                                direction=3;
                            }


                            if(var8rand<85)
                                direction=((direction-1)&3);
                            else if(var8rand>170)
                                direction=(direction+1)%4;





                        }while(1);



                        if((nowcords.x==lastbivio.x)&&(nowcords.y==lastbivio.y))
                        {
                            break;
                        }
                        else
                        {
                            {
                                nowcords.x=lastbivio.x;
                                nowcords.y=lastbivio.y;
                                direction=((direction+1)&3);
                            }
                        }

                    }while(1);
                }





                if((lastcheckedx==wmaze-3) && (lastcheckedy==wmaze-3))
                    goto labirintoquasifinito;
            }
        }
    }while(1);
//fine ultime pareti


labirintoquasifinito: ;

//return 9;

#define diocane01 3
    if( (mapmaze[wmaze-diocane01-1][wmaze-diocane01]==0) && (mapmaze[wmaze-diocane01][wmaze-diocane01-1]==0))
     mapmaze[wmaze-diocane01-1][wmaze-diocane01]=1;


//////////////////labirinto finito pronto




return 0;
}









