//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.14

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

峰岩重叠，涧壑湾环，虎狼成阵走，麋鹿作群行，无数獐魃转簇
簇，满山狐兔聚丛丛，道旁荆棘牵漫，岭上松楠秀丽。

LONG);

  set("exits", ([
        "southwest"     : __DIR__"shanpo1",
        "north"     : __DIR__"shanlu9",
      ]));
  set("outdoors",1);
  setup();
}
