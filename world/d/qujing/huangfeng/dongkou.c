//Cracked by Roath
//  ัýษ๑ึฎี๙ ฃฑกฃฃฐ
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "ษฝยท");
  set ("long", @LONG

ษฝยทตฤลิฑ฿ำะาปฟ้สฏัยฃฌสฏัยลิหสณ๖าปฟ้วเสฏฃฌษฯส้ฃบ
[33m
                กรกรกรกรกรกรกรกรกร
                กร [1;37mปฦท็ม๋ปฦท็ถด [0;33mกร
                กรกรกรกรกรกรกรกรกร[m

LONG);
  set("exits", ([
        "westdown"  : "/d/qujing/liusha/dadao1",
        "eastdown"  : __DIR__"shanlu4",
        "northdown": __DIR__"in1",
        "south":   __DIR__"zhaozhe",
          ]));
  set("outdoors","hfd");
  setup();
}
