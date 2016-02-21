// hgweishi.c
 
inherit NPC;
 
void create()
{
        int rd;
 
        rd=random(4);
        set_name("»¤¹¬ÎÀÊ¿", ({ "wei shi", "shi"}) );
        set("title", "Ìì¹¬");
        set("gender", "ÄÐÐÔ" );
        set("long", 
                "Ò»¸öÍþÎäµÄ»¤¹¬ÎÀÊ¿£¬°òÀ«ÑüÔ²£¬Á¦´óÎÞÇî¡£\n"
                "ËûÊÖ³Ö±øÈÐ£¬Éí´©±¦¼×£¬Ä¿¹âÉ¨ÊÓ×ÅÃ¿¸öÂ·¹ýµÄÈË¡£\n"
        );
        set("age", 19+random(15));
        set("str", 25);
        set("int", 20);
        set("per", 15+random(10));
        
    
    set("combat_exp", 170000);
  set("daoxing", 70000);

  



	set("max_kee", 800);
	set("max_sen", 800);
        set("force",800);
        set("max_force",800);
	set("force_factor", 55);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
        set_skill("unarmed",109);
        set_skill("dodge",109);
        set_skill("parry",109);
        switch(rd) {
        case 0:
                set_skill("stick",99);
                break;
        case 1:
                        set_skill("sword",99);
                        break;
        case 2:
                        set_skill("fork",99);
                        break;
        default :
                        set_skill("axe",99);
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
 
ÿÿÿÿ