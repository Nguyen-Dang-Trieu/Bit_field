#include <stdio.h>

struct Disk_Register {  
    unsigned int ready: 1;         // 1 bit field named "ready"
    unsigned int error: 1;         // 1 bit field named "error"
    unsigned int wr_prot: 1;
    unsigned int dsk_spinning: 1;
    unsigned int command: 4;       // 4 bits field named "command"
    unsigned int error_code: 8;
    unsigned int sector_no: 16;
};

void printBits(int a){
    for(int i = 31; i >= 0; i--){
    /* 
    Giải thích: a & (1 << i) != 0
     a = 0000 0000 0000 0000 0000 0000 0000 0000 (giá trị khởi tạo)
     1 = 0000 0000 0000 0000 0000 0000 0000 0001

     Ví dụ: 
     a = 0000 0000 0000 0000 0000 0000 0000 0100
     1 = 0000 0000 0000 0000 0000 0000 0000 0001 << 2 (ở đây i = 2) => 1 = 0000 0000 0000 0000 0000 0000 0000 0100

     1 = 0000 0000 0000 0000 0000 0000 0000 0001 << 3 (ở đây i = 3) => 1 = 0000 0000 0000 0000 0000 0000 0000 1000

     Kết quả: 
                      a & (1 << 2)                                                                                             a & (1 << 3)
         0000 0000 0000 0000 0000 0000 0000 0100                                                                  0000 0000 0000 0000 0000 0000 0000 0100
                              &                                                                                                      &
         0000 0000 0000 0000 0000 0000 0000 0100                                                                  0000 0000 0000 0000 0000 0000 0000 1000
         ---------------------------------------                                                                  ---------------------------------------
         0000 0000 0000 0000 0000 0000 0000 0100 = 4 khác 0 => thõa màn điều kiện if -> in ra '1'                 0000 0000 0000 0000 0000 0000 0000 0000 = 0 => điều kiện if sai -> else chạy in ra '0'
      
    */
        if(a & (1<<i) != 0){
            putchar('1');
        } else{
            putchar('0');
        }
    }
}

int main(int argc, char* argv[]){
    struct Disk_Register r;
    
    printf("sizeof(r) = %lu\n", sizeof(r));
    
    int *p = (int*) &r;  
    
    *p = 0;                    // Clear all 32 bits in r
    printBits(*p);
    putchar('\n');
    
    r.error = 1;              // Set the error bit (bit #30)
    printBits(*p);
    putchar('\n');
    
    r.dsk_spinning = 1;       // Set the disk spinning bit (#28)
    printBits(*p);
    putchar('\n');
}
