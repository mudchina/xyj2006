//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("笨鬼", ({ "fool" }));
        set("title", "思考几百年");
        set("age", 150);
        set("attitude", "peaceful");
        set("int", 1);
        set("per", 10);
        
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("chat_chance", 20);
        set("chat_msg", ({
                "笨鬼喃喃道：“我想了几百年，到底我该先踏出右脚还是先踏出左脚呢？你能回答(answer)我吗？”\n",
        }));
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);
        setup();
}

void die()
{
        object me = this_player();
        object ob = new("/d/shushan/npc/fool");
        ob->move(environment(me));

        if( environment() ) {
        message("sound", "\n笨鬼倒下去了...", environment());
        message("sound", "\n但很快又站起来了...\n", environment());
        }
        destruct(me);
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        if( !present("fbook", who)) return notify_fail("你虽然聪明，但不知道答案！\n");
        message_vision(CYN"书中仙回答：“这个问题很简单，那你把脚砍断就可以啦”！\n", this_player());
        command("idiot "+ me->query("id"));
        command("papaya "+ me->query("id"));
        command("die "+ me->query("id"));
        write("说罢，笨鬼消失得无影无踪！\n"NOR);
        destruct(me);
        return 1;
}