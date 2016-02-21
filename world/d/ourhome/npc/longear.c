// longear.c
// 1996/12/06 by cglaem
#include <ansi.h>

inherit NPC;

string send_mail();
string receive_mail();
string choose;
int begin_go();
object copy_yao(object ob);

void create()
{
	set_name("顺风耳", ({"shunfeng er", "er", "longear",
"youchai","chai" }) );
	set("title", "邮差");
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"前玉皇大帝亲信。因为偷听玉皇大帝跟嫦娥调情而被罚为邮差。\n");
	set("combat_exp", 8000);
  set("daoxing", 100000);

	set("attitude", "friendly");
	set("inquiry", ([
                        "name":"连我你都不认识？大名鼎鼎的顺风耳就是我。", 
		"here" : "鬼知道这是什么地方！我只负责收信发信。",
                        "嫦娥" : "唉...可惜只闻其声未见其人。",
                        "玉皇大帝" : "你别提他！一提我就有气...只许州官放火，不许百姓点灯。",
		"武学书籍"    : (: begin_go :),
	    "book"   : (: begin_go :),
	    "发信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"信件" : (: receive_mail :),
		"信" : (: receive_mail :),
		"mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	set("per", 15);
            set("max_kee", 500);
            set("max_gin", 100);
            set("max_sen", 300);
            set("force", 150);
            set("max_force", 300);
            set("force_factor", 0);
	setup();
	add_money("coin", 70);
	carry_object("/d/ourhome/obj/linen")->wear();
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到大石头来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到大石头来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}

int begin_go()
{
	object me,ob;
    me=this_player();
	ob=this_object();
    
		if (random(2)==1) choose="左";
		  else
	    choose="右";		
		if (me->query("fangcun/panlong_putuo")!="begin")
	       return 0;
       if (me->query_temp("longear_cured"))
	     {
		   call_out("answer_book",1);
		   return 1;
		 }
      if (me->query_temp("putuo/longear"))
	     {
		  message_vision ("\n顺风耳喃喃道：疼,疼死我了！\n",me);
		  return 1;
		 }
	  
	   me->set_temp("putuo/longear",choose);
     command("say 走开走开,这几天我"+choose+"耳朵又犯老毛病了,疼得厉害,谁都别来烦我！\n");
     return 1;

}

void answer_book()
{
	object me;
    me=this_player();
    message_vision ("顺风耳‘哦’的一声道：原来"+RANK_D->query_respect(me)+"要打听这个，嘿嘿，找我老顺就对啦！\n\n",me);
    command("say "+RANK_D->query_respect(me)+"可要看仔细了！\n");
    message_vision (HIW"顺风耳朝天大喝一声：来！\n\n",me);
    message_vision ("只见天空中缓缓飘下来一本名册．\n"NOR,me);

	call_out("answer_book1",2);
}

void answer_book1()
{
	object me,ob,wuxuebook;
    me=this_player();
    ob=this_object();
	message_vision ("那名册竟然飘到了$N的怀里．\n\n",me);
    command("say "+RANK_D->query_respect(me)+"此名册乃我花了多年时间查到关于武学书籍下落的纪录，这就送于你了！\n");
    wuxuebook=new("/d/nanhai/obj/wuxuebook");
	wuxuebook->move(me);
	ob->delete_temp("cured");
	me->delete_temp("longear_cured");
   me->delete_temp("putuo/longear");
}

int accept_object (object who, object ob)
{
  object me = this_object();
  object ob2;
  string msg = "$N说道：这位"+RANK_D->query_respect(who);
  string msg1 = "$N说道：你这"+RANK_D->query_rude(who);

  if (!who->query_temp("putuo/longear"))
	  return 0;
  
  if (me->query_temp("cured"))
  {
    if (ob->query("id") != "yao")
	  {
      	message_vision (msg+"这是何意？\n",me);
		return 1;
	  }

	message_vision (msg+"太客气了，我耳病已经好了,不用再麻烦了！\n",me);
    call_out("destroy_object",1,ob);
    return 1;
  }  
  
  if (ob->query("id") != "yao")
  {
    message_vision (msg1+"，大仙我正疼的厉害,还给我这些乱七八糟的东西！\n",me);
    return 1;
  }

    
  message_vision ("顺风耳接下药，半信半疑的看了看。\n",me);
  call_out("delayed_vision",1,
           "然后一口吞了下去。\n",me); 
  ob2 = copy_yao(ob);
  call_out("eat_drug",3,me,ob2,who);
  return 1;
}

void delayed_vision (string msg, object me)
{
  message_vision (msg,me);  

}

void destroy_object (object ob)
{
  destruct (ob);
}

void eat_drug (object me, object ob, object who)
{
      if (! ob->query_temp("is_longear"))
  {
    message_vision ("$N突然一阵子耳鸣，不禁疼的大声呻吟起来。\n",me,who);
    message_vision ("$N大喊道：假药，假药,"+RANK_D->query_rude(me)+"想害死我！\n",me,who);
    who->set("fangcun/panlong_nowayputuo",1);
	destruct (ob);
    return;
  }

	message_vision ("$N渐渐的脸色好转了过来,精神也已慢慢恢复了。\n",me);
    message_vision ("\n$N对$n说道：多谢这位"+RANK_D->query_respect(who)+"治好了我的老毛病,如有什么要在下帮忙的一定尽力.\n",me,who);
    who->delete("fangcun/panlong_nowayputuo");
	who->set_temp("longear_cured",1);
    me->set_temp("cured",1);
	me->command_function("thank "+who->query("id"));
    destruct (ob);
}

object copy_yao ( object me )
{
        object who = new ( "/d/qujing/zhuzi/obj/yao.c");

        who -> set("name", me->query("name"));
        who -> set_temp("is_longear", me->query_temp("is_longear") );
        who -> move(this_object());
        
        return who;
}

