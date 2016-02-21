// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by mon

int valid_kill(object killer, object victim)
{    int pk_k, pk_v;   
 
     if(environment(killer)->query("no_fight"))
       return 0;
       //can't init a kill in a no_fight room.
       //this is for /feature/attack's auto kill.

     if(userp(victim) && killer->query_condition("no_pk_time")>480 
       && userp(killer))
       return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");

     return 1;
}

