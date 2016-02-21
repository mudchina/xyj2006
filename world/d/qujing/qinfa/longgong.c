// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "龙宫");
  set ("long", @LONG

一条长长的回廊环绕，中间是盘龙的宫室，由八面玲珑的金色
屏风围起，铺有橙红色云彩绒毯，上面有一细鳞缎绣龙头龙尾
望月龙床。

LONG);

  set("exits", ([
        "west"    : __DIR__"jinluan",
        "east"    : __DIR__"fenggong",
        "northeast"    : __DIR__"qingong1",
        "southeast"    : __DIR__"qingong2",
      ]));
  set("objects", ([
        __DIR__"npc/king"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

