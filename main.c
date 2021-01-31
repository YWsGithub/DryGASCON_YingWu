
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bytes_utils.h"
#include "drysponge.h"
#include "drygascon128k32.h"

#define DRYGASCON_DIGESTSIZE 32

void bstr(const unsigned char *data, unsigned long long length){
    for (unsigned long long i = 0; i < length; i++)
		printf("%02X", data[i]);

    printf("\n");
}

int main(int argc, char *argv[]){  //執行時可在命令列輸入要傳給程式的參數 //argc 是一個整數，其值就是 argv 陣列的長度

    printf("argc=%u\n",argc);

    size_t mlenmax = 0;//high bound for mlen
    for(int i=1;i<argc;i++){
        mlenmax += (strlen(argv[i]))/2;
    }

    //printf("mlenmax=%lu\n",mlenmax);
    uint8_t *msg = malloc(mlenmax);
    if(0==msg){
        printf("ERROR: could not allocate memory (%lu bytes requested)\n",mlenmax);
        return -2;
    }

    uint8_t *m=msg;
    size_t remaining=mlenmax;
    for(int i=1;i<argc;i++){
        //printf("remaining=%lu\n",remaining);
        size_t bufsize = strlen(argv[i])+1;
        char *buf = malloc(bufsize);
        if(0==buf){
            printf("ERROR: could not allocate memory (%lu bytes requested)\n",bufsize);
            return -3;
        }
        strcpy(buf,argv[i]);
        size_t nbytes = user_hexstr_to_bytes(m,remaining,buf,bufsize);
        //size_t nbytes = 0;//hexstr_to_bytes(m,remaining,buf);
        m+=nbytes;
        remaining-=nbytes;
        free(buf);
    }
    size_t mlen = mlenmax-remaining;
    //printf("mlen=%lu\n",mlen);

    uint8_t out[DRYGASCON_DIGESTSIZE*2] = {0};

    drygascon128_hash(
        out,     
        msg,  
        mlen     
    );
    bstr(out, DRYGASCON_DIGESTSIZE);

    free(msg);
    return 0;
}
