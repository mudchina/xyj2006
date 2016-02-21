//Cracked by Roath
//girl.c

inherit NPC;

void create()
{
        set_name("农家女", ({"girl"}));
        set("gender", "女性" );
        set("age", 15);
        set("long",  
"五观庄附近的农家女。平时帮帮种菜养花，闲了常找观内的女弟子玩。\n");
        set("combat_exp", 20);
        set("attitude", "peaceful");
        set("per", 25);
        set("max_kee", 200);
        set("max_gin", 200);
        set("max_sen", 200);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
}

int accept_fight(object me)
{
        return 0;
}

