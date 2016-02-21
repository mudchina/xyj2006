inherit NPC;
#include <ansi.h>
void begin(object obj);

void create()
{
  set_name("唐太宗", ({"tang taizong", "tang", "tai zong", "zong", "king", "emperor"}));
  set("long", "大唐国之皇帝唐太宗。\n");
  set("title", "大唐国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 80);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("force_factor", 50);
  set("max_mana", 800);
  set("mana", 800);
  set("mana_factor", 40);
  set("combat_exp", 220000);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set_weight(5000000);  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init ()
{
    object who=this_player();
    if(!who) return;

  call_out ("test_player",1,this_player());
  if ((int)who->query("quest/reward") ){
      who->start_busy(2);
  }
//add_action("do_tiaozhan", "tiaozhan");
  add_action("do_jieshou", "jieshou");
  add_action("do_baodao","baodao");
  add_action("do_lingjiang","lingjiang");
}

string *strs = ({
  "$N对$n惊叹道：",
  "$N对$n赞赏道：",
  "$N微笑着对$n说道：",
  "$N赞许地对$n说道：",
});

void test_player (object who)
{
  object me = this_object();
  object where = environment (me);
  object dachen;
  string str;
  int rand, reward, color;
  mapping colors;

  if (who->query("quest/reward") < 1)
    return;

    colors=who->query("quest/colors");
    color=sizeof(colors);
//    if(!color) return;
    switch(color) {
      case 1: reward=1;break;
      case 2: reward=1;break;
      case 3: reward=3;break;
      case 4: reward=7;break;
      case 5: reward=10;break;
      case 6: reward=15;break;
      case 7: reward=25;break;
      default: reward=1;
    }
    
  // mon 12/17/98
  if(((int)who->query("combat_exp")+(int)who->query("daoxing"))/2
	  <20000) { // for newbie, no color request.
             // for older players, rewards depends on number of colors.
      if(color<2) color=2;
      if(reward<10) reward=10;
  }

  who->set_temp("quest/reward_point",
	  (int)who->query("quest/reward")*reward/6);

  message_vision ("\n一进大殿，$N身上涌起淡淡的"+
	  (color>2?chinese_number(color)+"彩":"")+
	  "祥云。\n",who);
  
  if(color==1) { // no dx & pot rewards.
      rand=random(6);
  } else {
    rand=random(100);
  }
    
  if(rand==0)
        str = "zhang shiheng";  
  else if(rand<3)
        str = "meng ziru";
  else if(rand<6)
        str = "du ruhui";       
  else if(rand<53)
        str = "duan zhixian";
  else 
        str = "xu maogong";     
    
  dachen = present (str, where);

  if (! dachen) {
    dachen = present ("da chen", where);
    //someone took dachen out of this room. nobody should do this.
    //here only give minimum reward as penalty.
    who->set_temp("quest/reward_point",0);
  }

  if (! dachen ||
      !living(dachen))
  {
    message_vision ("$N对$n说道：大臣们不在，"+RANK_D->query_respect(who)+
                    "稍候也。\n",me,who);
    return;
  }
  message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
                  "祥云缭绕，面生瑞气，朕果然有赏御赐与你！\n",me,who);
  message_vision ("\n$N走上前，赶紧在$n的殿前俯身跪下。\n",who,me);
  who->start_busy (3,3);
  call_out ("reward_player",2,me,who,dachen);
}

void reward_player (object me, object who, object dachen)
{

    // added by mon 5/29/98 to prevent players repeatedly
    // get reward.
  if ((int)who->query("quest/reward") < 1)
    return;

  message_vision ("\n旁边闪过大臣$N低声向$n说了几句，$n点了点头。\n",dachen,me);
  dachen->reward(who);
  message_vision ("\n$N连忙俯身一拜，小心翼翼地站起来。\n",who,me);
  who->delete("quest/reward");
  who->interrupt_me();
}

int do_tiaozhan(string arg)
{
	object obj,me;
	string tiaozhan_menpai;
	
	obj =this_player();
	me = this_object();
	tiaozhan_menpai = obj->query("family/family_name");
	
	if(!obj->query("zhangmen"))
	    return notify_fail("你不是掌门，不能发起挑战。\n");
	    
	if(arg == tiaozhan_menpai)
	        return notify_fail("你傻了，要挑战自己的门派？\n");
	
	if(arg != "方寸山三星洞" && arg != "南海普陀山"
	   && arg!="将军府" && arg!="五庄观"
	   && arg!="阎罗地府" && arg!="月宫"
	   && arg!="东海龙宫" && arg!="大雪山"
	   && arg!="陷空山无底洞" && arg!="火云洞"
	   && arg!="盘丝洞" && arg!="昆仑山玉虚洞"
	   && arg!="蜀山派" && arg!="三界散仙")
	 return notify_fail("你要挑战哪个门派。\n");
	 
	if(me->query_temp("tiaozhan"))
	  return notify_fail("已经有人发起挑战了。\n"); 
	 me->set_temp("tiaozhan",tiaozhan_menpai);
	 me->set_temp("beitiaozhan",arg);
	 command("chat "+tiaozhan_menpai+"掌门前来挑战"+arg+"，"+arg+"掌门速到大殿应战。");
	 call_out ("not_yingzhan",300,arg);
	 return 1;
	 
}	 
	
void not_yingzhan(string arg)
{
	object me=this_object();
	command("chat "+arg+"掌门胆小怕事，不敢前来应战。");
	me->delete_temp("tiaozhan");
	me->delete_temp("beitiaozhan");
}

int do_jieshou()
{
	object me,obj;
	string yingzhan_menpai;
	
	obj =this_player();
	me = this_object();
	yingzhan_menpai = me->query_temp("beitiaozhan");
	
	if(! yingzhan_menpai)
	  return notify_fail("没有人发起过挑战。\n"); 
	if(!obj->query("zhangmen"))
	    return notify_fail("你不是掌门，不能应战。\n");
	if ( yingzhan_menpai != obj->query("family/family_name") )
	   return notify_fail("没有人对你派发起过挑战。\n"); 
	if(me->query_temp("yingzhan"))
	  return notify_fail("已经有人应战了。\n");    
	
	remove_call_out("not_yingzhan");
	me->set_temp("yingzhan",yingzhan_menpai);
        command("chat "+yingzhan_menpai+"掌门接受"+me->query_temp("tiaozhan")+"的挑战，两派弟子在五分钟内前来大殿报到进入战场。");
        call_out("cui_baodao",60,4);
        return 1;
}	
	
void cui_baodao(int time)
{
	object me;
	string tiaozhan,yingzhan;
	me = this_object();
	if( !time ) {begin(me); return;}
	tiaozhan = me->query_temp("tiaozhan");
	yingzhan = me->query_temp("yingzhan");
	
	command("chat "+tiaozhan+"和"+yingzhan+"两派弟子在"+chinese_number(time)+"分钟内前来大殿报到进入战场。");
        call_out("cui_baodao",60,time-1);
}	
	
			
int do_baodao()
{
	object me,obj;
	string yingzhan_menpai,tiaozhan_menpai,me_menpai;
	
	obj =this_player();
	me = this_object();
	yingzhan_menpai = me->query_temp("yingzhan");
	tiaozhan_menpai = me->query_temp("tiaozhan");
	me_menpai = obj->query("family/family_name");
	
	if (!yingzhan_menpai || !tiaozhan_menpai)
	     return notify_fail("现在还不能进入战场。\n");
	if (me_menpai != yingzhan_menpai && me_menpai != tiaozhan_menpai)
	     return notify_fail("你派掌门没有来发出挑战或还没来应战。\n");
	if(me->query_temp("mpwarbegin"))
	     return notify_fail("战斗已经开始，现在不能进入战场了。\n");      
	if(present("dieda wan",obj) || present("hunyuan dan",obj)
	   || present("jishen wan",obj) || present("jinchuang yao",obj)
	   || present("jingu fen",obj))
	       return notify_fail("不能带药物进入战场。\n");
	if(present("huicheng seal",obj))
	       return notify_fail("不能带回城符进入战场。\n");       
	
	obj->remove_ride();
	obj->set_temp("mpwar_chance",5);
        obj->set_temp("mpwar_join",1);
	if(random(2)) obj->move("/d/zhanchang/zhanchang1");
	        else  obj->move("/d/zhanchang/zhanchang2");
	message_vision("$N进入了战场。\n",obj);
	
	
	return 1;
}


void begin(object me)
{
	string yingzhan_menpai,tiaozhan_menpai;
	yingzhan_menpai = me->query_temp("yingzhan");
	tiaozhan_menpai = me->query_temp("tiaozhan");
		
	command("chat 朕宣布："+tiaozhan_menpai+"和"+yingzhan_menpai+
	        "两派的大战正式开始，两派弟子都要为本门争光。");
	me->set_temp("mpwarbegin",1);
	call_out("check_fight",1);
	call_out("check_people",180);
}

void check_fight()
{

	object *all;
	int i;
	
	all = children("/obj/user");
		
	for (i = 0; i < sizeof(all); i++)
	 
	 {
	   if( !all[i]->query_temp("mpwar_chance")) continue;
	   	     
	   if( !all[i]->is_fighting() )
                all[i]->add_temp("no_fight_time",1);
                else all[i]->delete_temp("no_fight_time");     
                
           if (all[i]->query_temp("no_fight_time")==220 )
             tell_object(all[i],HIR"你还有20秒去寻找对手。\n"NOR);
              
           if(all[i]->query_temp("no_fight_time")>240)
               {all[i]->delete_temp("last_damage_from");
                all[i]->die();
               }
          }     
         
           call_out("check_fight",1);
}         


void check_people()
{

	object *all;
	object me;
	string tiaozhan,yingzhan,win;
	int tiao_number,ying_number,i;
	me = this_object();
	tiaozhan = me->query_temp("tiaozhan");
	yingzhan = me->query_temp("yingzhan");
	
	all = children("/obj/user");
		
	for (i = 0; i < sizeof(all); i++)
	 
	 {
	   if( !all[i]->query_temp("mpwar_chance")) continue;
	   
	   if (all[i]->query("family/family_name")==tiaozhan)
	      tiao_number++;
	   if (all[i]->query("family/family_name")==yingzhan)
	      ying_number++;	     
	   
          }     
           
           if(tiao_number && ying_number)
              {command("chat 现在战场内还有"+chinese_number(tiao_number)+
               "名"+tiaozhan+"弟子和"+chinese_number(ying_number)+
               "名"+yingzhan+"弟子。");
               call_out("check_people",180);
               return;
               } 
             if(tiao_number)
              {command("chat "+tiaozhan+"大获全胜，全歼敌人，战斗结束。"); 
               win=tiaozhan;
              } 
             else {command("chat "+yingzhan+"大获全胜，全歼敌人，战斗结束。"); 
                   win=yingzhan;
                  } 
             
             all = children("/obj/user");
             for (i = 0; i < sizeof(all); i++)
             {if( !all[i]->query_temp("mpwar_chance")) 
                    {if(all[i]->query("family/family_name")!=win)
                    	all[i]->delete_temp("mpwar_join");
                        continue;
                    }
              else {all[i]->move("/d/huanggong/dadian");
                    all[i]->remove_all_killer();
                    all[i]->set("eff_kee",all[i]->query("max_kee"));
                    all[i]->set("eff_sen",all[i]->query("max_sen"));
                    all[i]->set("kee",all[i]->query("max_kee"));
                    all[i]->set("sen",all[i]->query("max_sen"));
                   } 
              }
 
              me->delete_temp("mpwarbegin",1);
              me->delete_temp("tiaozhan",1);
              me->delete_temp("beitiaozhan",1);
              me->delete_temp("yingzhan",1);
              remove_call_out("check_fight");
}

int do_lingjiang()
{
	object me,obj;
	int reward_qn,reward_dx;
	
	me = this_player();
	obj = this_object();
	
	
	if (!me->query_temp("mpwar_join"))
	  return notify_fail("你没奖励可拿。\n");
	
	if (obj->query_temp("mpwarbegin"))
	  return notify_fail("战斗还没结束，你怎么知道谁会赢。\n");
	  
	 reward_qn = 1000+me->query_temp("mpwar_chance")*500;
         reward_dx = 5000+me->query_temp("mpwar_chance")*1000;
         
         message_vision(CYN"唐太宗说道：奖励$N"+reward_qn+"潜能，"+
              reward_dx +"武学经验和"+COMBAT_D->chinese_daoxing(reward_dx)+"道行。\n"NOR,me);
         
         me->add("potential",reward_qn);
         me->add("combat_exp",reward_dx);
         me->add("daoxing",reward_dx);
         me->delete_temp("mpwar_join");
         me->delete_temp("mpwar_chance");
         
         return 1;
}
