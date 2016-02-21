// keeper.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("°¢ÂŞ±¾", ({ "a luoben", "monk", "luoben" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 54);
	set("str", 25);
	set("per", 25);
	set("title", "²¨Ë¹É®ÈË");
	set("long",
	"ÕâÊÇÒ»Î»À´×ÔÎ÷ÓòµÄ¾°½ÌÉ®ÈË£¬Ó¥±ÇÉîÄ¿£¬Ğë·¢½Ô°×¡£\n"
	"ÏóÓĞÂú¸¹µÄÑ§ÎÊ£¬Õı×øÔÚÄÇÀï±ÕÄ¿³ÁË¼¡£\n");
        set("combat_exp", 100000);
  set("daoxing", 200000);

        set("attitude", "peaceful");

	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("unarmed", 80);
        set_skill("literate", 80);

	set("max_kee", 800);
        set("max_gin", 300);
	set("max_sen", 400);
	set("max_force", 300);
	set("force", 300);
	set("force_factor", 10);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 10);

	set("inquiry", ([
		"here": "´óÌÆ¾°½ÌËÂ\n",
		"name": "°¢ÂŞ±¾\n",
	]) );

        setup();

	carry_object(__DIR__"obj/sengpao")->wear();
	carry_object(__DIR__"obj/sengxie")->wear();

}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || !present(ob, environment(this_object())) ) return;
        say( "°¢ÂŞ±¾ËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
		+ "£¬ÓÃÄãµÄÕæĞÄÏòÌì¸¸Æíµ»°É¡£\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("°¢ÂŞ±¾²»ÊÕÎïÆ·µÄ¾èÏ×¡£\n");
	else if( val > 100 )
	{
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - (random((int)who->query("kar")) + val/1000) );
                if(who->query("bellicosity")<0)
		   who->set("bellicosity",0);
        }
        say( "°¢ÂŞ±¾ËµµÀ£º¶àĞ»ÕâÎ»" + RANK_D->query_respect(who)
                + "£¬Ìì¸¸Ò»¶¨»á±£ÓÓÄãµÄ¡£\n");

        return 1;
}

ÿ