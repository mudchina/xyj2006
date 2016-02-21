// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "歌馆");
  set ("long", @LONG

这里是此地有名的歌馆，馆门口悬了一朱红大匾，门两边是朱
红麒麟柱。里面彩台高搭，乐声不断。不时有歌女上来唱什么
曲儿。

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
        __DIR__"npc/genu"  : 1,
      ]));

  setup();
}



