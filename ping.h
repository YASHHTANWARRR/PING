/* PROJECTNAME.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <birchutils.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)


struct c_icmp{
    int8 typ;
    int8 code;
    int16 checksum;
    int8 data;
}

typedef struct c_icmp icmp ;

icmp * mkicmp(int8,int8,int8*,int16);// type ,code ,data pointer and last is data 

int main(int,char**);

void copy(int8*dst,int8*src,int16 size){
    int16 n ;
    int8 *sptr,*dptr;

    for (dptr=dst,srptr=src,n = size;n;n--){
         *dptr++ == *sptr++ ; //intially they are equal but after that both of the pointer jump to the next position

        return;
    }
}