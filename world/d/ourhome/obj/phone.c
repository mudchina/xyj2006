// phone.c 
// it will send you to someone place
// usage: dial <someone>

#include <ansi.h>

inherit ITEM;

int do_dial(string);
void init();

void create()
{
	set_name(HIG "空间传送器" NOR, ({ "space phone", "phone", "space"}) );
	set_weight(50);
	set_max_encumbrance(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "台");
                set("long", @LONG
这是个随身听那么大个的东西。不知是什么作的却发着金属的光泽。
拨你想去人家的号码，它就会把你送倒那儿。 dial <someone>
LONG
                );

set("is_monitored",1);
		set("value", 1000);
		set("material", "steel");
		set("no_get",0);
	}
	setup();
}

void init()
{
        if(wizardp(this_player())) {
	  add_action("do_dial", "dial");
	}
}


int do_dial(string arg)
{

	object me;

	me=this_player();

	if (!arg)
	{
		return notify_fail("你要去哪里？\n");	
	}
	if ( file_size("/u/"+arg+"/workroom.c")<0)
	{
	   message_vision("空间传送器对$N说道：没有这家。\n",me);
         return notify_fail(""); 
	}

      message_vision("空间传送器对$N说道：接通啦！\n", me);
	
      me->move("/u/"+arg+"/workroom.c");
      
      message_vision("空间传送器对$N说道：你到了。\n", me);
	return 1;
}
