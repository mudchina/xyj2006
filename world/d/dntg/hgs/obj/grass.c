// grass.c

#include <ansi.h>

inherit ITEM;

int do_make(string);

void create()
{
	set_name("小草", ({ "grass"}) );
	set("long", "一颗绿油油的小草。\n");
	set("unit", "颗" );
        set("no_sell",1);
}



void init()
{                                             
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");

        message_vision("$N饥不择食，咬了几口青草，苦得又都吐了出来！\n" , me);

        destruct(this_object());

        return 1;

}

