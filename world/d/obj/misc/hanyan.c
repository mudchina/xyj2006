//Cracked by Roath
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>

inherit STICK;

void create()
{
  set_name(HIB "旱烟枪" NOR, ({ "hanyan qiang","hanyan", "qiang"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一根长长的老式旱烟枪。\n");
    set("unit", "根");
    set("wield_msg", "$N拿出$n叼在嘴上，眯眼将$n点着。\n");
    set("unwield_msg", "$N将$n叭地一敲，藏入怀里。\n");
  }
  init_stick(2);
  setup();
}

void init ()
{
  add_action ("do_smoke", "smoke");
}

int do_smoke (string arg)
{
  object me = this_player();
  object ob = this_object();
  string msg;

  if (! arg || this_object() != present (arg, me))
    return 0;

  switch (random(5))
  {
    case 0:
      { msg = "$N拿起$n，眯起眼吸了一口。\n"; break; }
    case 1:
      { msg = "$N叼着$n吸了一口烟。\n"; break; }
    case 2:
      { msg = "$N皱着眉低头在$n上吸了一口旱烟。\n"; break; }
    case 3:
      { msg = "$N一边沉思一边拿起$n吸了口烟。\n"; break; }
    case 4:
      { msg = "$N略点点头，在$n上吸了一吸。\n"; break; }
  }
  message_vision (msg,me,ob);
  remove_call_out ("smoke_spreads");
  call_out ("smoke_spreads",random(3)+3,me,ob);
  return 1;
}

int smoke_spreads (object me, object ob)
{
  string msg;
  switch (random(5))
  {
    case 0:
      { msg = "烟从$N的鼻孔里喷出来，在空中散开。\n"; break; }
    case 1:
      { msg = "一串烟圈从$N的嘴里吐了出来。\n"; break; }
    case 2:
      { msg = "青烟慢慢在空气中散开。\n"; break; }
    case 3:
      { msg = "烟慢慢飘开。\n"; break; }
    case 4:
      { msg = "周围散发着淡淡的烟味。\n"; break; }
  }
  message_vision (msg,me,ob);
  if (random(4) == 0)
    return 1;
  remove_call_out ("smoke_spreads");
//  call_out ("smoke_spreads",random(3)+3,me,ob);
  return 1;
}


