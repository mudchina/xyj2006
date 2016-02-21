//  Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c
//  modified by vikee for xlqy
// 2000-11-25 14:22

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

再向前进就是妖洞了，但是石门紧闭，这一处的风景倒是宜人的
很，居住于此也可以称作妖仙了。
LONG);

  set("exits", ([
        "north"  : __DIR__"road4",
      ]));
  set("outdoors","hf");
  setup();
}

void init()
{
        add_action("do_break","break");
}
int do_break(string arg)
{
        object ob = this_player();

        if( ! arg || arg != "door" )
                return notify_fail("你要砸开什么？\n");

        if( ob->query("force") < 500 )
                return notify_fail("你的内力不够。\n");

        if( !ob->query_temp("fired") )
        {         
         write("你一用劲，结果栽了个大跟头。\n");
         ob->unconcious();
         return 1;
        }

        message_vision("\n只见$N双手发力，大喊一声：“开”\n",ob);
        message_vision("就见石门被$N击个粉碎。\n",ob);
        set("exits/enter",__DIR__"in1");
        ob->set("force",0);
        return 1;
}
