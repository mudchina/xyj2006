//Cracked by Roath

inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG

    这是江州唯一的一家杂货铺，店铺里乱七八糟的堆沏一些物品，
而店老板也是一副懒洋洋的样子。他有气无力的向街上的熟人打着
招呼。
LONG );
        set("exits", ([
                "north" : __DIR__"pingan-1",
        ]));
        set("objects", ([
    __DIR__"npc/yang":1,
        ]));
      setup();
        replace_program(ROOM);
}
