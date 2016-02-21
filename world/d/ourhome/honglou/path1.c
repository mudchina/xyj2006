// Room: /u/hkgroup/path1

#include <room.h>
inherit ROOM;

void init();
void do_close2();
int do_push(string);
int valid_leave();
string look_door2();

void create ()
{
  set ("short", "曲径通幽");
  set ("long", @LONG

　　迎门一带翠嶂挡在面前。其中微露羊肠小径。
山上有镜面白石一块(stone)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "door" : (: look_door2 :),
  "stone" : "
　　　　『曲径通幽』

",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pavilion",
  "out" : __DIR__"bula",
  "east" : __DIR__"cglaem",
  "west" : __DIR__"dream",
]));
  set("outdoors", "/u/hkgroup");

  setup();
}

void init()
{
        add_action("do_push", "push");
        add_action("do_close", "close");
}

void close_door2()
{
        object room;

        if(( room = find_object(__DIR__"workroom")) ) {
                delete("exits/out");
                        message("vision", "咯吱一声, 角门慢慢地合上了。\n",
                        this_object());
                room->delete("exits/enter");
                message("vision", "咯吱一声, 角门从里面慢慢地合上了。\n", room);
        }
        else message("vision","ERROR: door not found(close).\n", room);

}

int do_close(string arg)
{
        object room;

        if (!query("exits/out"))
                return notify_fail("角门已经是关着的了。\n");

        if (!arg || (arg != "door" && arg != "out"))
                return notify_fail("你要关什么？\n");

        remove_call_out("close_door2");
        call_out("close_door2", 2);

        return 1;
}

int do_push(string arg)
{
        object room;

        if (query("exits/enter"))
                return notify_fail("角门已经是开着了。\n");

        if (!arg || arg!="door")
                return notify_fail("你要推什么？\n");

        if( room = find_object(__DIR__"workroom") ) {
                set("exits/out", __DIR__"workroom");
                message_vision("$N轻轻地推了推门，只听吱地一声，角门慢慢地开了一条缝。\n",
                        this_player());
                room->set("exits/enter", __FILE__);
                message("vision", "\n里面有人推门，只听吱地一声，角门慢慢地开了一条缝。\n", 
                        room);
                remove_call_out("close_door2");
                call_out("close_door2", 10);

        }
        else message("vision", "ERROR: door not found(push).\n",this_player());

        return 1;
}

int valid_leave(object me, string dir)
{
        if (dir != "exits/out") {
                return ::valid_leave(me,dir);
        }

        if (!::valid_leave(me,dir)) return 0;
}

string look_door2()
{
        return("一道供人出入的角门。\n你试着推了推门。\n");
}
