#include <ansi.h>
inherit NPC;


void create()
{
    set_name(HIW "元始天尊" NOR, ({"yuanshi tianzun", "tianzun", "yuanshi"}));
    set("title", HIR "三清之首" NOR);
    set("long", "三清之首，法力无边。\n");
    set("gender", "男性");
    set("age", 13500);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);
    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("dao", 321 );
    set_skill("zhenyuan-force", 301);
    set_skill("spells", 321);
    set_skill("force", 301);
    set_skill("moonshentong", 301);
    set_skill("whip", 301);
    set_skill("staff", 301);
    set_skill("blade", 301);
    set_skill("spear", 301);
    set_skill("hammer", 301);
    set_skill("buddhism", 301);
    set_skill("taiyi", 301);
    set_skill("lotusforce", 301);
    set_skill("wuxiangforce", 301);
    set_skill("moonforce", 301);
    set_skill("stick", 301);
    set_skill("dodge", 301);
    set_skill("unarmed", 301);
    set_skill("parry", 301);
    set_skill("sword", 251);
      map_skill("force", "wuxiangforce");
      map_skill("spells", "dao");

    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :),
        (: cast_spell, "fenshen" :),
(: exert_function, "jldl" :)
}));
      setup();
   
}

int accept_fight(object me)
{
        write("仙人你也想打？\n");
        return 0;
}

int recognize_apprentice(object me)
{
      object ob = this_player();
      
        if (!(int)ob->query_temp("mark/仙"))
             return notify_fail( HIR "看起来" HIW "元始天尊" HIR "想杀死你！\n"NOR);
        if( ( ob->query("family/family_name") != "方寸山三星洞"
            && ob->query("family/family_name") != "南海普陀山"
            && ob->query("family/family_name") != "月宫"
            && ob->query("family/family_name") != "五庄观")
            || ob->query("combat_exp")  < 2000000 ) 
             return notify_fail( HIR "看起来" HIW "元始天尊" HIR "想杀死你！\n"NOR);

             ob->add_temp("mark/仙", -1);
               return 1;
}
