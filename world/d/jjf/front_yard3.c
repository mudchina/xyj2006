// Room: /d/jjf/front_yard2.c

inherit ROOM;

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG
空阔的场地上铺满了细细的黄土，正好适合演武。四面有几个
秦府家将正在练武。场地四边竖着几根木桩(logs)，还挖了若干个
大沙坑(pits)。西面是一间厢房，秦府的嘉宾可以去休息。场地东
边有个兵器架。
LONG);

  set("item_desc", ([ /* sizeof() == 3 */
  "pits" :
"沙坑里有些家将在练习轻功，你也可以跳(tiao)下去试试。\n",
  "logs" :
"几根木桩上有不少兵器打过的痕迹(strike)。\n",
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"keting.c",
  "west" : __DIR__"guest_bedroom",
  "north" : __DIR__"front_yard",
  "east" : __DIR__"jjf_bingqi",
]));
  set("objects", ([
		   __DIR__"npc/guard": 1,
		   ]));

  set("out_doors", 1);

  setup();
}

int valid_leave(object me, string dir)
{
  if (dir == "west" )
    {
      if (!((string)me->query("family/family_name")=="将军府"))
	{
	  return notify_fail("那里只有将军府的弟子才能进去．\n");
        }
      return ::valid_leave(me, dir); 
    }
  return 1;
}

void init()
{
  add_action("do_strike", "strike");
  add_action("do_tiao", "tiao");
}
int do_strike(string arg)
{
  object me=this_player(), weapn;
  string skll;
 
  if( (!arg) || !((arg == "logs") || (arg == "木桩")))
    return notify_fail("你要打什么？\n");
  if( (me->query("kee") < me->query("eff_kee")/5) || (me->query("eff_kee") < me->query("max_kee")/5))
    return notify_fail("你累得胳膊都抬不起来了，还是先休息一会儿吧！\n");
  if(! (me->query_temp("weapon")) && ! (me->query_temp("secondary_weapon")) )
    {
      message_vision("$N挥拳向木桩打去，结果把拳头打得鲜血淋漓。\n", me);
      me->receive_wound("kee", me->query("eff_kee")/10);
      return 1;   
 }
  if(!weapn=me->query_temp("weapon"))
    {
      weapn = me->query_temp("secondary_weapon");
    }
  skll = (string)weapn->query("skill_type");

  if (!((string)me->query("family/family_name")=="将军府"))
    {
      message_vision("$N挥舞手中兵器在木桩周围乱练了一会儿。\n", me);
    }
  else
    {
      message_vision("$N以木桩做把子练了一路兵器。\n", me);
      if ((int)me->query_skill(skll, 1)<30)
	{
	  me->improve_skill(skll, me->query("con"));
	  tell_object(me, "你领悟出一些基本兵器的窍门。\n");
	}
      else
	{
	  tell_object(me, "你忙乎了半天，手都磨出茧了，还是什么都没学到。\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

int do_tiao(string arg)
{
  object me=this_player();
 
  if( (!arg) || !((arg == "pits") || (arg == "沙坑")))
    return notify_fail("你要往哪里跳？\n");
  if( me->query("kee") < (int)(me->query("max_kee")/5))
    return notify_fail("再跳下去脚板都要磨破了！\n");
  if (!((string)me->query("family/family_name")=="将军府"))
    {
      message_vision("$N纵身跳下沙坑，结果跳不回来了，只好慢慢爬回来。\n", me);
    }
  else
    {
      message_vision("$N纵身跳下沙坑，又奋力跳了回来。\n", me);
      if ((int)me->query_skill("dodge", 1)<30)
	{
	  me->improve_skill("dodge", 40-me->query("str"));
	  tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
	}
      else
	{
	  tell_object(me, "你跳上跃下，闹了个灰头土脸，可是什么也没有学到。\n");
	}
    }
  me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}


