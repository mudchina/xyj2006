
inherit ROOM;
int xianguan_block();

void create ()
{
  set ("short", "瑶池东廊");
  set ("long", @LONG

瑶池东廊一列玉桌整齐排开，摆满各类仙酒。廊里酒香扑鼻；
有几个造酒的仙官，盘糟的力士，领几个运水的道人，烧火的
童子，在此酿造玉液琼浆，香醪佳酿。角落里有扇铁门(door)
通向贮酒的地窖。

LONG);

  set("exits", ([
        "west"  : "/d/pantao/yaob",
        "south"  : __DIR__"gate",
//      "down" :__DIR__"jiujiao",
      ]));

  set("xianguan",1);
   set("objects",([
    __DIR__"npc/xianguan" :1,
  ]));

  setup();
}

void init() {
  add_action("to_open","open");
}

int to_open(string arg) {
  object me=this_player();

  if (!arg || arg!="door") return notify_fail("打开什么？\n");
  if(query("exits/down")) return notify_fail("门已经是开着的了。\n");

  if (xianguan_block()) 
    return notify_fail("造酒仙官看了你一眼，你吓得马上把伸出去推门的手缩了回来。\n");

  if (me->query("force")<200) {
    message_vision("$N使出全身气力推门，可是犹如蚍蜉撼树，铁门丝毫未动。\n",me);
    return notify_fail("你的气力不够。\n");
  }
  message_vision("$N稍一提气，轻轻一推，铁门无声无息的打开了。\n",me);
  add("exits",(["down":__DIR__"jiujiao",]));
  me->start_busy(2);
  me->set_temp("yaochi_open",1);
  call_out("door_close",10);
  return 1;
}
void door_close() {

  remove_call_out("door_close");
  tell_room(this_object(),"铁门无声无息的关上了。\n");
  set("exits", ([
        "west"  : "/d/pantao/yaob",
        "south"  : __DIR__"gate",
      ]));
}

int valid_leave(object me, string dir)
{
    if ( dir == "down" && xianguan_block()) 
      return notify_fail("造酒仙官拦在你的面前：“请自重！”\n");
    return ::valid_leave(me, dir);
}

int xianguan_block() {
  object xianguan=present("zaojiu xianguan",this_object());

  if (xianguan && living(xianguan)) return 1;
  return 0;
}

