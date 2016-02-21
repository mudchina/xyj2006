//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <hedi.h>

void create ()
{
  set ("short", "河底");
  set ("long", @LONG

四周混沌沌的一片，河水寒冷彻骨，你感觉全身渐渐麻木，手
脚渐渐不听使唤，心仿佛没有了跳动的声音。四周静寂得可怕，
你分明感觉了四周暗藏着无尽的凶险。

LONG);
  set("exits", ([
        "south":   __DIR__"hedi1",
        "west":   __DIR__"hedi5",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
