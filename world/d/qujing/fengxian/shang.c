// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "上官府");
  set ("long", @LONG

上官府位于郡南，府前有双狮护门。府内灯火通明，左右各放
了两个临时搭起的祭台，上有新铸银花香炉，香烟缭绕终日不
断，以示官府求雨的决心。
    
LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao11",
        "southwest"    : __DIR__"shien",
        "southeast"    : __DIR__"shuode",
      ]));
  setup();
}

