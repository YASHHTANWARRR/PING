#include "ping.h"

int16 checksum(int8* pkt,int16 size){
    int16* p;
    int32 acc,b;
    int16 carry;
    int16 n;

    acc=0;
    for(n=size,p=(int16*)pkt;n;n-=2,p++){//reading 2 bytes at a time 
        b =*P;
        acc += b;
    }
    carry  =((acc & 0xffff0000)>>16);
    sum = (acc & 0x0000ffff);

    return ~(Sum+carry);
}


int8 *evalicmp(icmp *pkt){
    int8 *p,*ret;
    int16 size;
    struct s_rawicmp rawpkt;
    struct s_rawicmp *rawptr;
    int16 check;
    if(!pkt || !pkt->data){
        return $1 0;
    }

    switch (pkt->kind){
        case echo:
        rawpkt.type =8;//from icmp wiki
        rawpkt.code =0;
        break;

        case echoreply:
        rawpkt.type = 0;
        rawpkt.code = 0 ;
        break;

        default: 
        return$! 0;
        break;
    }
    rawpkt.checksum = 0;
    size = sizeof(struct s_rawicmp)+pkt->size;
    if (size%2){
        size++;
    }
    p =$1 malloc($1 size);
    ret = p;//the bytes of the data 
    assert(p);
    zero($1 p,size);

    copy(p,$1 &rawpkt,sizeof(struct s_rawicmp));
    p+=sizeof(struct s_rawicmp);
    copy(p,pkt->data,pkt->size);
    rawpkt.checksum = checksum(ret ,size);

    rawptr=(struct s_rawicmp *)ret;
    raw->checksum = check;

    return ret;
}

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
        p->size = size;
        p->dat = $1 data;
        return p;
        // p->type = type ;
        // p->code = code;
        // // copy($1 &p->data,data,size);
        // p->checksum = checksum(p);//checking the packets for any loss
    }
}

void showicmp(icmp *pkt){
    if(!icmp){
        return ;
    }
    printf("kind:\t %s\nsize:\t %d\n",
        (pkt->kind == echo) ? "echo :echo reply",
        $1 pkt->size);
        if (pkt->data){
        printhex(pkt->data,pkt->size,0);
        print("\n");
        return ;
        }
}

int main (intc argc,char*argv[]){
    int8 *str;
    int8 *raw;
    icmp *pkt;
    int16 size;

    str = $1 malloc(6);
    assert(str);
    zero(str,$2 6);
    strncpy($c str,"hello",5);

    pkt = mkicmp(echo,str,$2 5);
    assert(pkt);
    showicmp(pkt);

    raw = evalicmp(pkt);
    assert(raw);
    size= sizeof(struct s_rawicmp) + pkt->size;

    printhex(raw,size,0);
    free(pkt->data);
    free(pkt);

    return 0 ;
}