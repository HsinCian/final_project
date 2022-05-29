#include "struct.h"
#include "myIO.h"
#include "insert.h"
//INSERT(), DELETE(),PRINT(),SEARCH(), IS_OPEN()

void INSERT(int num_store,Store **HEAD){
    Store *p,*pre=(*HEAD),*new_node;
    for(p=(*HEAD);p!=NULL;p=p->next)
        pre=p;
    p=pre;//這樣才是正確的最後位置
    char type[13];
    for(int i=0;i<num_store;i++){
        if(p!=NULL){
            new_node=(Store *)malloc(sizeof(Store));
            scanf("%s %s %s",(new_node->name),type,(new_node->phonenumber));
	    new_node->type = gettype(type);
            scanf("%lf %lf",&(new_node->longitude),&(new_node->latitude));
            scanf("%f %d %d %d",&(new_node->rating),&(new_node->time[0]),&(new_node->time[1]),&(new_node->price));
            new_node->next=p->next;
            p->next=new_node;
            p=p->next;
        }
        else{
            (*HEAD)=malloc(sizeof(Store));
            scanf("%s %s %s",(*HEAD)->name,type,(*HEAD)->phonenumber);
	    (*HEAD)->type = gettype(type);
            scanf("%lf %lf",&((*HEAD)->longitude),&((*HEAD)->latitude));
            scanf("%f %d %d %d",&((*HEAD)->rating),&((*HEAD)->time[0]),&((*HEAD)->time[1]),&((*HEAD)->price));
            (*HEAD)->next=NULL;
            p=(*HEAD);
        }
    }
}


void PRINT(Store *HEAD){
    Store *p;
    printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    for(p=HEAD;p!=NULL;p=p->next){
	char type[13];
	totype(type, p->type);    	
        printf("%-30s\t%-12s\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
	printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
	IS_OPEN(p);
    }
}

void PRINT_TYPE(Store *HEAD){
    Store *p;
    printf("What type do you want? (CHICKEN_RICE / JAPANESE / KOREAN / AMERICAN / CHINESE / BREAKFAST / DRINKS / DESSERT)\n");
    char type[36];
    scanf("%s",type);
    int TYPE=gettype(type);
    printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
    for(p=HEAD;p!=NULL;p=p->next){
    	if(p->type == TYPE){		
		char type[13];
		totype(type, p->type);    	
		printf("%-30s\t%-12s\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
		printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
		IS_OPEN(p);
	}
    }
}

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

void IS_OPEN(Store *p){
	// Print the opening time.
	// If Name doesn’t exit, print “INVALID OPERATION”
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
}

void SEARCH(Store *HEAD,char Name[128]){
	// If Name doesn’t exit, print “INVALID OPERATION”
	Store *p;
  for (p = HEAD; p != NULL; p = p->next){
	if (strcmp(p->name,Name)==0){
		char type[13];
		totype(type, p->type);
		printf("NAME\t\t\t\tTYPE\t\t        PHONENUMBER\tLONGITUDE\tLATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
		printf("%-30s\t%-12s\t\t%s\t%f\t%f\t%.1f",p->name,type,p->phonenumber,p->longitude,p->latitude,p->rating);
		printf("\t%04d\t%04d\t%d\n",p->time[0],p->time[1],p->price);
		IS_OPEN(p);
		return;
	}
  }
  printf("INVALID OPERATION\n");
    
}


void PRINT_SORT(Store *HEAD,char sort_by[10]){
    Store *p;
    printf("%*s | %*s | %*s | %*s | %*s\n",-30,"NAME",-12,"PHONENUMBER",-10,sort_by,-4,"OPEN",-4,"CLOSE");
    for(p=HEAD;p!=NULL;p=p->next){ 	
        printf("%-30s | %-12s | ",p->name,p->phonenumber);
        if(strcmp(sort_by,"rating") == 0) printf("%-10d | ",p->rating);
        else if(strcmp(sort_by, "longitude") == 0) printf("%-10f | ",p->longitude);
        else if(strcmp(sort_by, "latitude") == 0) printf("%-10f | ",p->latitude); 
	printf("%-4d | %-4d\n",p->time[0],p->time[1]);
	IS_OPEN(p);
    }
}
