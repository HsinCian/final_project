#ifndef INSERT_H
#define INSERT_H

enum TYPE gettype(const char *string);

void INITIAL(Store **HEAD);

void INSERT(int num_store,Store **HEAD);

void PRINT(Store *HEAD);

//void PRINT_TYPE(Store *HEAD,int TYPE);

void DELETE(int num_store,Store **HEAD);

void IS_OPEN(Store *HEAD);

void SEARCH(Store *HEAD);

#endif
