// bigeye.c
// 1996/12/06 by cglaem
#include <ansi.h>
inherit NPC_SAVE;
string send_mail();
string receive_mail();
static int i;

void create()
{	reload("jiangrobot");
	set_name("千里眼", ({"qianli yan", "bigeye", "youchai","chai" }) );
	set("title", "邮差");
	set("gender", "男性" );
	set("age", 30);
	set("str", 40);
	set("long",
		"前玉皇大帝亲信。因为偷看玉女出浴而被罚为邮差。\n他本来是和顺风耳一起呆在花果山仙石处的，\n后因嫌不够热闹跑到长安来了。\n");
	set("combat_exp", 8000);
       set("daoxing", 100000);
 
	set("attitude", "friendly");
	set("inquiry", ([
                        "name":"连我你都不认识？大名鼎鼎的千里眼就是我。", 
		"here" : "鬼知道这是什么地方！我只负责收信发信。",
                        "玉女" : "嘿嘿．．．不错。就算砍头我也划算了。",
                        "玉皇大帝" : "你别提他！一提我就有气．．．只许州官放火，不许百姓点灯。",
		"发信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"信件" : (: receive_mail :),
		"信" : (: receive_mail :),
		//"mail" : "您讲的是外国话吧？我听不懂耶~~~~~~~~",
		"mail" : (: receive_mail :),
		"mailbox" : (: receive_mail :),
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
	if(clonep()) {
	  add_money("coin", 70);
	  carry_object("/d/ourhome/obj/linen")->wear();
     CHANNEL_D->register_relay_channel("rumor");
	  carry_object("/d/wiz/npc/caishen"); //note, here is a NPC.
	}
}

void relay_channel(object ob, string channel, string msg)
 {
        string who;
        if( !userp(ob) || (channel != "rumor") ) return;
      if (wizardp(ob)) return;
        who = ob->query("id");
        if( ob==this_object() ) return;
   if( msg!="" )
    {
     i+=1;
     if (i>10) i=1;
     delete("memory/"+i);
     add("memory/"+i+"/"+who,({ msg }));
    }
   else
     return 0;
}
string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到南城客栈来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦．．．要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "等一下到南城客栈来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找．．．有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
void init()
{
    if( !environment()  ||  base_name(environment()) != query("startroom") )
            return;
    add_action("give_quest", "quest");

}
int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "千里眼说道：在" + time + "内");

                return 1;
}



int give_quest()
{
        object me,letter;
        object *ob=livings();
        int i,timep;

        me = this_player();
// 宝物送到后的busy
        if((int)me->query("letter_over") > time())
               return notify_fail("千里眼赞许地对你说：有劳这位"+RANK_D->query_respect(me)+"，请先去歇息歇息！\n");
        if((int)(me->query("daoxing")) > 200000){
                message_vision("千里眼对$N说：这位"+RANK_D->query_respect(me)+"道行高深，这种小事怎敢劳您大驾？！\n",me);
                return 1;
        }
// 没完成任务的判断
        if ((int)me->query("letter/task_time")){
// 没完成任务， 但还在时间允许范围内 
        if( ((int)me->query("letter/task_time")) >  time() ){
                tell_object(me,"你现在的任务是把信送给"+me->query("letter/target")+"\n");
                write("千里眼生气的对你说： 你得把信帮我送到呀。\n");
                return 1;
        } 
// 没完成任务，时间已过，增加busy为惩罚时间。        
        else { if(!me->query("idle_start")){me->set("idle_time",time()+120+random(120));me->set("idle_start",1);} 
                 if(me->query("idle_time")>time())
                  {
        	 write("千里眼生气的对你说：这点小事都做不好,嗯。。。\n");
                 if(me->query_temp("idle_warned")&&!me->query_temp("wait_start")) {command("heng "+me->query("id"));me->delete_temp("idle_warned");me->set_temp("wait_start",1);}
                 if(!me->query_temp("idle_warned")&&!me->query_temp("wait_start")) {command("idle "+me->query("id"));me->set_temp("idle_warned",1);}
                 write("千里眼好像在生你的闷气，可能你得等等让他消消气了！\n");
                 return 1;
                   }
                }
                 }
        message_vision("千里眼对$N说：你来得正好，我这儿刚好有一封信要送出去。\n",me);
        timep = random(200) + 180;
        i=random(sizeof(ob));
// 排除送给巫师，巫师工作目下的npc, /d/wiz下的npc的可能性
// 不能送给exp<500的玩家
        while (1){
                i++;
                if (i==sizeof(ob))
                    i=random(sizeof(ob));
                if (ob[i]==me)  continue;
                if (!environment(ob[i])) continue;
                if (ob[i]->is_ghost())  continue;
                if (random(10)==3)
                    if ( !(userp(ob[i])&&ob[i]->query("combat_exp")>500&&!wizardp(ob[i]))) continue;
                if (sscanf(base_name(ob[i]),"/u/%*s" )||sscanf(base_name(ob[i]),"/d/wiz/%*s" )) continue;
         break;
        }
        time_period(timep,me);
        if(domain_file(base_name(environment(ob[i])))=="city"||
           domain_file(base_name(environment(ob[i])))=="gao"||
           domain_file(base_name(environment(ob[i])))=="huanggong"||
           domain_file(base_name(environment(ob[i])))=="sea"||
           domain_file(base_name(environment(ob[i])))=="nanhai"
           )
         me->set("letter/basic",1);
        tell_object(me, "把信送给『" + ob[i]->short(1) + HIW +"』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        letter = new(__DIR__+"obj/letter");
        letter->set_target(ob[i]->short(1));
// 解决别人可以帮忙送物的bug
        letter->set_owner(me->query("id"));
        letter->move(me);
        me->delete("idle_start");
        me->delete_temp("wait_start");
        me->set("letter/target",ob[i]->short());
        me->set("letter/task_time", (int)time() + timep);
        me->delete("letter_over");
        return 1;
}

