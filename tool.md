# switch

switch(變數名稱或運算式) {
    case 符合數字或字元:
        陳述句一;
        break;
    case 符合數字或字元:
        陳述句二;
        break;
    default:
        陳述三;
        break;
}

do-while


do
    {
        陳述句;
    } while (條件);



random

include:

#include <stdlib.h>  —> rand()
#include <time.h>  —> srand(time(NULL));

用法:

srand(time(NULL));       <— (必打!!!!!!用當時時間抽取不同亂數表，不然每次都是同一張亂數表上相同結果)

int 變數名 = rand() % 隨機數值範圍;

例: int num = rand() % 10 + 1;

