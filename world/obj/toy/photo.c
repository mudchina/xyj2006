// ash.c

inherit ITEM;

void create()
{
        set_name("灰烬", ({ "huijin", "ash" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("unit", "张");
				set("value",0);
		set("long", "一堆无法辨认的焦黑的灰烬，象是一场浩劫后留下的残余。\n");
		}
        setup();
}

void init()
{
}

