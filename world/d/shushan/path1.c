inherit ROOM;

void create()
{
        set("short", "蜀山山脚");
        set("long", @LONG
蜀道难，难于上青天，走惯平坦大道的你
今天才深深体会到行路的艰难，这里一条歪
歪斜斜，松松垮垮的木栈道，断断续续
的通往山顶
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"paifang",
  "southdown" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
