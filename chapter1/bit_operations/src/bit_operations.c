#include <stdio.h>
#include "../includes/bit_operations.h"

/*1. Вывести двоичное представление целого положительного числа, используя битовые операции (число вводится с клавиатуры).*/
/*2. Вывести двоичное представление целого отрицательного числа, используя битовые операции (число вводится с клавиатуры).*/

void positive_dec_to_bin(int num){

    int bits_count = sizeof(num) * BITS_IN_BYTE;

    for(int i = bits_count - 1; i >= 0; --i){
        printf("%d ", (num >> i) & 1);
    }

    printf("\n");
}


/*3. Найти количество единиц в двоичном представлении целого положительного числа (число вводится с клавиатуры).*/

int one_in_bin(int num){

    int bits_count = sizeof(num) * BITS_IN_BYTE;
    int one_count = 0;

    for(int i = bits_count - 1; i >= 0; --i){
        if((num >> i) & 1) {++one_count;}
    }

    return one_count;
}

/*4. Поменять в целом положительном числе (типа int) значение третьего байта на введенное пользователем число (изначальное число также вводится с клавиатуры).*/

int byte_replace(int num1, int num2){

    if(num2 >= 256 || num2 < 0){
        printf("Num2 must be less than 256 and positive\n");
        return 0;
    }

    int mask = 0xff00ffff;

    int replace_byte_pos = 3;

    int shift = (replace_byte_pos - 1) * BITS_IN_BYTE;

    num1 &= mask;

    num1 |= (num2 << shift);

    return num1;

}