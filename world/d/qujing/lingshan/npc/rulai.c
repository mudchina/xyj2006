//write by yesi
//yeahsi@21cn.com

inherit NPC;

#include <obstacle.h>
#include <ansi.h>
#include <localtime.h>

#define DEBUG 0

#define LEVEL_NONE 0
#define LEVEL_ASKED 1

string *list=({"yg-qiankun","yg-jianmang","yg-jianzhang","yg-zxzx","yg-sanshou","yg-xueshan",
                "yg-ba","yg-jldl","yg-xiao","yg-yanluo","yg-kunlun","yg-sanban",
	});
int reward_player ();
int recover_death ();

void create()
{
  set_name("如来佛", ({ "rulai fo", "rulai", "fo" }));
  set("title", "佛祖多陀阿伽陀");
  set("long", "大慈大悲灵山雷音古刹佛祖多陀阿伽陀如来佛爷。\n");
  set("gender", "男性");
  set("age", 10000);
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("rank_info/respect", "佛祖爷爷");
  //set("class", "bonze");
  set("str",100);
  set("per",100);
  set("max_kee", 10000);
  set("max_gin", 10000);
  set("max_sen", 10000);
  set("force", 10000);
  set("max_force", 10000);
  set("force_factor", 500);
  set("max_mana", 10000);
  set("mana", 10000);
  set("mana_factor", 500);
  set("combat_exp", 4000000);
  set("daoxing", 10000000);

  set_skill("literate", 300);
  set_skill("spells", 300);
  set_skill("buddhism", 300);
  set_skill("unarmed", 300);
  set_skill("jienan-zhi", 300);
  set_skill("dodge", 300);
  set_skill("lotusmove", 300);
  set_skill("parry", 300);
  set_skill("force", 300);
  set_skill("lotusforce", 300);
  set_skill("staff", 300);
  set_skill("lunhui-zhang", 300);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
  }) );
  set("inquiry", ([
    "die" : (: recover_death :),
    "death" : (: recover_death :),
    "recover" : (: recover_death :),
    "起死回生" : (: recover_death :),
    "复生" : (: recover_death :),
    "死" : (: recover_death :),
    "生" : (: recover_death :),
    "qujing" : (: reward_player :),
    "obstacle" : (: reward_player :),
    "obstacles" : (: reward_player :),
    "取经" : (: reward_player :),
    "经" : (: reward_player :),
  ]) );

  set("my_level",LEVEL_NONE);
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

int accept_object(object me, object ob)
{
  if ((me->query("fangcun/panlong_wzg_rsg")=="done")||(me->query("fangcun/panlong_wzg")=="done"))
	{	 
	 if (ob->query("id") == "renshen guo")
	{
	 command ("nod "+me->query("id"));
      command ("say 哦，" + RANK_D->query_respect(ob) + "不辞辛苦，千里迢迢送来人参果真是诚心之至！");
	  me->delete("fangcun/panlong_nowaywzg3");
	  me->add("fangcun/panlong_visite",1);
      call_out("destroy", 1, ob);
      return 1;
	}
	}
return 0;
}

void init ()
{
  add_action("do_back", "back");
  add_action("do_task", "task");
  add_action("do_cancel", "cancel");
}

void announce (object me, string str)
{
  if (DEBUG)
  { 
    object snowcat = find_player ("snowcat");
    if (snowcat && wizardp(snowcat))
      tell_object (snowcat,"◆ "+str+"\n");
  }
  else
  {
    CHANNEL_D->do_channel(me,"chat",str);
  }
}

