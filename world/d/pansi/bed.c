//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "千年寒冰床");
        set("long", @LONG

一块千年寒冰做成的小床．据说在这里对内功大有裨益.
LONG
        );
        
        set("exits", ([
                "out": __DIR__"shishi3",
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
  if (this_player()->query("family/family_name")=="盘丝洞") return 0;
  write("你冻的全身发抖,翻来复去怎麽也睡不着。\n");
  this_player()->start_busy(random(3));
  return 1;
}

