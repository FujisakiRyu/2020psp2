#define _USE_MATH_DEFINES
#define MU_A 170.8
#define MU_B 169.7
#define sigma_A 5.43
#define sigma_B 5.5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);




int main(void)
{
    int i;
    double val,z1,z2,u1,u2,y1,y2,x1,x2,max_val=1,min_val=1;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;

    u1=MU_A;
    y1=sigma_A;
    u2=MU_B;
    y2=sigma_B;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);


    z1=(val-u1)/y1;
    z2=(val-u2)/y2;
    x1=p_stdnorm(z1);
    x2=p_stdnorm(z2);
    max_val=max_val*x1;
    min_val=min_val*x2;
    }



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",max_val);
    printf("L_B: %f\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

