// tian-bing.c
 
inherit NPC;
 
void create()
{
        int rd;
 
        rd=random(4);
        set_name("Ìì±ø", ({ "tian bing", "tian", "bing" }) );
        set("gender", "ÄÐÐÔ" );
        set("long", 
                "ÍÐËþÀîÌìÍõÕÊÏÂÌì±ø£¬°òÀ«ÑüÔ²£¬Á¦´óÎÞÇî¡£\n"
                "ËûÊÖ³Ö±øÈÐ£¬Éí´©±¦¼×£¬Ä¿¹âÉ¨ÊÓ×ÅÃ¿¸öÂ·¹ýµÄÈË¡£\n"
        );
        set("age", 19+random(15));
        set("str", 25);
        set("int", 20);
        set("per", 15+random(10));
        set("combat_exp", 70000);
  set("daoxing", 50000);

	set("max_kee", 600);
	set("max_sen", 600);
        set("force",200);
        set("max_force",200);
	set("force_factor", 15);
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
 
ÿ