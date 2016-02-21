// whitexiu.c

inherit NPC;

void create()
{
        set_name("白衣秀士", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "男性" );
        set("age", 25);
        set("long", "一位风流书生．不过他面色看起来怪怪的，好像有满腹心事。\n");
        set("combat_exp", 5000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate", 30);
        set_skill("force", 30);   
        set("per", 25);
        set("max_kee", 1000);
        set("max_gin", 100);
        set("max_sen", 100);
        set("force", 150);
        set("max_force", 300);
        set("force_factor", 0);
        setup();
        carry_object("/d/ourhome/obj/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 20);
        set("inquiry", ([
                "name" : "关你屁事！\n",
                "here" : "长着眼睛你不会看啊。\n",
	    "袁守诚" : "江湖骗子。只有你们这帮傻瓜才信他。\n",
	    "算命先生" : "江湖骗子。只有你们这帮傻瓜才信他。\n",
	 ]) );
}



