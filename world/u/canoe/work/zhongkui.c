inherit NPC;
#include <ansi.h>
#include <obstacle.h>
#define LIMIT_LENGTH    40 // 长度
string replace_long(string long);
void random_place(object who,object seal);
mapping *wheres=({
      (["chinese":                "祭赛国",
       "weizhi" :              "/d/qujing/jisaiguo",]), 
 (["chinese":                "长安城外",
        "weizhi" :              "/d/changan",]), 
  (["chinese":                "长安城东",
       "weizhi" :              "/d/eastway",]), 
  (["chinese":                "高老庄",
       "weizhi" :              "/d/gao",]), 
  (["chinese":                "开封城",
       "weizhi" :              "/d/kaifeng",]), 
  (["chinese":                "方寸山",
       "weizhi" :              "/d/lingtai",]), 
  (["chinese":                "月宫",
       "weizhi" :              "/d/moon",]), 
  (["chinese":                "普陀山",
       "weizhi" :              "/d/nanhai",]), 
  (["chinese":                "龙宫",
       "weizhi" :              "/d/sea",]), 
  (["chinese":                "长安城西",
       "weizhi" :              "/d/westway",]), 
  (["chinese":                "五庄观",
       "weizhi" :              "/d/qujing/wuzhuang",]), 
  (["chinese":                "红楼一梦",
       "weizhi" :              "/d/ourhome/honglou",]), 
  (["chinese":                "地府",
       "weizhi" :              "/d/death",]), 
  (["chinese":                "蓬莱仙岛",
       "weizhi" :              "/d/penglai",]), 
  (["chinese":                "大雪山",
       "weizhi" :              "/d/xueshan",]), 
  (["chinese":                "豹头山",
       "weizhi" :              "/d/qujing/baotou",]), 
      (["chinese":                "乌鸡国",
       "weizhi" :              "/d/qujing/wuji",]), 
      (["chinese":                "车迟国",
       "weizhi" :              "/d/qujing/chechi",]), 
      (["chinese":                "宝象国",
       "weizhi" :              "/d/qujing/baoxiang",]), 
      (["chinese":                "比丘国",
       "weizhi" :              "/d/qujing/biqiu",]), 
      (["chinese":                "东土大唐",
       "weizhi" :              "/d/city",]), 
      (["chinese":                "凤仙郡",
       "weizhi" :              "/d/qujing/fengxian",]), 
      (["chinese":                "金平府",
       "weizhi" :              "/d/qujing/jinping",]), 
      (["chinese":                "女儿国",
       "weizhi" :              "/d/qujing/nuerguo",]), 
       (["chinese":                "钦法国",
       "weizhi" :              "/d/qujing/qinfa",]), 
       (["chinese":                "天竺国",
       "weizhi" :              "/d/qujing/tianzhu",]), 
       (["chinese":                "玉华县",
       "weizhi" :              "/d/qujing/yuhua",]), 
       (["chinese":                "天竺国",
       "weizhi" :              "/d/qujing/tianzhu",]), 
       (["chinese":                "朱紫国",
       "weizhi" :              "/d/qujing/zhuzi",]), 
      });

      void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"鬼见愁"NOR);
        set("gender", "男性" );
        set("age", 30);
    set("per", 100);
 set("long", "上天入地无所不能的抓鬼大仙，你在这里可以降妖(xiangyao)。\n");

        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
          setup();
                carry_object("/d/lingtai/obj/xiangpao")->wear();

}
void init()
{
    add_action("do_quest", "xiangyao");
    add_action("do_cancel", "cancel");
}
int do_quest()
{
	object who, seal;
	mapping room;
	int level,i;
	string kind,where;
	
	who=this_player();
	message_vision("$N诚心诚意地对$n说：“弟子愿意前去降妖除魔！”\n",who,this_object());
	if (who->query("obstacle/number") < sizeof(obstacles) && !wizardp(who))
             {message_vision(CYN"\n$N说道：$n尚未取得真经，得成正果，如何能降魔除怪。\n"NOR,this_object(),who);
              return 1;
             }
        if( who->query("canoetask/get") )
             {message_vision(CYN"\n$N说道：我不是已经给了任务给$n吗，快快起程。\n"NOR,this_object(),who);
              return 1;
             }
        
        if( who->query("canoetask/fail") )
             {message_vision(CYN"\n$N说道：$n先到禅房参悟，以提高自身的修行，再来拿任务吧。\n"NOR,this_object(),who);
              return 1;
             }
        
        if( who->query("canoetask/accomplish") )
             {message_vision(CYN"\n$N说道：降妖除魔固然重要，也千万不要忽略自身的修行，否则
很容易会令自身堕入魔道的，你这就去禅房好好参悟刚才的战斗去吧。\n"NOR,who);
              return 1;
             }
             
	if((time()-who->query("canoetask/last_time"))<3)
	{
		command("say 现在还算比较太平，你先去歇了吧。");
		return 1;
	}
	seal=new(__DIR__"obj/seal");
	seal->set("master", who);
        random_place(who,seal);
       
        //确定任务等级
        level = random(10);
        if (level<4) level=1;
        else if (level<7) level=2;
        else if (level<9) level=3;
        else level=4;
        
        //确定任务种类
        i = random(5);
        if (i==0) kind="杀";
        else if (i==1) kind="擒";
        else if (i==2) kind="降";
        else if (i==3) kind="收";
        else kind="劝";
        
        who->set("canoetask/get",1);
        who->set("canoetask/level",level);
        who->set("canoetask/kind",kind);
        where=seal->query("where"); 
        seal->set("level",level);
        seal->set("kind",kind);
        seal->set("times",random(5)+3);
        switch (kind)
          {
          	case "杀":
          	 {
          	 message_vision(CYN"\n$N说道：现在有个妖孽在"+where+"附近出没，此怪
已经残杀了不少无辜，恶贯满盈了，你这就去把它除掉。\n"NOR,this_object(),who);
		 break;
		 }
          	case "擒":
          	 {
          	 message_vision(CYN"\n$N说道：现在有个妖孽在"+where+"附近出没，此怪
尚未恶贯满盈，你这就去把它生擒回来，让我亲自点化它。\n"NOR,this_object(),who);
		 break;
		 }
          	case "降":
          	{
          	message_vision(CYN"\n$N说道：现在有个妖孽在"+where+"附近出没，此怪
刚刚道满出山却好勇斗狠，你去狠狠教训（fight）它一回。\n"NOR,this_object(),who);
 		break;
 		}
		case "劝":
		{
		message_vision(CYN"\n$N说道：现在有个妖孽在"+where+"附近出没，此怪
本性不坏，只是未能冲破迷津，你这就去点化（persuade）它。\n"NOR,this_object(),who);
        	break;
        	}
                case "收":
		{
		message_vision(CYN"\n$N说道：现在有个妖孽在"+where+"附近出没，此怪
天生资质非凡，是个可造之材，你去把它收服（shoufu）吧。\n这个紫金炼妖壶自有神奇妙用，你带着。"NOR,this_object(),who);
new(__DIR__"obj/zijinhu")->move(who);
          	}
        }
        message_vision(CYN"\n接着，$N给$n一张符，说道：参悟这张符对你很有帮助。\n"NOR,this_object(),who);
      //  who->set("canoetask/where",where);
        who->set("canoetask/start_time",time());
        MONITOR_D->report_system_msg (who->name()+"接到一个难度"+chinese_number(level)+"的"+kind+"妖任务。");
      return 1;
}
int accept_object(object who, object ob)
{
       if(!ob->query("canoetask"))
           return 0;
       if(who->query("canoetask/kind") != "收"||!who->query_temp("canoetask/shoufu"))
           return 0;
       who->start_busy(2);
       who->set("canoetask/accomplish",1);
       who->delete_temp("canoetask/shoufu");
       if(random(2)) message_vision(CYN"$N赞许地拍拍$n的头说：“好孩子，真聪明！三十年后一定超过我！”\n", this_object(),who);
       else message_vision(CYN"$N用力的拍着$n的背说：“好孩子，做得不错！”你去禅房参悟吧。\n", this_object(),who);   
       return 1;
}

void random_place(object who,object seal)
{
        int  fs,k;
        mixed*  file;
        object newob;
        string dirs;
        k=random(sizeof(wheres));
        dirs=wheres[k]["weizhi"];
        seal->set("where",wheres[k]["chinese"]);
        file = get_dir( dirs+"/*.c", -1 );
        if( !sizeof(file) )  return;
        for(k=0;k<5;k++)
         {
           fs = random(sizeof(file));
           if( file[fs][1] > 0 )
             {
              dirs+="/"+file[fs][0];
              newob=load_object(dirs);
                 if (newob)
                  {  
                   seal->set("file_name", dirs);
	           seal->set("desc",replace_long(newob->query("long")) );
	           seal->move(who);
	           who->set("canoetask/last_time", time()); 
        	  }
	     }
	}
}
string replace_long(string long)
{
	string tmp="", target="";
	int length, start, i;
	int blank_flag=0;
	
	long=replace_string(long, "\n", "");
	for(i=0;i<strlen(long);i++)
		if(long[i]>160 && long[i]<255)
		 	tmp+=long[i..i];
	length=strlen(tmp);
	if(length<LIMIT_LENGTH*2)
		return tmp;
	start=random(length-LIMIT_LENGTH);
	if(start%2)
		start--;
	length=0;
	for(i=start;i<start+LIMIT_LENGTH;i+=2)
	{
		if(blank_flag<-random(2)-2)
		{
			target+="■";
			length++;
			if(random(2) || length>2)
			{
				blank_flag=0;
				length=0;
			}
		}
		else
		{
			blank_flag--;
			target+=tmp[i..i+1];
		}
	}
	return target;
}
int do_cancel()
{
	object who = this_player();
	
	if (!who->query("canoetask/get"))
	     {tell_object(who,"你没有任务在身。\n"); return 1;}
	if(present("ghost seal",who)) destruct(present("ghost seal", who));   
	who->command("say 这个任务弟子恐怕无能为力。");
	message_vision(CYN"\n$N说道：好吧，符我收回去了，你到禅房好好参悟去吧。\n"NOR,this_object(),who);
	who->set("canoetask/fail",1);
	who->delete("canoetask/get");
	return 1;
}	

