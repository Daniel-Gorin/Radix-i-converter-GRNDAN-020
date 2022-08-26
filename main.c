#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter\n"
#define AUTHOR "Daniel Gorin\n"
#define YEAR "2022\n"

int main()
{
    int num, in, div, rem;
    float lo;
    char str,fin;
    char * Dec2RadixI(int decValue, int radValue, char * str);
    printf("*****************************\n");
    printf(TITLE);
    printf("Written by: ");
    printf(AUTHOR);
    printf("Date: ");
    printf(YEAR);
    printf("*****************************\n");
    num=0;
    while ( num >= 0 ) {
        printf("Enter a decimal number: ");
        scanf("%d",&num);//accepts the decimal input
        if (num >= 0){
            printf("The number you have entered is ");
            printf("%d",num);
            printf("\n");
            printf("Enter a radix for the converter between 2 and 16: ");
            scanf("%d",&in);//accepts integer input
            printf("The radix you have entered is ");
            printf("%d", in);
            printf("\n");
            printf("The log2 of the number is ");
            lo=log2(num);
            printf("%.2f",lo);
            printf("\n");
            div=num/in;
            printf("The integer result of the number divided by ");
            printf("%d",in);
            printf(" is ");
            printf("%d",div);
            printf("\n");
            rem=num%in;
            printf("The remainder is ");
            printf("%d",rem);
            printf("\n");
            printf("The radix-");
            printf("%d", in);
            printf(" value is ");
            Dec2RadI(num,in,64);
            }
    }
    printf("EXIT");
    return 0;
}
void Dec2RadI(int decValue, int radValue, int size)
{
    int i,j, cont;
    j=0;
    char res[size];
    char basechars[] = "0123456789ABCDEF"; //used to provide symbols for radValues greater than 9
    if (decValue == 0) {
        printf("0");//the result is always 0 if the dec Value is 0 regardless of the rad Value
    } else {
        while (decValue != 0) {
            cont = decValue % radValue;
            decValue = decValue / radValue;
            res[j++] = basechars[cont];//results with res being the correct value but backwards
        }
        for (i = j - 1; i >= 0; --i) {//loops throught from the final value placed in res to the first value placed in res in order to make str in the correct order
            printf("%c",res[i]);//prints the result
        }
    }
    printf("\n");
}
