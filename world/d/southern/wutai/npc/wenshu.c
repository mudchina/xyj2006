//Cracked by Roath
// wenshu-pusa

// #include <ansi.h>

inherit NPC;
void create()
{

  set_name("文殊菩萨", ({ "wenshu pusa", "pusa", "pu sa", "wenshu" }) );
  set("gender", "男性" );
  set("long", @LONG
    
　　文殊菩萨乃佛陀（本师释迦牟尼）之上首菩萨弟子。传说
五台山并非现在这般模样，也不叫五台山，而是叫五峰山，气
候异常恶劣 ，冬天滴水成冰，春天飞砂走石，夏天暑热难当，
农民们无法种庄稼。在此传教的文殊菩萨，从东海龙王那里得
到了一块清凉石，放在一条山谷后，五峰山立刻变志一个清凉
无比的地方。从此文殊菩萨也便在此落脚。
LONG );
  set("age",55);
  set("title", "佛教大乘菩萨");
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("class", "bonze");
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 4000);
  set("max_force", 2000);
  set("force_factor", 145);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 150);
  set("combat_exp", 2000000);
  set("daoxing", 10000000);

  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 180);
  set_skill("lotusmove", 180);
  set_skill("parry", 180);
  set_skill("force", 180);
  set_skill("lotusforce", 180);
  set_skill("staff", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
          (: cast_spell, "bighammer" :),
    }) );

  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}
	






