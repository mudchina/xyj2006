#include <ansi.h>
inherit ROOM;
int do_turn(string arg);
void reset();

void create ()
{
  set ("short", "供室");
  set ("long", @LONG

近后壁处铺着一张龙吞口漆雕供桌。桌上有一个大流金香炉，炉内香
烟缭绕。香炉后面供着两块牌位。右面书架上散乱地堆着一些东西，
书架边墙上有一个小木轮(wheel)，不知有何用处。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inner-tang",
  "east" : __DIR__"cave2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "wheel" : "
一个做得很精细的转盘，上有零到九几个数字。
",
		     "paiwei":"
\t\t尊\t\t\t尊
\t\t父\t\t\t兄
\t\t李\t\t\t哪
\t\t天\t\t\t吒
\t\t王\t\t\t三
\t\t生\t\t\t太
\t\t位\t\t\t子
\t\t\t\t\t生
\t\t\t\t\t位

",
]));

  setup();
}
void init()
{
  add_action("do_turn", "turn");
  add_action("do_turn", "zhuan");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要转什么？\n");
  if(arg=="wheel")
    return notify_fail("请输入相应的密码！\n譬如：turn 1 或 turn 1234。。。\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!="9657")
    {
      message_vision(RED "只见一道火光从轮中窜出，直向$N扑来！\n" NOR, me);
      if (mykee<=200)
	{
	  me->set_temp("death_msg", "被烧成了飞灰。\n");
	  me->die();
	  me->save();
	  return 1;
	}
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N显然伤得不轻！\n" NOR, me);	
      return 1;
    }			                                   
  else
    {
      message_vision("只听“叮”的一声，一道暗门突起，$N身不由己被推进暗室去了！\n", me);
      me->move(__DIR__"mishi");
      return 1;
    }
}
