// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit STICK;

void create()
{
        set_name( HIY "金箍棒" NOR, ({ "jin gu bang", "bang" }) );
        set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 500);
		set("material", "gold");
		set("replace_file", "/d/obj/weapon/stick/bintiegun");
		set("long", "此棒两头以金为箍，中间乃一段乌铁。上铸一行小字：“如意金箍棒”。\n");
		set("wield_msg", "$N一伸手，连喝几声：大！大！大！掌中忽然多了一条$n。\n");
		set("unwield_msg", "$N一吹气，几声轻喝：小！小！小！$n在$N掌中转了几转，忽然不见了。\n");
	}
	init_stick(250);
     set("no_sell",1);
	setup();
}

void init()
{
	object me=this_player();
	me->delete_temp("jgb_haven");
	call_out("jgb_check_idle",60);
	return ::init();
}

void jgb_check_idle()
{
	object me=this_player();
	remove_call_out("jgb_check_idle");
	if (me->is_fighting()) 
	{
	  call_out("jgb_check_idle",60);
	  return;
	}
	if (living(me)) {
	  if (me->in_input() || file_name(environment(me))==me->query_temp("jgb_haven/env"))
	 {
	   me->add_temp("jgb_haven/count",1);
	   if (me->query_temp("jgb_haven/count")>=20)
	   {	
	    message_vision("只听见滋溜一声,$n从$N的身上掉下来,钻入地里不见了.\n",me,this_object());
	    destruct(this_object());
	    return;
	   }
	 }
	else {
		me->set_temp("jgb_haven/env",file_name(environment(me)));
		me->set_temp("jgb_haven/count",0);
	     }
	}
	call_out("jgb_check_idle",60);
	return;
}
