#include<stdio.h>
#include<stdlib.h>
int position(char x,int pos)
{
    if(x=='w')
    {
        pos-=55;
    }
    else
    {
        pos+=55;
    }
    return pos;
}
int main()
{
    int a[15][55],upwal[15][55],lowal[15][55],i,j,k,n=1,score=0,pos=395,count=0,wan,m,temp1,temp2,gapn=0,gap=7,dis=11;
    char x;
    for(i=0;i<15;i++)
    {
        for(j=0;j<55;j++)
        {
            a[i][j]=n;
            n++;
        }
    }
    for(i=1;i<=57;i++) 
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<15;i++)
    {
        printf("|");
        for (j = 0; j < 55; j++)
        {
            int check = 0;
            if(pos == a[i][j])
                {
                    printf("@"); // head
                    check = 1;
                }
            if (!check) 
            {
                printf(".");
            }
        }
        printf("|");
        if(i!=7)
        {
            printf("\n");
        }
        if(i==7)
        {
            printf("\t\tpoints=%d\n",score);
        }
    }
    for(i=1;i<=57;i++) 
    {
        printf("-");
    }
    A:
    printf("\n");
    printf("Enter the move:");
    scanf(" %c",&x);
    if(x=='w' || x=='s')
    {
        if(pos==10 && x=='w' || pos==780 && x=='s')
        {
            printf("Blockes can't move\n");
        }
        else
        {
        pos=position(x,pos);
        }
    }
    else
    {
        printf("Move out of range\nTry again\n");
        goto A;
    }
    do
    {
        wan=rand()%770;
    }while(wan%55==0);
    
    if(count%dis==0)
    {
        
        temp1=wan;
        m=55-(wan%55);
        temp1+=m;
        temp2=temp1+(55*gap);
        for(i=14;i>=0;i--)
        {
            for(j=54;j>=0;j--)
            {
                if(count==0)
                {
                    upwal[i][j]=0;
                }
                if(a[i][j]==temp1 && temp1>=55)
                {
                    upwal[i][j]=temp1;
                    temp1-=55;
                }
            }
        }
        for(i=0;i<15;i++)
        {
            for(j=0;j<55;j++)
            {
                if(count==0)
                {
                lowal[i][j]=0;
                }
                if(a[i][j]==temp2 && temp2<=825)
                {
                    lowal[i][j]=temp2;
                    temp2+=55;
                }
            }
        }
        gapn++;
        if(gapn%7==0)
        {
            if(gap>=3)
            {
                gap--;
            }
            if(dis>=7)
            {
                dis--;
            }
        }
     }
    for(i=1;i<=57;i++) 
    {
        printf("-");
    }
    printf("\n");
    for(i=0;i<15;i++)
    {
        printf("|");
        for (j = 0; j < 55; j++)
        {
            if(upwal[i][j]!=0)
            {
                printf("*");
            }
            else if(lowal[i][j]!=0)
            {
                printf("*");
            }
            else if(pos == a[i][j])
                {
                    printf("@"); // head
                }
            else
            {
                printf(".");
            }
        }
        printf("|");
        if(i!=7)
        {
            printf("\n");
        }
        if(i==7)
        {
            printf("\t\tpoints=%d\n",score);
        }
    }
    for(i=1;i<=57;i++) 
    {
        printf("-");
    }
    for(i=0;i<15;i++)
     {
         for(j=0;j<55;j++)
         {
             if(pos==upwal[i][j] || pos==lowal[i][j])
             {
                 printf("\nGame over\n");
                 printf("\nScore=%d\n",score);
                 return 1;
             }
             if(upwal[i][j]==10)
             {
                 score++;
             }
             if(upwal[i][j]!=0)
             {
                 upwal[i][j-1]=upwal[i][j]-1;
                 upwal[i][j]=0;
                 if((upwal[i][j-1]-1)%55==0)
                 {
                     upwal[i][j-1]=0;
                 }
             }
             if(lowal[i][j]!=0)
             {
                 lowal[i][j-1]=lowal[i][j]-1;
                 lowal[i][j]=0;
                 if((lowal[i][j-1]-1)%55==0)
                 {
                     lowal[i][j-1]=0;
                 }
             }
         }
     }
    count++;
    goto A;
    return 0;
}
