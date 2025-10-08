#include <stdio.h>
#include "../includes/bit_operations.h"

int main(){
                    /*Task 1*/
    printf("########## TASK1 ##########\n\n");

    int task1_number;

    while (1){

        printf("Enter a positive number: ");
        scanf("%d", &task1_number);

        if(task1_number < 0){
            printf("Number is negative! Try again\n");
            continue;
        }

        break;
    }

    positive_dec_to_bin(task1_number);

                /*Task 2*/
    printf("########## TASK2 ##########\n\n");

    int task2_number;
    
    while (1){

        printf("Enter a negative number: ");
        scanf("%d", &task2_number);

        if(task2_number > 0){
            printf("Number is positive! Try again\n");
            continue;
        }

        break;
    }

    positive_dec_to_bin(task2_number);

                    /*Task 3*/
    printf("########## TASK3 ##########\n\n");

    int task3_number;
    
    while (1){

        printf("Enter a positive number: ");
        scanf("%d", &task3_number);

        if(task3_number < 0){
            printf("Number is negative! Try again\n");
            continue;
        }

        break;
    }

    printf("One in bits: %d\n", one_in_bin(task3_number));

                    /*Task 4*/
    printf("########## TASK4 ##########\n\n");

    int task4_number_1;
    int task4_number_2;

    while (1){

        printf("Enter two positive numbers: ");
        scanf("%d", &task4_number_1);
        scanf("%d", &task4_number_2);

        if(task4_number_1 < 0){
            printf("Number1 is negative! Try again\n");
            continue;
        }

        break;
    }

    printf("first number: ");
    positive_dec_to_bin(task4_number_1);

    printf("second_number: ");
    positive_dec_to_bin(task4_number_2);

    int new_number = byte_replace(task4_number_1, task4_number_2);

    printf("new number: ");
    positive_dec_to_bin(new_number);

    return 0;
}