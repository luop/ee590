#include <stdio.h>
#include "day.h"

//char **daytab;
//daytab = (char **)malloc(sizeof(char *) * 2);
//daytab[0] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//daytab[1] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int daytab[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int year, int month, int day){
  int i, leap;

  leap = ( ( year%4 == 0 ) && ( year%100 != 0 ) ) || ( year%400 == 0 );

  for (i = 1; i < month; i ++){
    //day += daytab[leap][i];
    day += (*(daytab + leap * 13 + i));
  }

  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){

  int i, leap;

  leap = ( ( year%4 == 0 ) && ( year%100 != 0 ) ) || ( year%400 == 0 );

  for (i = 1; yearday > (*(daytab + leap * 13 + i)); i ++){
    //yearday -= daytab[leap][i];
    yearday -= (*(daytab + leap * 13 + i));
  }

  *pmonth = i;
  *pday = yearday;
}
