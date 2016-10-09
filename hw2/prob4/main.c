#include <stdio.h>
#include <stdlib.h>
#include "day.h"


int main( int argc, char * argv[] ) {

  if ( argc == 3 || ) {
    int year = atoi(argv[1]);
    int yearday = atoi(argv[2]);

    int *pmonth;
    int *pday;

    month_day(year, yearday, *pmonth, *pday);
  }else if ( argc == 4 ){
    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int month = atoi(argv[3]);
    printf("%d",day_of_year(year, month, day));
  }else {
    printf("Usage: %s year <the day of year> - Month/Day\n", argv[0]);
    printf("Usage: %s year month day - the day of year\n", argv[0]);
  }
}
