#include "struct.h"
#include "myIO.h"
#include "insert.h" //functions:INSERT(), DELETE(),PRINT(),SEARCH(), IS_OPEN();
#include "sort_pointer_array.h" //any SORT();
#include "random.h"
#include "distance.h"
#include "my_habit.h"

int main(){
  Store *HEAD = NULL;
  int count = 0;
  int rec[8] = {0};
  double lat1, lng1;
  count = INITIAL(&HEAD, count);
  LOCATE(&lat1, &lng1);
  while(1){
    char cmd[20];
    printf("What do you want to do?\n(INSERT / DELETE / SEARCH / SORT / PRINT / PRINTTYPE / PRINTNEAR / RANDOM / RANDOMTYPE / RANDOMNEAR / DISTANCE / MY_HABIT / STOP)\n");
    scanf("%s", cmd);
    STRUPR(cmd);
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
    else if(strcmp(cmd, "SEARCH") == 0){
      char Name[128];
      scanf("%s",Name);
      SEARCH(HEAD,Name);
      RECORD_SEARCH(HEAD, Name, rec);
    }
    else if(strcmp(cmd, "SORT") == 0){
      char sort_by[10];
      printf("What do you want to sort? (longitude / latitude / rating)\n");
      scanf("%s", sort_by);
      printf("%s\n", sort_by);
      SORT(&HEAD, sort_by, count); //sort by: name(照ASCII), longitude, latitude, rating
      printf("Do you want to export to Excel?(Y/N)\n");
      char t[5];
      scanf("%s",t);
      if(strcmp("N",t)==0||strcmp("n",t)==0)PRINT_SORT(HEAD,sort_by);
      else if(strcmp("Y",t)==0||strcmp("y",t)==0)WRITE_EXCEL(HEAD);
      else printf("Please try again!\n");//Firstly writting data into output.csv. Secondly opening the file by appropriate program such as Excel or Liberoffice.
    }
    else if(strcmp(cmd, "PRINT") == 0)      PRINT(HEAD);
    else if(strcmp(cmd, "PRINTTYPE") == 0)  PRINT_TYPE(HEAD);
    else if(strcmp(cmd, "RANDOM") == 0)     RANDOM(HEAD);
    else if(strcmp(cmd, "PRINTNEAR") == 0)     PRINTNEAR(HEAD,lat1,lng1);
    else if(strcmp(cmd, "RANDOMTYPE") == 0) RANDOM_TYPE(HEAD);
    else if(strcmp(cmd, "DISTANCE") == 0)   DISTANCE(HEAD,lat1,lng1);
    else if(strcmp(cmd, "RANDOMNEAR") == 0) RANDOM_NEAR(HEAD,lat1,lng1);
    else if(strcmp(cmd, "MY_HABIT") == 0) MY_HABIT(HEAD, rec);
    else if(strcmp(cmd, "MAP") == 0) MAP(HEAD);
    else if(strcmp(cmd, "STOP") == 0){
            WRITE_BACK(HEAD);
            return 0;
    }
    else{
            printf("INVALID OPERATION, please input again\n");
    }
    printf("\n");
  }
  return 0;
}
