
//¹í½ðÐÇ¹Ù
inherit NPC;

void create()
{

        int gd,sk;

        gd=random(2);
        sk=random(10);

        set_name("±ÚË®ÐÇ¹Ù", ({ "xing guan", "huan", "star" }));
	set("long", @LONG
¶þÊ®°ËÎ»ÐÇ¹ÙÖ®Ò»£¬ÕýÔÚµîÖÐËÄ´¦Ñ²ÓÎ¡£
LONG);
	set("title", "ÐÇËÞ");

        if (gd==1) set("gender", "ÄÐÐÔ");
        else set("gender", "Å®ÐÔ");       


	set("age", 60);
	set("class", "taoist");
	set("attitude", "friendly");
	set("per", random(20) + 10);
	set("max_kee", 600);
	set("max_gin", 200);
	set("max_sen", 600);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 60);
	set("mana", 1500);
	set("max_mana", 1500);
	set("mana_factor", 60);
	set("combat_exp", 800000);
  set("daoxing", 800000);

	set("env/no_teach", 1);

	set("eff_dx", 800000);
	set("nkgain", 800);

	set_skill("dodge", 160);
	set_skill("force", 120);
        set_skill("huntian-qigong", 120);
	set_skill("parry", 120);
	set_skill("spells", 120);
        set_skill("unarmed", 160);
        set_skill("taiyi", 120);


        switch(sk)
        {
        case 0:

            set_skill("sword", 120);
            set_skill("xiaofeng-sword", 120);
            map_skill("sword", "xiaofeng-sword");
            map_skill("parry", "xiaofeng-sword");
            break;

        case 1:

            set_skill("sword", 120);
            set_skill("qixiu-jian", 120);
            map_skill("sword", "qixiu-jian");
            map_skill("parry", "qixiu-jian");
            break;

        case 2:

            set_skill("stick", 120);
            set_skill("qianjun-bang", 120);
            map_skill("sword", "qianjun-bang");
            map_skill("parry", "qianjun-bang");
            break;

        case 3:

            set_skill("spear", 120);
            set_skill("bawang-qiang", 120);
            map_skill("spear", "bawang-qiang");
            map_skill("spear", "bawang-qiang");
            break;

        case 4:

            set_skill("sword", 120);
            set_skill("zhuihun-sword", 120);
            map_skill("sword", "zhuihun-sword");
            map_skill("parry", "zhuihun-sword");
            break;

        case 5:

            set_skill("fork", 120);
            set_skill("yueya-chan", 120);
            map_skill("fork", "yueya-chan");
            map_skill("parry", "yueya-chan");
            break;

        case 6:

            set_skill("axe", 120);
            set_skill("sanban-axe", 120);
            map_skill("axe", "sanban-axe");
            map_skill("parry", "sanban-axe");
            break;

        case 7:

            set_skill("staff", 120);
            set_skill("lunhui-zhang", 120);
            map_skill("staff", "lunhui-zhang");
            map_skill("parry", "lunhui-zhang");
            break;

        case 8:

            set_skill("sword", 120);
            set_skill("snowsword", 120);
            map_skill("sword", "snowsword");
            map_skill("parry", "snowsword");
            break;

        default :

            set_skill("fork", 120);
            set_skill("fengbo-cha", 120);
            map_skill("fork", "fengbo-cha");
            map_skill("parry", "fengbo-cha");

        }


	map_skill("spells", "taiyi");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("force", "huntian-qigong");



	setup();

        if (gd==0) carry_object("/d/obj/cloth/nichang")->wear();
        else carry_object("/d/obj/cloth/jinpao")->wear();
       

        carry_object("/d/obj/armor/tiejia")->wear();


        switch(sk)
        {
        case 0:
            carry_object("/d/obj/weapon/sword/changjian")->wield();
            break; 

        case 1:
            carry_object("/d/obj/weapon/sword/changjian")->wield();
            break; 

        case 2:
            carry_object("/d/obj/weapon/stick/bintiegun")->wield();
            break; 

        case 3:
            carry_object("/d/obj/weapon/spear/changqiang")->wield();
            break; 

        case 4:
            carry_object("/d/obj/weapon/sword/changjian")->wield();
            break; 

        case 5:
            carry_object("/d/obj/weapon/fork/gangcha")->wield();
            break; 

        case 6:
            carry_object("/d/obj/weapon/axe/huafu")->wield();
            break; 

        case 7:
            carry_object("/d/obj/weapon/staff/chanzhang")->wield();
            break; 

        case 8:
            carry_object("/d/obj/weapon/sword/changjian")->wield();
            break; 

        default :
            carry_object("/d/obj/weapon/fork/gangcha")->wield();

        }

}


ÿ