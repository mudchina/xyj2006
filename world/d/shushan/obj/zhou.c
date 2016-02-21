#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIC"仙风云体符"NOR, ({ "fu" }) );
  set_weight(350);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一张蜀山仙术的灵符\n");
    set("unit", "道");
  }
  set("value",100000);
  set("no_drop",1);
  set("no_get",1);
//  set("no_give",1);
  set("no_put",1);
  setup();
}

int init ()  
{   
  add_action ("do_back", "back");
}

int do_back()
{
    object me,ob;
    me=this_player();
    ob=this_object();
	message_vision(HIY"\n\n一道金光罩住了$N的身影,$N一阵眩晕,直觉的全身都要被撕裂了一样！！！\n\n"NOR,me);
    
	me->move("/d/shushan/shanjiao");
	me->unconcious();
   destruct(ob);
return 1;
}


