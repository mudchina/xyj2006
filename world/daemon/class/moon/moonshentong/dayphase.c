// dayphase.c
// figure out the current phase of a day
// ref /adm/daemons/natured.c

static int DP_DAWN = 5;
static int DP_SUNRISE = 1;
static int DP_MORNING = 2;
static int DP_NOON = 0;
static int DP_AFTERNOON = 1;
static int DP_EVENING = 2;
static int DP_NIGHT = 3;
static int DP_MIDNIGHT = 4;

// day_phase is an array of mappings of the following type:
// length:time_msg:desc_msg:event_fun
// %d:%s:%s:%s

static mapping *day_phase = NATURE_D->query_day_phase();

int get_current_day_phase() {
    // ref. /adm/daemons/natured.c:init_day_phase()
    mixed *local = localtime(time()*60);
    int t = local[2] * 60 + local[1];
    int i;
    for (i=0; i<sizeof(day_phase); i++)
	if (t>=day_phase[i]["length"])
	    t -= (int)day_phase[i]["length"];
	else
	    break;
    return (i==0 ? sizeof(day_phase)-1 : i-1);
}
