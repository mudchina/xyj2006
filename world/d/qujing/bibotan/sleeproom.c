inherit ROOM;

void create()
{
        set("short", "睡房");
        set("long", @LONG

这里是碧波潭弟子的睡房，角落里躺着几个小妖，
正在呼呼大睡。
LONG
        );
        set("light_up", 1);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"longtai2",
]));
        set("no_magic", 1);

        setup();
        replace_program(ROOM);
}
