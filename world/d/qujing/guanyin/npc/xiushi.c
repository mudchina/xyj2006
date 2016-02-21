// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// whitexiu.c

inherit NPC;
string ask_me();

void create()
{
        set_name("白衣秀士", ({"xiu shi","xiushi","xiu","shi"}));
        set("gender", "男性" );
        set("age", 25);
        set("long", "一位风流书生，不过他面色看起来怪怪的。\n");
        set("combat_exp", 100000);
        set("attitude", "peaceful");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("force", 50);
        set("per", 25);
        set("max_kee", 700);
        set("max_sen", 700);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 20);
	set("inquiry", ([
		"佛衣会"     : (: ask_me :),
	]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
string ask_me()
{
	if(this_player()->query("obstacle/guanyin")!="done"){
		this_player()->set_temp("obstacle/guanyin_ask","foyi");
		call_out("autokill",1,this_player(),this_object());
		return "哼，你怎么知道的，看来不能留你活口！";
	}else{
		return "哼，关你什么事。";
	}	
}
void autokill (object me, object who)
{
  message_vision ("$n说罢，面露凶光，朝$N扑过来。\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
}
void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void unconcious()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  if ((ob)&&(ob->query_temp("obstacle/guanyin_yuanzhu"))&&(ob->query_temp("obstacle/guanyin_ask") == "foyi"))
  {
	ob->set_temp("obstacle/guanyin_xiushi",1);
	message_vision("$N转身想跑...晚了，一个趔趄，栽倒在地，现了原形，竟是条白花蛇怪。\n",me);
  }else{
	message_vision("$N一个趔趄，栽倒在地，现了原形，竟是条白花蛇怪。\n\n",me);
  }
  message_vision("$N索性提起来，摧做五七段。\n\n",ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",1,me);
}
void destruct_me(object me)
{
	if(me)
	destruct(me);
}
void die()
{
  unconcious();
}
