#include<stdio.h>
#include<string.h>
int lenghtoflastword (const char* s){
   int words = 0,inwords = 0,i,n,laststart = 0,lastend = 0,lastlen=0;
   n=strlen(s)-1;
   for(i=0;i<n;i++){
    if(s[i]!= ' ' && s[i]!= '\n' && s[i]!= '\t'){
        if(inwords == 0){
            words++;
            laststart = i;
        }
        words = 1;
        lastend = i;
    }
    else{
        inwords = 0;
        }
   }
   for(i=laststart;i<=lastend;i++){
    lastlen+=1;
   }
   return lastlen;
}
int main(){
    char str[1000];
    char *s = str;
    printf("enter a string:");
    fgets(str,sizeof(str),stdin);
    printf("%d",lenghtoflastword(s));
    return 0;
    }