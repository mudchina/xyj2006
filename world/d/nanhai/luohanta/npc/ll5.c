
inherit NPC;
inherit F_MASTER;

void create()
{
   set_name("日月罗汉", ({ "luo han", "luohan" }));
   set("title", "十八罗汉");   
   set("long", @LONG
南海观音座下十八罗汉。
LONG);
   set("gender", "男性");
   set("age", 25);
   set("attitude", "heroism");
   set("per", 9);
   
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("force", 3600);
   set("max_force", 1800);
   set("force_factor", 100);
   set("max_mana", 2000);
   set("mana", 2000);
   set("mana_factor", 20);
   set("combat_exp", 2000000);
   set_skill("spells", 120);
   set_skill("buddhism", 120);
   set_skill("unarmed", 120);
   set_skill("jienan-zhi", 120);
   set_skill("dodge", 120);
   set_skill("lotusmove", 120);
   set_skill("parry", 120);
   set_skill("force", 120);
   set_skill("lotusforce", 120);
   set_skill("staff", 120);
   set_skill("lunhui-zhang", 120);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
   }) );

           create_family("南海普陀山", 2, "弟子"); setup();
   carry_object("/d/nanhai/obj/sengpao")->wear();
carry_object("/d/nanhai/obj/budd_staff")->wield();

}
