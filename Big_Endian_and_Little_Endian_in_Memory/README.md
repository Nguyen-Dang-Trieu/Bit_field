<p align="center">
    <img src="./Images/1.png" width="800px" alt="">
</p>

**Example:**
~~~cpp
#include <stdio.h>

int main()
{
    // Correctly initialize an array of characters
    char a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Cast the array 'a' to a pointer of type 'short'
    short *b = (short *)a;

    /* Các máy tính hiện đại lưu trữ dữ liệu theo kiểu littler endian, nên khi truy xuất dữ liệu thì sẽ theo dạng Little Endian
    vd: mảng a có kiểu tử char (8bit) ở trên.
    Khi ép kiểu a thành kiểu short (16bit) thì mỗi lần đọc giá trị thì nó sẽ theo dạng Little Endian:

    + 1: 0000 0001, 2: 0000 0010 --- Big Endian: 0000 0001 0000 0010 - 258
    + 2: 0000 0010, 1: 0000 0001 --- Little Endian: 0000 0010 0000 0001 - 513   <---- Giá trị được chọn.
    */
    // Print the value at the current position of the pointer
    printf("%d\n", *b);
    
    // Move the pointer forward by 2 bytes (one short)
    b++; // b bây giờ đang trỏ tới số 3, 4.
    /*
      3: 0000 0011 - 4: 0000 0100
      Little Endian: 0000 0100 0000 0011  ---> 1027
    */
    // Print the value at the new position of the pointer
    printf("%d\n", *b);
    
    // Move the pointer forward by 4 bytes (two shorts)
    b += 2; // b bây giờ đang trỏ tới số 7, 8.
    /*
      7: 0000 0111 - 8: 0000 1000
      Little Endian: 0000 1000 0000 0111  ---> 2055
    */
    // Print the value at the new position of the pointer
    printf("%d\n", *b);

    return 0;
}
~~~
Output:
~~~cpp
513
1027
2055

~~~
