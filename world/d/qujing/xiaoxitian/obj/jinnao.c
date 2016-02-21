// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
  set_name("金铙",({"jin nao", "nao"}));
  set_weight(9000000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value", 100000);
    set("material","gold");
    set("long", "一只有丈把高的巨大金铙。\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
} 

void init ()
{
  add_action ("do_out", "out");
}

int do_out ()
{
  object me = this_object ();
  object who = this_player();
  object where = environment (who);
  object room = environment (me);

  if (where != me)
    return 0;

  if (who->query_temp("no_move") ||
      who->is_busy())
  {
    tell_object (who, "你在黑暗中摸索着向上爬，当地一声撞在金铙上。\n");
    return 1;
  }
  if (random (10))
  {
    tell_object (who, "你的头当地一声撞在金铙壁上。\n");
    return 1;
  }
  tell_object (who, "你将金铙掀起一道缝，往外爬去。\n",who,me);
  if (room->is_character())
    room = environment (room);
  who->move(room);
  message_vision ("金铙被顶了起来，$N从里面吃力地爬了出来。\n",who,me);
  return 1;
}


