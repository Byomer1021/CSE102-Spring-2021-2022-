#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(float pl,float pw);
char dt1b(float pl,float pw);

double dt2a(float x1,float x2,float x3,int x4,int x5);
double dt2b(float x1,float x2,float x3,int x4,int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */
double dt3a(float x1,float x2,int x3,int x4,int x5);
double dt3b(float x1,float x2,int x3,int x4,int x5);

#endif /* _UTIL_H_ */