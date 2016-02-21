// xiucai.c 

inherit NPC;
 
void create()
{
        set_name("张及第", ({ "xiucai", "zhang jidi", "zhang" }));
        set("long", "张秀才是村里唯一会读书的。为考状元及第改了名，到头来还是个穷秀才。\n");
        set("title", "秀才");
        set("gender", "男性");
        set("age", 65);
 
        set_skill("literate", 40);
 
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
 
        set("combat_exp", 4000);
        set("shen_type", 1);
        setup();
 
        set("chat_chance", 6);
        set("chat_msg", ({
                "张秀才说道：老夫写诗，别出心裁，不拘一格。就可惜没人能懂。唉。。。\n",
                "张秀才说道：早知道教书辛苦，不如算卦骗钱了。\n",
                "张秀才说道：之乎者也，之乎者也。汝若知乎，吾即折也。 \n",
                "张秀才说道：老夫胸怀安邦定国之策，至少也该请我到县衙门当个师爷呀！\n",
        }) );
}
 
int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/张"))
                return 0; 
        ob->add_temp("mark/张", -1);
        return 1;
}
 
int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/张"))
                who->set_temp("mark/张", 0);
        if (ob->query("money_id") && ob->value() >= 200) {
                message_vision( "张秀才高兴的对$N道：你算是找对人了。来晚了我连晚饭钱都没了。\n", who);
                who->add_temp("mark/张", ob->value() / 50);
                return 1;
        }
        return 0;
}
