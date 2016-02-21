

inherit NPC;

void create()
{
   set_name("文殊菩萨", ({ "wenshu pusa", "pusa", "pu sa", "wenshu" }));
   set("title", "佛教大乘菩萨");   
   set("long", @LONG
    
　　文殊菩萨乃佛陀（本师释迦牟尼）之上首菩萨弟子。传说
五台山并非现在这般模样，也不叫五台山，而是叫五峰山，气
候异常恶劣 ，冬天滴水成冰，春天飞砂走石，夏天暑热难当，
农民们无法种庄稼。在此传教的文殊菩萨，从东海龙王那里得
到了一块清凉石，放在一条山谷后，五峰山立刻变志一个清凉
无比的地方。从此文殊菩萨也便在此落脚。
LONG);
   set("gender", "男性");
   set("age", 55);
   set("per", 35);
   set("attitude", "friendly");
   set("max_kee", 3000);
   set("max_gin", 3000);
   set("max_sen", 3500);
   set("force", 2000);
   set("max_force", 2000);
   set("force_factor", 100);
   set("max_mana", 3500);
   set("mana", 3500);
   set("mana_factor", 200);
   set("combat_exp", 1000000);

        set("eff_dx", 400000);
        set("nkgain", 2000);

   set_skill("literate", 200);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 200);
   set_skill("jienan-zhi", 200);
   set_skill("dodge", 200);
   set_skill("staff", 200);
   set_skill("lunhui-zhang", 200);
   set_skill("lotusmove", 200);
   set_skill("parry", 200);
   set_skill("force", 200);
   set_skill("lotusforce", 200);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
  }) );

   setup();

   carry_object("/obj/money/gold");
      carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}

