inherit ROOM;

void create ()
{
  set ("short", "青草坡");
  set ("long", @LONG

这里的青草越来越密，眼前已无道路可循。草中偶有野兔类的
小兽跑过，发出悉悉嗦嗦的声音。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"jiandi2", 
  "west" : __DIR__"qingcao1",
]));

  set("outdoors", 1);

  setup();
}

