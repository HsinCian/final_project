#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insert.h" //functions:INSERT(), DELETE();
#include "search.h" //function:SEARCH(), IS_OPEN();
#include "sort.h" //any SORT();
//PRINT()你們自己決定放哪

enum type{meal, drinks, dessert};

typedef struct store{
  int type; //enum裡面的種類
  char name[128];
  char phonenumber[11];
  double longitude; //經度
  double latitude; //緯度
  float like; //評價
  int time[2];
  double distance;
  int price;
  struct store *next;
  struct stor *prev; //看你們要單或雙向(freestyle)
}Store;

int main(){
  while(1){
    char cmd[10];
    printf("What do you want to do? (INSERT/DELETE/SEARCH/IS_OPEN/SORT/STOP)\n");
    scanf("%s", cmd);
    if(strcmp(cmd, "INSERT") == 0) INSERT(); //參數自己填:)
    else if(strcmp(cmd, "DELETE") == 0) DELETE();
    else if(strcmp(cmd, "SEARCH") == 0) SEARCH();
    else if(strcmp(cmd, "IS_OPEN") == 0) IS_OPEN();
    else if(strcmp(cmd, "SORT") == 0) SORT():
    else if(strcmp(cmd, "STOP") == 0) return 0;
  }
  return 0;
}
