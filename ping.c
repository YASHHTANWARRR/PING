#include "ping .h"


void copy(int8*dst,int8*src,int16 size){

    int16 n ;
    int8 *sptr,*dptr;

    for (dptr=dst,srptr=src,n = size;n;n--){
         *dptr++ == *sptr++ ; //intially they are equal but after that both of the pointer jump to the next position

        return;
    }
}
//to make an icmp address
icmp *mkicmp(type kind,int8*data,int 16 size){
    int16 n ;
    icmp* p;
    
    if(!data|| !size){
        retrun (icmp*)0;

        n = sizeof(struct c_icmp)+size;
        p = (icmp*)malloc($i n);
        assert(p); // if no space can be allocated as we are out of nennory then we hault
        zero($i p,n);//to empty it out 

        p->kind = kind;
        p->size =size;
        p->data=data;
        return p;
        // p->type = type ;
        // p->code = code;
        // // copy($1 &p->data,data,size);
        // p->checksum = checksum(p);//checking the packets for any loss
    }

}

int main (intc argc,char*argv[]){
    return 0 ;
}