//Cracked by Roath
#include <ansi.h>

inherit NPC;

string *names = ({
  "虾臣",
  "蟹士",
  "巡水夜叉",
});

string *ids =   ({
   "xia chen",
   "xie shi",
   "xunshui yecha",
});

void create()
{

  int i;

  i=random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("gender", "男性" );
  set("age", 33);
  set("long", "泾水河的干将，正在四处巡逻。\n");
  set("class", "dragon");
  set("combat_exp", 50000);
  set("daoxing", 25000);

  set("attitude", "heroism");
  set_skill("unarmed", 50);
  set_skill("dragonfight", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("fork", 50);
  set_skill("fengbo-cha", 50);
  set_skill("spells", 50);
  set_skill("seashentong", 50);
  set_skill("dragonstep", 60);
  set_skill("force", 60);   
  set_skill("dragonforce", 50);
  map_skill("force", "dragonforce");
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("spells", "seashentong");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");

  set("max_kee", 500);
  set("max_sen", 500);
  set("mana", 500);
  set("max_mana", 500);
  set("mana_factor", 15);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 5);

  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
     (: perform_action, "fork", "fengbo" :),
        }) );

  setup();
  carry_object("/d/obj/armor/tenjia")->wear();
  carry_object("/d/obj/weapon/fork/gangcha")->wield();
}


