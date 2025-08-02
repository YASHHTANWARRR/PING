#include "ping .h"

//to make an icmp address
icmp *mkicmp(int8 type, int8 code,int8*data,int 16 size){
    int16 n ;
    icmp* p;
    
    if(!data|| !size){
        retrun (icmp*)0;

        n = sizeof(struct c_icmp)+size;
        p = (icmp*)malloc($i n);
        assert(p); // if no space can be allocated as we are out of nennory then we hault
        zero($i p,n);//to empty it out 

        p->type = type ;
        p->code = code;
        copy($1 &p->data,data,size);
        p->checksum = checksum(p);//checking the packets for any loss
    }

}

int main (intc argc,char*argv[]){
    return 0 ;
}