// worker.c
#include <ansi.h>

inherit NPC;
string try_me(object me);

void create()
{
        set_name("皤不分", ({"bo bufen", "bo"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个胖乎乎的道士，正傻呵呵的不知笑什么．\n");
	set("class", "taoist");
        set("combat_exp", 5000);
	set("daoxing", 10000);

        set("attitude", "friendly");

        set("chat_chance_combat", 50 );
        set("inquiry", ([
"笑什么": "师父刚教我一招移行换位，嘻嘻．．．\n",
"移行换位": "听师父说可以把人传到远处，你想试试看？\n",
"试试": (: try_me :),
]) );
        setup();

}

void init()
{
        object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
        
		if (me->query_temp("fangcun/qiansi_gongxi")==1) 
		{
                remove_call_out("greeting");
                if( !me || !visible(me) || environment(me) != environment() ) return;

				message_vision("\n"NOR,me);
	            command ("ah" );
				command ("say " + "师傅,这不是孙师叔当年招来的八条天龙吗？" );
				message_vision(WHT"\n\n广羲子大笑道：正是，正是！\n\n"NOR,me);
            call_out("destroy", 60, ob);
		}
       set("chat_chance", 10);
        set("chat_msg", ({
            (: random_move :)
        }) );
}

string try_me(object me)
{	me = this_player();
        command ("say 试试也好．．．");

message_vision("皤不分双手往$N头上一按，念了句咒语．$N迷糊之中好象飞了出去．．．\n",
me);
	me->move("/d/lingtai/hill");
	return "怪了，人怎么不见了？";
}

void destroy(object ob)
{
        destruct(ob);
        return;
}