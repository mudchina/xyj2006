//Cracked by Roath

// huangtong-key.c 

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "黄铜钥匙" NOR, ({"huangtong key", "key"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把黄铜钥匙。\n");
	}
  
	set("is_monitored",1);
	setup();
}

// to prevent robot hold keys. mon 10/31/98
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "落在地上，不见了。\n");
    destruct(me);
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    who->query("name")+"得到了"+name()+"！\n");
}
void init()
{
    call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}



