inherit NPC;
#include <ansi.h>
int give_gift();
void create()
{
    set_name(HIC"礼物大使"NOR, ({ "da shi"}));
       set("age", 18+random(10));
       set("gender", "男性");
  set("title", HIR"西游记2006专用"NOR);
       set("long","这位就是由九天大人没事干，深夜赶着写出来的礼物使者。\n");
        set("attitude", "peaceful");
  set("str", 50);
  set("kar", 50);
 set("per", 50);
      set("combat_exp", 200000000);
      set("daoxing", 200000000);
      set("max_force", 200000);
      set("max_mana", 200000);
set("max_kee", 40000);
set("max_sen", 40000);
set("force", 400000);
set("force_factor", 1000);
set("mana_factor", 1000);
set("mana", 1000);
       set_skill("unarmed", 1000);
        set_skill("dodge", 1000);
       set_skill("parry", 1000);
   set("inquiry",([
  "gift": (: give_gift :),
  "礼物": (: give_gift :),
   "新年": (: give_gift :),
   "过年": (: give_gift :),
]));
     setup();
}
int give_gift()
{
   object me;
   me=this_player();
        if(!me) return 0;
         if (me->query("take/新年")=="2002")
{
message_vision("\n\n礼物大使疑惑的看着你道：你不是又想来混一份礼物吧？\n\n"NOR,me);
return 1;
}
           me->set("take/新年","2002");
               if (me->query("combat_exp")<=100000)
me->add("potential",10000);
 if ((me->query("combat_exp")>=100001)&&(me->query("combat_exp")<=200000))
me->add("potential",30000);
               if (me->query("combat_exp")>200000)
me->add("potential",50000);
 message_vision("\n\n礼物大使拱手贺道："+HIR"新   "+HIY"年   "+BLU"快   "+HIG"乐   "+HIC"\n\n"+HIW"                       万   "+HIB"事   "+HIC"如   "+HIM"意\n\n"NOR,me);
         write ("在2002年新年到来之际，你得到西游记2006巫师组的新年祝福，你的潜能增长了。\n");
return 1;
}
