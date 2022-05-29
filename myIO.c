#include "struct.h"
#include "myIO.h"

void STRUPR(char *str){
	while(*str!='\0'){
		*str=toupper(*str);
		str++;
	}
}

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

void totype(char *string, enum TYPE type){
	if(type == 0) strcpy(string, "CHICKEN_RICE");
	if(type == 1) strcpy(string, "JAPANESE");
	if(type == 2) strcpy(string, "KOREAN");
	if(type == 3) strcpy(string, "AMERICAN");
	if(type == 4) strcpy(string, "CHINESE");
	if(type == 5) strcpy(string, "BREAKFAST");
	if(type == 6) strcpy(string, "DRINKS");
	if(type == 7) strcpy(string, "DESSERT");
}

int INITIAL(Store **HEAD, int count){
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
	   		new_node -> type = gettype(type);
			//printf("%d\n", (*HEAD) -> type);
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
			//printf("%d\n", (
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
		count++;
    	}
    	fclose(file);
	return count;
}

void WRITE_BACK(Store *HEAD){
	FILE *file;
	file = fopen("data.txt", "w");
	while(HEAD != NULL){
		fprintf(file, "%s ", HEAD->name);
		char type[13];
		totype(type, HEAD->type);
		fprintf(file, "%s ", type);
            	fprintf(file, "%s ", (HEAD->phonenumber));
            	fprintf(file, "%lf ",(HEAD->longitude));
            	fprintf(file, "%lf ",(HEAD->latitude)); 
          	fprintf(file, "%.1f ",(HEAD->rating));
           	fprintf(file, "%04d ",(HEAD->time[0]));
            	fprintf(file, "%04d ",(HEAD->time[1]));
            	fprintf(file, "%d\n",(HEAD->price));
		HEAD = HEAD -> next;
	}
	fclose(file);
}

void WRITE_EXCEL(Store *HEAD){
	FILE *file;
	file = fopen("output.csv", "w");
	fprintf(file,"NAME\tTYPE\tPHONENUMBER\tLONGITUDE\t");
	fprintf(file,"LATITUDE\tRATING\tOPEN\tCLOSE\tPRICE\n");
	while(HEAD != NULL){
		fprintf(file, "%s\t", HEAD->name);
		char type[13];
		totype(type, HEAD->type);
		fprintf(file, "%s\t", type);
            	fprintf(file, "%s\t", (HEAD->phonenumber));
            	fprintf(file, "%lf\t",(HEAD->longitude));
            	fprintf(file, "%lf\t",(HEAD->latitude)); 
          	fprintf(file, "%.1f\t",(HEAD->rating));
           	fprintf(file, "%04d\t",(HEAD->time[0]));
            	fprintf(file, "%04d\t",(HEAD->time[1]));
            	fprintf(file, "%d\n",(HEAD->price));
		HEAD = HEAD -> next;
	}
	fclose(file);
	system("xdg-open output.csv");
}

void MAP(Store *HEAD){
	FILE *file;
	file = fopen("map.txt", "w");
	while(HEAD != NULL){
		//fprintf(file, "%s\t", HEAD->name);
		fprintf(file, "%d ", HEAD->type);
            	//fprintf(file, "%s\t", (HEAD->phonenumber));
            	fprintf(file, "%lf ",(HEAD->longitude));
            	fprintf(file, "%lf\n",(HEAD->latitude)); 
          	//fprintf(file, "%.1f\t",(HEAD->rating));
           	//fprintf(file, "%04d\t",(HEAD->time[0]));
            	//fprintf(file, "%04d\t",(HEAD->time[1]));
            	//fprintf(file, "%d\n",(HEAD->price));
		HEAD = HEAD -> next;
	}
	fclose(file);
	system("python3 pic.py");
}
