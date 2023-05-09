#include <stdio.h>

/* Cac kieu du lieu cua bit-fields: unsigned int, signed int, bool or unsigned char
*/
struct date{
    unsigned int d;
    unsigned int m;
    unsigned int y;
};

//đây là cách khai báo bit-fields
struct DATE{
    //D has value between 0 and 31, so 5 bits are sufficient
    int D:5;
    //M has value between 0 and 15. so 4 bits are sufficient
    int M:4;
    int Y;
};
int main()
{
    printf("Size of date is %lu bytes\n",sizeof(struct date)); // Output: Size of date is 12 bytes
    printf("Size of DATE is %d bytes\n",sizeof(struct DATE));  // Output: Size of DATE is 8 bytes

    struct date dt = {31,12,2014};
    struct DATE DT = {31,12,2014};

    printf("Date is %d/%d/%d\n",dt.d,dt.m,dt.y); // Output: Date is 31/12/2014
    printf("DATE is %d/%d/%d\n",DT.D,DT.M,DT.Y); // Output: DATE is -1/-4/2014
    /* Giải thích tại sao giá trị ngõ ra lại khác nhau như vậy
    Trước tiên ta phải hiểu là số âm hay dương được quyết định bởi bit MSB (1 = âm or 0 = dương), và để biểu diễn
    trong máy tính thì ta sử dụng phương pháp phần bù 2:

    VD: Biểu diễn số -45 trong bộ nhớ máy tính
    B1:Xác định số nguyên thập phân 45 được biểu diễn trong máy tính là: 0010 1101
    B2:Đảo ngược tất cả các bit ở bước 1 (bù 1): 1101 0010
    B3:Cộng thêm 1 vào giá trị thu được ở bước 2: 1101 0011
    -->Vậy với phương phá bù 2, số -45 ở hệ thập phân được biểu diễn trong máy tính như sau: 1101 0011
    
    Vậy khi biết 1 chuỗi bit trong memory thì làm sao để biết được nó biểu diễn số bao nhiêu thì ta dùng phương pháp
    đảo bù 2
    D =  31 (lưu trong 5 bits):  11111  (MSB = 1) -> âm
        11111 -> 00000 (bù 1) -> 0000 + 1 -> là giá trị 1 + thêm dk là số âm ==> ta sẽ thấy hiển thị là -1   
    M = 12 (lưu trong 4 bits): 1100 (MSB = 1) -> âm
        1100 -> 0011 (bù 1) -> 0011 + 1 -> 0100 (số 4) + thêm đk là số âm => Hiển thị là -4
    */
}
