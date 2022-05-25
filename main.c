#include "struct.h"
#include "insert.h" //functions:INSERT(), DELETE(),PRINT(),SEARCH(), IS_OPEN();
#include "sort_pointer_array.h" //any SORT();

int main(){
  Store *HEAD = NULL;
  int count = 0;
  INITIAL(&HEAD);
  while(1){
    char cmd[15];
    printf("What do you want to do? (INSERT/DELETE/SEARCH/IS_OPEN/SORT/PRINT/STOP)\n");
    scanf("%s", cmd);
    printf("%s\n", cmd);
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
      SORT(&HEAD, sort_by, count); //sort by: name(照ASCII), longitude, latitude, rating
      PRINT(HEAD);
    }
    else if(strcmp(cmd, "PRINT") == 0) return 0;
    else if(strcmp(cmd, "STOP") == 0) return 0;
    printf("\n");
  }
  return 0;
}
