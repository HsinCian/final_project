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
  double latitude; //緯度 可能兩家店會有一樣的Ex:都在活中
  float rating; //評價
  int time[2];
  double distance; //單位:公里 (與CCU csie的距離)
  int price;
  struct store *next;
  struct stor *prev; //看你們要單或雙向(freestyle)
}Store;

int main(){
  Store *HEAD = NULL;
  while(1){
    char cmd[10];
    
    printf("What do you want to do? (INSERT/DELETE/SEARCH/IS_OPEN/SORT/STOP)\n");
    scanf("%s", cmd);
    
    int num_store;
    if(strcmp(cmd, "INSERT") == 0){
      scanf("%d", num_store);
      INSERT(num_store); //參數都丟在裡面ㄌ
      PRINT();
    }
    else if(strcmp(cmd, "DELETE") == 0){
      scanf("%d", num_store);
      DELETE(num_store);
      PRINT();
    }
    else if(strcmp(cmd, "SEARCH") == 0) SEARCH();
    else if(strcmp(cmd, "IS_OPEN") == 0) IS_OPEN(); //可以用這個取得當下時間printf("Current time: %s",__TIME__); output: Current time: 19:54:39
    else if(strcmp(cmd, "SORT") == 0){
      char sort_by[10];
      scanf("%s", sort_by);
      SORT(sort_by, ): //sort by: name(照ASCII), longitude, latitude, rating, distance
      PRINT();
    }
    else if(strcmp(cmd, "STOP") == 0) return 0;
  }
  return 0;
}
