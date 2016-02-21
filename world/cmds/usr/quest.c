//Cracked by Roath
inherit F_CLEAN_UP;
#include <dbase.h>
#include <login.h>
#include <ansi.h>

string *quest_lib=({
        "/d/obj/quest/quest_am.c",
        "/d/obj/quest/quest_cl.c",
        "/d/obj/quest/quest_fd.c",
        "/d/obj/quest/quest_fn.c",
        "/d/obj/quest/quest_wp.c",
//        "/d/obj/quest/quest_kl.c",
//        "/d/obj/quest/quest/wr.c",
});

string *quest_fail_msg = ({
    "看了看你，然后又失望地摇了摇头，什么也不说。\n",
    "看起来很是生气，但似乎又发作不出来，只是轻轻哼了一声。\n",
    "惊奇地问：”什么，连这个都没做好？？！！！”\n"
    "沮丧地望着你，并不说话，但明显很失望。\n",
    "叹了口气：“本来对你期望甚高，怎知你却如此辜负于我的苦心...”\n",
    "摇了摇头：“我本不应该让你去的......”\n",
    "冷哼一声：“怎的你竟是如此不中用？！！”\n",
    "拍拍你的肩膀：“不要灰心，我知道你尽力了...”\n",
    "对着你摇了摇头，说：“连这点事都做不好.....下去吧。”\n",
    "看上去很不高兴，皱了皱眉头对你说：“下去歇着吧。”，嘴\n"
    "里嘟囔着：“真是没用。。。。”\n",
    "疑惑地看着你：“怎么回事？怎么你。。。”\n",
    "失望地看看你，慢慢地转过头去，跟其他弟子说话去了。\n",
    "嚷道：真是个饭桶！\n",
    "一晃脑袋，叹息道：也罢，也罢。为师本不该收你为徒的。\n"
});
string *quest_delay_msg = ({
    "似乎有些不满：“怎么现在才办好这件事？，你。。。”\n",
    "很不高兴地看了你两眼，一言不发，又把身子转了过去。。。\n",
    "瞪了你一眼：“真是误事，现在才回来....”\n",
    "很是圭怒，气呼呼地说：“你怎么现在才回来？！！”\n",
    "和蔼地笑了笑：“你应该早点回来呀....算了吧....”\n",
    "很是失望，叹了口气说：“你做事怎么如此磨蹭？！”\n",
    "好象有点生气：不行就早点回来嘛！害得人家以为你死了呢！\n",
    "气愤的说：怎么比猪还慢啊？要么大伙拱你算了。\n",
    "一脸得不耐烦：你还知道回来啊。。。\n",
    "气愤的吼道：这点小事，也要这么长时间！\n",
});

int time_period(int timep, object me);

private string get_quest_fail_msg();
private string get_quest_delay_msg();
/////////////////////////////////////////////////////////////////////////////
int give_reward(object me,mapping quest)
{
    int bonus,num;
    
    bonus = quest["bonus"];
    bonus += random(bonus);
  me->add("combat_exp",4*bonus/5);
    me->add("potential",bonus/3);
    me->add( "faith", 1);
    tell_object(me,HIW"你的忠诚度升高了。你还得到了"+chinese_number(bonus*3/4)+
                "点实战经验和"+chinese_number(bonus/5)+"点潜能。\n"NOR);
    
    num=me->query_temp("quest_number");
    num++;
    if(num==10){
        num=0;
        me->add("combat_exp",500);
        me->add("potential",200);
        tell_object(me,HIW"你得到了"+chinese_number(500)+
                "点实战经验和"+chinese_number(200)+"点潜能的附加奖励。\n"NOR);
    }             
    me->set_temp("quest_number",num);   
    return 1;
}

