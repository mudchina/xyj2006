//sgzl
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("天蓬元帅",({"tianpeng yuanshuai","yuanshuai","tianpeng"}));
  set("gender", "男性");
  set("title", "天河");
  set("age", 35);
  set("long", "    \n一位威风凛凛的大帅，负责巡查天河。\n");

  set("attitude", "heroism");
  set("class", "xian");
  set("combat_exp", 1200000);
  set("daoxing", 1000000);
  set("kee", 1600);
  set("max_kee", 1600);
  set("sen", 2200);
  set("max_sen", 2200);
  set("force", 1500);
  set("max_force", 1500);
  set("mana", 2500);
  set("max_mana", 2500);
  set("force_factor", 40);
  set("mana_factor", 40);
  set("str", 25);
  set("per", 13);


  set_skill("spells", 160);
  set_skill("dao", 150);
  set_skill("force", 160);
  set_skill("zhenyuan-force", 140);
  set_skill("rake", 150);
  set_skill("skyriver-rake", 180);
  set_skill("parry", 160);
  set_skill("yanxing-steps", 160);
  set_skill("dodge", 140);
  set_skill("unarmed", 150);
  set_skill("wuxing-quan", 180);


map_skill("spells", "dao");
map_skill("force", "zhenyuan-force");
map_skill("rake", "skyriver-rake");
map_skill("parry", "skyriver-rake");
map_skill("dodge", "yanxing-steps");
map_skill("unarmed", "wuxing-quan");
  set("inquiry", ([
  "name"   : "天蓬元帅",
  "here"   : "天河",
]));


setup();

carry_object("/d/kaifeng/obj/jiuchipa")->wield();
carry_object("/d/obj/armor/tongjia")->wear();

}

int accept_fight(object me)
{
  message_vision("天蓬元帅对$N把眼一瞪，喝道：呔，大胆，还不退下！\n", me);
  return 0;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

int heal_up()
{

  if( environment() && !is_fighting() ) 
    {
    call_out("leave", 1);
    return 1;
    }
    return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "吐了口唾沫，骂道：下次别叫老子碰到！
天蓬元帅走了出去。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void unconcious()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object temp_man; 
  if (ob && ob->query("dntg/bmw")=="fight")
  {
    ob->set("dntg/bmw","done");
    temp_man = new ("/d/dntg/sky/npc/announcer");
    temp_man->announce_success (ob);
  }
  message_vision ("\n$N冷哼一声化作一股狂风不见了。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void destruct_me(object me)
{
  destruct(me);
}

void die()
{
  unconcious();
}

