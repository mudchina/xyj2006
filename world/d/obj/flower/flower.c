// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  seteuid(getuid());

  switch (random(14))
  {
    case 0:
      { set_name(HIB "蓝玫瑰" NOR, ({ "flower","dream flower"})); break; }
    case 1:
      { set_name(HIB "黑郁金香" NOR, ({ "flower","dream flower"})); break; }
    case 2:
      { set_name(HIB "薄雪花" NOR, ({ "flower", "dream flower"})); break; }
    case 3:
      { set_name(HIB "野风信子" NOR, ({ "flower","dream flower"})); break; }
    case 4:
      { set_name(HIB "玉白露" NOR, ({ "flower","dream flower"})); break; }
    case 5:
      { set_name(HIB "睡芙蓉" NOR, ({ "flower","dream flower"})); break; }
    case 6:
      { set_name(HIB "紫蔷薇" NOR, ({ "flower","dream flower"})); break; }
    case 7:
      { set_name(HIB "大丽花" NOR, ({ "flower","dream flower"})); break; }
    case 8:
      { set_name(HIB "勿忘我" NOR, ({ "flower","dream flower"})); break; }
    case 9:
      { set_name(HIB "白玫瑰" NOR, ({ "flower","dream flower"})); break; }
    case 10:
      { set_name(HIB "翡翠绿" NOR, ({ "flower","dream flower"})); break; }
    case 11:
      { set_name(HIB "雪腊梅" NOR, ({ "flower","dream flower"})); break; }
    case 12:
      { set_name(HIB "曼陀罗" NOR, ({ "flower","dream flower"})); break; }
    case 13:
      { set_name(HIB "睡莲" NOR, ({ "flower","dream flower"})); break; }
  }
  set_weight(100);
  set("long","一朵色彩艳丽的"+query("name")+"。\n");
  set("unit", "朵");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 10);
  set("baihuaniang",1);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_wear", "dai");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  add_action ("do_water", "water");
  add_action ("do_fix", "fix");
  call_out("need_water", 10+random(10), environment(this_object()));
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N戴上一朵"+name+"，不禁想起年少时曾经的梦中人。\n"; break; }
    case 1:
      { msg = "$N戴上"+name+"，沉默几许……低首往事如烟。\n"; break; }
    case 2:
      { msg = "$N拿起"+name+"插在发际，婉尔一笑。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"别在胸前，禁不住泪如雨下。\n"; break; }
    case 4:
      { msg = "$N将"+name+"别在胸前，那个熟悉的名字脱口而出。\n"; break; }
    case 5:
      { msg = "$N将"+name+"插在胸前，心里不禁一热。\n"; break; }
    case 6:
      { msg = "$N将"+name+"拿起来，忘情地一吻，然后插在胸前。\n"; break; }
    case 7:
      { msg = "$N小心地把"+name+"别在发鬏上。\n"; break; }
    case 8:
      { msg = "$N将长发轻轻一甩，将"+name+"别在上面。\n"; break; }
  }
  //message_vision (msg,me);
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  //message_vision (msg,me);
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N闻了闻"+name+"，想起当年那好熟悉的清香味。\n"; break; }
    case 1:
      { msg = "$N低头嗅了一下"+name+"，扭过头去打了一个香香喷。\n"; break; }
    case 2:
      { msg = "$N捧着"+name+"一嗅，泪水滴在花瓣上。\n"; break; }
    case 3:
      { msg = "$N将一朵"+name+"放在鼻子下，想啊想啊……\n"; break; }
    case 4:
      { msg = "$N捧着"+name+"闻了一下：唉，今夕是何夕。\n"; break; }
    case 5:
      { msg = "$N将"+name+"捧起闻了闻，又惦记起昨天的故人。\n"; break; }
    case 6:
      { msg = "$N不禁将"+name+"轻轻一闻，思绪绵绵如窗外的细雨。\n"; break; }
    case 7:
      { msg = "$N闻了闻"+name+"，痴痴地听着窗外飘过的小雨。\n"; break; }
    case 8:
      { msg = "$N将"+name+"轻轻一嗅，不禁念道：明日天涯何处……\n"; break; }
  }
  message_vision (msg,me);
  return 1;
}

int do_fix (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N将"+name+"小心地用湿润的丝绢包好。\n";
  flower->set("fixed",1);
  message_vision (msg,me);
  return 1;
}

void need_water (object where)
{
  object flower = this_object();
  object who = environment(flower);
  string name = flower->query("name");
  string msg;
  object seed;

  if (!who || !living(who))
    return;

  if (flower->query("fixed"))
    return;

  switch (flower->query("water"))
  {
    case 0:
      { msg = "风吹过，"+name+"在$N的眼前轻晃了一下。\n"; break; }
    case 1:
      { msg = name+"有点干了，哦，该淋一点水了。\n"; break; }
    case 2:
      { msg = name+"慢慢低下头。\n"; break; }
    case 3:
      { msg = name+"抬起头，无声地看着$N。\n"; break; }
    case 4:
      { msg = name+"艰难地重新伸直腰杆：“水”……\n"; break; }
    case 5:
      { msg = name+"终于干枯了。\n"; flower->set("name","干"+name); break; }
    default:   //added by mon 8/31/97
      {  
        if(flower->query("water")>10 && random(10)==0) {
          message_vision(name+
	  "随风而起，化作了片片花雨．．．\n"+
	  "再看时，只有一粒乌黑的花籽还留在$N手上。\n"
	  ,who);
	  seed = new (__DIR__"seed");
          seed->move(who);
          destruct(flower);
	  return;
	}
      }
  }
  if(msg)message_vision (msg,who);
  flower->set("water",flower->query("water")+1);
  call_out ("need_water",random(50)+50,where);
}

int do_water (string arg)
{
  object flower = this_object();
  object who = this_player();
  string name = flower->query("name");
  string msg;

//  if (arg != "flower")
  if (!arg) return 0;
  if (this_object()!=present(arg,this_player()))
    return 0;

  if (flower->query("water") >= 5)
  {
    message_vision ("$N的泪水一滴滴流在"+name+"上。\n",who);
    return 1;
  }

  switch (random(9))
  {
    case 0:
      { msg = "$N口含清水，喷在"+name+"的花瓣上。\n"; break; }
    case 1:
      { msg = "$N将一点清水洒在"+name+"上。\n"; break; }
    case 2:
      { msg = "$N伸出手抓住细细的小雨，淋在"+name+"上。\n"; break; }
    case 3:
      { msg = "$N小心地捧起一点点露水，滴在"+name+"的花蕾上。\n"; break; }
    case 4:
      { msg = "$N一阵心痛，泪水流在"+name+"的花瓣上。\n";break; }
    case 5:
      { msg = "$N双手捧着"+name+"，伸到窗外的小雨中……\n";break; }
    case 6:
      { msg = "$N仔细地拿起一只小杯子，将水滴在"+name+"上。\n";break; }
    case 7:
      { msg = "$N捧起从野外采来的晨露，洒在"+name+"的花瓣上。\n";break; }
    case 8:
      { msg = "$N用手指蘸着清水，一点点滴在"+name+"的花瓣上。\n";break; }
  }
  message_vision (msg,who);
  message_vision (name+"重新露出了天真的笑容。\n",who);
  flower->set("water",0);
  return 1;
}
