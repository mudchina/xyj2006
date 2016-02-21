// trap.c
// created by mes, updated 6-21-97 pickle
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "石洞深处");
  set ("long", @LONG

断断续续的呻吟变得更加清晰了，前方也透出了一点豆大的灯光，依
稀可见黑影幢幢。脚下突然踢到几具横七竖八的骷髅，你不禁捏了一
把冷汗。
LONG);
  set("trap", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jail",
  "south" : __DIR__"lock",
]));

  setup();
}
void init()
{
  add_action("do_disarm", "disarm");
}
int do_disarm()
{
  object me=this_player(), room=this_object();
  int mykar,mydodge,factor;
  int damage, kee, maxkee;
  mykar=(int)me->query_kar();
  mydodge=me->query_skill("dodge");
  factor=(int)(mykar*3+mydodge);
  maxkee=(int)me->query("max_kee");
  kee=(int)me->query("kee");
  damage=maxkee*3/5;
  if (!me->query_temp("mark/wudidong_aware_of_trap"))
    return notify_fail("你要干什么？这里阴森森的，还不快走？\n");
  me->delete_temp("mark/wudidong_aware_of_trap");
  if (me->query_temp("has_paid") > 0)
return notify_fail(BLU "你成功地拆除了房间里的机关。\n" NOR, me);
  if (random(factor)>50)
    {
      message_vision(BLU "$N成功地拆除了房间里的机关。\n" NOR, me);
      me->set_temp("has_paid", 2);
      return 1;
    }
  else
    {
      message_vision(RED "一阵乱箭向$N射来。" NOR, me);
      if(damage>kee)
	{
	  me->set_temp("has_paid", 1);
	  call_out("playerdead", 1, me);
	  return 1;
	}
      else
	{
	  message_vision(RED "$N伤得不轻。\n" NOR, me);
	  message_vision(BLU "机关被拆除了. \n" NOR, me);
	  me->receive_damage("kee", damage);
	  me->receive_wound("kee", damage-10);
	  me->set_temp("has_paid", 2);
	  return 1;
	}
    }
}
int valid_leave(object me, string dir)
{
  object room=this_object();
  int damage, kee, maxkee;
  maxkee=(int)me->query("max_kee");
  kee=(int)me->query("kee");
  if (dir =="north" && me->query_temp("has_paid") <= 0)	
    {
	if(!userp(me)) return 0;

      message_vision(RED "$N向北走去，突然间，墙里射出一阵箭雨。\n" NOR, me);
      call_out("playerdead", 1, me);
      return notify_fail("");
    }
 me->set_temp("has_paid", 1);
  return ::valid_leave(me, dir);
}
void playerdead(object me)
{
  int mypot, mylp, mynewpot;

  if (me->query("combat_exp")<800000 && random(2))
  {
    me->delete_temp("last_damage_from");
    me->set_temp("death_msg", "被乱箭射死了。\n");
    me->die();
    me->save();
  }
  else
  {
    me->unconcious();
  }
  return;
}
