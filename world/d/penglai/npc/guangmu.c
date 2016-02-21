//Cracked by Roath
inherit NPC;
int waiting(object me);
int checking(object me);

void create()
{
        set_name("Ä§Àñºì", ({ "mo lihong","mo", "guangmu", "tianwang", "wang" }) );
        set("gender", "ÄĞĞÔ" );
	set("title", "¹ãÄ¿ÌìÍõ");
        set("long","¹ãÄ¿ÌìÍõÏ²¶¯²»Ï²¾²£¬²»Ô¸ÔÚÌìÉÏÊØÃÅ¡£
ÓñµÛ±ãÅÉËûÑ²ÓÎËÄ·½£¬±£ÎÀÖÚÏÉ¼Ò°²È«¡£\n");
        set("age",40);
        set("str",30);
        set("int",25);

        set("max_kee",900);
        set("kee",900);
        set("max_sen",900);
        set("sen",900);
        set("combat_exp",900000);

        set("force",800);
        set("max_force",800);
        set("mana",600);
        set("max_mana",600);

        set("force_factor", 60);
        set("mana_factor",50);

        set_skill("unarmed",100);
        set_skill("parry",120);
        set_skill("dodge",120);
        set_skill("spear",120);
        set_skill("bawang-qiang", 120);
        set_skill("force",120);
	set_skill("moshenbu", 120);

	map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry","bawang-qiang");
        setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
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
	object me;
	me=this_object();

        if( !ob || environment(ob) != environment() ) 
		return;
	if( (string)ob->query("id") == (string)me->query("revenge_target")){
		command("say ´óµ¨" + ob->query("name") + "£¬µ¨¸ÒÄ±º¦ÏÉ¼Ò£¬ÄÇÀïÅÜ£¡\n");
		this_object()->kill_ob(ob);
		set_leader(ob);
		ob->fihgt_ob(this_object());
		call_out("checking", 0, me);
	}
	else
		call_out("waiting", 1, me);
	return;
}
int waiting(object me)
{
        object killer;
        killer = find_player(me->query("revenge_target"));

        if ( objectp(killer) )
        {
                if (killer->is_ghost())
                {
                        me->delete("revenge_target");
                        call_out("do_back", 1, me);
                        return 1;
                }else if (me->is_fighting() && present(killer, environment(me)))
                {
                        call_out("checking", 0, me);
                        return 1;
                }else if (living(me) && !environment(killer)->query("no_fight"))
                {
                        call_out("do_back", 1, me);
                        return 1;
                }
        }

        remove_call_out("waiting");
        call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
        object ob;

        if (me->is_fighting()) 
        {
                call_out("checking", 1, me);
        return 1;
        }

        if( objectp(ob = present("corpse", environment(me)))
                 && ob->query("victim_name") == me->query("revenge_name") )
        {
                me->delete("waiting_target");
                call_out("do_back", 1, me);
        return 1;
        }

        call_out("waiting", 0, me);
        return 1;
}
int do_back(object me)
{
	message_vision("$N·ß·ßµÄºßÁËÒ»ÉùµÀ£ºÏÂ´Î±ğÈÃÀÏ×Ó´şµ½£¡\n", me);
        return 1;
}

ÿ