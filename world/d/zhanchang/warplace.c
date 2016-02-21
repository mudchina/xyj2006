// create by yesi


inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "战场");
  set ("long", @LONG

门派战斗的场地

LONG);

  setup();
}

void init()
{
    object room,king,me;
    object* member;
    int i;
    string me_menpai;
        
    room = this_object();
    me = this_player();
    king = find_living("tang taizong");
    me_menpai = me->query("family/family_name");
    
    if( king->query_temp("mpwarbegin") && !wizardp(me))
    {
    	member = all_inventory(room);
        for (i=0;i<sizeof(member);i++)
          {if(member[i]->query("family/family_name") == me_menpai) continue;
           if(wizardp(member[i])) continue;
           else {member[i]->kill_ob(me);
                 me->kill_ob(member[i]);
                }
          }
    }      
     
    add_action("do_kill", "kill");
    add_action("do_quit", "quit");
    add_action("do_cast", "cast");
    add_action("do_ji", "ji");
    add_action("do_get", "get");     
    
}

int do_kill()
{
	write("这里不需要用这个命令。\n");
	return 1;
}
	
int do_quit()
{
	write("在战场内不能退出游戏。\n");
	return 1;
}


int do_cast(string spell)
{
	if(spell=="shuidun" || spell=="tudun" || spell=="huodun"
	   || spell=="escape" || spell=="miwu")
	  {write("你不能用这个法术。\n");
	   return 1;
	  }
	  
	 return 0;
}	 
	  
int do_ji()
{
	write("战场内不能用ji。\n");
	   return 1;	  
}
	   
int valid_leave(object me, string dir)
{
	if(time()-me->query_temp("warmove")<3)
	   return notify_fail("你现在不能移动。\n");
	
	if(me->is_fighting())
	   {me->set_temp("warmove",time());
	    return ::valid_leave(me, dir);
	   }
	
	return ::valid_leave(me, dir);   
}

int do_get()
{
	write("战场内不能用get。\n");
	   return 1;	  
}	   	   