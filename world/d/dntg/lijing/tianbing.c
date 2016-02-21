
inherit NPC;
 
void create()
{
        int rd;
 
        rd=random(4);
        set_name("天兵", ({ "tian bing", "tian", "bing" }) );
        set("gender", "男性" );
        set("long", 
                "托塔李天王帐下天兵，膀阔腰圆，力大无穷。\n"
                "他手持兵刃，身穿宝甲，目光扫视着每个路过的人。\n"
        );
        set("age", 19+random(15));
        set("str", 25);
        set("int", 20);
        set("per", 15+random(10));
        set("combat_exp", 70000);
        set("daoxing", 50000);

        set("max_kee", 1000);
        set("max_sen", 1000);
        set("force",2000);
        set("max_force",200);
        set("force_factor", 100);
        set("mana", 200);
        set("max_mana", 200);
        set("mana_factor", 20);
        set_skill("unarmed",59);
        set_skill("dodge",59);
        set_skill("parry",59);
        switch(rd) {
        case 0:
                set_skill("stick",59);
                break;
        case 1:
                        set_skill("sword",59);
                        break;
        case 2:
                        set_skill("fork",59);
                        break;
        default :
                        set_skill("axe",59);
                        break;
        }
 
        setup();
        carry_object("/d/obj/armor/tianjia")->wear();
        switch(rd) {
        case 0:
                carry_object("/d/obj/weapon/stick/bintiegun")->wield();
                break;
        case 1:
                carry_object("/d/obj/weapon/sword/tiejian")->wield();
                break;
        case 2:
                carry_object("/d/obj/weapon/fork/gangcha")->wield();
                break;
        default :
                carry_object("/d/obj/weapon/axe/bigaxe")->wield();
                break;
        }
}
 
void heart_beat() {
       
   set("eff_kee", 1000);
   set("eff_sen", 1000);
   set("kee",1000);
   set("sen",1000);
   set("force",2000);
       
   ::heart_beat();
}
