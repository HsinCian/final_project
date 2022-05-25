#ifndef STRUCT_H
#define STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct store{
  char name[128]; //店家名稱
  enum TYPE{CHICKEN_RICE, JAPANESE, KOREAN, AMERICAN, CHINESE, BREAKFAST, DRINKS, DESSERT}type;
  char phonenumber[11]; //電話
  double longitude; //經度
  double latitude; //緯度
  float rating; //評價
  int time[2]; //營業時間
  double distance; //單位:公里 (與CCU csie的距離)
  int price; //大概的價位
  struct store *next; //Linkedlist
}Store;

#endif
