#include "struct.h"
#include "sort_pointer_array.h"
#include "insert.h"

int cmp_longitude(const void* a,const void* b){
  if( (*(Store**)a)->longitude - (*(Store**)b)->longitude >0) return 1;
  else if ( (*(Store**)a)->longitude - (*(Store**)b)->longitude < 0) return -1;
  else return 0;
}

int cmp_latitude(const void* a,const void* b){
  if( (*(Store**)a)->latitude - (*(Store**)b)->latitude >0) return 1;
  else if ( (*(Store**)a)->latitude - (*(Store**)b)->latitude < 0) return -1;
  else return 0;
}

int cmp_rating(const void* a,const void* b){
  if( (*(Store**)a)->rating - (*(Store**)b)->rating >0) return 1;
  else if ( (*(Store**)a)->rating - (*(Store**)b)->rating < 0) return -1;
  else return 0;
}

/*int cmp_distance(const void* a,const void* b){
  if( (*(Store**)a)->distance - (*(Store**)b)->distance >0) return 1;
  else if ( (*(Store**)a)->distance - (*(Store**)b)->distance < 0) return -1;
  else return 0;
}*/

void SORT(Store **HEAD, int count){
	char sort_by[10];
	FILE *file;
	file = fopen("input.txt", "r");
	fscanf(file, "%s", sort_by);
	fclose(file);
	Store *temp[count];
	Store *head = *HEAD;
	for (int i = 0; i < count; i++){
		temp[i] = head;
		if (head->next != NULL)
		head = head->next;
	}

	int i = count;
	int j = 0;
	
	printf ("by:%s\n", sort_by);
    if(strcmp(sort_by,"longitude")==0){
      qsort(temp,i,sizeof(Store*),cmp_longitude);
    }
	else if(strcmp(sort_by,"latitude")==0){
      qsort(temp,i,sizeof(Store*),cmp_latitude);
    }
	else if(strcmp(sort_by,"rating")==0){
      qsort(temp,i,sizeof(Store*),cmp_rating);
    }
    /*else if(strcmp(sort_by,"distance")==0){
      qsort(temp,i,sizeof(temp[0]),cmp_distance);
    }*/
	

	Store *current;
	(*HEAD) = temp[0];
	current = (*HEAD);
	j++;
	while (j < i){
		current->next = temp[j];
		if (j == i-1){
			current->next->next = NULL;
		}
		current = current->next;
		j++;
	}

      char t[5];
	  file = fopen("YN.txt", "r");
	  fscanf(file, "%s", t);
      if(strcmp("N",t)==0||strcmp("n",t)==0)PRINT_SORT(*HEAD,sort_by);
      else if(strcmp("Y",t)==0||strcmp("y",t)==0)WRITE_EXCEL(*HEAD);
      else printf("Please try again!\n");//Firstly writting data into output.csv. Secondly opening the file by appropriate program such as Excel or Liberoffice.*/
}
