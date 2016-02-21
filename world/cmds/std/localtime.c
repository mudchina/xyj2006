#include <localtime.h>

//static string *week_day = ({ "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" });
static string *week_day = ({ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" });
static string *month = ({ "Jan", "Feb", "Mar", "Apr", "May", 
 "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" });

int main()
{
    int t;
	mixed*  lt;
	string  output;
	string  hr, min, sec;

	t = time();
	lt = localtime( t );

	if( lt[LT_HOUR] < 10 )
	   hr = sprintf("0%d", lt[LT_HOUR]);
    else 
	   hr = sprintf("%d", lt[LT_HOUR]);
	if( lt[LT_MIN] < 10 )
	   min = sprintf("0%d", lt[LT_MIN]);
    else 
	   min = sprintf("%d", lt[LT_MIN]);
	if( lt[LT_SEC] < 10 )
	   sec = sprintf("0%d", lt[LT_SEC]);
    else 
	   sec = sprintf("%d", lt[LT_SEC]);

	output = sprintf("现在时间 %s %s %d %s:%s:%s %s %d\n",
	  week_day[ lt[LT_WDAY] ], month[ lt[LT_MON] ], lt[LT_MDAY],
	  hr, min, sec, lt[LT_ZONE], lt[LT_YEAR] );
	write( output );
	return 1;	
}
