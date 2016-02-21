
//servent.c
inherit NPC;
void create()
{
       set_name("哑仆", ({"servent"}));
       set("long", "哑仆是当年李逍遥大侠于苗疆救的一人，他感念李逍遥救命之恩，
自愿充当仆人，照顾李忆如。\n");
       set("gender", "男性");
       set("age", 70);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
       set("int", 30);
       set("str", 30);
       set("cps", 30);
       set("max_kee", 1500);
       set("max_gin", 1500);
       set("max_sen", 1500);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 80);
       set("max_mana", 1500);
       set("mana", 3000);
       set("mana_factor", 60);
       set("combat_exp", 800000);
        set("eff_dx", 250000);
       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
 set_skill("stick", 120);
 set_skill("spells", 120);
 set_skill("dao", 120);
 set_skill("puti-zhi", 120);
 set_skill("wuxiangforce", 120);
 set_skill("force", 120);
 set_skill("qianjun-bang", 120);
 set_skill("jindouyun", 120);
 map_skill("spells", "dao");
 map_skill("unarmed", "puti-zhi");
 map_skill("force", "wuxiangforce");
 map_skill("stick", "qianjun-bang");
 map_skill("parry", "qianjun-bang");
 map_skill("dodge", "jindouyun");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
  (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :),
                (: perform_action, "stick.qiankun" :),
        }) );
        setup();
        carry_object("/d/lingtai/obj/xiangpao")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}
