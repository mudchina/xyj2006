//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("Öª¿Í½£Í¯", ({ "zhike jiantong", "jiantong","tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 12 + random(5));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 30);
        set("combat_exp", 50000);
        set("daoxing", 70000);

        set_skill("force", 50);
        set_skill("zixia-shengong", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("spells", 50);
        set_skill("hunyuan-zhang", 50);
        set_skill("shushan-jianfa", 50);
        set_skill("sevensteps", 50);    
        set_skill("taoism",50);

        map_skill("dodge", "sevensteps");
        map_skill("spells", "taoism");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
        map_skill("unarmed", "hunyuan-zhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
