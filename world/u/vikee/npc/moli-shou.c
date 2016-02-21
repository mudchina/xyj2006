inherit NPC;
 
void create()
{
        set_name("魔礼寿", ({ "moli shou", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "男性" );
        set("long","
四大天王之一，身担着保护后宫安全的重担，非同小可。他
的武功似乎属佛门一派，护国天王还有另外的杀手绝招，但
没有人知道是什么。也许正因为如此，玉皇才放心让他独担
重任。\n"
        );
	set("class", "xian");
	set("title", "持国天王");
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_kee",1200);
        set("kee",1100);
        set("max_sen",1100);
        set("sen",1100);
        set("combat_exp",2500000);
        set("daoxing",2500000);
        set("force",2500);
        set("max_force",1500);
        set("mana",2500);
        set("max_mana",1500);
        set("force_factor", 70);
        set("mana_factor",80);

        set("nkgain", 800);

        set_skill("unarmed",140);
	set_skill("changquan", 150);
        set_skill("parry",140);
        set_skill("dodge",150);
        set_skill("mace",150);
	set_skill("spells", 140);
        set_skill("wusi-mace",150);
        set_skill("force",140);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","lunhui-zhang");
	map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "在下就是持国天王，奉圣谕把守北天门。",
                "here" : "这里就是北天门，里面是后宫禁地。",
        ]) );
        setup();
	carry_object("/d/obj/fabao/biyu-pipa");
        carry_object("/d/obj/weapon/mace/copperjian")->wield();
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
