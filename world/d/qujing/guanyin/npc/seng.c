// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit NPC;

void create()
{
   set_name("无名僧", ({ "seng" }));
   set("long", "一位年轻的僧人，脸上总是带着热情的笑容。\n他负责在此迎接前来参禅进香的客人。\n");
   set("gender", "男性");
   set("age", 25);
   set("attitude", "peaceful");
   set("class", "bonze");
   set("max_kee", 200);
   set("max_gin", 200);
   set("max_sen", 200);
   set("force", 100);
   set("max_force", 100);
   set("force_factor", 10);
   set("max_mana", 100);
   set("mana", 100);
   set("mana_factor", 10);
   set("combat_exp", 5000);
   set_skill("literate", 20);
   set_skill("unarmed", 25);
   set_skill("dodge", 20);
   set_skill("parry", 25);
   set_skill("force", 10);
   set_skill("spells", 10);
   set_skill("buddhism", 10);
   set_skill("unarmed", 30);
   map_skill("spells", "buddhism");
   
   setup();
   add_money("silver", 20);
   carry_object("/d/nanhai/obj/sengpao")->wear();
}
