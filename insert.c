#include "struct.h"
#include "insert.h"
//INSERT(), DELETE(),PRINT(),SEARCH(), IS_OPEN()

enum TYPE gettype(const char *string){
	if(strcmp(string, "CHICKEN_RICE") == 0) return CHICKEN_RICE;
	if(strcmp(string, "JAPANESE") == 0) return JAPANESE;
	if(strcmp(string, "KOREAN") == 0) return KOREAN;
	if(strcmp(string, "AMERICAN") == 0) return AMERICAN;
	if(strcmp(string, "CHINESE") == 0) return CHINESE;
	if(strcmp(string, "BREAKFAST") == 0) return BREAKFAST;
	if(strcmp(string, "DRINKS") == 0) return DRINKS;
	if(strcmp(string, "DESSERT") == 0) return DESSERT;
}

void INITIAL(Store **HEAD){
	FILE *file;
	file = fopen("data.txt", "r");
	Store *p,*pre=(*HEAD),*new_node;
	for(p=(*HEAD);p!=NULL;p=p->next) pre=p;
	p=pre;//這樣才是正確的最後位置
	char tmp[120];
	char type[36];
	while(fscanf(file, "%s", tmp)!= EOF){
		if(p!=NULL){
			new_node=(Store *)malloc(sizeof(Store));
			strcpy(new_node->name, tmp);
            		fscanf(file, "%s", type);
	   		(*HEAD) -> type = gettype(type);
            		fscanf(file, "%s", (new_node->phonenumber));
            		fscanf(file, "%lf",&(new_node->longitude));
            		fscanf(file, "%lf",&(new_node->latitude)); 
            		fscanf(file, "%f",&(new_node->rating));
            		fscanf(file, "%d",&(new_node->time[0]));
            		fscanf(file, "%d",&(new_node->time[1]));
            		fscanf(file, "%d",&(new_node->price));
            		new_node->next=p->next;
            		p->next=new_node;
            		p=p->next;
        	}
        	else{
            		(*HEAD)=malloc(sizeof(Store));
	    		strcpy((*HEAD)->name, tmp);
            		fscanf(file, "%s", type);
	   		(*HEAD) -> type = gettype(type);
            		fscanf(file, "%s", ((*HEAD)->phonenumber));
            		fscanf(file, "%lf",&((*HEAD)->longitude));
            		fscanf(file, "%lf",&((*HEAD)->latitude)); 
            		fscanf(file, "%f",&((*HEAD)->rating));
            		fscanf(file, "%d",&((*HEAD)->time[0]));
            		fscanf(file, "%d",&((*HEAD)->time[1]));
            		fscanf(file, "%d",&((*HEAD)->price));
            		(*HEAD)->next=NULL;
            		p=(*HEAD);
        	}
    	}
    	fclose(file);
}

void INSERT(int num_store,Store **HEAD){
    Store *p,*pre=(*HEAD),*new_node;
    for(p=(*HEAD);p!=NULL;p=p->next)
        pre=p;
    p=pre;//這樣才是正確的最後位置
    for(int i=0;i<num_store;i++){
        if(p!=NULL){
            new_node=(Store *)malloc(sizeof(Store));
            scanf("%s %s %s",(new_node->name),(new_node->type),(new_node->phonenumber));
            scanf("%lf %lf",&(new_node->longitude),&(new_node->latitude));
            scanf("%f %d %d %d",&(new_node->rating),&(new_node->time[0]),&(new_node->time[1]),&(new_node->price));
            new_node->next=p->next;
            p->next=new_node;
            p=p->next;
        }
        else{
            (*HEAD)=malloc(sizeof(Store));
            scanf("%s %s %s",(*HEAD)->name,(*HEAD)->type),(*HEAD)->phonenumber);
            scanf("%lf %lf",&((*HEAD)->longitude),&((*HEAD)->latitude));
            scanf("%f %d %d %d",&((*HEAD)->rating),&((*HEAD)->time[0]),&((*HEAD)->time[1]),&((*HEAD)->price));
            (*HEAD)->next=NULL;
            p=(*HEAD);
        }
    }
}


void PRINT(Store *HEAD){
    Store *p;
    for(p=HEAD;p!=NULL;p=p->next){
    	printf("NAME\t        TYPE\tPHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tDISTANCE\tPRICE\n");
        printf("%-15s\t%s\t%s\t%f\t%f\t%.1f",p->name,p->type,p->phonenumber,p->longitude,p->latitude,p->rating);
	if(p->time[0]==0)
		printf("\t000%d\t%d\t%d\n",p->time[0],p->time[1],p->price);
	else
		printf("\t%d\t%d\t%d\n",p->time[0],p->time[1],p->price);
    }
}

/*void PRINT_TYPE(Store *HEAD,int TYPE){
    Store *p;
    for(p=HEAD;p!=NULL;p=p->next){
    	if(p->type == TYPE){
		printf("NAME\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tDISTANCE\tPRICE\n");
		printf("%-15s\t%s\t%f\t%f\t%.1f",p->name,p->phonenumber,p->longitude,p->latitude,p->rating);
		if(p->time[0]==0)
			printf("\t000%d\t%d\t%lf\t%d\n",p->time[0],p->time[1],p->distance,p->price);
		else
			printf("\t%d\t%d\t%lf\t%d\n",p->time[0],p->time[1],p->distance,p->price);
	}
    }
}*/

void DELETE(int num_store,Store **HEAD){
    Store *p,*pre=NULL;
    char Name[128];

    for(int i=0;i<num_store;i++){
        scanf("%s",Name);
        for(p=(*HEAD);p!=NULL;p=p->next){
            if(strcmp(p->name,Name)==0&&p!=(*HEAD)){
                pre->next=p->next;
                free(p);
                break;
            }
            if(strcmp(p->name,Name)==0&&p==(*HEAD)){
                p=(*HEAD)->next;
                free((*HEAD));
                (*HEAD)=p;
                break;
            }
            pre=p;
        }
        if(p==NULL)
            printf("INVALID OPERATION\n");
    }
}

void IS_OPEN(Store *HEAD){
	// Print the opening time.
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
	char Name[128];
	scanf("%s",Name);
	for (p = HEAD; p != NULL; p = p->next){
		if (strcmp(p->name,Name)==0){
			const char * const delim = ":";
			char buf[30] = {0};
			char *substr = NULL;
			strcpy(buf, __TIME__);
			substr = strtok(buf, delim);
			int time1,time2;
			time1 = atoi(substr);
			substr = strtok(NULL, delim);
			time2 = atoi(substr);
			if(p->time[0] <= (100*time1+time2) && (100*time1+time2) <= p->time[1]){
			    printf("YES\n");
			}
			else
			    printf("NO\n");
			
			return;
		}
	}
	printf("INVALID OPERATION\n");
	
}

void SEARCH(Store *HEAD){
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
  char Name[128];
  scanf("%s",Name);
  for (p = HEAD; p != NULL; p = p->next){
	if (strcmp(p->name,Name)==0){
		printf("%s %d %s %lf %lf %f %04d %04d %d\n",p->name,p->type,p->phonenumber,p->longitude,p->latitude,p->rating,p->time[0],p->time[1],p->price);
		return;
	}
  }
  printf("INVALID OPERATION\n");
    
}