//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
        set("short", "树丛中");
        set("long", @LONG

这里满地桃花,发出阵阵迷香,真想躺在花瓣从中好好睡一觉.
LONG
        );
        
        set("exits", ([
                "east": __DIR__"tao_in",
            ]));
	set("objects",([
		__DIR__"obj/guo" : 3,
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
  write("花香一阵阵飘来,你翻来覆去怎麽也睡不着。\n");
  this_player()->start_busy(random(2));
  return 1;
}

