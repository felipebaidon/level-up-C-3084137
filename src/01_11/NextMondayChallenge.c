#include <time.h>
#include <stdio.h>

#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR   60
#define HOURS_IN_DAY      24

//#define DEBUG

int main(void)
{
  /* get current date */
  time_t timeNow;
  struct tm *timestamp;
  const char *weekday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  const char *month[] = {"January", "February", "March", "April",
                         "May", "June", "July", "August",
                         "September", "October", "November", "December"};
  
  int daysForNextMonday = 8; //assuming today is monday, including both mondays

/* get today*/
  time(&timeNow);
#ifdef DEBUG
  int daysFromToday = 300;
  timeNow += daysFromToday * SECONDS_IN_MINUTE* MINUTES_IN_HOUR*HOURS_IN_DAY;
#endif
  timestamp = localtime(&timeNow);
  printf("Today is: %s %s %d %d\n", weekday[timestamp->tm_wday], month[timestamp->tm_mon], timestamp->tm_mday, timestamp->tm_year + 1900);

/* Next monday will be in 8 - today days */
  if(timestamp->tm_wday == 0)
  {
    daysForNextMonday = 1;
  }
  else
  {
    daysForNextMonday = daysForNextMonday - timestamp->tm_wday;
  }
  
/* compute next date */
  timeNow = timeNow + daysForNextMonday * SECONDS_IN_MINUTE * MINUTES_IN_HOUR * HOURS_IN_DAY;
  timestamp = localtime(&timeNow);
  printf("Next monday will be: %s %d %d\n", month[timestamp->tm_mon], timestamp->tm_mday, timestamp->tm_year + 1900);

  return 0;
}