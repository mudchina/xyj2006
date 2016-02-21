// Room: create by smile 12/10/1998
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIC "万骨坑" NOR);
  set ("long", @LONG

    万骨坑原来是一个小沙坑，自从白骨精把吃剩的人骨都
扔在这里，就慢慢的堆积成一个大包，白骨精灵机一动，
干脆指使手下把坑挖大挖深，吃剩的人肉、骨头都扔到这
里，遂取名万骨坑。
    坑中腐尸散发出一股腥臭味，血肉污垢到处都是，由此
又滋生出一类妖怪，是死去的鬼魂日缠夜绕凝聚而成的骷
髅怪，白骨精降服后收为贴身护卫，训练了成保卫白骨洞
的骷髅兵。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "east": __DIR__"dongnei",
  ]));
  set("objects",([
        __DIR__"npc/kuloubing":3,
        __DIR__"obj/furou":3,
                ]));
  set("outdoors", __DIR__"");                   
  setup();
}

void init()
{
       add_action("do_dive","dive");
       add_action("do_dive", "tiao");
}

int do_dive(string arg)
{
  object me;
    me=this_player();
   if(!arg||(arg!="keng"&&arg!="pits"))
    return notify_fail("你要往哪跳？\n");
    message_vision("$N一纵身，往坑底跳了下去。",me);
   if(arg=="keng")
     me->move(__DIR__"kengdi1");
   if(arg=="pits")
     me->move(__DIR__"kengdi2");
   return 1;
}
