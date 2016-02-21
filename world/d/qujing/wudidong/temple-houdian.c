// Room: /d/qujing/wudidong/south
inherit ROOM;

void create()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿就更加破败了。一面墙壁前还供着一尊菩萨像(statue)，但泥塑
上的漆早已剥落，显然经过了无数风风雨雨。村里人都说这里闹鬼，
也不知是真是假。仔细看看，四处有不少老鼠出没的痕迹。但除此也
没什么别的可疑之处。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "statue" : "这庙似乎供的是观音菩萨。\n",
]));
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"temple-qiandian",
]));
  setup();
}
void init()
{
  add_action("do_push", "push");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "statue" && arg != "菩萨像") || !arg)
    return notify_fail("你要推什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query_temp("no_move")) return notify_fail("你被定住了，什么也干不了。\n");
  if (me->query_skill("yaofa", 1) > 15
   && me->query("family/family_name") == "陷空山无底洞")
  {
      message_vision("$N掐指念句咒语，借土遁走了！\n", me);
      me->move(__DIR__"shanlu1");
      return 1;
  }
  if (me->query_str()<40||myeffstr<20)
    {
      message_vision("$N抱着泥像左右推动，但费尽九牛二虎之力，也动不得分毫。\n", me);
      return 1;
    }
  if(random(diff)>4)
    {
      message_vision("只听“哗啦”一声，房顶落下一堆砖瓦，正砸在$N头顶！\n", me);
      message_vision("$N伤得颇重，而且神志也有点不清了。\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      me->receive_damage("sen", mymaxsen*percentage/100);
      return 1;
    }
  message_vision("$N用力推动泥像，只听一阵“轧轧”声过后，泥像前露出一个大洞。\n", me);
  message_vision("$N纵身一跃，跳了进去，大洞随即又合上了。\n", me);
  me->move(__DIR__"shanlu1");
  return 1;
}
