#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


int infix(char*);
int isoperator(char[]);
int precedence(char[],char[]);
int isnum(char[]);
int perform(int,int,char []);

int main() {
	char str[80];
	int a;

        fgets(str,80,stdin);
     	a = infix(str);
        printf("\nanswer of infix evaluation = %d\n", a);
        return 0;
}


int infix(char* str) {
	int i = 0,j = 0,x = 0,k=0,result=0,set=0,y=0;
    	int op1,op2,preced=0,p=0,q=0,m=0,count=0;
        char buffer[10];
    	char* tokenstore[40];
    	char str1[10],ch;
    	char s[10];
    
    	char *token = strtok(str, " ");
        while(token != NULL) {
    
        
        	tokenstore[i]=malloc(strlen(token)+1);
       		
        	strcpy(tokenstore[i], token);
         	
        	token = strtok(NULL, " ");
       	 	++i;
        	
        }
	count=i;
	if(isnum(tokenstore[count-1])) {
         	j=0;k=0;
        	while(j < (count-1)) {
        
        		k=j+1;
        		if((isnum(tokenstore[j]))&&(isoperator(tokenstore[k]))){
         		
                               
                                j=j+2;
                        }
         		else {
        		 
        			set=0;
        			break;
        		} 
               
          	set=1;
       		}
       }
       
       if(set==0) {
		printf("\n infix expression is invalid:\n");
                exit(0);
       }
       if(set==1) {
                printf("\n infix expression is valid:\n");
                x=1;
                y=x+2;
       		while(x<count) {
           		
                        if(count==3){
                                result = 0;  
                        	p=atoi(tokenstore[x-1]);
            			q=atoi(tokenstore[x+1]);
            			result= result + perform(p,q,tokenstore[x]);
                                snprintf(buffer, 10, "%d", result);
            			strcpy(tokenstore[x-1],buffer);
                               
                                return(atoi(buffer));
                                        
                        }
         		else if(count>3){
                        preced = precedence(tokenstore[x],tokenstore[y]);
           		if(preced==1) {
                                result = 0;
            			p=atoi(tokenstore[x-1]);
            			q=atoi(tokenstore[x+1]);
            			result= result + perform(p,q,tokenstore[x]);
                                snprintf(buffer, 10, "%d", result);
            			strcpy(tokenstore[x-1],buffer);
                                
            			m=x;
            			while(m<(count-2)){
             				tokenstore[m]=tokenstore[m+2];
             				m++;
             			}
             		count=count-2;
            		}
		
			else if(preced==2) {
                                result = 0;  
        			p=atoi(tokenstore[y-1]);
             			q=atoi(tokenstore[y+1]);
             			result= result + perform(p,q,tokenstore[y]);
                                
                                snprintf(buffer, 10, "%d", result);
            			strcpy(tokenstore[y-1],buffer);
 				   
             			
             			m=y;
            			while(m<(count-2)) {
            				tokenstore[m]=tokenstore[m+2];
            				m++; 
            			}
            			count=count-2 ;
            		  }
                      }
		}
	}
	
}
int isoperator(char str2[]) {
	if((strcmp(str2,"+") == 0)||(strcmp(str2,"/") == 0)||(strcmp(str2,"-") == 0)||(strcmp(str2,"*") == 0)||(strcmp(str2,"%") == 0))
		return 1;
        else
                return 0;
}
int isnum(char string[]) {
  	if(atoi(string)>0 && atoi(string)<=1000) 
  		return 1;
        else
                return 0;
} 
int precedence(char str1[],char str2[]){
                
    	if(((strcmp(str1,"+")==0)||(strcmp(str1,"-")==0))&&((strcmp(str2,"*")==0)||(strcmp(str2,"/")==0)||(strcmp(str2,"%")==0)))
                return 2;
        else if(((strcmp(str1,"+")==0)||(strcmp(str1,"-")==0))&&((strcmp(str2,"+")==0)||(strcmp(str2,"-")==0)))
                 return 1;
        else if(((strcmp(str1,"*")==0)||(strcmp(str1,"/")==0)||(strcmp(str1,"%")==0))&&((strcmp(str2,"*")==0)||(strcmp(str2,"/")==0)||(strcmp(str2,"%")==0)))
                 return 1;
        else if(((strcmp(str1,"+")==0)||(strcmp(str1,"-")))&&((strcmp(str2,"+")==0)||(strcmp(str2,"-")==0)))
                return 1;
} 
int perform(int p,int q,char str1[]) {
        int z=0;
        	if(strcmp(str1,"/")==0){
           		z=p/q;
            		return z;
        	}  
       		else if(strcmp(str1,"+")==0){
            		z= p+q;
            		return z;
        	}
       		else if(strcmp(str1,"*")==0){
           		z=p*q;
            		return z;
        	}
       		else if(strcmp(str1,"-")==0){
          		z=p-q;
         		return z;
        	}
        	else if(strcmp(str1,"%")==0){
          		z=p%q;
           		return z;
        	}
       
         
}
        



