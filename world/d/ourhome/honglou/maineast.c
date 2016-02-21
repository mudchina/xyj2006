// Room: /u/hkgroup/maineast
inherit ROOM;

int do_serve();

void create ()
{
  set ("short", "缀锦阁");
  set ("long", @LONG

　　大观楼东面飞楼。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"main",
]));

  setup();
}

void init()
{
	add_action("do_serve", "bian!");
}

int do_serve()
{
        object who, obn;
        object room;

	who = this_player();

        room = environment(who);

        obn = new("/obj/example/wineskin");
        obn->move(room);

        obn = new("/obj/example/chicken_leg");
        obn->move(room);
        message_vision("食物和水出现在$N眼前。\n", who);

        return 1;
}

