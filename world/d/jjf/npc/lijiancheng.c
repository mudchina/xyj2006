// 李建成 npc: /d/jjf/npc/lijiancheng.c
// created 5-20-97 pickle
 
inherit NPC;
string expell_me(object me);
 
void create()
{
  set_name("李建成", ({"li jiancheng", "li", "jiancheng", "lijiancheng", "qiwang", "qi wang", "wang", "qi"}));
  set ("long", @LONG
李建成乃是唐高祖李渊的大儿子，受封齐王，随高祖南征北战
时颇立战功。虽无二弟李世民显赫，但也非老三李元吉一般屡
吃败仗。
LONG);
 
  set("title", "齐王");
  set("gender", "男性");
  set("age", 36);
  set("str", 25);
  set("per", 25);
  set("int", 25);
  set("combat_exp", 250000);
  set_skill("spear", 100);
  set_skill("force", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("yanxing-steps", 60);
  set_skill("bawang-qiang", 60);
  set_skill("lengquan-force", 60);
  set_skill("unarmed", 100);
  set_skill("changquan", 60);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 200);
  set("max_kee", 600);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 30);

  setup();
  carry_object("/d/jjf/obj/lingjian-qi.c"); 
  carry_object("/d/obj/weapon/spear/tiespear")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  string myrude=RANK_D->query_rude(me), player=me->query("id");
  int kar=(int)me->query_kar();

  if ((string)me->query("family/family_name") == "将军府")
    {
      command("say 老子最恨的就是将军府弟子！你个"+myrude+"竟然自己送上门来！");
      command("emote 踌躇道：杀还是不杀？");
      if (random(kar-10) > 10)
       {
         command("sneer "+player);
         command("say 老子今天心情好，你个"+myrude+"趁早给我滚！");
         me->move("/d/jjf/zuixing");
         return notify_fail("幸亏你运气好，否则。。。\n");
       }
      command("emote 喝道：杀！");
      command("kill "+player);
      return 1;
    }
    command("say 刀剑无情，本王若是伤了你怎么办？\n");
  return 0;
}
