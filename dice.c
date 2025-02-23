#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void)
{
    float bet,a,b,c,win,wining=0,profit=0;
    int round,i,dice,lost=0,win0=0;
    printf("\tods:");
    printf("\n0 to 25:x3.96 \n0 to 50:x1.98 \n0 to 75:x1.32 \n0 to 98:x1.0102 ");
    do{
        printf("\nenter the amount to bet on:");
        scanf("%f",&bet);

    }while(bet<0 || bet>999);
    printf("enter your bet");
    do{
        printf("\nbet:");
        scanf("%d",&dice);
        
    }while( bet<0);
    printf("ener for how many raound you wana play");
    do{
        printf("\nround:");
        scanf("%d",&round);
        
    }while( bet<0);
    srand(time(NULL));
    for(i=0;i<round;i++)
    {
        
        int random = (rand() %98) +0;
        if (random <= dice)
        {
            if( dice== 98 && random <=98 )
            {
              win = (float)(bet*1.0102);
              wining = wining+  win;
            }
            else if(dice== 75 && random <= 75)
            {
              win = (float)(bet*1.32);
              wining = wining+  win;
            }
            else if(dice==50 && random <=50 )
            {
              win = (float)(bet*1.98);
              wining = wining+  win;
            }
            else if(dice==25 && random <=25 )
            {
              win = (float)(bet*3.96);
              wining = wining+  win;
            }
            printf("\ndice= %d",random);
            printf("\nyou win:%0.4f",win);
            win0++;
            profit= profit + (win - bet);

        }
        else
        {
            printf("\ndice= %i",random);
            printf("\nyou lost");
            lost++;
        }

    }
    printf("\n");
    printf("\nlost count:%d",lost);
    printf("\nwin count:%d",win0);
    printf("\namount lost: %0.4f",(float)(bet*lost));
    printf(" amount won: %0.4f",wining);
    printf("\nprofit:%f",(float)(profit-((float)(bet*lost))));
    
    
   
    
}