// Room: /d/ourhome/xiaoting.c
//cglaem...12/15/96.


#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);
int do_out(object ob);

void create()
{
        set("short", "聚见亭");

	set("long", @LONG

--聚 见 亭-- 

秋风清，秋风明
落叶聚还散
寒鸦栖复惊 
相思相见知何日
此时此夜难为情

由此往北可看到一条荒郊小路。而往其它方向则是
朦朦胧胧的什么也看不清。你隐隐约约地觉得只要
跨出栏杆往外一走(out)也许就永远回不来了。
LONG
	);


	set("exits", ([
	"north" : __DIR__"kedian4",
	]));

  set("objects", ([ 
               __DIR__"obj/table" : 1,
               __DIR__"obj/seat" : 2,
        ]));
                                              
	set("no_clean_up", 0);
      
	setup();     
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_sit", "sit");
 	add_action("do_out","out");
}

int do_sit(string arg)
{     
      object me;

      me=this_player();

	if ( !arg || ((arg != "seat")&&(arg != "table") ))
		return notify_fail("你要坐在什么上面？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经坐下了。\n");	
      
      if ( arg != "seat")	
	      return notify_fail("坐桌子上？太不雅观了吧。\n");
        	
	this_player()->set_temp("marks/sit", 1);
	message_vision("$N舒舒服服地在石凳上坐下来，翘起了二郎腿。\n",me);
      return 1;	
}

int do_stand(string arg)
{
      object me;

      me=this_player();

      if (!this_player()->query_temp("marks/sit"))
          return notify_fail("你本来就站着。\n");

      this_player()->set_temp("marks/sit", 0);
      message_vision("$N伸了个懒腰，站了起来。\n", me);
      return 1;
}

int do_out(object ob)
{
        ob = this_player();
        write(HIB "你跨出栏杆往外一迈，一阵浓雾向你卷来．．．\n" NOR);

        message("vision", sprintf(HIB+"%s跨出栏杆往外一迈，一阵浓雾卷来．．．\n一眨眼的功夫%s就不见了。\n"+NOR, ob->name(), ob->name()), environment(ob),({ ob }));
        write(RED "你眼前一阵黑．．．\n\n\n" NOR);
        ob->move("/d/dntg/hgs/entrance");
        write(HIY "\n紧接着霞光一闪，你发现自己出现在一个陌生的地方。\n\n" NOR);
        message("vision", HIY 
        "只听惊天动地的一声巨响，紧接着霞光万道，仙石崩裂---\n"+
        "居然从里面蹦出一个人来！\n" NOR, environment(ob),  ({ ob }) );
        return 1;
}


int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回给邮差。\n");
		destruct(mbox);
	}
	return 1;
}

