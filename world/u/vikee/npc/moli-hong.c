//sgzl 

inherit NPC;
void create()
{
        set_name("魔礼红", ({ "moli hong", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"魔家四将之一，使一杆方天画戟，秘授一把伞。名曰：「混元伞。」\n"
                "伞皆明珠穿成，有祖母绿，祖母碧，夜明珠，辟尘珠，辟火珠，辟水\n"
                "珠，消凉珠，九曲珠，定颜珠，定风珠。还有珍珠穿成「装载乾坤」\n"
                "四字，这把伞不敢撑，撑开时天昏地暗，日月无光，转一转乾坤晃动。\n"
	);
	set("age",50);
	set("title", "广目天王");
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
	set_skill("spear",150);
	set_skill("bawang-qiang",150);
	set_skill("force",150);
	set_skill("spells", 150);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下广目天王魔礼红，奉圣谕把守东天门。",
		"here" : "这里就是东天门, 入内就是天界了。",
	]) );

	setup();
	carry_object("/d/obj/weapon/spear/huaji")->wield();
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
