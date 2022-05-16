#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

uint32_t mem = 0;  //이거 하나만 가지고 어떻게 야아구 겜을 만들 수 있을까....ㅠ

#define set_nibble(mem, index, value) (mem |= (value) << ((index) * 4)) 
#define get_nibble(mem, index) ((mem >> (index * 4)) & 0xF)

void init_random(void)
{
    int32_t table[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    srandom(time(NULL));

    for (int x, i = 0; i < 3; i++) {
        do {
            x = random() % 10;
        } while (table[x] == -1);

        set_nibble(mem, i, table[x]);
        table[x] = -1;
    }
}

void reset_num(void)
{
    mem &= 0x00000FFF;
    return;
}

void input_num(void)
{
    uint8_t buf = 0;
    for (int i = 3; i < 6; ++i) {
        scanf("%hhd",&buf);
        set_nibble(mem, i, buf);
    }
}

void process(void) {  //줄이기
    for(int i=0;i<3;i++) {
        for(int j=3;j<6;j++) {
            if(i==j-3) {
                if(get_nibble(mem, i) == get_nibble(mem, j)) {
                    set_nibble(mem, 6, (get_nibble(mem, 6)+1));
                }
            }
            else {
                if(get_nibble(mem, i) == get_nibble(mem, j)) {
                    set_nibble(mem, 7, (get_nibble(mem, 7)+1));
                }
            }
        }
    }
    return;
}


void display_mem(void)
{
    for(int i = 0; i < 6; ++i) {
        printf("%d ", get_nibble(mem, i));
    }
    printf("\n%d\n", get_nibble(mem,6));
    switch(get_nibble(mem, 6)) {
        case 0:
            printf("s: 0 ");
            break;
        case 1:
            printf("s: 1 ");
            break;
        case 3:
            printf("s: 2 ");
            break;
        case 7:
            printf("s: 3 ");
            break;
    }
    switch(get_nibble(mem, 7)) {
        case 0:
            printf("b: 0\n");
            break;
        case 1:
            printf("b: 1\n");
            break;
        case 3:
            printf("b: 2\n");
            break;
        case 7:
            printf("b: 3\n");
            break;
    }
    return;
}

int main()
{
    init_random();
    do {
        reset_num();
        input_num();
        process();
        display_mem();
    }while(get_nibble(mem, 6)!=7);
    return 0;
}

