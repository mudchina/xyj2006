//created by vikee
//2000.11

#include <ansi.h>
inherit ITEM;
int get_gift(string arg);
void create()
{
  set_name(HIY"礼物台" NOR ,({"gift table","table"}));
  set("long","这是西游记2006巫师为了奖励新手做的礼物台，玩家可以在这里拿(take)礼物(gift)。");
  set("unit", "个");
  set("value", 1000000000000);
}
void init()
{
  if (!wizardp(this_player())) 
   set("no_get","这个东西拿不起来。\n");
  add_action("get_gift","take");
}
int get_gift(string arg)
{
  object me = this_player();
  object lw;
  if (arg!="gift")      return 0;
  if (me->query("newbie_gift")) return notify_fail("你已经拿过礼物了,别太贪心哟！\n");
  message_vision("$N从礼物台上拿下一份礼物。\n" NOR, me);
  lw=new("/u/vikee/gift");
  lw->move(me);
  me->set("newbie_gift",1);
  return 1;
}