int recover_death()
{
  object me = this_object();
  object who = this_player();

  if (who->query("obstacle/mud_age") > who->query("death/mud_age"))
  {
    message_vision ("$N对$n摇了摇头：老夫未闻死迅也。\n",me,who);
    return 1;
  }
  if (!who->query("death"))
  {
    message_vision ("$N对$n摇了摇头：老夫未闻死迅也。\n",me,who);
    return 1;
  }

  if (! who->query("obstacle/reward"))
  {
    message_vision ("$N对$n摇了摇头：你先去西域过关吧。\n",me,who);
    return 1;
  }
  if (who->query("obstacle/rebirth") >= 3)
  {
    message_vision ("$N对$n摇了摇头：你三根救命毫毛已用尽也。\n",me,who);
    return 1;
  }
  who->add("obstacle/rebirth",1);
  message_vision ("\n$N拔出一根救命毫毛，佛手一扬……。\n",me);
  message_vision ("\n$N顿觉天悬地转乾坤倒置，刹那间禁不住浑身颤抖！\n",who);
  if (who->query("death/combat_exp_loss"))
  {
    tell_object (who,"你突然发现你的武学全部恢复了！\n");
    who->add("combat_exp", (int)who->query("death/combat_exp_loss"));
  }
  if (who->query("death/dx_loss"))
  {
    tell_object (who,"你突然发现你的道行全部恢复了！\n");
    who->add("daoxing", (int)who->query("death/dx_loss"));
  }
// if (who->query("death/mud_age"))
//{
// tell_object (who,"你突然发现你的潜能全部恢复了！\n");
// who->add("potential", (int)who->query("potential")-who->query("learned_points"));
//}
  if (who->query("death/skill_loss"))
  {
    tell_object (who,"你突然发现你的武功全部恢复了！\n");
    who->skill_death_recover();
  }
log_file("RECOVER","["+ctime(time())+"] "+sprintf("%s(%s)使用了救命毫毛.\n"
, who->query("name"),who->query("id")));
  who->delete("death");
  who->save();
  return 1;

}

void do_reward (object who)
{
  object me = this_object();
  int size1 = sizeof(obstacles);
  int size2;
  string *strs = values(obstacles);
  mapping skills = who->query_skills();
  int i;

  if (! interactive (who))
    return;

  if (who->query("obstacle/reward"))
    return;

  if (who->query_temp("no_move"))
    return;

  if (who->query("obstacle/number") < size1)
    return;

  size2 = sizeof(skills);

  message_vision ("宝殿里紫霞缭绕金光万道，$N见到如来真身浑身一软拜倒在地！\n",
                  who);
  message_vision ("\n$N对$n说："+RANK_D->query_respect(who)+
                  "一路上历经灾愆患难，万里迢迢苦尽功成也。\n",me,who);
  i = (size1+size2+2)*3;
  who->start_busy(i,i);
  who->set_temp("no_move",1);

  strs = (string *)sort_array (strs, 1);
  for (i = 0; i < size1; i++)
  {
    call_out("rewarding1",(i+1)*3,me,who,strs[i]);
  }
  call_out("rewarded1",(size1+1)*3,me,who);
  strs = keys(skills);
  for (i = 0; i < size2; i++)
  {
    call_out("rewarding2",(size1+i+2)*3,me,who,strs[i]);
  }
  call_out("rewarded2",(size1+size2+2)*3,size2,me,who);
}

void rewarding1 (object me, object who, string str)
{
  int i = 600+random(who->query("kar")*30);

  who->add("obstacle/reward",i);
  who->add("potential",i);
  message_vision ("\n$N说道："+str+"一关，奖$n"+chinese_number(i)+
                  "点潜能！\n",me,who);
  tell_object(who,"你的潜能增加了"+chinese_number(i)+"点！\n");
}

void rewarded1 (object me, object who)
{
  int i = who->query("obstacle/reward");

  remove_call_out("rewarding1");
  message_vision ("\n$N一点头：共计"+chinese_number(i)+"点潜能！\n",me);
  announce (me,who->query("name")+"西天取经历经灾愆，奖励"+
            chinese_number(i)+"点潜能！\n");
}

void rewarding2 (object me, object who, string str)
{
  int i = who->query_skill(str,1);
  string name = to_chinese(str);

  who->set_skill(str,i+1);
  message_vision ("\n$N说道：奖励一级"+name+"！\n",me,who);
  tell_object(who,"你的"+name+"增加了一级！\n");
}

void rewarded2 (int size, object me, object who)
{
  remove_call_out("rewarding2");
  message_vision ("\n$N一点头：共计"+chinese_number(size)+"级技能！\n",me);
  announce (me,who->query("name")+"西天取经功德无量，奖励"+
            chinese_number(size)+"级技能！\n");
  call_out("informing",1,me,who);
}

