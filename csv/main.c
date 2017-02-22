/* 
 * File:   main.c
 * Author: Impala
 *
 * Created on February 22, 2017, 8:19 AM
 */

#include<stdio.h>

#include<string.h>

void create_marks_csv(char *filename,int a[][3],int n,int m){

printf("\n Creating %s.txt file",filename);

FILE *fp;

int i,j;

filename=strcat(filename,".txt");

fp=fopen(filename,"w+");

fprintf(fp,"Student Id, Physics, Chemistry, Maths");

for(i=0;i<m;i++){

    fprintf(fp,"\n%d",i+1);

    for(j=0;j<n;j++)

        fprintf(fp,",%d ",a[i][j]);

    }

fclose(fp);

printf("\n %sfile created",filename);

}

int main(){

    int a[3][3]={{50,50,50},{60,60,60},{70,70,70}};

    char str[100];

    printf("\n Enter the filename :");

    gets(str);

create_marks_csv(str,a,3,3);

return 0;

}
