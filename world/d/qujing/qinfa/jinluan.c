// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "金銮殿");
  set ("long", @LONG

此殿为国王朝政和会见外宾的场所，大殿里铺设有一级级青玉
台阶，每一级台阶上左右各一对金银大鼎燃着香烟袅袅。西面
的大门通向殿外，东面有琉璃拱门通向宫内。

LONG);

  set("exits", ([
        "west"    : __DIR__"gongmen",
        "east"    : __DIR__"longgong",
      ]));
  set("objects", ([
        __DIR__"npc/taijian"    : 2,
      ]));
  setup();
}

