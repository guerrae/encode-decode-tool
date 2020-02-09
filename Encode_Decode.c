#include <stdio.h>
#include <stdlib.h>

main(){
    //declared char
    char code_opt, xin, xin2;
    
    //declared files
    FILE *fin, *fout;
    
    fin = fopen("in.txt", "r");
    fout = fopen("out.txt", "w");
    
    //intro screen
    printf("Press the \"e\" key to encode your file\n");
    printf("press the \"d\" key to decode your file\n");
    
    //user input for encode or decode
    scanf("%c", &code_opt);
    
    //loop that asks for correct input 'e' or 'd'
    while(code_opt != 101 && code_opt != 100){
        if(code_opt != 10){printf("Wrong input please try again\n");}
        scanf("%c", &code_opt);
    }
    
    //encode section
    if(code_opt == 101){
        //throws error if file not found
        if (fin == NULL){ 
                printf("                  File \"in.txt\" was not found.\n");
                printf(" Make sure the file is located in the same directory as the executable.\n\n");
                system("pause");
                return (0);
        }
        //while reads the file
        while((fscanf(fin, "%c", &xin)) != EOF){
                //the if and switch decide what to do with the characters it reads
                if(xin >= 97 && xin <= 122){
                                fprintf(fout, "%c", xin-64);
                }
                
                else if(xin >= 48 && xin <= 57){
                                fprintf(fout, "%c", xin+11);
                }
                
                else{
                    switch(xin){
                         case 32:
                           fprintf(fout, "%c", 69);
                           break;
                         case 46:
                           fprintf(fout, "%c", 70);
                           break;
                         case 10:
                           fprintf(fout, "%c", 71);
                           break;
                    }
                }
        }
        //lets the user know what just happened
        printf("File encoding complete\n");
    }
    
    //decode section
    else if(code_opt == 100){
        //throws error if file not found
        if (fin == NULL){ 
                printf("                  File \"in.txt\" was not found.\n");
                printf(" Make sure the file is located in the same directory as the executable.\n\n");
                system("pause");
                return (0);
        }
        //while reads the file
        while((fscanf(fin, "%c", &xin2)) != EOF){
                //the if and switch decides what to do with the characters it reads
                if(xin2 >= 33 && xin2 <= 58){
                                fprintf(fout, "%c", xin2+64);
                }
                
                else if(xin2 >= 59 && xin2 <= 68){
                                fprintf(fout, "%c", xin2-11);
                }
                
                else{
                    switch(xin2){
                         case 69:
                           fprintf(fout, "%c", 32);
                           break;
                         case 70:
                           fprintf(fout, "%c", 46);
                           break;
                         case 71:
                           fprintf(fout, "%c", 10);
                           break;
                    }
                }
        }
        //lets the user know what just happened
        printf("File decoding complete\n");
    }
     
    //close all opened files
    fclose(fin);
    fclose(fout);

    system("pause");
    return(0);
}
