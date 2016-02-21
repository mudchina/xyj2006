//sgzl
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("猪八戒",({"zhu bajie","bajie","zhu"}));
  set("gender", "男性");
//  set("title", "无能");
  set("age", 35);
  set("long", "    \n原来是管理天河的大元帅，因调戏嫦娥被贬到人间。\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 600000);
  set("daoxing", 600000);
  set("kee", 1500);
  set("max_kee", 1500);
  set("sen", 1500);
  set("max_sen", 1500);
  set("force", 1800);
  set("max_force", 1800);
  set("mana", 2000);
  set("max_mana", 2000);
  set("force_factor", 80);
  set("mana_factor", 80);
  set("str", 30);
  set("per", 13);


  set_skill("spells", 140);
  set_skill("dao", 140);
  set_skill("force", 140);
  set_skill("zhenyuan-force", 130);
  set_skill("rake", 140);
  set_skill("skyriver-rake", 160);
  set_skill("parry", 140);
  set_skill("yanxing-steps", 140);
  set_skill("dodge", 130);
  set_skill("unarmed", 150);
  set_skill("wuxing-quan", 150);


map_skill("spells", "dao");
map_skill("force", "zhenyuan-force");
map_skill("rake", "skyriver-rake");
map_skill("parry", "skyriver-rake");
map_skill("dodge", "yanxing-steps");
map_skill("unarmed", "wuxing-quan");
set("inquiry", ([
	"元帅" : "我原本是天上的天蓬元帅！"
]));


setup();

carry_object("/d/kaifeng/obj/jiuchipa")->wield();
carry_object("/d/obj/armor/tongjia")->wear();

}

int accept_fight(object me)
{
  message_vision("猪八戒懒懒的看了$N一眼，显然他不想理你！\n", me);
  return 0;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object temp_man; 
  if ((ob && ob->query("obstacle/gao")=="done") || 
  (ob && ob->query_temp("obstacle/gao_asked")!=1))
  {
     message_vision ("\n$N冷哼一声化作一股狂风不见了。\n",me);   
     destruct(me);
   }

  if (ob && (ob->query_temp("obstacle/zhu_killed")==1) && (ob->query_temp("obstacle/zhu_shidong")==1))
  {
    message_vision ("\n$N飞向空中深深作了一辑，说到“我猪无能从此向善，保护师傅唐僧西天取经”。\n",me);
    call_out ("destruct_me",3,me);
    temp_man = new("/d/gao/npc/gao");
    temp_man->announce_success (ob);
  }
  else
  {
    ob->set_temp("obstacle/zhu_killed",1);
    message_vision ("\n$N冷哼一声化作一股狂风不见了。\n",me);
    destruct(me);
  } 
  
}

