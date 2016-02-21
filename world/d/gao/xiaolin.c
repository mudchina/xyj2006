// xiaolin.c

inherit ROOM;

void create()
{
  set ("short", "小树林");
  set ("long", @LONG

小林中树木密密麻麻，看不到一个人影，却偶尔能听到有人说
着什么。你向前走着，却感到好象有人暗中盯着你。你的心一
下悬了起来。。。
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"xiaolu",
"north" : __DIR__"xiaolin1",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


