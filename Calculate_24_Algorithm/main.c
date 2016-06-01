//
//  main.c
//  Calculate_24_Algorithm
//
//  Created by Xiaoyu Ai on 2/05/2016.
//  Copyright © 2016 Xiaoyu Ai. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


typedef float (*PTRFUNC) (float, float);

void generateCard(float* array, int options){
    srand((unsigned int)time(NULL));
    for (int i=0; i<4; i++) {
        if ((options == 0) || (options == 1)) {
            array[i] = rand() % 10 + 1+ 0.0;
        }
        else{
            array[i] = rand() % 13 + 1 + 0.0;
        }
    }
    
}



void printArray(int* array, int len){
    for (int i=0; i<len; i++) {
        if (i%3==0) {
            printf("\n");
        }
        printf("%d ", array[i]);
    }
}

void printFloatArray(float* array, int len){
    for (int i=0; i<len; i++) {
        if (i%4==0){
            printf("\n");
        }
        printf("%f ", array[i]);
        
    }
    printf("\n");
}


void operation(int a, int b, char* op){
    
}

float add(float a, float b){
    return a+b;
}

float multiply(float a, float b){
    return a*b;
}

float minus(float a, float b){
    return a-b;
}

float divide(float a, float b){
    return a/b;
}

void calculation(int* cards){
    
}

/*
 *   Calculate Full Pertutation of the 4 input numbers using two queues with loop
 */


static float per[24*4];
static int counts=0;
static int op_order[4*4*4*3];
void swap(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void perm(float list[], int k, int m)
{
    int i;
    if(k > m)
    {
        for(i = 0; i <= m; i++){
            //printf("%f ", list[i]);
            per[counts] = list[i];
            counts++;
            
        }
        
        //printf("\n");
        m++;
    }
    else
    {
        for(i = k; i <= m; i++)
        {
            swap(&list[k], &list[i]);
            perm(list, k + 1, m);
            swap(&list[k], &list[i]);
        }
    }
}

void genOperation(int* array){
    int l =0;
        for (int i=0; i<4; i++) {
            for(int j=0;j<4;j++){
                for (int k=0; k<4; k++) {
                    array[l] = i;
                    array[l+1] = j;
                    array[l+2] = k;
                    l+=3;
                }
                
            }
        }

    }

char mapOperationToChar(int op_index){
    char op_name;
        switch (op_index) {
        case 0:{
            op_name = '+';
            break;}
        case 1:{
            op_name = '-';
            break;
        }
        case 3:{
            op_name = '*';
            break;
        }
        case 4:{
            op_name = '/';
            break;
        }
            
            
        default:
            break;
    }
    return op_name;
    
}

void printAnswer(int card_index, int op_index){
    printf("%d%c%d%c%d%c%d = 24\n", (int ) per[card_index], mapOperationToChar(op_index), (int ) per[card_index], mapOperationToChar(op_index), (int ) per[card_index],mapOperationToChar(op_index),  (int ) per[card_index]);
    
    }


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    PTRFUNC operations[] = {add, minus, multiply, divide};
    
    printf("Hello, World!\n");
    float cards[4] = {1,2,3,4};
    
    //generateCard(cards, 0);
    printf("The Input Cards are: \n");
    printFloatArray(cards, 4);
    
    perm(cards, 0, 3);
    
    genOperation(op_order);
    //printf("Show Operation Order:");
    //printArray(op_order, 4*4*4*3);
    int solutionFoundFlag = 0;
    for (int i=0; i<24; i+=4) {
        for (int j=0; j<4*4*3; j+=3) {
            float temp = operations[op_order[j]](per[i+0], per[i+1]);
            float temp2 = operations[op_order[j+1]](temp, per[i+2]);
            float result = operations[op_order[j+2]](temp2, per[i+3]);
            if (result==24.0) {
                printAnswer(i, j);
                solutionFoundFlag = 1;
                break;
            }
            
            
        }
    }
    if (solutionFoundFlag==0) {
        printf("No Solution Found. \n");
    }
    
    
    
    
               
    
    

    return 0;
    
}
 

