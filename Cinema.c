#include <stdio.h>
#include <string.h>
#include <time.h>
struct Movie{
	char movieId[6];
	int customerId;
	char customerType[4];
	char dateAndTime[23];
	int seatNo;
};
struct Bill{
	int customerId;
	char movieName[30];
	char customerType[4];
	float amnt;
};
void intro();
void file(struct Bill b[100],int i);
void twodarray();
int main(){
	int ask,i=0,j,k,n,mv,ml,r,age,exit=0,search,kal;
	float sum,asum,dis=0,*pasum,*amount[100];
	pasum = &asum;
	char movies_name[10][30]={"AntMan_And_The_Wasp","Men_In_Black_3","John_Wick_4","Puss_In_Boots:The_Last_Life","The_Big_bang_theory"};
	time_t t;
	time(&t);
	intro();
	struct Movie m[100];
	struct Bill b[100];
	do{
	printf(":");
	scanf("%d",&ask);
	switch(ask){
		case 1:
			printf("===========\tAvailable Movies\t==========\n");
			for(k=0;k<5;k++){
				printf("%d.) %s\n",k+1,movies_name[k]);
			}
			printf("===================================================\n");
			break;	
		case 2:
			printf("Are you a regular customer:\n");
     		scanf("%s",&m[i].customerType);
     		strcpy(b[i].customerType,m[i].customerType);
     		printf("Enter you age:");
			scanf("%d",&age);
     		if (strcmp("y",m[i].customerType)==0 && age<10)
     		dis=-15;
     		else if (strcmp("y",m[i].customerType)==0 && age>=10)
     		dis=-10;
     		else if (strcmp("y",m[i].customerType)!=0 && age<10)
     		dis=-5;
     		else
     		dis=0;
     		b[i].amnt=100+dis;
     		amount[i] = &b[i].amnt;
     		printf("Enter the movies you want to watch:\n");
			scanf("%d",&mv);
			switch(mv){
				case 1:
					strcpy(m[i].movieId,"ant523");
					strcpy(b[i].movieName,"AntMan_And_The_Wasp");
					break;
				case 2:
					strcpy(m[i].movieId,"mib523");
					strcpy(b[i].movieName,"Men_In_Black_3");
					break;
				case 3:
					strcpy(m[i].movieId,"jw4823");
					strcpy(b[i].movieName,"John_Wick_4");
					break;
				case 4:
					strcpy(m[i].movieId,"pib824");
					strcpy(b[i].movieName,"Puss_In_Boots:The_Last_Life");
					break;
				case 5:
					strcpy(m[i].movieId,"tbbt15");
					strcpy(b[i].movieName,"The_Big_bang_theory");
					break;
				default:
					printf("That film is not avalable.Kindly enter a valid value");
					break;
			}
	 		m[i].customerId=2023019+i;
	 		b[i].customerId=m[i].customerId;
	 		strcpy(m[i].dateAndTime,ctime(&t));
	 		m[i].seatNo =101+i;
            i++;
			break;
		case 3:
			printf("\nMovieId\t\tCustomerId\t\tCustomerType\t\tDateAndTime\t\tSeatNumber\n");
	        for(j=0;j<i;j++)
			{
		    printf("%s\t\t%d\t\t\t%s\t\t%s\t\t%d\n",m[j].movieId,m[j].customerId,m[j].customerType,m[j].dateAndTime,m[j].seatNo);
	        }
		  	break;
		case 4:			
			printf("====================================================\n");
			printf("%s\n",ctime(&t));
			printf("CustomerId\t\tCustomerType\t\tAmount\t\tMovie Name\n");
			for(r=0;r<i;r++)
			{
		    printf("%d\t\t\t%s\t\t\t%f\t\t%s\n",b[r].customerId,b[r].customerType,b[r].amnt,b[r].movieName);
		    sum+=b[r].amnt;
	        }
	        printf("----------------------------------------------------------------\n");
	        printf("\t\t\t\tTotal:%f\n",sum);
	        file(b,i);
			break;
		case 5:
			printf("Enter customer id to be searched:");
			scanf("%d",&search);
			for(j=0;j<i;j++)
			{
			if (search == m[j].customerId){
			 printf("ID found!!\n");
			 printf("%s\t\t%d\t\t\t%s\t\t%s\t\t%d\n",m[j].movieId,m[j].customerId,m[j].customerType,m[j].dateAndTime,m[j].seatNo);
		}
			}
			break;
		case 6:
			printf("Amount collection till now...\n\n");
			printf("Customer ID : Amount\n\n");
			for(j=0;j<i;j++){
				printf("%d: %f \n",m[j].customerId,*amount[j]);
				*pasum+=*amount[j];
			}
			printf("Total collection:%f\n",*pasum);
			break;
		case 7:
			exit=1;
			break;
		default:
			printf("Error enter a valid value\n");
			break;
	}

}while(exit==0);
  return 0;
}
void intro(){
	printf("=========================================================================\n");
	printf("###  # #  ##   ###   ##  ###\n"); 
	sleep(1);
	printf("#    # #  # #   #   #     # \n");
	sleep(1);
	printf("#    ###  ##    #   ##    # \n");
	sleep(1);
	printf("#    # #  # #   #     #   # \n");
	sleep(1);
	printf("###  # #  # #  ###  ##    # \n\n\n\t\t###  ###  #    #  ###  #   #    # \n\t\t#     #   # #  #  #    ## ##  #   #\n\t\t#     #   #  # #  ###  # # #  #####\n");
	printf("\t\t#     #   #   ##  #    # # #  #   #\n\t\t###  ###  #    #  ###  #   #  #   #\t\t......Since 2023\n");
	printf("=========================================================================\n\n\n\n");
    printf("Welcome to Christ Cinemas.Use the following guideline to opeate across the system\t\t\n");
    printf("\t\t1.TO SEE THE AVAILABLE MOVIES\n\t\t2.TO BOOK A SEAT\n\t\t3.TO SEE THE USER TABLE\n\t\t4.TO PRINT THE BILL\n\t\t5.SEARCH FOR A CUTOMER\n\t\t6.TOTAL AMOUNT\n\t\t7.EXIT\n");
}
void file(struct Bill b[100],int i){
	int r;
	float sum;
	FILE *fp;
	fp = fopen("bill.txt","w");
	fputs("====================================================\n",fp);
	fputs("CustomerId\t\tCustomerType\t\tAmount\t\tMovie Name\n",fp);
	for(r=0;r<i;r++)
	{
		    fprintf(fp,"%d\t\t\t%s\t\t\t%f\t\t%s\n",b[r].customerId,b[r].customerType,b[r].amnt,b[r].movieName);
		    sum+=b[r].amnt;
	}
	fputs("----------------------------------------------------------------\n",fp);
	fprintf(fp,"\t\t\t\tTotal:%f\n",sum);
	fclose(fp);
}
void twodarray(){
    int arr[3][3],b[9]; 
    int i,j,k=0,temp; 
    printf("\nEnter the elements of the array:\n"); 
    for(i=0;i<3;++i){  
	for(j=0;j<3;++j){
		printf(":");
	    scanf("%d",&arr[i][j]); }
    } 
    printf("\nThe elements entered are :\n"); 
    for(i=0;i<3;++i) { 
	   for(j=0;j<3;++j){ 
	       printf("%d ",arr[i][j]); 
	   } 
	   printf("\n"); 
    } 
    for(i=0;i<3;i++){ 
	    for(j=0;j<3;j++) 
     	b[k++]=arr[i][j]; 
    } 
    printf("\nEntered 1-D Matrix is:\n"); 
    for(k=0;k<9;k++) 
    printf("%d ",b[k]); 
    for (i=0;i<9;i++){ 
 	    for (j=0;j<(8-i);j++) 
	    { 
   	        if(b[j]>b[j+1]) 
	        { 
	         	temp = b[j]; 
	        	b[j] = b[j+1]; 
		        b[j+1] = temp; 
	        } 
	    } 
    } 
    printf("\n\nSorted 1D array used is:\n"); 
    for(i=0;i<9;i++){ 
	    printf("%d ", b[i]); 
    } k=0;
    for(i=0;i<3;i++){ 
	    for(j=0;j<3;j++) 
	    { 
	        arr[i][j]=b[k]; 
	        k++; 
	    } 
    } 
    printf("\n\nSorted 2D Array is:\n"); 
    for(i=0;i<3;i++) 
    { 
	    for(j=0;j<3;j++) 
	    { 
            printf("%d ",arr[i][j]); 
	    } 
    	printf("\n"); 
    } 
    printf("\n\nTranspose of Sorted 2D Array is:\n"); 
    for(i=0;i<3;i++) 
    { 
	    for(j=0;j<3;j++) 
	    { 
            printf("%d ",arr[j][i]); 
	    } 
    	printf("\n"); 
    }
}


	
