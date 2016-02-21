//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/shanlu2.c

inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG

走到这你发现这个地方原来是个小山丘，难怪走起来有点吃力，
前面的景象也不是很清楚，但是能隐隐约约看到一户人家的样
子，不时还能听到两声野兽咆哮的声音。
LONG);

  set("exits", ([
        "eastdown" : __DIR__"shanlu1",
        "westup"   : __DIR__"shanlu3",
      ]));
  set("outdoors","sc");
  setup();
}
