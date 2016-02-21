// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
string ask_me();

void create()
{
          set_name("金池上人", ({"lao yuanzhu", "yuanzhu"}));
          set("gender", "男性");
          set("title", "老院主");
          set("long", "观音院的主持。\n");
          set("attitude", "heroism");
          set("class", "yaomo");
          set("bellicosity", 800);
          set("per", 18);
          set("age", 270);
          set("str", 25);
          set("looking", "满面皱纹，一双昏眼，牙齿脱落，腰驼背屈。\n");
          set("combat_exp", 1200000);
          set_skill("unarmed", 175);
          set_skill("dodge", 175);
          set_skill("blade", 175);
          set_skill("parry", 175);
          set_skill("force", 175);
          set_skill("spells", 175);
          set_skill("moshenbu", 175);
          set_skill("cuixin-zhang", 175);
          map_skill("unarmed", "cuixin-zhang");
          map_skill("parry", "cuixin-zhang");
          map_skill("dodge", "moshenbu");
          set("force", 700);
        set("max_force", 700);
        set("force_factor", 30);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 300);
        set("mana", 300);
  set("chat_chance",10);
  set("chat_msg",({
         "老院主嘴里嘀咕道：老衲一生最喜爱袈裟...\n",
  }));
	set("inquiry", ([
		"袈裟"     : (: ask_me :),
	]) );
   set("mana_factor", 20);
   set_temp("apply/armor", 25);
   setup();
   carry_object("/d/qujing/guanyin/obj/jinshan")->wear();
   carry_object("/d/qujing/guanyin/obj/sengpao")->wear();
   carry_object("/d/qujing/guanyin/obj/guaizhang")->wield();
}
string ask_me()
{
	if(this_player()->query("obstacle/guanyin")!="done"){
		this_player()->set_temp("obstacle/guanyin_ask","ok");
		call_out("autokill",1,this_player(),this_object());
		return "哼，怎么没烧死你？！袈裟没了，要命倒有一条，老衲我今个也不想活了...";
	}else{
		return "我可不敢要你的袈裟了。";
	}	
}
void autokill (object me, object who)
{
  message_vision ("$n说罢，面露凶光，扑向$N！\n",me,who);
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
  if ((ob) && (ob->query_temp("obstacle/guanyin_ask") == "ok"))
  {
	ob->set_temp("obstacle/guanyin_yuanzhu",1);
	message_vision("\n老院主突然转身，一头朝墙上撞去...\n",me);
	message_vision("可怜只撞得脑破血流魂魄散，咽喉气断染红沙。\n" ,me);
	message_vision("$N哎呀一声，气绝身亡。\n\n",me);
  }else{
	message_vision("$N一个趔趄，栽倒在地，死了。\n\n",me);
  }
  message_vision("一阵风吹过，老院主的尸体顿时化作灰烬。\n\n",me);
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
