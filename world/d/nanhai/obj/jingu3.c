//Cracked by Roath
// jingu.c 紧箍咒

#include <ansi.h>

inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"紧箍咒"NOR, ({ "jingu zhou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "篇");
        set("long",
        "紧箍咒，又唤做“定心真言”。撞见神通广大的妖魔，只依所用的咒语念一念，管教他入我门来。\n");
        set("material", "paper");       
        }
	setup();
}

void init()
{
	if (this_player() -> query("family/family_name") != "南海普陀山" ) {
		remove_call_out("free_jingu");
		call_out("free_jingu", 120, this_object(), this_player()); 
	}

	::init();
}

void free_jingu(object ob, object who)
{
        if(!who || !ob) return;

	if (who -> query("family/family_name") != "南海普陀山" ) {
		tell_object(who, HIR"你仿佛听到有人说：非佛门中人，得之无用，不如弃之。\n"
			+ "随着一声轻响，紧箍咒已腾空而去，不留下一丝痕迹。\n\n"NOR);
		destruct(ob);
	}
	else { 
		call_out("free_jingu", 120, ob, who);
	}
	return;
}
