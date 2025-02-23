#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

int main(void)
{
    float bet;
    int n=0,h=0 , random,random0,random2,total=0,a[8],i,check=5,check0=0,check1,b,random1,c[8],x,ext,total1=0,lose=1;
    char de;
    while(1)
    {
        srand(time(NULL));
        random = rand() % 11 + 1;
        if(n==0)
        {
            random1 = rand() % 11 + 1;
            random2 = rand() % 11 + 1;
        }
        

        printf("\nyour cards: \t\thost cards:");
        if (random == 1)
        {
            printf("\nyou got A");
            if( total + 11 > 21)
            {
                random = 1;
            }
            else if( total + 11 <=21)
            {
                random = 11;
            }
        }
        else if(random == 11)
        {
            random0 = rand() % 3 + 1;
            if( random0 == 1)
                {
                    printf("\nyou got a jake");
                }
            else if(random0 == 2)
                {
                    printf("\nyou got a Queens");
                }
            else if(random0 == 3)
                {
                    printf("\nyou got a king");
                }
            random = 10;
        }
        else
        {
            printf("\nyou got: %d",random);
        }
        // operater logique
        if (random1 == 1)
        {
            c[0] = random1 = 11;
           
        }
        else if(random1 == 11)
        {
            c[0] = random1 = 10;
        }
        else
        {
            c[0] = random1;
        }
        if (random2 == 1)
        {
            if( c[0] + 11 > 21)
            {
               c[1] = random2 = 1;
            }
            else if( c[0] + 11 <=21)
            {
                c[1] = random2 = 11;
            }
           
        }
        else if(random2 == 11)
        {
            c[1] = random2 = 10;
        }
        else
        {
            c[1] = random2;
        }
        a[n]=random;
        printf("\ncards: ");
        for(i=0;i<=n;i++)
        {
            if(a[i]==1 || a[i]==11)
            {
                printf(" A");
            }
            else
            {
                printf(" %d",a[i]);
            }
            
        }
        if(c[0]==1 || c[0]==11)
            {
                printf(" \t\tA * ");
            }
            else
            {
                printf(" \t\t%d * ",c[0]);
            }
       
        total = total + random;
        if (total > 21)
         {
            while(1)
            {
                for(b=0;b<=n;b++)
                {
                    if(a[b] == 11)
                    {
                        a[b] = 1;
                        check = 0;
                        break;
                    }
                    else
                    {
                        check = 1;
                    }
                }
              if( check == 1)
                {
                    printf("\ntotal:%d", total);
                    printf("\nyou lost");
                    lose = 0;
                    break;
                }
              total = 0;
              for (i=0; i<=n ;i++)
              {
                total = total + a[i];
              }
              if(total <= 21)
              {
                break;
              }
            }
         }
        if(check == 1)
        {
            break;
        }
        

        if(n!=0)
        {
            printf("\nh:hit \ns:stand:");
            printf("\ndecision:");
            scanf(" %c",&de);
            if(de == 's' || de == 'S')
            {
             
              printf("\nyour cards: \t\thost cards:");
              printf("\ncards: ");
              for(i=0;i<=n;i++)
              {
                if(a[i]==1 || a[i]==11)
                {
                 printf(" A");
                }
                else
                {
                printf(" %d",a[i]);
                }
            
              }
              if(c[0]==1 || c[0]==11)
              {
                 printf(" \t\tA %d ",c[1]);
              }
              else
              {
                printf(" \t\t%d %d ",c[0],c[1]);
              }
              total1 = c[0] + c[1];
              h=2;
              if(total1<17)   //adjsuting the card for the host
              {

                while(1)
                {
                    random2 = rand() % 11 + 1;
                    if (random2 == 1)    //asingh the approprate values
                    {
                        if( total1 + 11 > 21)
                        {
                           c[h] = random2 = 1;
                        }
                        else if( total1 + 11 <=21)
                        {
                            c[h] = random2 = 11;
                        }
                       
                    }
                    else if(random2 == 11)
                    {
                        c[h] = random2 = 10;
                    }
                    else
                    {
                        c[h] = random2;
                    }

                    printf("\nyour cards: \t\thost cards:");
                    printf("\ncards: ");
                    for(i=0;i<=n;i++)   /*will show the plyers cards*/
                    {
                      if(a[i]==1 || a[i]==11)
                      {
                       printf(" A");
                      }
                      else
                      {
                      printf(" %d",a[i]);
                      }
                  
                    }
                    printf("\t\t");
                    for(i=0;i<=h;i++)   /*will show the host cards*/
                    {
                      if(c[i]==1 || c[i]==11)
                      {
                       printf(" A");
                      }
                      else
                      {
                      printf(" %d",c[i]);
                      }
                  
                    }
                    total1=0;
                    for(i=0;i<=h;i++)
                    {
                        total1 = total1 +c[h];
                    }
                    if(total1>=17 && total1<21)
                    {
                        break;
                    }
                    if(total1>21) //see if there is any previous ace to reduce
                    {
                        while(1)
                        {
                            for(i=0;i<h;i++)
                            {
                                if(c[i]==11)
                                {
                                    c[h]=1;
                                    check1 = 0;
                                    break ;
                                }
                                else
                                {
                                    check1 = 1;
                                }
    
                            }
                            if(check1 == 1)
                            {
                                printf("\nthe host loses");
                                printf("\n you win");
                                lose = 0;
                                break; // going to brake the while loop
                            }
                            for(i=0;i<=h;i++)
                            {
                                total1 = total1 +c[h];
                            }
                            if(total1<=21)
                            {
                                break;
                            }

                        }

                        if(check1 == 1)
                        {
                            break; // going to brake the while in ligne 185
                        }
                        if(total1>17) //if the casino rule is satisfied it will break
                        {
                            break; 
                        }
                        

                    }
                    h++;
                }
                
                      

            
                
              }
              printf("\ntotal:%d",total);
              break;
            }

        }
        
        sleep(3);
        n++;
    }
    if(lose == 1)
    {
        if(total<total1)
        {
            printf("\nyou lost");
        }
        else if(total == total1)
        {
            printf("\ndraw");
        }
        else
        {
            printf("you won");
        }

    }
    
}