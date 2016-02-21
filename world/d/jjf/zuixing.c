// created 6-8-97 pickle
// Room: /d/jjf/zuixing.c
 
inherit ROOM;
 
void create ()
{
  set ("short", "醉星楼");
  set ("long", @LONG

太子李建成和三子李元吉对高祖御旨起麒麟阁十分不满，认为这是对
秦王的偏爱。于是二人穷二府之资，在麒麟阁对面造了一座及其华丽
宏伟的彩楼，名「醉星楼」。为了吸引百姓前来观看，二人甚至不惜
发送食物钱财。
LONG);

  set("no_fight", 1);
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/qinbing-jian" : 1,
  __DIR__"npc/qinbing-qi" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/city/xuanwu-n0",
  "up" : __DIR__"zuixing2",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(me->query("env/invisibility")) return ::valid_leave(me, dir);
  if(dir == "up" && objectp(present("qin bing", environment(me))))
    {
       if (member_array("qin bing",me->parse_command_id_list())==-1
          && member_array("qin bing",me->parse_command_id_list())==-1 )
         return notify_fail("亲兵喝道：闲杂人等不得乱闯！\n");
    }
  return ::valid_leave(me, dir);
}

void init()
{
  add_action("do_kan", "kan3");
  add_action("do_kan", "砍");
  add_action("do_kan", "chop");
}
int do_kan(string arg)
{
  object me=this_player(), here=this_object(), ob, zhuzi;
  int kar=me->query_kar();
 
  if( (!arg || arg != "柱子") && (arg != "zhuzi" && arg!="pillar"))
    return notify_fail("你要从哪里下手？\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe" )
    return notify_fail("没顺手的家伙怎么拆得动？\n");
 if(objectp(present("qin bing", environment(me))))
    return notify_fail("看样子要想拆楼，先得把亲兵料理了！\n");
  if(!me->query_temp("mark/jjf醉星楼二楼broken"))
    return notify_fail("还没砸二楼呢，就来打一楼的主意？\n");
  here->add("pending/breakdown", 1);
  if (here->query("broken"))
    return notify_fail("柱子都塌了，还砍什么砍？要命的快出去吧！\n");
  message_vision("$N用足了劲，一斧抡向彩楼的柱子！只见几片木片四散飞开。\n", me);
  if (here->query("pending/breakdown") >= (int)(40 - kar)/5 )
    {
      message_vision("只听一声巨响，支撑房子的柱子从中折断，整座醉星楼塌了下来！\n", me);
      message_vision("$N虽然搞得灰头土脸，但居然没有受伤！大命不死，还是赶紧出去吧！\n", me);
      here->set("long", @LONG

这里曾经是一座豪华气派的彩楼，但不知为何被人拆掉了，只剩一片
废墟。几块烂木头下面到处都是酒杯碗筷的碎片。半截被砍断的柱子
倒在门边。
LONG);
      me->delete_temp("mark/jjf醉星楼二楼broken");
      here->set("broken", 1);
      here->set("outdoors", 1);
      zhuzi=new(__DIR__"obj/zhuzi");
      zhuzi->move(here);
      here->set("exits", ([ /* sizeof() == 1 */
         "west" : "/d/city/xuanwu-n0",
]));

    }
  me->receive_damage("kee", (int)me->query("max_kee")/4);
  return 1;
}
