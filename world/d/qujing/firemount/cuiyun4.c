// rewritten by snowcat on 4/11/1997
// Room: cuiyun4

inherit ROOM;

void create ()
{
  set ("short", "翠云山");
  set ("long", @LONG

山中林木葱葱，青草郁郁。一派鸟语花香的景象。山势巍峨高耸，
山腰白云袅绕，真似那世外桃源，海上蓬莱。林中隐隐传来丁丁丁
伐木之声。路边是一堆一堆乱七八糟的树枝，看上去好象曾被人翻
动过。

LONG);

  set("exits", ([
        "southup"  : __DIR__"cuiyun3",
        "eastdown" : __DIR__"cuiyun5",
      ]));
  set("outdoors", "firemount");

  setup();
}


void init()
{
  add_action("do_search", "search");
}

int do_search (string arg)
{
  object me = this_player();

  if (!arg || arg != "bone")
  {
    message_vision ("$N蹲下去寻找什么。\n",me);
    return 1;
  }

  message_vision ("$N蹲下去在枯树枝里胡乱翻了起来。\n",me);
  return 1;
}
