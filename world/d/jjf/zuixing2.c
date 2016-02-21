// Room: /d/jjf/zuixing2
inherit ROOM;
 
void create ()
{
  set ("short", "醉星楼二楼");
  set ("long", @LONG

上得楼梯，迎面是一面玉石屏风，上绘嫦娥奔月的故事。转过屏风，
只见两人坐在一张桌上狂饮作乐，旁边舞女在奏乐起舞。一边，几个
青衣小童正在伺候着。有的在上菜，有的在打扇。
LONG);
  set("objects", ([ /* sizeof() == 4 */
    __DIR__"npc/liyuanji.c": 1,
    __DIR__"npc/lijiancheng.c": 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"zuixing",
]));
  set("light_up", 1);
 
  setup();
}
void init()
{
  add_action("do_kan", "砍");
  add_action("do_kan", "chop");
  add_action("do_kan", "kan3"); 
} 
int do_kan(string arg)
{
  object me=this_player(), here=this_object(), ob;
  int kar=me->query_kar();
 
  if( (!arg || arg != "柱子") && (arg != "zhuzi" && arg!="pillar"))
    return notify_fail("你要从哪里下手？\n");
  if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "axe" )
    return notify_fail("没有顺手的家伙怎么拆得动？\n");
 
 if(objectp(present("li jiancheng", environment(me))) || objectp(present("li yua
nji", environment(me))))
    return notify_fail("当朝达贵在此，不怕砸伤了担责任吗？\n");
  
  here->add("pending/breakdown", 1);
  if (here->query("already_breakdown"))
    return notify_fail("柱子都塌了，还砍什么砍？要命的快下楼去吧！\n");
  message_vision("$N用足了劲，一斧抡向彩楼的柱子！只见几片木片四散飞开。\n", me);
  if (here->query("pending/breakdown") > (int)(40 - kar)/5 )
    {
      message_vision("只听一声巨响，柱子从中折断，" + here->query("short") + "塌了下来！\n", me);
      message_vision("$N虽然搞得灰头土脸，但居然没有受伤！大命不死，还是赶紧下楼去吧！\n", me);
      here->set("long", @LONG

这里曾经是一间华丽无比的房间，但现在只剩一片废墟。几块烂木头
下面到处都是酒杯碗筷的碎片。原来在这里服侍的舞女、小童也早就
不知去向了。
LONG);
      here->set("already_breakdown", 1);
      here->set("outdoors", 1);
      me->add_temp("mark/jjf醉星楼二楼broken", 1);
      me->add("mark/jjf拜魏徵无望", 1);
    }
  me->receive_damage("kee", (int)me->query("max_kee")/4);
  return 1;
}
