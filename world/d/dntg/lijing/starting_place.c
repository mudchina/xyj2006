
#include <ansi.h>

inherit ROOM;

void init() {

  set("long",@LONG

一片开阔的草地，被猴子们当作他们的教军场，只见其中一个严肃的
通背猿指挥着一列列，一排排走过来的猴子兵。草地的北侧竖着一根
十丈多高的旗杆，上面挂着一面大旗(flag)，在风中飒飒飘舞。
LONG);

  add_action("do_start",({"raise","gua","sheng","hang"}));
  add_action("do_look","look");

}

int do_look(string arg) {
  object me=this_player();

  if (!arg || arg!="flag") return 0;
  write ("一面三尺见方的大旌旗，迎风飘展。\n");
  if (query("host")) write("旗上绣着"+HIY"齐天大圣"+
        query("host")->query("name")+NOR"几个大字。\n\n");
   else write("风太大，看不清楚旗上面写着什么。\n\n");
  return 1;
}

int do_start(string arg) {
   object me=this_player();
   object host=query("host");
   object lijing;

   if (!arg || arg!="flag") return notify_fail("你要做什么？\n");
   if (host)
      return notify_fail(host->query("name")+"已在此占山为王了。\n");   
   if (me->query("combat_exp")<100000)
     return notify_fail("旗杆太高了，你功夫太差，挂不上去。\n");
   if (me->query("dntg/lijing")=="done")
     return notify_fail("你上次已经过足齐天大圣瘾了，这次留给别人玩吧。\n");

   set("host",me);
   message_vision(HIG"$N将“齐天大圣”的大旗挂上旗杆。\n"NOR,me);
   message_vision(HIG"$N高声宣布：“从今日起，"+RANK_D->query_self_rude(me)
     +"就是齐天大圣，与玉帝老儿平起平坐！”\n"NOR,me);

  lijing=new("/d/dntg/lijing/lijing");
  lijing->move(environment(me));
  lijing->set("target",me);
  lijing->start();
   
  return 1;
}
