// gao.c

inherit NPC;
int zhuyao();

void create()
{
       set_name("高员外", ({"gao yuanwai", "gao"}));

set("long","高家庄的主人，吃的胖乎乎的．\n按说大财主应该乐呵呵地，他却愁眉苦脸，象是遇到了什么难事．\n");
       set("gender", "男性");
       set("age", 46);
       set("title", "庄主");
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 5000);
        set_skill("unarmed", 15);
	set_skill("dodge", 30);
	set_skill("parry", 15);
set("inquiry", ([
"name": "老夫姓高，乃是家中的主人．\n",
"here": "高老庄是也．\n",
"妖怪": (: zhuyao :),
]) );

	setup();
       add_money("silver", 3+random(5));
	carry_object("/d/ourhome/obj/choupao")->wear();
}
int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="mmmmmm") {
                say("高庄主笑道：多谢"  + RANK_D->query_respect(who) +
"，老夫这厢有礼了．\n高庄主说道：这是以前一名高士留下的，也许对您有用．\n");
	m=new("/d/gao/obj/pa_book");
        m->move(who);
	call_out("destroy", 1, ob);
	return 1;
        }
	else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

int zhuyao()
{
 object me=this_player();
 object obp;
 if (me->query("obstacle/gao")=="done")
 {
 	message_vision("笑道：多谢这为大仙为我儿除妖。\n高庄主说道：这是以前一名高士留下的，也许对您有用．\n",me);
 	obp=new("/d/gao/obj/pa_book");
 	obp->move(me);
 	obp=new("/d/gao/obj/pa");
 	obp->move(me);
 }
 else
 {
 	say("高庄主一脸愁容，说到：前几天来了个猪妖，硬要抢我女儿为妻。\n");
 	say("恳求大仙仗义相助，我女儿就被锁在后院西面阁楼里！\n");
 	me->set_temp("obstacle/yuanwai",1);
 	message_vision("$N说完有哭了起来。\n",this_object());
 }
 return 1;
}


void announce_success (object who)
{
  int i;
  object ob;
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/gao") == "done")
    return;

  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/gao","done");
//  ob=new("/clone/jian");
//  ob->move(who);
//  who->add("combat_exp",i+4000);
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"高老庄降伏猪八戒");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
