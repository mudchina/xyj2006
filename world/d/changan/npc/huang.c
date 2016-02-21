//created 5-20-97 pickle

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;
//inherit SKILL;

void create()
{
  set_name(HIY"黄飞虎"NOR, ({"huang feihu", "huang", "feihu", "huangfeihu"}));
  set ("long", @LONG
开国武成王黄飞虎，兴周第一大将，封神榜
上五岳之首东岳泰山大齐仁圣大帝，下凡寻
找其五色神牛的下落。
LONG);
 
  set("title", HIW"东岳泰山大齐仁圣大帝"NOR);
  set("gender", "男性");
  set("age", 43);
  set("str", 45);
  set("per", 35);
  set("int", 30);
  set("cor", 50);
  set("cps", 40);
  set("combat_exp", 8000000);
  set_skill("spear", 200);
  set_skill("force", 180);
  set_skill("dodge", 180);
  set_skill("stick", 180);
  set_skill("literate", 180);
  set_skill("dali-bang", 180);
  set_skill("huoyun-qiang", 180);
  set_skill("parry", 160);
  set_skill("unarmed", 180);
set_skill("wuyue-spear", 200);
set_skill("spells", 180);
set_skill("pingtian-dafa", 180);
  set_skill("moshenbu", 180);
  set_skill("huomoforce", 180);
  set_skill("moyun-shou", 180);
map_skill("force", "huomoforce");
map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("spear", "wuyue-spear");
  map_skill("parry", "wuyue-spear");
  map_skill("stick", "dali-bang");
  map_skill("dodge", "moshenbu");
  set("max_sen", 6000);
  set("max_kee", 8000);
set("force", 10000);
set("max_force", 6000);
set("mana",6000);
set("max_mana",3000);
set("daoxing",5000000);
set("force_factor", 200);
set("mana_factor", 150);
  set("chat_chance_combat", 100);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "buhui" :),
                (: perform_action, "unarmed", "zhangxinlei" :),
  }) );
 
  create_family("火云洞", 1, "蓝");
  setup();
 
carry_object("/d/obj/weapon/spear/huaji2")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}
 
int accept_fight(object me)
{
  command("say 老夫手重，若是伤人反而不美了。\n");
  return 0;
}
int attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="火云洞") {
if (((int)ob->query("combat_exp") < 400000 )) {
command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return 0;
   }
        command("haha "+ob->query("id"));
 command("say 看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他pk到没道行！\n");
command("recruit " + ob->query("id") );
return 0;
}
command("say " + RANK_D->query_respect(ob) +
"还是再苦练几年枪法罢！\n");
       return 1;
}
/*
{  
string myname=RANK_D->query_respect(me);
 if ((int)me->query_skill("spear")< 200) 
//  if ((int)me->query_skill("spear")< 200) 
    {
      command("say 这"+myname+"再苦练几年枪法罢！");
      return 0;
    }
  if ((int)me->query_skill("stick") < 200 )
    {
      command("say 这"+myname+"知道我那孽畜的下落？");
      return 0;
    }
  command("say 看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他pk到没道行！\n");
  command("recruit " + me->query("id") );
  return 1;
}
*/
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "yaomo");
      ob->set("title", "五岳大帝座下山神");
}

