//Cracked by Roath


inherit NPC;
#include <ansi.h>
int do_ok(string arg);

void create()
{
        set_name("刘伯钦", ({"liu boqin","liu"}));
        set("gender","男性");
        set("age",30);
        set("title",HIY"镇山太保"NOR);
        set("long","山中的一个猎户，十分的粗壮。");
        set("per", 20);
        set("str", 50);
        set("attitude","friendly");
        set("combat_exp",100000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",40);
        set("max_kee",300);
        set("kee",300);
        set("sen",300);
        set("max_sen",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("fork",100);

        set("inquiry",([
                "镇山太保" : "镇山太保就是我啊。",
                "here": "这个地方叫做双叉岭",
                ]));
        setup();

        carry_object("/d/obj/cloth/luoyi2")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_ok","ok");
}
void check(object ob)
{
        if( this_object()->query("said") ) return ;
        if( environment()->query("short") == "山坡" && ob->query_temp("tiger_kill")=="yes")
        {
        command("say 这位....真是厉害，想我镇山太保也不如啊。");
        command("say 如不嫌弃，到我家一叙如何(yes)？ ");
        this_object()->set("said",1);
        }
        return ;
}
int do_ok(string arg)
{
        object me = this_player();
        object ob = this_object();
        
   if(!me->query_temp("tiger_kill"))
	return 0;
   if( me->query("obstacle/sc") == "done"||me->query("obstacle/jz") != "done")
        {
        command("say 我还有点事情。\n");
        command("hehe");
        call_out("des",1,ob);
          return 0;
        }
         if( me->query("obstacle/jz") == "done")
        {
        command("say 好吧，那我们走吧。");
        me->set_temp("sc/taibao_seen",1);
        
        me->move("/d/qujing/shuangcha/shanlu4");
        ob->move("/d/qujing/shuangcha/shanlu4");
        message_vision(HIR "$N和刘伯钦向山坡走了过来。"NOR,me);
        me->move("/d/qujing/shuangcha/shanlu5");
        ob->move("/d/qujing/shuangcha/shanlu5");
        message_vision(HIR "$N和刘伯钦向山脚走了过来。"NOR,me);
        me->move("/d/qujing/shuangcha/enter");
        ob->move("/d/qujing/shuangcha/enter");
        message_vision(HIR "$N和刘伯钦向村前走了过来。"NOR,me);  
        me->move("/d/qujing/shuangcha/gate");
        ob->move("/d/qujing/shuangcha/gate");
        message_vision(HIR "$N和刘伯钦向大门走了过来。"NOR,me);  
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N和刘伯钦向庭院走了过来。"NOR,me);
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N和刘伯钦向庭院走了过来。"NOR,me);
        me->move("/d/qujing/shuangcha/zhengting");
        ob->move("/d/qujing/shuangcha/zhengting");
        message_vision(HIR "$N和刘伯钦向客厅走了过来。\n"NOR,me);
        command("say 稍等，待我出去一会。");
        destruct(ob);
        me->set_temp("home",1);        
	me->delete_temp("tiger_kill");
        return 1;
        }
}
void des()
{
        destruct(this_object());
}
