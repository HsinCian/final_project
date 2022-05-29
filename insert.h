#ifndef INSERT_H
#define INSERT_H

void INSERT(int num_store,Store **HEAD);

void PRINT(Store *HEAD);

void PRINT_TYPE(Store *HEAD);

void DELETE(int num_store,Store **HEAD);

void IS_OPEN(Store *HEAD);

void SEARCH(Store *HEAD, char Name[128]);

void PRINT_SORT(Store *HEAD,char sort_by[10]);
  
#endif
