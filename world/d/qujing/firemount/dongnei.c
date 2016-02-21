// rewritten by snowcat on 4/11/1997
// Room: dongnei

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞里一片漆黑，你什么也看不清，似乎觉得有许多眼睛在黑暗中盯
着你。你环顾四周，模模糊糊分辨出一个一个的影子。

LONG);

  set("exits", ([
        "out" : __DIR__"shimen",
      ]));
  set("objects", ([
    __DIR__"npc/xiaoyao" : 3,
  ]));

  setup();
}

void init()
{
  add_action("do_koujian", "koujian");
}

int do_koujian (string arg)
{
  object me = this_player();
  object princess = present("tieshan gongzhu",environment(me));

  if (arg != "princess")
  {
    message_vision("只见$N伏下身去……\n",me);
    tell_object(me,"你想叩见谁？\n");
    return 1;
  }  

  message_vision("只见$N伏下身去喊道："+
                 RANK_D->query_self(me)+
                 "叩见公主！\n",me);

  if (princess)
    message_vision("$N伸手一把将$n小鸡似的拎起来：不必不必。\n",princess,me);
  else
  {
    message_vision("洞穴里隐隐地泛出一些红色云雾。\n",me);
    call_out("princess_appear",10+random(10),me);
  }
  return 1;
}

void princess_appear(object me)
{
  object princess;

  if (environment(me) != this_object())
    return;

  if (present("tieshan gongzhu",environment(me)))
    return;

  princess = new (__DIR__"npc/princess");
  princess->move(environment(me));
  message_vision("一阵红色云雾聚在一起，慢慢凝做$N。\n",princess);
}
