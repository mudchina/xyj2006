// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name(HIB "五弦琴" NOR, ({ "wuxian qin"})); 
  set_weight(100000);
  set("long","一架古色古香的五弦琴。\n");
  set("unit", "架");
  setup();
}

init ()
{
  add_action ("do_play", "play");
}

int do_play (string arg)
{
  object me = this_player();
  object qin = this_object();
  string *msgs = ({
    "$N伸出纤指在琴上轻拨了一下，不禁想起梦中人。\n",
    "$N轻拨了一下琴弦，脸色绯红。\n",
    "$N若有所思地在弦上一拨，沉默几许……\n",
    "$N伏身抚琴，禁不住泪如雨下。\n",
    "$N轻轻地弹着琴，面色婉尔。\n",
    "$N小心地弹着琴弦，低低地唱了起来。\n",
    "$N边唱边弹，一曲凄歌断人心肠。\n",
  });

  if (arg != "wuxian qin")
  {
    tell_object (me,"想弹什么呢？\n");
    return 1;
  }

  message_vision (msgs[random(sizeof(msgs))],me);
  return 1;
}

