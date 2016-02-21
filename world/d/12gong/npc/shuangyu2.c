// by happ@YSZZ

 
inherit NPC;
#include "star.h" 
void create()
{
        set_name("阿布罗迪", ({"aphrodite two"}));
        set("long", "号称最美丽的圣斗士，并以玫瑰为武器。也是比较邪恶的黄金圣
斗士，但在冥界之战中仍为雅典娜献身。 守护着双鱼座.\n");
        set("gender","男性");
        set("title", "【"+HIY"黄金圣斗士"+NOR"】");
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",8000000);
        set("chat_chance",20);
        set_skill("dodge", 330);
        set_skill("force", 330);
        set_skill("parry", 330);
        set_skill("unarmed", 330);
        set_skill("sword", 330);
        set_skill("westsword",330);
        set_skill("boxing",330);
        set_skill("balei",330);
        set_skill("spells",330);
        set_skill("shuangyu", 330);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangyu");
        map_skill("dodge","balei");
        set("max_force", 6500);
        set("force", 12000);
        set("max_mana",6000);
        set("mana",12000);
        set("mana_factor",230);
        set("force_factor", 200);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/sy_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        remove_call_out("check_me");
        call_out("check_me",12);
}
void check_me()
{
        command_function("say 我先走一步了!\n");
        destruct(this_object());
}
