//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

走到这你发现路已经变得很难走了，不再象刚出长安那样的阳关
大道，不但路径难辨，十分容易走错方向，而且难行之极，你一
边拨开身边的杂草一边向前走着。
LONG);

  set("exits", ([
        "eastdown" : "/d/westway/jiayu",
        "westup"   :    __DIR__"shanlu2",
      ]));
  set("outdoors","sc");

}
