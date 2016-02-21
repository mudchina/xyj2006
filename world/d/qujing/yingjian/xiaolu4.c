//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu4.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

有人做诗赞叹山川之美：

        茆舍数椽山下盖，松竹梅兰真可爱。穿林越岭觅干柴，
        没人怪，从我卖，或少或多凭世界，将钱沽酒随心快，
        瓦钵磁瓯殊自在，醌旄醉了卧松阴，无挂碍，无利害，
        不管人家兴与败。
LONG);

  set("exits", ([
        "west" : __DIR__"lakeside1",
        "east" : __DIR__"xiaolu2",
      ]));
  set("outdoors","yj");
  setup();

}
