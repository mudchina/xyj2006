//Cracked by Roath
//  ัýษ๑ึฎี๙ ฃฑกฃฃฐ
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/enter.c

inherit ROOM;

void create ()
{
  set ("short", "ีýต๎");
  set ("long", @LONG

ึปผ๛ีýต๎ษฯส้หฤธ๖ฝ๐ืึฃบ

                  กิกิกิกิกิกิกิกิกิกิ
                  กิกิ            กิกิ
                  กิกิ  [1;33mนÛา๔์๘ิบ[m  กิกิ
                  กิกิ            กิกิ
                  กิกิกิกิกิกิกิกิกิกิ


LONG);

  set("exits", ([
        "south"    : __DIR__"fzroom",
        "north"  : __DIR__"sleeproom",
        "out"    : __DIR__"shanmen",
      ]));
  set("objects", ([
        __DIR__"npc/monk1" :1,
        __DIR__"npc/monk_gz":1,
        ]));
  setup();

}
