//Cracked by Roath
//  妖神之争 １。０
//  happ@YSZZ 2000.4.2
// /d/jz/dadian.c

inherit ROOM;

void create ()
{
  set ("short", "大殿");
  set("long", @LONG

这是金山寺的大殿，虽然年久失修，但是整个寺院都显得很整洁，
弥勒和尚高高在上，笑看着每一个人。殿前放着一个功德箱，用
来接受善人的捐赠。
LONG);
        set("exits",([
                "eastdown": __DIR__"shanmen",
                "south": __DIR__"fzroom",
                ]));
        set("objects",([
                __DIR__"obj/xiang" : 1,
                ]));
 setup();

}
