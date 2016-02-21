// Room: some place in 西牛贺洲
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "松树林");
  set ("long", @LONG

松林之中非常的暗，光线全被如伞如盖的树枝挡住．周围看
不到一个人影，你只能手摸着树干一步步走．除了脚下的枯
枝发出被踩断时的惨叫，只有一些无聊的小虫无聊的叫着．
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"forrest",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 2]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


