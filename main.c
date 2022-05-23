#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "insert.h" //functions:INSERT(), DELETE(),PRINT();
#include "search.h" //function:SEARCH(), IS_OPEN();
#include "sort.h" //any SORT();

enum type{meal, drinks, dessert}; //將店家分成三大類

typedef struct store{
  int type; //enum裡面的分類
  char name[128]; //店家名稱
  char phonenumber[11]; //電話
  double longitude; //經度
  double latitude; //緯度
  float rating; //評價
  int time[2]; //營業時間
  double distance; //單位:公里 (與CCU csie的距離)
  int price; //大概的價位
  struct store *next; //Linkedlist
}Store;

int main(){
  Store *HEAD = NULL;
  int count = 0;
  while(1){
    char cmd[10];
    
    printf("What do you want to do? (INSERT/DELETE/SEARCH/IS_OPEN/SORT/STOP)\n");
    scanf("%s", cmd);
    printf("%s\n, cmd);
    int num_store;
    if(strcmp(cmd, "INSERT") == 0){
      scanf("%d", &num_store);
      count = count + num_store;
      INSERT(num_store,&HEAD); //參數都丟在裡面ㄌ
      PRINT(HEAD);
    }
    else if(strcmp(cmd, "DELETE") == 0){
      scanf("%d", &num_store);
      count = count - num_store;
      DELETE(num_store,&HEAD);
      PRINT(HEAD);
    }
    else if(strcmp(cmd, "SEARCH") == 0) SEARCH(HEAD);
    else if(strcmp(cmd, "IS_OPEN") == 0) IS_OPEN(HEAD); //可以用這個取得當下時間printf("Current time: %s",__TIME__); output: Current time: 19:54:39
    else if(strcmp(cmd, "SORT") == 0){
      char sort_by[10];
      scanf("%s", sort_by);
      printf("%s\n", sort_by);
      SORT(&HEAD, sort_by, count): //sort by: name(照ASCII), longitude, latitude, rating, distance
      PRINT(HEAD);
    }
    else if(strcmp(cmd, "STOP") == 0) return 0;
    printf("\n");
  }
  return 0;
}
