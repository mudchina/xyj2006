inherit NPC;
string try_me(object me);

void create()
{
        set_name("秦安", ({"qin an", "qin"}));
        set("title", "将军府总管");
        set("gender", "男性");
        set("age", 45);

        set("combat_exp", 35000);
        set_skill("unarmed", 70);
	set("force", 200);
	set("force_factor", 10);
        set_skill("dodge", 70);
	set_skill("parry", 70);
        setup();
        set("inquiry", ([
"俸银": (: try_me :),
]) );

        carry_object("/d/gao/obj/magua")->wear();
        add_money("silver", 10);

}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{	
        if( !arg ) return notify_fail("你说什么？\n");
        this_player()->set_temp("pending/jiangjun_answer", 0);
        message_vision("$N答道：" + arg + "\n", this_player());
        if( arg== "拜师" ) {
                command("haha");
                command("say 不是我吹，我家将军武功没人能比！\n");
                this_player()->set_temp("pending/jiangjun_answer", 1);
        } else {
                command("say 你胡说什么呀？一边玩去！\n");
        }
        return 1;
}

string try_me(object dum)
{ 	object me;
	me = this_player();
if ((int)me->query("combat_exp")<100000)
return ("将军府看重武学,你还是多在此方面多下苦功啊!\n");
         if(me->query("age")<16)
             return ("先去学点本事吧，别光想着银子。！\n");
        if((string)me->query("family/family_name")!="将军府"){
        return ("你非官家，何来俸银！！！\n");
	}
	else
        if(!(int)me->query("money_get")){
                me->set("money_get", 500);
		if((int)me->query("money_get") >
		  (int)me->query("combat_exp"))
		  return ("先去好好学点本事吧，别就想着俸银！\n");
        }
        if((int)me->query("money_get") < (int)me->query("combat_exp")){
                add_money("gold", 1);
                command("give 1 gold to " + me->query("id"));
                me->add("money_get", 500);
		return ("是时候了，这是本月俸银．\n");
        }
	else
                me->add("money_get", 100);
		me->save();
		return ("月钱刚送过，怎么又来要了？\n");
}

