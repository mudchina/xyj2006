// 肉包子 renroubao.c
// 9-16-97 pickle

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("肉包子", ({ "rou baozi","baozi","bao", "dumpling" }) );
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
"一个香喷喷、热腾腾的大包子。\n");
    set("unit", "个");
    set("value", 0);
    set("name_recognized", "人肉包子");
  }
}

void init()
{
    add_action("do_eat", "eat");
}
int do_eat(string arg)
{
    object me=this_player();
    object baozi=this_object();
    string owner=query("owner");
    int mycap=me->max_food_capacity();
    int myfood=me->query("food");
    string msg, str;

    if(!id(arg)) return 0;
    if(myfood>mycap*9/10) {write("你没胃口，吃不下这么大的一个包子。\n");return 1;}
    message_vision("$N拿起$n，有滋有味地吃了下去。\n", me, baozi);
    me->set("food", mycap);
    if(!owner || owner != me->query("id")
    || !query("reward") || (query("type") != "有奖励"))
	return 1;
    msg=GRN"你突然感到身体有些变化，似乎将包子馅活着时的道行吸收了一些！\n"NOR;
    tell_object(me, msg);
    me->add("daoxing", query("reward"));
    me->add("wudidong/sell_reward", query("reward"));

    me->add("kill/nkgain", query("reward"));
    str=COMBAT_D->chinese_daoxing((int)query("reward"));
    log_file("npc_kill","["+ctime(time())+"] "+me->query("id")
       +" got "+str +" 道行 by selling.\n");
    CHANNEL_D->do_channel(this_object(), "sys",me->query("id")
       +" got "+str +" 道行 by selling.");

    destruct(baozi);

    return 1;
}
