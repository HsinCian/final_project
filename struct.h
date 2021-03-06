#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct store{
  char name[128];         //店家名稱
  enum TYPE{CHICKEN_RICE, JAPANESE, KOREAN, AMERICAN, CHINESE, BREAKFAST, DRINKS, DESSERT}type;
  char phonenumber[11];   //電話
  double longitude;       //經度
  double latitude;        //緯度
  float rating;           //評價
  int time[2];            //營業時間
  int price;              //大概的價位(0:0~100 / 1:100~300 / 2:300~500 / 3:500以上)
  struct store *next;     //Linkedlist
}Store;

#endif
