#include <ansi.h>

inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "新手礼物" NOR,({"gift"}));
  set("long","这是一份礼物，你可以试着打开("+HIR+"open"+NOR+")来看看。");
  set("unit","份");
  set("value", 0);
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西拿不起来。\n");
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
   }
    if(this_player()==environment())
  add_action("do_open", "open");
}

int do_open(string arg)
{
  object yudi;
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("你要打开什么?\n");
  if (me->query("newbie_liwu")) return notify_fail("你已经拿过礼物了，怎么还想要？\n");
  message_vision(HIG"$N把礼物盒轻轻的打开，一道光芒从天而降，$N被这光芒包住，$N觉得浑身充满了力量!\n" NOR,me);
  
  me->add("potential",5000);  //the reward just is a example ,you can modify it as your wish. :P
  me->add("combat_exp",10000); //vikee 10/5/2000
  tell_object(me,HIW"你被奖励了：\n" +
  chinese_number(10000) + "点武学\n"+        
  chinese_number(5000) + "点潜能\n" NOR);
  me->set("newbie_liwu",1);
  yudi = new("/d/dntg/sky/npc/yuhuang.c");
  yudi->command_function("chat 听说一个名叫"+me->name()+"的人，得到了新手礼物，开始了他的西游生涯...\n");
  destruct(yudi);
  destruct(this_object());
  return 1;
}

