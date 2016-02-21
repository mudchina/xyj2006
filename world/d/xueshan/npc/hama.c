//Cracked by Roath
inherit NPC;

void create()
{
set_name("朱睛冰蟾", ({"bing chan", "hama"}));
set("race", "野兽");
set("age", 33);

set("long", @LONG
一只大蟾蜍，通体雪白，眼珠却血也般红，模样甚是可爱，却也不见有何珍异之处。
LONG);

set("attitude", "aggressive");
set("class", "yaomo");
set("combat_exp", (random(5)*100000+50000));
set("daoxing", (random(5)*100000+50000));
set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
set("verbs", ({ "bite"}));

set("kee", 800);
set("max_kee", 800);
set("sen", 1200);
set("max_sen", 800);
set("force", 1000);
set("max_force", 1000);
set("mana", 1000);
set("max_mana", 500);
set("force_factor", 30);
set("mana_factor", 40);
set("str", 30);


set_skill("unarmed", 80);
set_skill("parry", 80);
set_skill("yingzhaogong", random(30)+20);
set_skill("spells", 100);
set_skill("dengxian-dafa", random(100)+70);
set_skill("force", 100);
set_skill("ningxie-force", random(100)+70);


map_skill("force", "ningxie-force");
map_skill("spells", "dengxian-dafa");
map_skill("unarmed", "yingzhaogong");
map_skill("unarmed", "yingzhaogong");

set("chat_chance_combat", 40);
set("chat_msg_combat", ({
    (: cast_spell, "jieti" :),
    (: cast_spell, "juanbi" :),
    (: cast_spell, "tuntian" :),
  }) );

setup();
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  ob = new ("/d/xueshan/obj/cookfood");
  ob->set("name",me->query("name"));
  ob->set("cook/type","hama");
  ob->set("cook/value",5);
  ob->move(where);
  message_vision ("\n$N缩成一团，不再动了。\n",me);
  destruct (me);
}

void die ()
{
  unconcious();  
}

