#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct FILE_DATA{
    int  gender;
    double heights;
    double ID;
}
data[14];

int main(void)
{

char fname1[FILENAME_MAX],fname2[FILENAME_MAX],buf[256];
FILE *fp1,*fp2;
int i,gender,nodata;
double ID,heights,search;
struct FILE_DATA;

printf("input the filename of samlie heishts:");
fgets(fname1,sizeof(fname1),stdin);
fname1[strlen(fname1)-1]='\0';
printf("input the filename of sample ID:");
fgets(fname2,sizeof(fname2),stdin);
fname2[strlen(fname2)-1]='\0';

fp1=fopen(fname1,"r");
if(fp1==NULL)
{
    fputs("File open error\n",stderr);
    exit(EXIT_FAILURE);
}

i=0;

while(fgets(buf,sizeof(buf),fp1)!=NULL)
{
    sscanf(buf,"%d,%lf",&gender,&heights);
    data[i].gender=gender;
    data[i].heights=heights;
    i++;

}
i=0;

while(fgets(buf,sizeof(buf),fp2) !=NULL)
{
 sscanf(buf,"%lf",&ID);
 data[i+1].ID=ID;
 i++;
}
printf("Which ID's data do you want?:");
scanf("%lf",&search);

for(i=1;i<15;i++)
{
    if(data[i].ID==search)
    {
        printf("ID:%.0lf\n",data[i].ID);
        if(data[i].gender==1)
        {
            printf("gender :Male\n");
        }
        else
        {
            printf("gender :Female\n");
        }
        printf("heights:%.2lf\n",data[i].heights);
    }
    else
    {
        nodata++;
    }
}
if(nodata==14)
{
    printf("NO data");
}

if(fclose(fp1)==EOF)
{
    fputs("file close error\n",stderr);
    exit(EXIT_FAILURE);
}

if(fclose(fp2)==EOF)
{
    fputs("file close error\n",stderr);
    exit(EXIT_FAILURE);
}



return 0;
}