// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
int give_good(object who);
int give_bad(object who);
int test_player (object who);
void create()
{
   set_name("黑汉", ({ "hei han", "han" }));
   set("title", "黑风洞洞主");   
   set("long", @LONG
黑汉本是山间野兽，不知从哪里学到一身好本领。
后遇见南海观音，被南海观音收为徒弟。
LONG);
   set("gender", "男性");
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("max_kee", 850);
   set("max_gin", 800);
   set("max_sen", 850);
   set("force", 400);
   set("max_force", 500);
   set("force_factor", 50);
   set("max_mana", 250);
   set("mana", 300);
   set("mana_factor", 20);
   set("combat_exp", 30000);
   set_skill("literate", 50);
   set_skill("spells", 160);
   set_skill("buddhism", 160);
   set_skill("unarmed", 200);
   set_skill("jienan-zhi", 195);
   set_skill("dodge", 180);
   set_skill("lotusmove", 180);
   set_skill("parry", 185);
   set_skill("force", 190);
   set_skill("lotusforce", 190);
   set_skill("staff", 160);
   set_skill("lunhui-zhang", 150);
   set_skill("spear", 160);
   set_skill("huoyun-qiang", 150);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jingang" :),
     (: cast_spell, "yinshen" :),
   }) );
   setup();
   carry_object("/d/qujing/guanyin/obj/boots")->wear();
   carry_object("/d/qujing/guanyin/obj/head")->wear();
   carry_object("/d/qujing/guanyin/obj/heilvshi")->wear();
   carry_object("/d/qujing/guanyin/obj/kaijia")->wear();
   carry_object("/d/qujing/guanyin/obj/zaopao")->wear();
   carry_object("/d/qujing/guanyin/obj/zaoying")->wield();
}
int accept_object (object who, object ob)
{
  object me = this_object();
  string msg = "黑汉说道：这位"+RANK_D->query_respect(who);

  if (test_player (who)){
  if ((ob->query("id") != "panzi")||(ob->query("guanyin")!="true"))
  {
	tell_object (who,msg+"，这就是你的不是啦，怎么随便拿东西骗我啊！不过东西我收了。\n");
	return 1;
  }
  if ((who)&&(who->query_temp("obstacle/guanyin_lingxuzi")))
  {
     if(random(3) < 1 ){
	call_out("give_bad",2,this_player());
	return 1;
     }
  }
  call_out("give_good",2,this_player());
  return 1;
  }else{
	tell_object (who,"黑汉怒道：你是怎么混进来的？不过看在你这份礼的份上，放你一马，赶快给老子滚远点！\n");
	return 1;
  }
}
int test_player (object who)
{
  string *names;
  string name;
  names = who->query_temp("apply/name");
  if (! names)
    return 0;
  if (sizeof(names) < 1)
    return 0;
  name = names[0];
  if (name == "凌虚子")
    return 1;
  return 0;
}
int give_good(object who)
{
  object me = this_object();
  message_vision ("$N接过盘子，对$n连声道谢。\n",me,who);
  message_vision("$N将仙丹嚼碎了咽到肚中，脸色突然转绿，一下跌倒在地！\n", me);
  message_vision("过了一阵，$N头上冒出淡淡的紫气，又神采奕奕的站了起来。\n", me);
  tell_object (who,"黑汉笑道：以后有这等好货，还请关照啊，呵呵。\n");
  return 1;
}
int give_bad(object who)
{
  object me = this_object();
  message_vision ("$N接过盘子，狐疑地看着$n。\n",me,who);
  message_vision("$N慢慢将仙丹凑在嘴边，伸出舌头添了添，脸色突然转紫，“啪”地把个仙丹捏个粉碎！\n", me);
  tell_object (who,"黑汉脸色一沉道：哼，这药丸恐怕有假吧！\n");
  who->set_temp("obstacle/guanyin_ask","xiandan");
  call_out("autokill",1,this_player(),this_object());
  return 1;
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
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  
  if ((ob)&&(ob->query_temp("obstacle/guanyin_lingxuzi"))&&(ob->query_temp("obstacle/guanyin_ask")=="xiandan"))
  {
    ob->set_temp("obstacle/guanyin_heihan",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("\n突然观音菩萨喊道：手下留情。\n",me);
  message_vision ("\n观音菩萨拿出紧箍咒套向$N头上。\n",me);
  message_vision ("\n$N倒在地上现出原形：原来是一只黑熊怪。\n",me);
  message_vision ("\n观音菩萨道：此怪倒是有些慧根，我收了去，自有用处，你等继续西去吧。\n",me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/guanyin/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}
void unconcious ()
{
  die ();
}
int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}
void destruct_me(object me)
{
	if(me)
	destruct(me);
}
