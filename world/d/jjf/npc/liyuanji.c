// 李建成 npc: /d/jjf/npc/lijiancheng.c
// created 5-20-97 pickle
 
inherit NPC;
string expell_me(object me);
 
void create()
{
  set_name("李元吉", ({"li yuanji", "li", "yuanji", "liyuanji", "jianwang", "jian wang", "wang", "jian"}));
  set ("long", @LONG
李元吉乃是唐高祖李渊的三子，受封建王。三子中以李元吉最
为无用。他空有一身蛮力，但无恶不作，毫不以领地百姓为重。
且在作战时屡失重要据点，实在令高祖大为头痛。
LONG);
 
  set("title", "建王");
  set("gender", "男性");
  set("age", 22);
  set("str", 40);
  set("per", 15);
  set("int", 20);
  set("cps", 50);
  set("cor", 50);
  set("combat_exp", 300000);
  set_skill("blade", 50);
  set_skill("force", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("yanxing-steps", 50);
  set_skill("wuhu-blade", 100);
  set_skill("lengquan-force", 50);
  set_skill("unarmed", 50);
  set_skill("changquan", 100);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("blade", "wuhu-blade");
  map_skill("parry", "wuhu-blade");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 150);
  set("max_kee", 700);
  set("force", 500);
  set("max_force", 500);
  set("force_factor", 50);

  setup();
  carry_object("/d/jjf/obj/lingjian-jian.c"); 
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
 
int accept_fight(object me)
{
  string myrude=RANK_D->query_rude(me), player=me->query("id");
  int kar=(int)me->query_kar();

  if ((string)me->query("family/family_name") == "将军府")
    {
      command("say 你个"+myrude+"！竟敢在太岁爷头上动土！");
      command("kill "+player);
      return 1;
    }
  if (random(kar-10) > 10)
   {
     command("sneer "+player);
     command("say 老子今天没兴致，你个"+myrude+"趁早给我滚！");
     me->move("/d/jjf/zuixing");
     return notify_fail("幸亏你运气好，否则。。。\n");
   }
  command("say 老子生平最爱杀人！今天算你倒霉！");
  command("kill "+player);
  return 1;
}
