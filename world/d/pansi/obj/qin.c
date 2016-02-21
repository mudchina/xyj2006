// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;
void init();
int do_play(string arg);
void create()
{
  set_name(HIB "七弦琴" NOR, ({ "wuxian qin"})); 
  set_weight(10000);
  set("long","一架古色古香的七弦琴,但是已经断了两根弦。\n");
  set("unit", "架");
  setup();
}

void init()
{
  add_action("do_play", "play");
}

int do_play(string arg)
{
  object me, where;
  int sen_cost, gain;
  
//  object qin = this_object();
  string *msgs = ({
    "$N伸出纤指在琴上轻拨了一下，不禁想起梦中人。\n",
    "$N轻拨了一下琴弦，脸色绯红。\n",
    "$N若有所思地在弦上一拨，沉默几许……\n",
    "$N伏身抚琴，禁不住泪如雨下。\n",
    "$N轻轻地弹着琴，面色婉尔。\n",
    "$N小心地弹着琴弦，低低地唱了起来。\n",
    "$N边唱边弹，一曲凄歌断人心肠。\n",
  });
  me = this_player();
  where=environment(me);
	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("琴要放在膝上弹。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致弹琴...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还弹琴...\n");
	if( where->query("no_fight") )
			return notify_fail("此处不宜大声喧哗。\n");
	if( (int)me->query_skill("qin",1)<50 )
		return notify_fail("你伸手撩拨了几下琴弦，要使这断弦的琴响起来，显然琴艺还没入门。\n");
	if( (int)me->query_skill("qin",1)>100 )
		return notify_fail("你的琴艺已经炉火纯青，此琴已与你合而为一。\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("qin", 1)/5+(int)me->query("int")+1;
	me->improve_skill("qin", gain);
	message_vision (msgs[random(sizeof(msgs))],me);


  
  return 1;
}

