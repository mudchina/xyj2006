// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/tulu1.c

inherit ROOM;

void create ()
{
  set ("short", "乡间土路");
  set ("long", @LONG

一条土路通往西边的小村，村子建于群山之间，一条溪流绕村
而过。远远的听到村中鸡鸣犬吠，还有人们劳动时唱的山歌，
路上有三三两两的行人走过，都是些补实的村中之人。

LONG);

  set("exits", ([
        "eastdown"      : __DIR__"shanlu3",
        "west"      : __DIR__"tulu2",
       "south"   : __DIR__"inn",
       ]));
  set("objects", ([
                __DIR__"npc/people": 1 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      who->query("people") == "people" &&
      dir == "eastdown")
    return 0;
  return ::valid_leave (who, dir);
}
