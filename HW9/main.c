#include <stdio.h>
#include <string.h>

void listCustomers();
void addCustomer();
void newLoan();
void calculateLoan(float amount, int period, float interestRate);
void getReport();

union Person{ 
	char name[50]; 
	char address[50]; 
	long int phone;
}; 

union Loan{ 
	float arr[3];
}; 

struct BankAccount{ 
	union Person Customer; 
	union Loan Loans[3];
};

int main(){
	
	int opCode;
	
	do{
		
		printf("=========================================\n  Welcome to the bank management system\n=========================================\n");
		printf("	1. List All Customers\n	2. Add New Customer\n	3. New Loan Application\n	4. Report Menu\n	5. Exit System\n");
		scanf("%d", &opCode);
		
		switch(opCode){
			case 1:
				listCustomers();
				break;
			case 2:
				addCustomer();
				break;
			case 3:
				newLoan();
				break;
			case 4:
				getReport();
				break;
			case 5:
				return 0;	
		}
		
	}while(1);
	
}

void listCustomers(){
	
	FILE *file = fopen("customers.txt", "r");
	
	char temp[50];
	char customer[50];
	
	while(!feof(file)){
		strcpy(customer, "");
		fgets(temp, 50, file);
		for(int j=0; j<strlen(temp); j++){
			if(temp[j] == '|'){
				customer[j] = '\0';
				break;
			} 
			customer[j] = temp[j];
		}
		if(customer[0] == '\0') break;
		printf("Customer Name = %s\n", customer);
	}
	
	fclose(file);

}

void addCustomer(){
	
	FILE *file = fopen("customers.txt", "a");
	
	struct BankAccount account;
	
	printf("Enter customer name = ");
	while(!getchar() == '\n');
	fgets(account.Customer.name, 50, stdin);
	if((strlen(account.Customer.name) > 0) && (account.Customer.name[strlen(account.Customer.name) - 1] == '\n')) account.Customer.name[strlen(account.Customer.name) - 1] = '\0';
	fprintf(file, "%s|", account.Customer.name);
	printf("Enter customer address = ");
	fgets(account.Customer.address, 50, stdin);
	if((strlen(account.Customer.address) > 0) && (account.Customer.address[strlen(account.Customer.address) - 1] == '\n')) account.Customer.address[strlen(account.Customer.address) - 1] = '\0';
	fprintf(file, "%s|", account.Customer.address);
	printf("Enter customer phone = ");
	scanf("%ld", &account.Customer.phone);
	fprintf(file, "%ld|\n", account.Customer.phone);
	
	fclose(file);
	
}

void newLoan(){
	
}

void getReport(){
	
}
