// huayuan.c

inherit ROOM;

void create()
{
  set ("short", "后花园");
  set ("long", @LONG

后花园中花草甚多，什么凤仙、鸡冠、秋葵、百合、蔷薇、牡丹等
等，不可枚举，满目皆是．遇花开之时，后花园中红红紫紫，漫如
锦屏．真想多呆一会，好好看看．
LONG);
set("item_desc",(["flower":
"漂亮的花园被人踩的乱七八糟，痕迹一直通到矮墙边．．．\n"
]));

set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"houyuan",
]));
	set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("你要爬什么？\n");
        else
                message_vision("$N一扒墙头，翻了过去。\n", me);
                me->move("/d/gao/xiaolu");
                me->set_temp("apply/dodge",0);
                me->set_temp("ride/dodge",0);
		tell_room( environment(me), "「咕咚」一声，" + me->name() + "从墙头上跳了下来！\n",
({me}) );
                return 1;
}

