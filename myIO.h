#ifndef MYIO_H
#define MYIO_H

enum TYPE gettype(const char *string);

void totype(char *string, enum TYPE type);

void INITIAL(Store **HEAD);

void WRITE_BACK(Store *HEAD);

#endif
