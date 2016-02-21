// dibao.c

inherit NPC;

string ask_for_rumors();
string reply_about_monks();
void create()
{
  set_name("张弟宝",({"zhang dibao","zhang","dibao"}));
  set("title","地保");
  set("gender", "男性");
  set("age", 40);
  set("long","张地保的爹娘似乎生他时就知他要当地保，给他取了这么个好名字。\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "friendly");
  set("inquiry", ([
		   "name" : "在下姓张，忝为本村地保。",
		   "here" : "这里是张村儿，都姓张。",
		   "rumors" : (: reply_about_monks :),
		   "方丈" : "也不知哪位大英雄有本事把他搭救出来。全村上下这两天都人心惶惶的。",
		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
string reply_about_monks()
{
  command("say 听说村里的小庙闹鬼了，也不知道怎么回事。");
  return ("唉，我早就说过不该弄那么个破庙。这不？连方丈都给抓去了。");
}
string ask_for_rumors()
{
  command("say 唉，近日老有些大老鼠跑来跑去，不知会不会糟蹋庄稼。");
  return "村里老张家又出了事，听说犁头被个铁骷髅碰断了。唉。";
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  say("地保说道：这位" + RANK_D->query_respect(ob)+"，欢迎来到张家村！\n");
}
