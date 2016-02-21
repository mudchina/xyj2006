
inherit "/d/dntg/lijing/troops.c";
 
void create()
{
 
        set_name("巨灵神", ({ "juling shen", "shen", "juling" }) );
        set("gender", "男性" );
        set("long","托塔李天王帐下先锋大将，膀阔腰圆，力大无穷。\n");
        set("age",40);
        set("title", "先锋大将");
        set("info_rank/rude","毛神");
        set("str", 400);
        set("int", 20);
        set("con", 30);
        set("spi", 20);
        set("per", 15);
        set("class", "xian");
        set("attitude", "heroism");
        set("combat_exp", 950000);
        set("daoxing", 800000);

        set("max_kee", 2000);
        set("max_sen", 3000);
        set("force",4400);
        set("max_force",4000);
        set("force_factor", 100);
        set("mana", 5000);
        set("max_mana", 5000);
        set("mana_factor", 0);

        set_skill("unarmed",150);
        set_skill("dodge",100);
        set_skill("parry",200);
        set_skill("axe", 180);
        set_skill("force", 100);
        set_skill("spells", 100);
        set_skill("changquan", 150);
        set_skill("sanban-axe", 180);
        set_skill("baguazhou", 100);
        set_skill("moshenbu", 100);
        set_skill("lengquan-force", 150);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("axe", "sanban-axe");
        map_skill("parry", "sanban-axe");
//        map_skill("dodge", "moshenbu");
        setup();
        carry_object("/d/obj/armor/tongjia")->wear();
        carry_object("/d/obj/weapon/axe/huafu")->wield();
}
