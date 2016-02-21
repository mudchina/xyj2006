// create by snowcat.c 4/20/1997
// room: /d/eastway/dyt.c

inherit ROOM;

void create ()
{
  set ("short", "大雁塔");
  set ("long", @LONG

大雁塔为一座七层方形塔，塔身十分雄伟，底座宽大，造
型简洁庄严神秘。方塔底座有门，门楣上有石刻画。

LONG);

  set("exits", ([
        "enter"    : __DIR__"dyt1",
        "west"     : __DIR__"ciensi",
      ]));
  set("outdoors", __DIR__);

  setup();
}






