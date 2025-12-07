#include<stdio.h>
#include<string.h>
int main(){
    int i;
    char inpass[6],ogpass[5] = "1234";
    printf("HINT:THE PASSWORD CONTAINS ONLY 4 DIGITS");
    for(i=0;i<3;i++){
        printf("\nENTER PASSWORD:");
        fgets(inpass,sizeof(inpass),stdin);
        inpass[strcspn(inpass,"\n")]='\0';
        if (strcmp(inpass,ogpass)==0)
        {
            printf("\nAccess Granted");
            break;
        }
        else
        {
            if(i==2){
                printf("\nAccount Locked");
                break;
            }
            else{
                printf("\nretry");
            }
        }
    }
    return 0;
}