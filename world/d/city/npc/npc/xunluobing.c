// wujiang.c 武将

inherit NPC;

void create()
{
        set_name("巡逻官兵", ({ "xunluo guanbing","guanbing", "bing" }));
        set("gender", "男性");
        set("age", random(10) + 20);
        set("str", 25);
	set("con", 25);
	set("spi", 25);
	set("dex", 25);
	set("int", 25);
        set("long", "他威风凛凛，杀气腾腾，负责城内商家安全。\n");
        set("combat_exp", 50000);
	set("class", "fighter");
        set("attitude", "herosim");
        set_skill("unarmed", 70);
        set_skill("force", 70);
        set_skill("spear", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set_skill("bawang-qiang", 30);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	set("max_kee", 700);
	set("max_sen", 700);
        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 20);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
        message_vision("巡逻官兵对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "吐了口唾沫，骂道：下次别叫老子碰到！
巡逻官兵走了出去。\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