void informing (object me, object who)
{
  who->interrupt_me();
  who->set_temp("no_move",0);
  who->save();
  me->set("my_level",LEVEL_NONE);
  me->delete_temp("invite");
  message_vision ("\n$N对$n说：起身，可去宝阁取真经一本。\n",me,who);
  message_vision ("\n$N又补充道：日后若有不测，可来大雄宝殿起死回生三次。\n",
                  me);
}

int reward_player ()
{
  object me = this_object();
  object who = this_player();
  object *all, *list;
  int size1 = sizeof(obstacles);
  int i, j;

  if (me->query("my_level") == LEVEL_ASKED)
  {
    message_vision ("$N对$n摇头说道：老夫正忙。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/reward"))
  {
    message_vision ("$N对$n说道：你不是已经来过了吗？\n",me,who);
    return 1;
  }

  if (who->query_temp("no_move"))
  {
    message_vision ("$N对$n摇摇头。\n",me,who);
    return 1;
  }

  if (who->query("obstacle/number") < size1)
  {
    message_vision ("$N对$n摇头说道：你尚未历尽难关。\n",me,who);
    return 1;
  }

  if (me->query("last_player") != who)
  {
    me->set("last_player",who);
    me->set_temp("invite","public");
    announce (me,who->query("name")+"不远万里前来取真经！");
    announce (me,"诸位仙贤如愿观礼，使accept rulai fo便可！\n");
    remove_call_out ("inviting");
    call_out ("inviting",1,me);
    return 1;
  }

  all = users();
  i = sizeof(all);
  list = all_inventory(environment(me));
  j = sizeof(filter_array(list, (:userp:))) - 1;

  if(i>12) i =12;
  if ((i/4-j) > 0)
  {
    message_vision ("$N对$n摇摇头：创世游记现有多位玩家，"
                    "此处仅有数位仙贤在邀，可否再邀"+chinese_number(i/4-j)+
                    "位仙贤前来观礼？\n",me,who);
    if (! DEBUG)                 
      return 1;
  }
  announce (me,"西游记西天取真经观礼："+who->query("name")+"大雄宝殿拜礼！\n");

  me->set("my_level",LEVEL_ASKED);
  do_reward (who);
  return 1;
}

void inviting (object me)
{
  int i;
  object *list;

  if (! me->query_temp("invite"))
    return;
  
  remove_call_out ("inviting");
  call_out ("inviting",4+random(4),me);

  list = users();
  i = sizeof(list);
  while  (i--)
  {
    string here, there;

    reset_eval_cost();
    if (!environment(list[i]))
      continue;
    if (environment(list[i])->query("unit")) // not a room
      continue;
    if (list[i]->is_fighting())
      continue;
    if (list[i]->is_busy())
      continue;
    if (list[i]->query_temp("no_move"))
      continue;
    if (list[i]->is_ghost()) // Checking ghost
      continue;
    if (!living(list[i]))
      continue;
    if ((string)list[i]->query_temp("accept")!=me->query("id"))
      continue;

    list[i]->set_temp("accept",0);
    here = (string)environment(me);
    there = (string)environment(list[i]);
    if (here == there)
      continue;

    message_vision("$N若有所思地向远方伸出手……\n",me);
    list[i]->set_temp("accept",0);
    list[i]->set_temp("lingshan/from",there);
    message_vision("一团祥云飘来，云中伸出一只巨大的佛手将$N轻轻托起，消失在天空。\n",list[i]);
    list[i]->move(here);
    message_vision("……$N轻轻一翻掌，$n稳稳地跳下来落在地上。\n",me,list[i]);
    break;
  }
}

int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("lingshan/from");

  message_vision("$N请求$n送$N回返。\n",who,me);
  //if (!there)
  //  there = "/d/city/kezhan";
  there = "/d/city/kezhan";

  who->set_temp("accept",0);
  message_vision("$N的手掌轻轻托起$n向远方伸去……\n",me,who);
  who->move(there);
  message_vision("……云中伸出一只巨大的佛手轻轻一翻，只见$N从里面跳出来。\n",who);
  
  return 1;
}

void die()
{
  if (environment())
    message("sound", "\n\n如来缓缓一点头：佛法无边！\n\n", environment());

  set("eff_kee", 10000);
  set("eff_gin", 10000);
  set("eff_sen", 10000);
  set("kee", 10000);
  set("gin", 10000);
  set("sen", 10000);
  set("force", 10000);
  set("mana", 10000);
}

