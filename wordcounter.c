#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int words = 0,isword = 0,i,n;
    char str[10000];
    printf("enter string:");
    fgets(str,sizeof(str),stdin);
    n = strlen(str)-1;
    for(i=0;i<n;i++)
    {
        if(str[i]!='\n' && str[i]!= '\t' && str[i]!=' ' && ispunct(str[i])==0){
            if(isword == 0){
                words++;
                isword = 1;
            }
        }
        else{
            isword = 0;
        }
    }
    printf("\n THE TOTAL NUMBER OF WORDS IN THE GIVEN STRING IS : %d",words);
    return 0;
}