#ifndef SORT_POINTER_ARRAY_H
#define SORT_POINTER_ARRAY_H

int cmp_longitude(const void* a,const void* b);

int cmp_latitude(const void* a,const void* b);

int cmp_rating(const void* a,const void* b);

//int cmp_distance(const void* a,const void* b);

void SORT(Store **HEAD, int count);

#endif
