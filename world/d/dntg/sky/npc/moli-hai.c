//modified by vikee for xlqy for NK_DX
//2000-11-23 16:21


inherit NPC;
void create()
{
        set_name("魔礼海", ({ "moli hai", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"魔家四将之一，使一根盘龙棍，背上一面琵琶，上有四条弦；也按\n"
                "地、水、火、风，拨动弦声，风火齐至，如青云剑一般。\n"
	);
	set("age",50);
	set("title", "多闻天王");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_kee",3100);
	set("kee",3100);
	set("max_sen",3100);
	set("sen",3100);
	set("combat_exp",3000000);
        set("daoxing",3000000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);

        set("eff_dx", 1500000);
        set("nkgain", 800);
	
	set_skill("unarmed",240);
	set_skill("yingzhaogong", 240);
	set_skill("parry",240);
	set_skill("dodge",240);
	set_skill("stick",240);
	set_skill("kusang-bang",240);
	set_skill("force",240);
	set_skill("spells", 240);
	set_skill("moshenbu", 240);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "kusang-bang");
	map_skill("stick", "kusang-bang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下多闻天王魔礼海，奉圣谕把守北天门。",
		"here" : "这里就是北天门, 入内就是天界了。",
	]) );

	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}


int accept_fight(object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N说到：也要你知道本天王的厉害！\n", ob);
      }
        return 1;
}

void kill_ob (object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N说到：送你上西天！\n", ob);
      }

        ::kill_ob(me);

}

