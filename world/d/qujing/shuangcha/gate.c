//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/gate.c

inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG

这座大门是用草编成的，十分精致，门前一只小狗正在玩耍。
地上堆了一些树叶，看来主人也是个不拘小节的人。
LONG);

  set("exits", ([
        "east" : __DIR__"enter",
        "enter"   : __DIR__"yard",
      ]));
  set("outdoors","sc");
  set("objects" ,([
        __DIR__"npc/dog" :1,
        ]));
  setup();

}
int valid_leave(object me, string dir)
{
        if( present("dog") )
        tell_object(me,"大狼狗向你汪汪乱叫。\n");
        return ::valid_leave(me, dir);
}
