#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <conio.h>
#include <ctime>
using namespace std;
int file_massive()
{
    srand(time(NULL));
    int a[10][2],i,j;
    FILE *f = fopen("p.txt", "wt");
    FILE *dfile=fopen("pictures.pnm","w");
    for (i = 0; i < 10; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            a[i][j] = rand() % 11;
            printf(" %d", a[i][j]);
            fprintf(f, " %d", a[i][j]);
        }
        printf("\n");
        fprintf(f, "\n");
    }
    fclose(f);
}
int main()
{
    file_massive();
    int a,b;
    int ba[10][10],q,j;
    float x,y;
    std::vector<int> v1;
    std::vector<int> v2;
    fstream F;
    F.open("p.txt");
    if (F)
    {
        printf("file is found.\n");
        while (!F.eof())
        {
            F>>a;
            v1.push_back(a);
        }
        F.close();
        int vector1_size = v1.size();
        vector1_size=vector1_size-1;
        printf("massiv points:\n");
        for (int i = 0; i < vector1_size; i=i+2) 
        {
            srand(time(NULL));
            FILE *dfile=fopen("pictures.pnm","w");
                        for (q = 0; q <10 ; q++)
                        {
                            for ( j = 0; j < 10; j++)
                            {
                                if(v1[i]!=q && v1[i+1]!=j) 
                                {
                                    ba[q][j]=0;
                                }
                                else ba[q][j]=1;
                                 fprintf(dfile, "%d", ba[q][j]);
                            }
                            fprintf(dfile, "\n");
                        }
                        fclose(dfile);
                        printf("    x=%d  y=%d\n",v1[i],v1[i+1]);
        }
        printf("radius.\n");
        scanf("%d",&b);
        printf("receiv massiv points:\n");
        for(int i = 0; i < vector1_size; i=i+2)
        {
            if(pow((pow(v1[i],2)+pow(v1[i+1],2)),0.5)<=b)
            {
                v2.push_back(v1[i]);
                v2.push_back(v1[i+1]);
                printf("    x=%d  y=%d\n",v1[i],v1[i+1]);
                x=x+v1[i];
                y=y+v1[i+1];
            }
        }
        printf("mass center:\n");
        int vector2_size = v2.size();
        vector2_size=vector2_size*0.5;
        x=x/vector2_size;
        y=y/vector2_size;
        printf("    x=%f  y=%f\n",x,y);
    }
    else printf("file not found!\n");
    getch();
    return 0;
}
