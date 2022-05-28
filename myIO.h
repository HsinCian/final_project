#ifndef MYIO_H
#define MYIO_H

enum TYPE gettype(const char *string);

void totype(char *string, enum TYPE type);

int INITIAL(Store **HEAD, int count);

void WRITE_BACK(Store *HEAD);

void WRITE_EXCEL(Store *HEAD);

#endif
