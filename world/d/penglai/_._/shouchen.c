// teller.c
//cglaem...12/16/96.

inherit NPC;

string suanming(object me);

void create()
{
        set_name("袁守诚", ({"yuan shoucheng","yuan"}));
        set("title","算命先生");
        set("gender", "男性" );
        set("age", 55);
        set("class","taoist");
        set("long", "能知天地理，善晓鬼神情．长安城里没有不认识他的。\n");
        set("combat_exp", 8000);
        set("daoxing", 80000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 350);
        set("max_gin", 300);
        set("max_sen", 300);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "小道姓袁名守诚．．．嘿嘿，在这长安一带还算小有薄名。\n",
                "here" : "你没来过长安？这地方可是天下第一繁华所在。\n", 
	    "算命" : (: suanming :),
	    "算卦" : (: suanming :),
	    "suanming" : (: suanming :),
	 ]) );

        set("chat_msg", ({
	    "袁守诚晃了晃手上的桂花酒袋笑道：我这人没别的毛病，就是好点这个。\n",	
                "袁守诚上上下下打量了你几眼。\n",
                "袁守诚皱了皱眉，一副欲言又止的样子。\n",
                "袁守诚神秘兮兮地四面张望了一下，在你耳边悄声道：\n客官最近没觉得哪儿不得劲？\n",
                (: random_move :)
        }) );
}

string suanming(object me)
{
        me = this_player();

        if( !me->query_temp("suanming/paid") )
        {
                if( me->query_temp("suanming/asked") ) 
                {
                        message_vision("袁守诚闭上眼睛，不理$N了。\n", me);
                        return "今天又没钱打酒了．．．\n";
                }
                else
                {
                        me->set_temp("suanming/asked", 1);
                        message_vision("袁守诚拖长声音干咳了几声。\n", me);
                        return "这个．．．天机不可泄露啊。\n";
                }
        }
        else
        {
                me->delete_temp("suanming");
                message_vision("袁守诚对$N道：你算是找对人了！说罢掐指算了几算。\n", me);
                if(me->query("life/live_forever"))
                        return "失敬！失敬！原来"+
			    RANK_D->query_respect(me)+
			    "跳出三界外，不在五行中，已是戡破生死大限了！\n";
                else if(me->query("age")<16)
		    return RANK_D->query_respect(me)+
			"定会长命百岁，前途不可限量！\n";
		else
                   return RANK_D->query_respect(me)+"有"+
		       me->query("life/life_time")+"年的阳寿。\n";
        }
}

int accept_object(object me, object ob)
{
	object nowords;

        if( (string)ob->query("name")=="桂花酒袋" )
        {
		command("u&me " + me->query("id"));
       		command("say 这位" + RANK_D->query_respect(me) + "就是跟我投缘！\n这里我也有一点小意思，请笑纳。\n");
	        carry_object("/d/obj/book/nowords");
	        command("give nowords to " + me->query("id"));
       		return 1;
        }
        else if( ob->value() >= 100000 )
        {
                message_vision("袁守诚满面堆欢地对$N道："+RANK_D->query_respect(me)+"就是豪爽！有什么问题您尽管问！\n", me);
                me->set_temp("suanming/paid", 1);
                return 1;
        }
        else
        {
            command("say 不敢当不敢当．．．您太客气了。");
            return 1;
        }
}
