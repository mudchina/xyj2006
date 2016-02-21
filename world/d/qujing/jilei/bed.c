//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "兽骨床上");
        set("long", @LONG

一张用兽骨堆积起来的床，床上面铺着一张兽皮，勉强可以睡
觉．

LONG
        );
        
        set("exits", ([
                "out": __DIR__"woshi",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}
