// rewritten by snowcat on 4/11/1997
// room: cuiyun3

inherit ROOM;

int room_busy = 0;
int no_bone = 0;

void create ()
{
  set ("short", "翠云山");
  set ("long", @LONG

山中林木葱葱，青草郁郁。一派鸟语花香的景象。山势巍峨高耸，
山腰白云袅绕，真似那世外桃源，海上蓬莱。林中隐隐传来丁丁丁
伐木之声。路边是一堆一堆乱七八糟的树枝，看上去好象曾被人翻
动过。

LONG);

  set("objects", ([
        __DIR__"npc/qiaofu" : 1,
      ]));
  set("outdoors", "firemount");
  set("exits", ([
        "westup"    : __DIR__"cuiyun2",
        "northdown" : __DIR__"cuiyun4",
      ]));

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

  if (!me->query_temp("know_palm_bone"))
  {
    message_vision ("$N蹲下去在枯树枝里胡乱翻了起来。\n",me);
    return 1;
  }

  if (me->query("combat_exp")<4000)
  {
    message_vision ("$N道行不够，也在枯树枝里装模作样地翻来翻去。\n",me);
    return 1;
  }  

  if (room_busy)
  {
    remove_call_out ("reset_room_busy");
    call_out ("reset_room_busy",random(5)+5);
    message_vision ("$N在枯树枝里瞎忙乎。\n",me);
    return 1;
  }

  if (no_bone)
  {
// remove_call_out("reset_no_bone");
// call_out("reset_no_bone",2700);
    message_vision ("$N整个把枯树枝翻遍了也找不出什么来了。\n",me);
    return 1;
  }

  if (random(10) == 0)
  {
    object bone = new (__DIR__"obj/bone");
    bone->move(me);
    message_vision ("$N眼睛一亮：芭蕉骨！\n",me);
    message_vision ("\n$N看看四下没人注意赶紧把芭蕉骨揣进怀里。\n",me);
    no_bone = 1;
    call_out ("reset_no_bone",3600);
    return 1;   
  }

  message_vision ("$N认真地在枯树枝里翻来翻去找芭蕉骨。\n",me);
  room_busy = 1;
  call_out ("reset_room_busy",random(5)+5);
  return 1;
}

void reset_room_busy()
{
  room_busy = 0;
}

void reset_no_bone()
{
  no_bone = 0;
}
