//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu5.c

inherit ROOM;

void create ()
{
  set ("short", "山脚");
  set ("long", @LONG

来到山脚下，很显眼是一座山庄，庄园不大，尽收眼底，一条
小河流自山上流进村庄里，星星点点地可以看到有一些人在那
忙活着什么。
LONG);

  set("exits", ([
        "eastup" : __DIR__"shanlu4",
        "westdown"   : __DIR__"enter",
      ]));
  set("outdoors","sc");

}
