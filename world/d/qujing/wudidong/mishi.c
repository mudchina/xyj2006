// /d/qujing/wudidong/mishi.c
// created by mes, updated 6-20-97 pickle

#include <room.h>
inherit ROOM;

void reset();

void create()
{
  set ("short", "暗室");
  set ("long", @LONG

这儿是无底洞的一个支洞，也是玉鼠精的练功房。除了玉鼠之外，
很少有其他人进出。房间布置得十分简单，但是屋中央摆着一张
十分醒目的玉台(tai)。
LONG);
  set("item_desc",([
		    "tai" : "
这是一张用万年南极冰玉所雕成的玉台，玲珑透剔。想来必是玉鼠练
功之用。台上刻着几个殷红的大字：

\t\t\t天魔座\n\n
\t\t  入我门来，万劫不复
\n",
		    ]));
  set("exits", ([ /* sizeof() == 2 */
		 "out" : __DIR__"gongshi",
		 ]));
  set("no_clean_up", 1);
  set("if_bed", 1);
  set("sleep_room", 1);
  set("outdoors", 0);
  setup();
}       
void init()
{
  add_action("do_climb", "climb");
  add_action("do_climb", "pa");
  add_action("do_lian", "lianxi");
  add_action("do_lian", "xiuxing");
}
int do_climb(string arg)
{
  object me=this_player();
  if ( !arg || (arg !="tai" && arg != "off" && arg != "down" && arg!="xia") )
    return notify_fail("你要爬什么？\n");
  if (arg == "tai")
    {
      if ((int)me->query_temp("mark/无底洞天魔台climbed"))
	return notify_fail("你已经坐在台上了，还想爬到哪儿去？\n");
      message_vision("$N纵身一跃，爬上天魔台去了。\n", me);
      me->set_temp("mark/无底洞天魔台climbed", 1);
      return 1;
    }
  if(!(int)me->query_temp("mark/无底洞天魔台climbed"))
    return notify_fail("你不在台上。\n");
  message_vision("$N从台上跳了下来。\n", me);
  me->delete_temp("mark/无底洞天魔台climbed");
  return 1;
}
int do_lian()
{
  object me=this_player();
  int myspells, myspi, learned, sencost;
  if ((int)me->query_temp("mark/无底洞天魔台climbed") != 1)
    return notify_fail("只有身在天魔台才可练功。\n");
  if((  (int)me->query_skill("dao", 1)>50
     || (int)me->query_skill("taiyi",1)>50
     || (int)me->query_skill("gouhunshu", 1)>50
     || (int)me->query_skill("moonshentong", 1)>50
     || (int)me->query_skill("buddhism", 1)>50
     || (int)me->query_skill("dengxian-dafa", 1)>50
     || (int)me->query_skill("baguazhou", 1)>50)
     && !wizardp(me))
    return notify_fail("不知为何你的先天灵气不能与天魔台的魔魂交合，也许
你现有的法术已学得太深了。\n");
  myspells=(int)me->query_skill("spells", 1);			
  if(me->query_skill("yaofa", 1)>=myspells)
    return notify_fail("你的基本法术修为不够高深，难以与天魔台的魔魂交合。\n");
  myspi=(int)me->query_spi();
  learned=(myspells+myspi)/6;

  if( myspells < 100 )
  	sencost = 30+(myspells/10);
  else  
 	sencost = 30+(myspells/5);

  if ((int)me->query("sen")<=sencost)
      return notify_fail("你神智不清，再练下去会有危险的！\n");
  if(me->query("mana")<=(sencost/2))
      return notify_fail("你的法力不足，难以领会高深的妖法。\n");
  me->delete_temp("spellslevel");
  me->delete_temp("d_mana");
  me->delete_temp("apply/name");
  me->delete_temp("apply/id");
  me->delete_temp("apply/short");
  me->delete_temp("apply/long"); 
  me->receive_damage("sen", sencost/10);
//  me->add("mana", -(sencost/2));
  tell_object (me, "你的「妖法」略有进展。\n");
  me->improve_skill("yaofa",learned);
  if (random(100+me->query_kar()*10)<1)
  //mon 1/23/98. old formula was <1, I changed to <10.
  //don't know exactly, but <1 seems impossible.
// lestat 2001 恢复为原版
  {
    message_vision("$N昏昏地睡了过去。\n", me);
    me->delete_temp("mark/无底洞天魔台climbed");
    me->move("/d/ourhome/honglou/main");
    if (random(40-me->query_kar())<10)
	me->set("dream_place", "/d/qujing/wudidong/mishi");
  }
  return 1;
}

int valid_leave(object me, string dir)
{
  if(dir=="out" && (int)me->query_temp("mark/无底洞天魔台climbed")==1)
    return notify_fail("先从台上跳下去吧！\n");
  return ::valid_leave(me, dir);
}