void unconcious()
{
  die ();
}

int do_task()
{
	object me = this_player();
        object guai;
        int level,i,time;
        int size1 = sizeof(obstacles);
        string kind,where,msg;
        mixed*  lt;
        
        time = time();
        lt = localtime( time );
        
        me->command("say 敢问佛祖，最近可有妖怪为害？");
        
        if (me->query("obstacle/number") < size1 && !wizardp(me))
             {message_vision(CYN"\n如来佛说道：你尚未取得真经，得成正果，如何能降魔除怪。\n"NOR,me);
              return 1;
             }
 if (me->query_temp("pkgame")) return notify_fail("认真比赛先？\n");
        if( me->query("rulaitask/get") )
             {message_vision(CYN"\n如来佛说道：我不是已经给了任务你吗，快快起程。\n"NOR,me);
              return 1;
             }
        
        if( me->query("rulaitask/fail") )
             {message_vision(CYN"\n如来佛说道：你先到禅房参悟，以提高自身的修行，再来拿任务吧。\n"NOR,me);
              return 1;
             }
        
        if( me->query("rulaitask/accomplish") )
             {message_vision(CYN"\n如来佛说道：降妖除魔固然重要，也千万不要忽略自身的修行，否则
很容易会令自身堕入魔道的，你这就去禅房好好参悟刚才的战斗去吧。\n"NOR,me);
              return 1;
             }
             
        if( me->query("rulaitask/oneday") >59 
            && lt[LT_MDAY]==me->query("rulaitask/whichdate") )
             {message_vision(CYN"\n如来佛说道：你今天辛苦了，去休息吧。\n"NOR,me);
              return 1;
             }
        
        //确定任务等级
        level = random(10);
        if (level<5) level=1;
        else if (level<8) level=2;
        else level=3;
        
        //确定任务种类
        i = random(4);
        if (i==0) kind="杀";
        else if (i==1) kind="擒";
        else if (i==2) kind="降";
        else kind="劝";
        
        if(lt[LT_MDAY]!=me->query("rulaitask/whichdate"))
           {me->set("rulaitask/whichdate",lt[LT_MDAY]);
            me->delete("rulaitask/oneday");
           } 
        
        me->set("rulaitask/get",1);
        me->set("rulaitask/level",level);
        me->set("rulaitask/kind",kind);
        me->add("rulaitask/oneday",1);
        guai = new("/u/yesi/"+list[random(sizeof(list))]);
        where=guai->invocation(me, level);
        switch (kind)
          {
          	case "杀": {message_vision(CYN"\n如来佛说道：现在有一个"+where+"附近出没，此怪
已经残杀了不少无辜，恶贯满盈了，你这就去把它除掉吧。\n"NOR,me); break;}
          	case "擒": {message_vision(CYN"\n如来佛说道：现在有一个"+where+"附近出没，此怪尚未恶
贯满盈，但极难点化，你这就去把它生擒回来，让我亲自点化它。\n"NOR,me); break;}
          	case "降": {message_vision(CYN"\n如来佛说道：现在有一个"+where+"附近出没，此怪刚刚道满出山
尚未为恶，但非常好勇斗狠，你只需狠狠教训它一回，它就不敢为恶了。\n"NOR,me); break;}
		case "劝": message_vision(CYN"\n如来佛说道：现在有一个"+where+"附近出没，此
怪本性不坏，只是未能冲破迷津，你这就去点化它吧。\n"NOR,me);
          }
        me->set("rulaitask/guai",guai);
        me->set("rulaitask/where",where);
        me->set("rulaitask/start_time",time());
        msg = me->name()+"接到一个难度"+chinese_number(level)+"的"+kind+"妖任务。";
        MONITOR_D->report_system_msg (msg);
        return 1;
}        


int do_cancel()
{
	object me = this_player();
	
	if (!me->query("rulaitask/get"))
	     {tell_object(me,"你没有任务在身。\n"); return 1;}
	    
	me->command("say 这个任务弟子恐怕无能为力。");
	message_vision(CYN"\n如来佛说道：好吧，那我亲自去收服此怪，你到禅房好好参悟去吧。\n"NOR,me);
	me->set("rulaitask/fail",1);
	me->delete("rulaitask/get");
	return 1;
}	


