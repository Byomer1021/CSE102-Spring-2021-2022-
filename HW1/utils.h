#ifndef _UTILS_H_
#define _UTILS_H_

int find_divisible(int x, int y, int z);
int find_nth_divisible(int n, int f_I, int z);
int validate_identity_number(char identity_number [11]);
int password(char pasword [4] );
int create_customer(char identity_number , int password);
int check_login(char identity_number , int password);
int withdrawable_amount(float cash_amount);

#endif /* _UTILS_H_ */