#include<stdio.h>
#include<string.h>
struct library{
    int Book_ID;
    char Title[200];
    char Author[100];
    int Quantity;
};
int main()
{
    struct library books[1000];
    int i,num,n,search,id_search,id_dlt,found=0;
    char tsearch[200];
    FILE *Record , *Temp_Record;
    printf("enter number of Records:");
    scanf("%d",&num);
    getchar();
    for(i = 0;i<num;i++){
        printf("BOOK %d",i+1);
        printf("\nEnter Book ID:");
        scanf("%d",&books[i].Book_ID);
        getchar();
        printf("Enter Book Title:");
        fgets(books[i].Title,sizeof(books[i].Title),stdin);
        printf("Enter Book Author:");
        fgets(books[i].Author,sizeof(books[i].Author),stdin);
        printf("Enter Quantity:");
        scanf("%d",&books[i].Quantity);
    }
    Record = fopen("Record.dat","ab");
    fwrite(books,sizeof(struct library),num,Record);
    fclose(Record);
    Record = fopen("Record.dat","rb");
    printf("------------RECORD----------");
    for(i=0;i<num;i++){
        fread(&books[i],sizeof(struct library),1,Record);
        printf("\nBOOK %d:-",i+1);
        printf("\nBOOK ID:%d",books[i].Book_ID);
        printf("\nBOOK TITLE:%s",books[i].Title);
        printf("\nBOOK AUTHOR:%s",books[i].Author);
        printf("\nBOOK QUANTITY:%d",books[i].Quantity);
        printf("\n--------------------------------------");
    }
    fclose(Record);
    printf("\n");
    printf("\n");
    Record = fopen("Record.dat","rb");
    printf("WHAT WOULD YOU LIKE TO DO?");
    printf("\n1 - SEARCH");
    printf("\n2 - DELETE");
    printf("\nENTER CHOICE:");
    scanf("%d",&n);
    getchar();
    switch(n){
        case 1:
         printf("1 - SEARCH BY TITLE");
         printf("\n2 - SEARCH BY BOOK ID");
         printf("\nENTER CHOICE:");
         scanf("%d",&search);
         getchar();
         switch(search){
            case 1:
             printf("Enter title:");
             fgets(tsearch,sizeof(tsearch),stdin);
             for(i=0;i<num;i++){
                 fread(&books[i],sizeof(struct library),1,Record);
                 if(strcmp(books[i].Title,tsearch)==0){
                     found = 1;
                     printf("\nBOOK FOUND");
                     printf("\n-------------------------------");
                     printf("\nBOOK ID:%d",books[i].Book_ID);
                     printf("\nBOOK TITLE:%s",books[i].Title);
                     printf("\nBOOK AUTHOR:%s",books[i].Author);
                     printf("\nBOOK QUANTITY:%d",books[i].Quantity);
                     break;
                 }
             }
             if(found==0){
                printf("\nNO BOOK FOUND");
             }
             break;
            case 2:
             rewind(Record);
             found = 0;
             printf("Enter BOOK ID:");
             scanf("%d",&id_search);
             for(i=0;i<num;i++){
                 fread(&books[i],sizeof(struct library),1,Record);
                 if(books[i].Book_ID == id_search){
                     found = 1;
                     printf("\nBOOK FOUND");
                     printf("\n---------------------------");
                     printf("\nBOOK ID:%d",books[i].Book_ID);
                     printf("\nBOOK TITLE:%s",books[i].Title);
                     printf("\nBOOK AUTHOR:%s",books[i].Author);
                     printf("\nBOOK QUANTITY:%d",books[i].Quantity);
                     break;
                 }
             }
             if(found == 0){
                 printf("\nNO BOOK FOUND");
             }
             break;
            default:
             printf("Enter valid choice");
             break;
        }
         break;
        case 2:
         found = 0;
         Temp_Record = fopen("Temp_Record.dat","wb");
         printf("Enter BOOK ID to delete:");
         scanf("%d",&id_dlt);
         rewind(Record);
         for(i=0;i<num;i++){
            fread(&books[i],sizeof(struct library),1,Record);
                 if(books[i].Book_ID == id_dlt){
                     found = 1;
                     printf("\nBOOK TO BE DELETED:");
                     printf("\n---------------------------");
                     printf("\nBOOK ID:%d",books[i].Book_ID);
                     printf("\nBOOK TITLE:%s",books[i].Title);
                     printf("\nBOOK AUTHOR:%s",books[i].Author);
                     printf("\nBOOK QUANTITY:%d",books[i].Quantity);
                     break;
                }
         }
         if(found == 0){
            printf("\nNO BOOK FOUND");
            break;
         }
         rewind(Record);
         found=0;
         for(i=0;i<num;i++){
            fread(&books[i],sizeof(struct library),1,Record);
            if(books[i].Book_ID == id_dlt){
                found = 1;
                continue;
            }
            fwrite(&books[i],sizeof(struct library),1,Temp_Record);
         }
         if(found == 1){
            printf("\nBOOK SUCCESSFULLY DELETED");
         }
         fclose(Record);
         fclose(Temp_Record);

         remove("Record.dat");
         rename("Temp_Record.dat","Record.dat");
         break;

        default:
         printf("Enter valid choice");
         break;
    }
    return 0;
}