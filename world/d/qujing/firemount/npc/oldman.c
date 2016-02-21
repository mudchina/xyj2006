// rewritten by snowcat on 4/12/1997

inherit NPC;

void create()
{
  set_name("老者", ({"oldman","man"}));
  set("gender", "男性");
  set("age", 60);
  set("long","这是一位常住此地的老人。白眉白须，铜面碧眼，极为和蔼。\n"); 
  set("attitude", "friendly");
  set("combat_exp", 5000);
  set("per", 25);
  set_skill("dodge", 10);
  setup();

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);
}

int accept_fight(object me)
{
  say("老者颤危危地说道："+RANK_D->query_respect(me)+"饶了我这点老命吧。\n");
  return 0;
}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
        "here":   "这儿是火焰山，自古以来有两大宝：铁扇，芭蕉骨。\n",
        "火焰山": "火焰山八百里大火，凡人实是插翅难飞，要用铁扇才能灭火。\n",
        "铁扇":   "找铁扇公主吧，据说比武也行，赠送芭蕉骨也行。\n",
        "芭蕉骨": "去庙里问土地，只有他指点才能去找芭蕉骨。\n",
        "铁扇公主": "她就住在翠云山中，真是一个女菩萨。\n",
      ]));

  if (interactive(ob = this_player()) && !is_fighting())
  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;

  switch (random(1))
  {
    case 0:
    {
      say( "老者迎上前道："+RANK_D->query_respect(ob)+"打哪儿来呀？\n");
      break;
    }
  }
}

