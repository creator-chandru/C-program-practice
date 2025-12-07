#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    char str[1000],rev[1000],temp[2];
    printf("enter a string to check for palindrome:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] = '\0';
    n = strlen(str);
    for(i=n;i>=0;i--){
        temp[0] = str[i];
        temp[1] = '\0';
        strcat(rev,temp);
    }
    if(strcmp(rev,str)==0){
        printf("the given string is a PALINDROME");
    }
    else{
        printf("the given string is NOT a PALINDROME");
    }
    return 0;
}