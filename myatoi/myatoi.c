/*
 * This programs solves a leetcode challenge May 2020.
 * It is ugly as sin, but when submitted it was the fastest solution.
*/
#include <stdio.h>

#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)

int myAtoi(char * str){
  
    long num = 0;
    int i;
    int zero = (int)'0';
    int sign = 1;
    int val = 0;
    int stripping = 1;
    int hassign = 0;

    
    for (i=0; str[i] != 0; i++) {

      if (stripping) {
	switch (str[i]) {
	case '-':
	  sign = -1;
	case '+':
	  if (hassign) {
	    return (0);
	  } 
	  hassign = 1;
	  continue;
	case ' ':
	  if (hassign) {
	    return (0);
	  } 
	  continue;
	}
      }
      
      val = (int)str[i] - zero;
      if (val >= 0 && val <= 9) {
	num = (num * 10) + val;
	stripping = 0;
      } else if (num != 0) {
	break;
      } else {
	return 0;
      }

      if (num > INT_MAX) {
	break;
      }
    }
    
    if (num > INT_MAX) {
      if (sign == -1) {
        return (INT_MIN);
      } else {
        return (INT_MAX);
      }
    }
    
    num = num * sign;
    
    return (num);
}

int main(int argc, char **argv) {
  int num;

  printf("4 = %d\n", myAtoi("4"));
  printf("+-4 = %d\n", myAtoi("+-4"));
  printf("- 4 = %d\n", myAtoi("- 4"));
  printf("42 = %d\n", myAtoi("42"));
  printf("   -42 = %d\n", myAtoi("  -42"));
  printf("420 = %d\n", myAtoi("420"));
  printf("-420 = %d\n", myAtoi("-420"));
  printf("-420... = %d\n", myAtoi("-420..."));
  printf("20000000000000000 = %d\n", myAtoi("20000000000000000"));
  printf("2147483648 = %d\n", myAtoi("2147483648"));
  printf("2147483648 = %d\n", myAtoi("2147483649"));
  printf("2147483648 = %d\n", myAtoi("-2147483649"));
}
