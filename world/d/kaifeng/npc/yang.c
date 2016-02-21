inherit NPC;
#include <ansi.h>

void reset_balance(object me);

void create()
{
  set_name("杨老板", ({"yang laoban", "yang", "laoban"}));
  set("gender", "男性");
  set("age", 45);
  set("max_kee", 700);
  set("max_sen", 700);
  set("combat_exp", 40000);
  set("attitude", "friendly");
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
  add_money("silver", 10);
}

void init()
{
  call_out("reset_balance", 1, this_player());
  ::init();
}

void reset_balance(object me)
{
  int myexp;
  int allowed, removed_gold;
  string myid;
  string NPCNAME=this_object()->name();
  if (!me) return;
  myexp=me->query("combat_exp")/1000;
  myid=me->query("id");
  if(myexp<1) myexp=1;
  if(myexp>100) myexp=100;
  allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
  if (me->query("balance") > allowed)
  {
    me->set("balance_old", me->query("balance"));
    me->set("balance", allowed);
    removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
    log_file("MONEY_RESET", ctime( time() )+"：魏大人收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
    tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
                "，这、这真不知怎么说是好．．．\n"NOR);
    tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
                "昨日魏大人从长安派人前来察案，发觉你老的黄金来路．．．\n"NOR);
    tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
                "若不是在下帮你老辩解，你老的钱就全都充公了．．．\n"NOR);
  }
  return;
}

