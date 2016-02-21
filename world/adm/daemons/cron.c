
#include <ansi.h>
#include <user.h>
#include <command.h>
#include <globals.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <obstacle.h>
// #define FILE "/d/obj/npc/emery.c"
#define DEBUG "canoe"
int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void dianmao();
//void emery();

void create()
{
        seteuid( ROOT_UID );
        init_cron();
}

int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}

void init_cron()
{
        mixed *local;
        local = localtime(time());
        if ( !((local[1])%30)) autosave();

        if ( !((local[1])%30)) dianmao();
//if ( !((local[1])%50)&& random(3) == 1) emery();

       if ( !((local[1])%30))
       if (random(5))TASK_D->init_dynamic_quest();
        else TASK_D->init_dynamic_quest(1);
        call_out("init_cron", 60);  
}

void autosave()
{
 object *user ;
 int i;
        user = users();
 message("channel:chat",HIR"【太平盛世】："HIY"自动更新西游记2006任务榜。\n"NOR,users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
}

void dianmao()
{
 object *user;
 int size1,i;
      int iMax ;
 size1 = sizeof(obstacles);
 user = users();
 if ( member_array(DEBUG,SECURITY_D->query_wizlist()) == -1 && ( sizeof(user) > random(60) + 10 ) )
	shutdown(0);
 message("channel:chat",HIY+"【大唐盛世】徐茂功(Xu maogong)：时辰已到，各位同仁速到大殿点卯。\n"+NOR,users());
     iMax = sizeof(user) ;
          for(i=0; i < iMax ; i++)
        {
           //if ( user[i]->query("obstacle/number") == size1 )
           //{
// user[i]->set("dianmao",1);
  if((int)query_idle(user[i])>IDLE_TIMEOUT&&!wizardp(user[i]))
     {
           if ( time() - (int)user[i]->query("birthday") < 3600 )
                               destruct( user[i] ); 
                else
                     {
                          if ( user[i]->save() )
                                    destruct( user[i] ); 
                               }
          }
           //}
        }
}         


