// written by smile on 12/20/1998

inherit NPC;

int give_lingfu();
void say_hi (object who);


void create()
{
  set_name("黑面山神", ({"heimian shanshen","shan shen", "shanshen"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 500000);
  set("per", 50);
  set_skill("dodge", 150);
  set("max_sen",2000);
  set("max_gee",2000);
  set("max_gin",2000);
  set("force",800);
  set("max_force",800);
  set("max_mana",1620);
  set("force_factor",30);
  set_skill("spells",150);
   set_skill("dao",90);
  set_skill("stick",120);
   set_skill("qianjun-bang",100);
   map_skill("stick","qianjun-bang");
   map_skill("spells","dao");
  setup();

  set("inquiry", ([
       "here": "这儿是白骨山，白骨洞就在上面在此。\n",
       "白骨山": "白骨山妖气重重，瘴气迷天，小心啊。\n",
       "白骨洞": "白骨洞住了个吃人的妖精，厉害异常啊，老夫就是被他赶下山的。\n",
       "name": "黑面山神就是老夫，要上白骨山，唯有问老夫索要灵符。\n",
       "灵符": (: give_lingfu :),
       "lingfu": (: give_lingfu :),
      ]));

  set("chat_chance",30);
  set("chat_msg",({
       "黑面山神唉的叹了一口气，难道就没有人去把白骨精给降服。！\n",
       "黑面山神自言自语道，这白骨山瘴气重重，寻常人是上不得山的。\n",
       "黑面山神笑道，不过老夫的清瘴灵符是一定有用的。\n",
  }));

  carry_object("/d/obj/cloth/choupao")->wear();
   carry_object("/d/obj/weapon/staff/muzhang")->wield();

}

int give_lingfu()
{
  object me = this_object();
  object who = this_player();
  object lingfu;

  if (who->query("combat_exp") < 10000 ||
      present("lingfu",who))
  {
    command ("shake");
       command("sigh");
       command("say 我看这位"+RANK_D->query_respect(who)+"还是自己慢慢琢磨吧！");
    return 1;
  }

  lingfu = new ("/d/qujing/baigudong/obj/lingfu");
  lingfu->move(me);
  command("hehe");
  command("give "+who->query("id")+" lingfu"); 
  who->set_temp("obstacle/baigudong_lingfu_getted",1); 
  return 1;
}

void init()
{
  object ob;
   object where;
   ::init();
    where=environment();
  if(!where->query("baigudong_has_sitted")) return;
   ob=where->query("baigudong_hero");
  if(!ob) return;
  if(present("shanshen",where)) return;
   say_hi(ob);
   call_out("destruct_me",120,this_object());
}


void say_hi (object who)
{
   command("hi "+who->query("id")); 
}

void destruct_me (object me)
{
  message_vision ("$N往边上山石一靠便消失了。\n",me);
  destruct (me);
}
