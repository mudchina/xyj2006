// Room: create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "坑底");
  set ("long", @LONG

    坑底腐尸散发出一股腥臭味，周围坑壁溅满血污，耳
边时有“呼呼”的呼气声。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "up": __DIR__"wangukeng",
  ]));
  set("objects",([
        __DIR__"npc/jiangshi":4,
                ]));
  set("outdoors", __DIR__"");                   
  setup();
}
