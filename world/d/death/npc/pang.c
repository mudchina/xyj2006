//Cracked by Roath
#include <ansi.h>
#include <login.h>

inherit NPC;
void ask_life();

string *death_msg = ({  
        HIW "崔判官向你招招手，说道：新来的，你莫乱跑，画了生死簿，我好送你还阳。\n\n" NOR,
        HIW "崔判官看着你笑了笑，说道：生死有命，你也不要太难过了。\n\n" NOR,
        HIW "崔判官从怀中拿出一个黑底白字的册子翻看着。。。\n\n" NOR,
        HIW "崔判官合上册子，说道：命不该死，多留无益，我这便送你还阳去吧！\n\n" NOR,
        HIW "崔判官伸手向你一指，你的魂魄又回到了自己身上。。。\n\n"
                "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});

void create()
{
       set_name(HIW"崔珏"NOR, ({"cui jue", "cui"}));
	set("title",HIW"朱笔判官"NOR);
       set("gender", "男性");
	set("long", "崔判官原是阳世为官，因广积阴德，死后被封为阴间判官。\n");
       set("age", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
       set("max_kee", 600);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 650);
       set("max_force", 600);
       set("force_factor", 20);
       set("max_mana", 600);
	set("mana",600);
       set("mana_factor", 10);
       set("combat_exp", 100000);
  set("daoxing", 100000);

       set_skill("unarmed", 50);
       set_skill("dodge", 40);
       set_skill("parry", 70);
	set_skill("sword", 80);
        set_skill("force", 50);

setup();

        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/sword/panguanbi")->wield();
}

void init()
{
        ::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;

        call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
        //if( !ob || !present(ob)) return;
        if(!ob) return;
	if( !ob->is_ghost() ) return;

	if(!present(ob)) {
	    message_vision("冥冥之中刮起一股阴风，将$N的鬼魂卷住不见了。\n",
		    ob);
	    ob->move(environment(this_object()),2);
	    ob->start_busy(3);
	}
        tell_object(ob, death_msg[stage]);
        if( ++stage < sizeof(death_msg) ) {
                call_out( "death_stage", 5, ob, stage );
                return;
        } else
                ob->reincarnate();
	ob->set("gin", (int)ob->query("max_gin"));
	ob->set("kee", (int)ob->query("max_kee")/4);
	ob->set("sen", (int)ob->query("max_sen")/4);
        ob->move(REVIVE_ROOM);
        tell_room(environment(ob), 
		"眼前一股青气飘荡，满满地聚成了一个人的样子。\n",({ob, ob}));
}
