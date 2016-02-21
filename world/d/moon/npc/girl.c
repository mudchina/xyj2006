//girl.c

inherit NPC;

void create()
{
        set_name("豌豆花", ({"girl"}));
        set("gender", "女性" );
        set("age", 11);
        set("long",  
"麻姑的女儿，今年刚满十三岁。她又在咬指甲了, 一看你瞧她, 
脸唰的一下就红了, 把手忙往身后一藏, 低着头用脚尖在身前
划来划去的小声问, : 有...有...有什么事嘛?\n");
        set("combat_exp", 20);
        set("attitude", "peaceful");
        set("per", 25);
        set("max_kee", 100);
        set("max_gin", 100);
        set("max_sen", 100);
        setup();
        carry_object("/d/ourhome/obj/skirt")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

int accept_fight(object me)
{
	return 0;
}



