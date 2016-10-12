#include <stdio.h>
#include "day.h"

static int daytab[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int year, int month, int day){
  int i, leap;

  leap = ( ( year%4 == 0 ) && ( year%100 != 0 ) ) || ( year%400 == 0 );

  if ( (0 < month) && (month < 13) && (0 < day) && (day <= (*(daytab + leap * 13 + month))) ){ // valid month and day

    for (i = 1; i < month; i ++){
      day += (*(daytab + leap * 13 + i));
    }

    return day;

  }else{

    return -1;
  }
}

void month_day(int year, int yearday, int *pmonth, int *pday){

  int i, leap;

  leap = ( ( year%4 == 0 ) && ( year%100 != 0 ) ) || ( year%400 == 0 );

  if ( (leap && 0 < yearday && yearday <= 366) || (!leap && 0 < yearday && yearday <= 365) ){

    for (i = 1; yearday > (*(daytab + leap * 13 + i)); i ++){
      yearday -= (*(daytab + leap * 13 + i));
    }

    *pmonth = i;
    *pday = yearday;
  }
}
