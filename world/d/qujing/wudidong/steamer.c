// steamer.c by mes
// updated 9-18-97 pickle

#include <ansi.h>

inherit ROOM;

int do_tao();
int do_get();
void reset();

void create()
{
  set ("short", "蒸笼");
  set ("long", @LONG

好大的一个蒸笼，不知为何你会落在这儿，快点逃(tao)吧！
LONG);
  set("no_fight", 1);
  set("no_magic", 1);
  set("outdoors", 0);
  set("valid_startroom", 1);
  setup();

}
void init()
{
  add_action("do_tao", "tao");
  add_action("do_get", "get");
  add_action("do_get", "ji");
}

int do_get() {return 1;}

int do_tao()
{	
  object me, user, bao;
  string fainter, msg;
  int kee,  mkee;
  
  me=this_player();
  kee=(int)me->query("kee");
  mkee=(int)me->query("max_kee");
  if (random(100)<80) // 20% chance escape
  {		
      if (kee<=mkee/5) {
	me->set_temp("death_msg","被蒸熟了。\n");
	bao = new(__DIR__"obj/renroubao.c");
	bao->set("long", "一个香喷喷、热腾腾的人肉包子，据说肉馅是"
		 + me->query("name") + "的肉做的，上面还沾着一些血丝。\n"
		 + "其肉馅味道之鲜美，不由得让人垂涎欲滴。\n");
	fainter = me->query("wudidong/last_sold_by");
	if (!fainter) {
	    if(bao->move("/d/city/kezhan.c"))
		tell_object("/d/city/kezhan.c",
			"砰地一声，天上掉下一个大肉包子！\n");
	} else {
	  user = find_player(fainter);
	  if (user)
	  {
	    if(!bao->move(user))
		bao->move(environment(user));
	    tell_object(user, "你的人肉包子蒸熟了。\n");
	  } else 
	    if(bao->move("/d/city/kezhan.c"))
		tell_object("/d/city/kezhan.c",
			"砰地一声，天上掉下一个大肉包子！\n");
	}
	//by mon 8/25/97
	me->die();
	return 1;
      }
      else
      {
	  message_vision(RED "一阵烈火，把$N烧退了回来。\n" NOR, me);
	  me->receive_damage("kee", mkee/5);
	  me->receive_wound("kee", mkee/5-10);
	  switch (random(4)) {
	    case 0: 
		  me->add_maximum_force(-5);
	      msg="你觉得自己的内力似乎也随之在消逝．．．\n";
	      break;
	    case 1: 
	          me->add_maximum_mana(-5);
	      msg="你觉得自己的法力似乎也随之在消逝．．．\n";
	      break; 
            default :
	      me->add("combat_exp", 
		      -((int)me->query("combat_exp")/1000));
	      msg="你觉得自己的道行似乎也随之在消逝．．．\n";
	      break;
	  }

	  write(msg);
	  me->save();
	  return 1;
	}	
    }
  else
    {
      message_vision(HIG "$N一咬牙，“呼”地一声跳了出去。\n" NOR, me);
      me->move(__DIR__"kitchen");
      message_vision(CYN "$N突然从炉上的蒸笼里跳了出来，模样十分狼狈。\n" NOR, me);
      me->save();
      return 1;
    }
}
