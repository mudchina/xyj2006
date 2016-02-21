//【蜀山剑派】dhxy-evil 2000.7.5
// modified by vikee
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("白发老头", ({ "baifa laotou","fairy","laotou" }));
        set("title", "好象很聪明的");
        set("age", 300);
        set("attitude", "peaceful");
        set("int", 100);
        set("per", 20);
        
        set("max_kee", 100);
        set("max_sen", 100);


        setup();
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object who = this_player();
        object me = this_object();
        object ob;
        if (!arg || (arg != "书中仙" && arg != "老神仙"))
                return notify_fail("你要回答什么？\n");

        message_vision(CYN"白发老人说：“好，这才象样，我回去看书咯，但我会每时每刻在你身边帮助$N的！”\n", this_player());
        command("haha"+ me->query("id"));
        command("great"+ me->query("id"));
        who->add_temp("shushan/answer_book_fairy",1);
        write(CYN"说罢，白发老人消失得无影无踪！\n"NOR);
        message_vision("$N发现身上多了一本书。\n",this_player());
        ob = new("/d/shushan/obj/fbook");
        ob->move(who);
        destruct(me);
        return 1;
}
