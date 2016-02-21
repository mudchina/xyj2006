//Cracked by Roath

#include <ansi.h>
#include <combat.h>

inherit NPC;
#include <flowers.h>

string name;

void create()
{
  name=flowers[random(sizeof(flowers))];
  set_name(name+"仙子", ({ "hua xianzi","xianzi","xian" }) );
  set("long",@LONG
一位品貌秀丽，气质高雅的花仙子，浑身散发出一股异香，
既非冰麝，又非旎檀，似花香而非花香，时刻变换，竟有百
种香气。
LONG);
  set("gender", "女性");
  set("age", 20);
  set("str", 10+random(21));
  set("dex", 10+random(21));
  set("int", 10+random(21));
  set("cor", 10+random(21));
  set("spi", 10+random(21));
  set("con", 10+random(21));  
  set("per", 10+random(21));

  set("combat_exp", 10000);
  set("daoxing", 10000);

  set_skill("unarmed", 80);
  set_skill("parry", 80);
  set_skill("dodge", 80);
  set_skill("moondance",80);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("moonshentong",180);
  map_skill("spells","moonshentong");
  map_skill("dodge","moondance");

  set("max_kee", 1000);
  set("max_sen", 1000);
  set("mana", 4000);
  set("max_mana", 1000);
  set("mana_factor", 60);
  set("force", 2000);
  set("max_force", 1000);
  set("force_factor", 120);
  
  setup();
  if (clonep())  carry_object("/obj/loginload/skirt")->wear();
  if (clonep())  carry_object("/obj/loginload/shoes")->wear();

}

void init() {
}
