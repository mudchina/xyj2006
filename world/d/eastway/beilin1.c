// create by snowcat.c 4/20/1997
// room: /d/eastway/beilin1.c

inherit ROOM;

void create ()
{
  set ("short", "碑林");
  set ("long", @LONG

你走进碑林之中，这里荟萃了举世闻名的碑帖，有王羲之，颜真卿，
柳公泉，欧阳询，诸遂良所书的碑刻。也有石经，石台孝经，大秦景
教流行中国碑等等。
LONG);

  set("exits", ([
        "north" : __DIR__"beilin2",
        "south" : __DIR__"jinshi",
      ]));
  set("objects", ([ /* sizeof() == 1 */
       __DIR__"obj/shibei" : 4,
      ]));
  set("outdoors", __DIR__);

  setup();
}






