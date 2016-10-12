#include <stdio.h>
#include <stdlib.h>
#include "day.h"


int main( int argc, char * argv[] ) {

  if ( argc == 3 ) {
    int year = atoi(argv[1]);
    int yearday = atoi(argv[2]);

    int pmonth = -1;
    int pday = -1;

    month_day(year, yearday, &pmonth, &pday);

    if ( pmonth == -1 ){
      printf("Illegal input\n");
      return pmonth;
    }else{
      printf("%d %d\n", pmonth, pday);
      return 0;
    }
  }else if ( argc == 4 ){
    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int day = atoi(argv[3]);

    int yearday = day_of_year(year, month, day);
    if ( yearday == -1){
      printf("Illegal input\n");
      return yearday;
    }else{
      printf("%d\n", yearday);
      return 0;
    }
  }else {
    printf("Usage: %s year <the day of year> - Month/Day\n", argv[0]);
    printf("Usage: %s year month day - the day of year\n", argv[0]);
    return 1;
  }
}
