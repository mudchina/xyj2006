//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "牙玉软榻上");
        set("long", @LONG

一张牙玉色的软榻，榻四周雕着竹叶格，看上去极为精致，纱
衾鸳枕之间散发出一丝丝幽香．
LONG
        );
        
        set("exits", ([
                "out": __DIR__"bedroom",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}
void init() {
  add_action("do_sleep","sleep");
  ::init();
}
int do_sleep() {
  if (this_player()->query("family/family_name")=="月宫") return 0;
  write("你想到这里是嫦娥的卧室，兴奋得两眼发光，翻来复去怎麽也睡不着。\n");
  this_player()->start_busy(random(3));
  return 1;
}

