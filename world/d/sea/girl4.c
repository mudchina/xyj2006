// hill.c

inherit ROOM;

void create()
{
  set ("short", "云房");
  set ("long", @LONG

整个房间象是包在一团云中。听说是当年龙王与太上老君打赌赢来
的。在这里练武(lianwu)感到轻飘飘的，对练习轻功却是有莫大的
好处。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"girl2",
]));
set("objects", ([
                __DIR__"npc/beisao": 1,
               "/d/obj/armor/tenjia": 1,
]) );

        set("no_clean_up", 0);
//      
        set("water", 1);
//  
        setup();
}

void init()
{
	add_action("do_dodge", "lianwu");
}

int do_dodge()
{
	object me=this_player();

	if( (string)me->query("family/family_name")!="东海龙宫" ){
		if( (string)me->query_temp("family/family_name")!="东海龙宫"){
		message_vision("$N在云上跳了几跳，脚下一个不稳，灌了一肚子水。\n", me);
  if (me->query("water")<me->max_water_capacity())         me->set("water", (int)me->max_water_capacity());
		return 1;
		}
	}

	if( (int)me->query_skill("dodge")  >= 50)
		return notify_fail("你的轻功已经很高了，再练也帮不了多少了。\n");

        if( (int)me->query_skill("dodge",1)  >= 150)
                return
notify_fail("你的轻功已经很高了，再练也帮不了多少了。\n");


	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在很累，歇歇吧！\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神不济，歇歇吧！\n");

	message_vision("$N在半云半雾中练了起来，看起来轻飘飘的。\n", me);
	tell_object(me, "你的「基本轻功」进步了。\n");
	me->improve_skill("dodge", (int)me->query_int()/5);
	me->receive_damage("kee", 20+random(5));
	
	return 1;
}