int give_quest(object me,object ob)
{
    mapping quest ;
    int j,timep;  
    string tag ;

if( time() - me->query("cancel_time") < 30)
        {
         tell_object(me,ob->name()+"一脸的不高兴:这点事情都干不好,等我心情好再来吧!\n");
         return 1;
        }
    if ( !me->is_apprentice_of(ob) )  
    {
         tell_object(me,ob->name()+"疑惑地看着你：“这位"+RANK_D->query_respect(me)+"想要干什么？”\n");
         return 1;
    }
    if ( quest = me->query( "fy_quest" ) )
    {
           if ( me->query("task_time") && me->query("task_time") < time() )
           {
              if ( !quest["delay_msg"] )
                  tell_object( me, ob->name() + get_quest_delay_msg() );
              else
                  tell_object( me, replace_string(quest["quest_msg"],"$N",ob->query("name")));
              me->delete_temp("quest_number");
              me->delete("fy_quest");        
              me->delete("done_quest");
          }else if ( me->query("done_quest") == quest["quest"] ){
              tell_object( me, replace_string(quest["reward_msg"],"$N",ob->query("name")));
              give_reward(me,quest);
              me->delete("done_quest");
              me->delete("fy_quest");
              return 1;
          }
          else{
          tell_object(me,ob->name()+"疑惑地看着你：“这位"+RANK_D->query_respect(me)+"不是还有任务么？”\n");
          return 1;
        }
    }
    
    // 现在先共用一个quest库
         seteuid(getuid());
    quest = quest_lib[random(sizeof(quest_lib))]->query_quest(me);
    tell_object(me,replace_string(quest["quest_msg"],"$N",ob->query("name")));
    if ( quest["send_ob"] )
        new( quest["send_ob"] )->move(me);
    me->set("fy_quest", quest);
    me->delete("task_time");
    if (!(timep = quest["time"]))timep = 400+random(200);
    time_period( timep, me );
    me->set("task_time", time() + timep);
    return 1;
}

int time_period(int timep, object me)
{
    int t, d, h, m, s;
    string time;
    t = timep;
    s = t % 60; t /= 60;
    m = t % 60; t /= 60;
    h = t % 24; t /= 24;
    d = t;

    if ( d ) time = chinese_number(d) + "天";
    else time = "";

    if ( h ) time += chinese_number(h) + "小时";
    if ( m ) time += chinese_number(m) + "分";
    time += chinese_number(s) + "秒";

    tell_object(me,HIW "你有" + time + "的时间\n去完成你师傅给的任务。\n"NOR);
    return 1;
}

int accept_object(object me, object who, object ob )
{
    mapping quest;

    if ( !me->is_apprentice_of(who))
    {
//        tell_object( me, who->name() + "疑惑地看着你：这位" +
  //          RANK_D->query_respect(me) + "是什么意思？\n" );
        return 0;
    }
 if (userp(who))
{
        tell_object(me, who->name() + "笑道：我虽然是你师傅，但我也是玩家？\n");
return 0;
}
    if ( !(quest = me->query("fy_quest")))
    {
        tell_object(me, who->name() + "笑道：你给我东西干什么？\n");
        return 0;
    }
    if ( "找" + ob->query("name") != quest["quest"] || userp(ob) )
    {
        tell_object(me, who->name() + "皱眉说：我当初可不是让你去找这个呀！\n");
        return 0;
    }
    if ( me->query("task_time") && ( me->query("task_time") < time() ) )
    {
        if ( !quest["delay_msg"] )
            tell_object( me, who->name() + get_quest_delay_msg() );
        else
            tell_object(me, quest["delay_msg"]);
        me->delete("fy_quest");
        me->delete_temp("quest_number");
        return 1;
    }
    else
    {
        tell_object( me, replace_string(quest["reward_msg"],"$N",who->query("name")));
        give_reward(me,quest);
        me->delete("fy_quest");
        return 1;
    }
}

string get_quest_fail_msg()
{
    return quest_fail_msg[ random( sizeof( quest_fail_msg ) ) ];
}

string get_quest_delay_msg()
{
    return quest_delay_msg[ random( sizeof( quest_delay_msg ) ) ];
}

int main(object me, string arg)
{
    object* inv;
  mapping quest;
    int i,nowtime;
    
    inv=all_inventory(environment(me));
    for(i=0;i<sizeof(inv);i++){
        if(me->is_apprentice_of(inv[i])){
           if(arg=="cancel"){
                if( me->query("faith")<50 )
                 return notify_fail("你师傅现在还不是很信任你，还是去做吧。\n");
                else
                me->add("faith",-2);
                me->delete_temp("quest_number");
                me->delete("fy_quest");
                me->set("cancel_time",time());
                tell_object(me,inv[i]->query("name")+get_quest_fail_msg());
           }else
           give_quest(me,inv[i]);
           return 1;
        }
    }
    if(!(quest =  me->query("fy_quest")))
               return notify_fail("你现在没有任务\n");
    write("你现在的任务是" + "【" + quest["quest"] + "】。\n");
    nowtime = (int) me->query("task_time") - time();
    if( nowtime  > 0 )
                time_period(nowtime, me);
        else
                write("但是你已经没有足够的时间来完成它了。\n");    
    return 1;
}

