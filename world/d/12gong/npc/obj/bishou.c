// by 九天(take)
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
   set_name(HIR"匕首"NOR, ({"bi shou", "shou", "bi"}));
   set_weight(0);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("long", "这是一把充满邪恶的匕首,上面好像还带着未干的血迹。\n");
     set("value", 0);
     set("material", "steel");
     set("wield_msg", "$N从颈上取下一把$n握在手中。\n");
     set("unwield_msg", "$N将手中的$n带回颈上。\n");
set("no_drop","你既然要了它,何必扔掉?\n");
    set("no_give","刺杀雅典娜的凶器,哪能随便给人？\n");
}
   init_sword(50);
   setup();
}

void init()
{
  add_action("do_stab", "stab");
}

int do_stab(string arg)
{
  object me = this_player();
  object where = environment(me);
  object ob; 

  if (arg =="athena")
    {   
        me->start_busy(10);
		call_out("applying",1,me);     
	}
	 else
  return notify_fail ("这把匕首只能用来刺杀雅典娜.\n");
	 
return 1;


}

void applying (object me)
{
  
  message_vision (RED"\n$N静悄悄地靠近毫无防备的女神-雅典娜\n",me);
  message_vision (RED"\n雅典娜发现$N有点不对,正想张口询问$N的来意.\n",me);
    message_vision (RED"\n\n$N一个箭步冲向女神,将邪恶的匕首深深的插进了雅典娜的胸口........\n",me);
	call_out("finish_kill",2,me);
}

void finish_kill(object me)
{
	message_vision (BLU"\n\n\n雅典娜惊讶的看着你,慢慢的倒了下去!\n"NOR,me);
    present("athena",environment(me))->unconcious();
    message("channel:rumor", HIM + "【谣言】某人：听说女神雅典娜被"+me->query("family/family_name")+"的"+HIY""+
     me->query("name")+HIM"刺伤了。\n"NOR,users());
    destruct (this_object());
}
 