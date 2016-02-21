// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "大厅");
  set ("long", @LONG

环顾四周，可见大厅颇具规模，里面放着木桌木椅之类，大厅
的北面悬挂着一口铜钟，由蔓藤牵动着。西边有通道引向莲花
洞的前厅。

LONG);

  set("exits", ([
        "west"   : __DIR__"qianting",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 2,
      ]));

  setup();
}



