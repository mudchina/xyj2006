//sgzl 

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
	set("max_kee",1100);
	set("kee",1100);
	set("max_sen",1100);
	set("sen",1100);
	set("combat_exp",1000000);
        set("daoxing",1200000);
	set("force",2500);
	set("max_force",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
        set("nkgain", 800);
        set("nkgain", 500);

	set_skill("unarmed",150);
	set_skill("yingzhaogong", 150);
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("stick",150);
	set_skill("kusang-bang",150);
	set_skill("force",150);
	set_skill("spells", 150);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下多闻天王魔礼海，奉圣谕把守西天门。",
		"here" : "这里就是西天门, 入内就是天界了。",
	]) );

	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

void kill_ob (object ob)
{
  object me = this_object();  
  set("combat_exp",3000000+random(1330000));
  set("daoxing", 6000000+random(1330000));
  set("eff_kee",1100);
  set("kee",1100);
  set("sen",1100);
  set("eff_sen",1100);
  message_vision ("$N说到：送你上西天！\n",me);      
  ::kill_ob(ob);
}
