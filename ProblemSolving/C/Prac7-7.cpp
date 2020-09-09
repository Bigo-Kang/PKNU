#include <stdio.h>

int main()
{
    int x1[50],y1[50],x2[50],y2[50];
    int n=0;

    FILE *fp = fopen("/Users/KangDaeWon/Clion/Practice2/input2.txt","r");
    while(!feof(fp))
        fscanf(fp,"%d %d %d %d",&x1[n],&y1[n],&x2[n],&y2[n++]);

    int horX1[50],horY1[50],horX2[50],horY2[50];
    int verX1[50],verY1[50],verX2[50],verY2[50];

    //distinction
    int a=0,b=0;
    for(int i=0;i<n;i++) {
        if(y1[i] == y2[i]){
            horX1[a]=x1[i];
            horY1[a]=y1[i];
            horX2[a]=x2[i];
            horY2[a++]=y2[i];
        }
        if(x1[i]==x2[i]){
            verX1[b]=x1[i];
            verY1[b]=y1[i];
            verX2[b]=x2[i];
            verY2[b++]=y2[i];
        }
    }

    //checkContact
    int contact[50][2];
    int count=0;

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(horX1[i]<=verX1[j] && verX1[j]<=horX2[i] && verY1[j]<=horY1[i] && horY1[i]<=verY2[j]){
                contact[count][0] = verX1[j];
                contact[count++][1]=horY1[i];
            }
        }
    }

    //sort
    for(int i=count-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(contact[i][0]<contact[j][0]){
                int tmpX = contact[i][0];
                contact[i][0] = contact[j][0];
                contact[j][0] = tmpX;
                int tmpY = contact[i][1];
                contact[i][1] = contact[j][1];
                contact[j][1] = tmpY;
            }
            else if(contact[i][0] == contact[j][0] && contact[i][1]<contact[j][1]){
                int tmpX = contact[i][0];
                contact[i][0] = contact[j][0];
                contact[j][0] = tmpX;
                int tmpY = contact[i][1];
                contact[i][1] = contact[j][1];
                contact[j][1] = tmpY;
            }
        }
    }

    //output
    for(int i=0;i<count;i++)
            printf("[%d, %d]\n",contact[i][0],contact[i][1]);

    return 0;
}