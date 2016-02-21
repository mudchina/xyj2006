// Room: /u/mimi/zhuziguo/wall.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create()
{
  set ("short", "人骨亭");
  set ("long", @LONG
    这里是白骨洞众妖闲时休息的地方。整个亭堂都是用
人骨搭建而成，亭顶是用九个骷髅和九百九十九环锁骨
连成，四根亭柱，都是用大腿骨顶起来的。被妖精吃掉
的冤魂不得超生,遂聚集此地，以致这里终年阴风惨惨，
鬼气森森。

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "northup" : __DIR__"dongkou",
    "westdown" : __DIR__"guangchang",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/baigujiangjun" : 1,
  ]));
  set("outdoors", __DIR__"");                   
  setup();
}

int valid_leave (object who, string dir)
{
  object ob = present ("baigu jiangjun", environment(who));
  if (dir == "northup" && ob && living (ob))
      return notify_fail (ob->query("name")+"喝道：呔,哪里来的生人，敢往我白骨洞闯！\n");
  
  if(! interactive (who) &&
      who->query("xiaoyao") == "xiaoyao" &&
       dir == "southdown")
    return 0;

  return ::valid_leave(who, dir);
}
